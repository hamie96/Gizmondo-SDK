/*
 * mzpokeysnd.c - POKEY sound chip emulation, v1.6
 *
 * Copyright (C) 2002 Michael Borisov
 * Copyright (C) 2002-2005 Atari800 development team (see DOC/CREDITS)
 *
 * This file is part of the Atari800 emulator project which emulates
 * the Atari 400, 800, 800XL, 130XE, and 5200 8-bit computers.
 *
 * Atari800 is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Atari800 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Atari800; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "config.h"
#include <stdlib.h>
#include <math.h>

#ifdef ASAP /* external project, see http://asap.sf.net */
#include "asap_internal.h"
#else
#include "atari.h"
#endif
#include "mzpokeysnd.h"
#include "pokeysnd.h"
#include "remez.h"

void Update_consol_sound(int);

#define SND_FILTER_SIZE  2048

#define NPOKEYS 2
#define MAX_SAMPLE 180

/* Volume only emulations declarations */
#ifdef VOL_ONLY_SOUND

#define	SAMPBUF_MAX	2000
extern int	sampbuf_val[SAMPBUF_MAX];	/* volume values */
extern int	sampbuf_cnt[SAMPBUF_MAX];	/* relative start time */
extern int	sampbuf_ptr;                    /* pointer to sampbuf */
extern int	sampbuf_rptr;                   /* pointer to read from sampbuf */
extern int	sampbuf_last;                   /* last absolute time */
extern int	sampbuf_AUDV[4 * MAXPOKEYS];	/* prev. channel volume */
extern int	sampbuf_lastval;		/* last volume */
extern int	sampout;			/* last out volume */
uint16	samp_freq;
extern int	samp_consol_val;		/* actual value of console sound */
#endif  /* VOL_ONLY_SOUND */

/* M_PI was not defined in MSVC headers */
#ifndef M_PI
# define M_PI 3.141592653589793
#endif

static unsigned int num_cur_pokeys = 0;

/* Filter */
static unsigned sample_rate; /* Hz */
static unsigned pokey_frq; /* Hz - for easier resampling */
static int filter_size;

static int filter_data[SND_FILTER_SIZE] =
{
105296,
105005,
104947,
104883,
104813,
104737,
104655,
104568,
104498,
104445,
104409,
104391,
104389,
104377,
104354,
104320,
104275,
104218,
104167,
104121,
104080,
104045,
104014,
103979,
103941,
103898,
103852,
103801,
103752,
103705,
103658,
103613,
103570,
103524,
103478,
103430,
103380,
103329,
103278,
103228,
103178,
103128,
103078,
103029,
102978,
102927,
102876,
102824,
102773,
102721,
102670,
102619,
102569,
102518,
102468,
102418,
102367,
102317,
102268,
102219,
102170,
102122,
102074,
102027,
101980,
101934,
101889,
101844,
101800,
101757,
101714,
101673,
101632,
101592,
101553,
101515,
101478,
101442,
101407,
101373,
101340,
101309,
101279,
101250,
101222,
101195,
101170,
101146,
101124,
101103,
101083,
101065,
101049,
101034,
101020,
101008,
100998,
100989,
100981,
100976,
100972,
100969,
100969,
100970,
100972,
100976,
100982,
100990,
100999,
101010,
101023,
101038,
101054,
101072,
101091,
101112,
101135,
101159,
101186,
101213,
101242,
101273,
101306,
101340,
101375,
101412,
101451,
101491,
101532,
101575,
101619,
101665,
101711,
101759,
101809,
101859,
101910,
101963,
102017,
102071,
102127,
102183,
102241,
102299,
102358,
102417,
102478,
102539,
102600,
102662,
102724,
102786,
102849,
102912,
102976,
103039,
103102,
103166,
103229,
103292,
103355,
103418,
103480,
103542,
103604,
103664,
103725,
103784,
103843,
103901,
103958,
104015,
104070,
104124,
104177,
104229,
104279,
104328,
104376,
104422,
104467,
104510,
104552,
104592,
104630,
104666,
104700,
104733,
104763,
104791,
104818,
104842,
104864,
104884,
104901,
104916,
104929,
104940,
104948,
104954,
104957,
104958,
104956,
104952,
104945,
104936,
104923,
104909,
104891,
104871,
104849,
104823,
104795,
104765,
104731,
104695,
104657,
104615,
104571,
104525,
104476,
104424,
104370,
104314,
104255,
104193,
104129,
104063,
103994,
103923,
103850,
103775,
103697,
103617,
103536,
103452,
103367,
103279,
103190,
103100,
103008,
102914,
102818,
102721,
102623,
102524,
102424,
102322,
102220,
102117,
102013,
101908,
101802,
101697,
101591,
101484,
101378,
101271,
101165,
101058,
100952,
100846,
100741,
100636,
100532,
100429,
100327,
100226,
100126,
100027,
99930,
99834,
99740,
99647,
99557,
99468,
99382,
99297,
99215,
99135,
99058,
98983,
98911,
98842,
98776,
98713,
98653,
98596,
98543,
98493,
98447,
98404,
98365,
98329,
98298,
98270,
98247,
98227,
98212,
98201,
98194,
98191,
98193,
98199,
98210,
98226,
98246,
98270,
98300,
98334,
98372,
98416,
98464,
98517,
98575,
98637,
98704,
98776,
98853,
98935,
99021,
99112,
99208,
99308,
99413,
99523,
99637,
99755,
99878,
100005,
100137,
100272,
100412,
100556,
100704,
100855,
101011,
101170,
101333,
101499,
101668,
101840,
102016,
102195,
102376,
102559,
102746,
102935,
103126,
103319,
103514,
103710,
103909,
104108,
104308,
104510,
104712,
104916,
105119,
105323,
105526,
105729,
105933,
106135,
106337,
106537,
106736,
106935,
107131,
107325,
107516,
107706,
107894,
108078,
108258,
108436,
108610,
108781,
108947,
109109,
109266,
109419,
109567,
109709,
109846,
109977,
110102,
110221,
110334,
110439,
110538,
110630,
110715,
110791,
110860,
110920,
110973,
111017,
111053,
111079,
111095,
111103,
111102,
111090,
111068,
111036,
110994,
110941,
110877,
110803,
110717,
110620,
110512,
110392,
110260,
110116,
109960,
109792,
109612,
109419,
109214,
108996,
108765,
108521,
108264,
107994,
107711,
107415,
107106,
106783,
106446,
106096,
105733,
105356,
104965,
104561,
104143,
103711,
103266,
102807,
102335,
101849,
101349,
100836,
100310,
99770,
99217,
98650,
98070,
97477,
96871,
96253,
95621,
94976,
94320,
93650,
92968,
92274,
91568,
90851,
90121,
89380,
88627,
87864,
87090,
86304,
85508,
84702,
83885,
83059,
82223,
81378,
80523,
79659,
78787,
77906,
77017,
76119,
75215,
74303,
73384,
72458,
71525,
70586,
69641,
68691,
67735,
66774,
65808,
64839,
63865,
62887,
61905,
60921,
59934,
58944,
57953,
56958,
55963,
54967,
53970,
52972,
51974,
50976,
49979,
48983,
47988,
46994,
46002,
45012,
44026,
43041,
42059,
41081,
40108,
39138,
38172,
37211,
36255,
35305,
34361,
33422,
32488,
31562,
30643,
29732,
28827,
27929,
27040,
26159,
25287,
24424,
23568,
22723,
21887,
21061,
20244,
19438,
18642,
17857,
17082,
16319,
15566,
14825,
14096,
13378,
12672,
11978,
11296,
10627,
9970,
9325,
8694,
8075,
7469,
6876,
6296,
5730,
5176,
4637,
4110,
3597,
3097,
2611,
2139,
1680,
1235,
803,
386,
-18,
-408,
-785,
-1149,
-1499,
-1835,
-2158,
-2468,
-2764,
-3047,
-3317,
-3574,
-3818,
-4048,
-4267,
-4472,
-4665,
-4845,
-5013,
-5169,
-5313,
-5445,
-5565,
-5673,
-5770,
-5856,
-5930,
-5994,
-6046,
-6089,
-6121,
-6143,
-6154,
-6156,
-6148,
-6131,
-6105,
-6070,
-6026,
-5973,
-5913,
-5844,
-5767,
-5683,
-5591,
-5492,
-5387,
-5274,
-5155,
-5029,
-4899,
-4762,
-4619,
-4471,
-4319,
-4162,
-4000,
-3834,
-3663,
-3489,
-3311,
-3130,
-2946,
-2759,
-2569,
-2378,
-2184,
-1987,
-1789,
-1590,
-1390,
-1188,
-986,
-782,
-579,
-375,
-172,
31,
234,
436,
638,
838,
1038,
1236,
1433,
1627,
1820,
2011,
2200,
2387,
2571,
2752,
2930,
3106,
3278,
3448,
3613,
3776,
3935,
4091,
4242,
4390,
4534,
4674,
4809,
4941,
5068,
5191,
5310,
5424,
5533,
5638,
5738,
5834,
5925,
6011,
6093,
6170,
6242,
6309,
6372,
6429,
6482,
6530,
6574,
6613,
6647,
6676,
6700,
6720,
6736,
6747,
6753,
6755,
6752,
6746,
6734,
6719,
6699,
6676,
6648,
6617,
6581,
6542,
6499,
6453,
6403,
6350,
6293,
6233,
6170,
6104,
6035,
5963,
5888,
5811,
5731,
5649,
5565,
5478,
5390,
5299,
5207,
5112,
5016,
4919,
4820,
4720,
4619,
4517,
4414,
4310,
4205,
4100,
3994,
3888,
3782,
3675,
3568,
3462,
3356,
3250,
3144,
3038,
2934,
2830,
2726,
2624,
2522,
2422,
2323,
2225,
2128,
2033,
1939,
1846,
1756,
1667,
1579,
1494,
1410,
1329,
1249,
1172,
1096,
1023,
952,
883,
817,
753,
692,
632,
576,
522,
470,
421,
375,
331,
290,
251,
215,
182,
151,
123,
98,
75,
55,
38,
23,
11,
1,
-5,
-9,
-11,
-10,
-7,
-1,
6,
17,
30,
45,
62,
82,
104,
129,
155,
183,
214,
246,
280,
317,
355,
394,
436,
479,
524,
570,
618,
667,
718,
769,
822,
876,
932,
988,
1045,
1103,
1162,
1222,
1282,
1343,
1404,
1466,
1528,
1591,
1654,
1717,
1780,
1844,
1907,
1971,
2034,
2097,
2160,
2222,
2285,
2346,
2408,
2469,
2529,
2588,
2647,
2705,
2763,
2819,
2875,
2930,
2983,
3036,
3087,
3138,
3187,
3235,
3282,
3327,
3371,
3414,
3455,
3495,
3534,
3571,
3606,
3640,
3673,
3704,
3733,
3761,
3787,
3811,
3834,
3855,
3875,
3892,
3909,
3923,
3936,
3947,
3956,
3964,
3970,
3974,
3977,
3978,
3977,
3974,
3970,
3965,
3958,
3949,
3938,
3926,
3913,
3898,
3881,
3863,
3843,
3822,
3800,
3776,
3751,
3724,
3697,
3668,
3637,
3606,
3573,
3539,
3504,
3468,
3431,
3393,
3354,
3315,
3274,
3232,
3190,
3146,
3102,
3057,
3012,
2966,
2919,
2872,
2824,
2776,
2728,
2678,
2629,
2579,
2529,
2478,
2428,
2377,
2327,
2276,
2225,
2174,
2122,
2070,
2019,
1968,
1918,
1868,
1818,
1768,
1718,
1668,
1617,
1566,
1517,
1468,
1422,
1377,
1333,
1288,
1241,
1194,
1145,
1094,
1048,
1006,
967,
932,
902,
866,
825,
779,
728,
672,
626,
592,
569,
557,
556,
537,
501,
449,
378,
291,
209,
134,
64
};

static double filter_data_dbl[SND_FILTER_SIZE] =
{
1.031590156,
1.031824795,
1.031871723,
1.031914651,
1.031953579,
1.031988507,
1.032019435,
1.032046363,
1.032074721,
1.032104511,
1.032135731,
1.032168382,
1.032202463,
1.032238133,
1.032275390,
1.032314235,
1.032354669,
1.032396690,
1.032440437,
1.032485911,
1.032533110,
1.032582036,
1.032632688,
1.032685185,
1.032739527,
1.032795714,
1.032853746,
1.032913622,
1.032975431,
1.033039171,
1.033104843,
1.033172448,
1.033241984,
1.033313508,
1.033387020,
1.033462520,
1.033540009,
1.033619485,
1.033700961,
1.033784437,
1.033869914,
1.033957390,
1.034046867,
1.034138312,
1.034231724,
1.034327103,
1.034424450,
1.034523765,
1.034624956,
1.034728025,
1.034832970,
1.034939792,
1.035048491,
1.035158918,
1.035271073,
1.035384955,
1.035500565,
1.035617902,
1.035736749,
1.035857105,
1.035978970,
1.036102344,
1.036227227,
1.036353336,
1.036480669,
1.036609226,
1.036739009,
1.036870016,
1.037001891,
1.037134632,
1.037268241,
1.037402717,
1.037538060,
1.037673845,
1.037810072,
1.037946741,
1.038083853,
1.038221406,
1.038358900,
1.038496336,
1.038633712,
1.038771029,
1.038908287,
1.039044917,
1.039180919,
1.039316292,
1.039451037,
1.039585154,
1.039718003,
1.039849584,
1.039979897,
1.040108941,
1.040236718,
1.040362534,
1.040486390,
1.040608286,
1.040728221,
1.040846197,
1.040961469,
1.041074038,
1.041183903,
1.041291065,
1.041395524,
1.041496500,
1.041593994,
1.041688005,
1.041778533,
1.041865579,
1.041948323,
1.042026765,
1.042100906,
1.042170744,
1.042236281,
1.042296688,
1.042351964,
1.042402111,
1.042447128,
1.042487015,
1.042520949,
1.042548928,
1.042570955,
1.042587027,
1.042597146,
1.042600521,
1.042597151,
1.042587038,
1.042570181,
1.042546579,
1.042515451,
1.042476794,
1.042430611,
1.042376900,
1.042315663,
1.042246202,
1.042168520,
1.042082616,
1.041988489,
1.041886141,
1.041774947,
1.041654908,
1.041526024,
1.041388294,
1.041241719,
1.041085767,
1.040920436,
1.040745728,
1.040561642,
1.040368179,
1.040164944,
1.039951938,
1.039729161,
1.039496613,
1.039254293,
1.039001936,
1.038739542,
1.038467110,
1.038184640,
1.037892133,
1.037589493,
1.037276722,
1.036953818,
1.036620782,
1.036277613,
1.035924388,
1.035561105,
1.035187766,
1.034804370,
1.034410917,
1.034007682,
1.033594664,
1.033171863,
1.032739281,
1.032296916,
1.031845245,
1.031384269,
1.030913987,
1.030434400,
1.029945507,
1.029448006,
1.028941896,
1.028427178,
1.027903851,
1.027371916,
1.026832288,
1.026284967,
1.025729953,
1.025167247,
1.024596848,
1.024019897,
1.023436395,
1.022846342,
1.022249737,
1.021646580,
1.021038233,
1.020424695,
1.019805966,
1.019182046,
1.018552935,
1.017920211,
1.017283875,
1.016643926,
1.016000365,
1.015353191,
1.014704185,
1.014053346,
1.013400674,
1.012746169,
1.012089832,
1.011433629,
1.010777561,
1.010121627,
1.009465828,
1.008810164,
1.008156762,
1.007505624,
1.006856747,
1.006210134,
1.005565783,
1.004925962,
1.004290672,
1.003659912,
1.003033682,
1.002411982,
1.001797187,
1.001189295,
1.000588307,
0.999994222,
0.999407042,
0.998829210,
0.998260725,
0.997701589,
0.997151801,
0.996611361,
0.996082740,
0.995565937,
0.995060954,
0.994567789,
0.994086443,
0.993619373,
0.993166580,
0.992728063,
0.992303822,
0.991893858,
0.991500567,
0.991123949,
0.990764005,
0.990420735,
0.990094138,
0.989786500,
0.989497823,
0.989228105,
0.988977348,
0.988745550,
0.988534832,
0.988345195,
0.988176638,
0.988029162,
0.987902765,
0.987799361,
0.987718948,
0.987661526,
0.987627096,
0.987615658,
0.987628856,
0.987666689,
0.987729159,
0.987816265,
0.987928007,
0.988065707,
0.988229366,
0.988418984,
0.988634560,
0.988876095,
0.989144552,
0.989439932,
0.989762234,
0.990111459,
0.990487606,
0.990891221,
0.991322303,
0.991780854,
0.992266872,
0.992780358,
0.993321408,
0.993890023,
0.994486201,
0.995109944,
0.995761251,
0.996439725,
0.997145367,
0.997878175,
0.998638150,
0.999425293,
1.000238684,
1.001078322,
1.001944209,
1.002836343,
1.003754726,
1.004697891,
1.005665839,
1.006658569,
1.007676082,
1.008718377,
1.009783425,
1.010871227,
1.011981783,
1.013115093,
1.014271155,
1.015447371,
1.016643740,
1.017860263,
1.019096938,
1.020353766,
1.021627574,
1.022918360,
1.024226126,
1.025550871,
1.026892594,
1.028247560,
1.029615767,
1.030997216,
1.032391907,
1.033799839,
1.035216731,
1.036642583,
1.038077395,
1.039521167,
1.040973898,
1.042430791,
1.043891845,
1.045357060,
1.046826437,
1.048299975,
1.049772397,
1.051243703,
1.052713893,
1.054182967,
1.055650925,
1.057112057,
1.058566361,
1.060013839,
1.061454491,
1.062888315,
1.064309226,
1.065717225,
1.067112310,
1.068494483,
1.069863742,
1.071213691,
1.072544329,
1.073855656,
1.075147673,
1.076420379,
1.077667136,
1.078887945,
1.080082805,
1.081251716,
1.082394678,
1.083504892,
1.084582359,
1.085627078,
1.086639049,
1.087618272,
1.088557873,
1.089457851,
1.090318207,
1.091138940,
1.091920050,
1.092654677,
1.093342821,
1.093984482,
1.094579659,
1.095128353,
1.095623808,
1.096066024,
1.096455001,
1.096790739,
1.097073238,
1.097295944,
1.097458855,
1.097561973,
1.097605296,
1.097588826,
1.097506305,
1.097357732,
1.097143108,
1.096862433,
1.096515707,
1.096097063,
1.095606502,
1.095044024,
1.094409628,
1.093703314,
1.092919698,
1.092058779,
1.091120558,
1.090105034,
1.089012207,
1.087837267,
1.086580212,
1.085241044,
1.083819762,
1.082316366,
1.080726695,
1.079050751,
1.077288533,
1.075440041,
1.073505275,
1.071480807,
1.069366637,
1.067162765,
1.064869191,
1.062485916,
1.060010309,
1.057442370,
1.054782099,
1.052029496,
1.049184561,
1.046245519,
1.043212370,
1.040085113,
1.036863749,
1.033548279,
1.030137831,
1.026632406,
1.023032005,
1.019336627,
1.015546273,
1.011661011,
1.007680843,
1.003605768,
0.999435786,
0.995170897,
0.990812138,
0.986359508,
0.981813009,
0.977172638,
0.972438397,
0.967612297,
0.962694338,
0.957684520,
0.952582842,
0.947389305,
0.942106895,
0.936735612,
0.931275455,
0.925726426,
0.920088523,
0.914365692,
0.908557932,
0.902665244,
0.896687628,
0.890625084,
0.884482486,
0.878259834,
0.871957129,
0.865574371,
0.859111559,
0.852574457,
0.845963064,
0.839277382,
0.832517409,
0.825683146,
0.818781188,
0.811811536,
0.804774189,
0.797669148,
0.790496412,
0.783263345,
0.775969946,
0.768616217,
0.761202156,
0.753727764,
0.746201093,
0.738622143,
0.730990915,
0.723307408,
0.715571622,
0.707792210,
0.699969170,
0.692102504,
0.684192210,
0.676238290,
0.668249901,
0.660227042,
0.652169715,
0.644077918,
0.635951652,
0.627800473,
0.619624383,
0.611423380,
0.603197465,
0.594946637,
0.586680746,
0.578399791,
0.570103771,
0.561792687,
0.553466539,
0.545135350,
0.536799121,
0.528457850,
0.520111538,
0.511760185,
0.503413873,
0.495072602,
0.486736373,
0.478405184,
0.470079036,
0.461767952,
0.453471932,
0.445190977,
0.436925086,
0.428674258,
0.420448343,
0.412247340,
0.404071250,
0.395920071,
0.387793805,
0.379702008,
0.371644681,
0.363621822,
0.355633433,
0.347679513,
0.339769219,
0.331902553,
0.324079513,
0.316300101,
0.308564315,
0.300880808,
0.293249580,
0.285670630,
0.278143959,
0.270669567,
0.263255506,
0.255901777,
0.248608378,
0.241375311,
0.234202575,
0.227097534,
0.220060187,
0.213090535,
0.206188577,
0.199354314,
0.192594341,
0.185908659,
0.179297266,
0.172760164,
0.166297352,
0.159914594,
0.153611889,
0.147389237,
0.141246639,
0.135184095,
0.129206479,
0.123313791,
0.117506031,
0.111783200,
0.106145297,
0.100596268,
0.095136111,
0.089764828,
0.084482418,
0.079288881,
0.074187203,
0.069177385,
0.064259426,
0.059433326,
0.054699085,
0.050058714,
0.045512214,
0.041059585,
0.036700826,
0.032435937,
0.028265955,
0.024190880,
0.020210712,
0.016325450,
0.012535096,
0.008839718,
0.005239316,
0.001733892,
-0.001676556,
-0.004992027,
-0.008213390,
-0.011340647,
-0.014373796,
-0.017312838,
-0.020157773,
-0.022910376,
-0.025570647,
-0.028138586,
-0.030614193,
-0.032997468,
-0.035291042,
-0.037494914,
-0.039609084,
-0.041633552,
-0.043568318,
-0.045416810,
-0.047179028,
-0.048854972,
-0.050444643,
-0.051948039,
-0.053369321,
-0.054708489,
-0.055965544,
-0.057140484,
-0.058233311,
-0.059248835,
-0.060187056,
-0.061047975,
-0.061831591,
-0.062537905,
-0.063172301,
-0.063734779,
-0.064225340,
-0.064643984,
-0.064990710,
-0.065271385,
-0.065486009,
-0.065634582,
-0.065717103,
-0.065733573,
-0.065690250,
-0.065587132,
-0.065424221,
-0.065201515,
-0.064919016,
-0.064583278,
-0.064194301,
-0.063752085,
-0.063256630,
-0.062707936,
-0.062112759,
-0.061471098,
-0.060782954,
-0.060048327,
-0.059267217,
-0.058446484,
-0.057586128,
-0.056686150,
-0.055746549,
-0.054767326,
-0.053755355,
-0.052710636,
-0.051633169,
-0.050522955,
-0.049379993,
-0.048211082,
-0.047016222,
-0.045795413,
-0.044548656,
-0.043275950,
-0.041983933,
-0.040672606,
-0.039341968,
-0.037992019,
-0.036622760,
-0.035240587,
-0.033845502,
-0.032437503,
-0.031016592,
-0.029582768,
-0.028142116,
-0.026694638,
-0.025240334,
-0.023779202,
-0.022311244,
-0.020842170,
-0.019371980,
-0.017900674,
-0.016428252,
-0.014954714,
-0.013485337,
-0.012020122,
-0.010559068,
-0.009102175,
-0.007649444,
-0.006205672,
-0.004770860,
-0.003345008,
-0.001928116,
-0.000520184,
0.000874507,
0.002255956,
0.003624163,
0.004979128,
0.006320852,
0.007645597,
0.008953363,
0.010244149,
0.011517957,
0.012774785,
0.014011460,
0.015227982,
0.016424352,
0.017600568,
0.018756630,
0.019889940,
0.021000496,
0.022088298,
0.023153346,
0.024195641,
0.025213154,
0.026205884,
0.027173832,
0.028116997,
0.029035379,
0.029927514,
0.030793401,
0.031633039,
0.032446430,
0.033233573,
0.033993548,
0.034726356,
0.035431998,
0.036110472,
0.036761779,
0.037385522,
0.037981700,
0.038550315,
0.039091365,
0.039604851,
0.040090869,
0.040549420,
0.040980502,
0.041384117,
0.041760264,
0.042109489,
0.042431791,
0.042727171,
0.042995628,
0.043237163,
0.043452739,
0.043642357,
0.043806016,
0.043943716,
0.044055458,
0.044142564,
0.044205034,
0.044242867,
0.044256065,
0.044244627,
0.044210197,
0.044152775,
0.044072362,
0.043968958,
0.043842561,
0.043695085,
0.043526528,
0.043336891,
0.043126173,
0.042894375,
0.042643618,
0.042373900,
0.042085223,
0.041777585,
0.041450988,
0.041107718,
0.040747774,
0.040371156,
0.039977865,
0.039567901,
0.039143660,
0.038705143,
0.038252350,
0.037785280,
0.037303934,
0.036810769,
0.036305786,
0.035788983,
0.035260362,
0.034719922,
0.034170134,
0.033610997,
0.033042513,
0.032464681,
0.031877501,
0.031283416,
0.030682428,
0.030074536,
0.029459740,
0.028838041,
0.028211811,
0.027581051,
0.026945761,
0.026305940,
0.025661589,
0.025014976,
0.024366099,
0.023714961,
0.023061559,
0.022405895,
0.021750096,
0.021094162,
0.020438094,
0.019781891,
0.019125554,
0.018471049,
0.017818377,
0.017167538,
0.016518532,
0.015871358,
0.015227797,
0.014587848,
0.013951512,
0.013318788,
0.012689677,
0.012065757,
0.011447028,
0.010833490,
0.010225143,
0.009621986,
0.009025381,
0.008435328,
0.007851826,
0.007274875,
0.006704476,
0.006141770,
0.005586756,
0.005039435,
0.004499807,
0.003967872,
0.003444545,
0.002929827,
0.002423717,
0.001926216,
0.001437323,
0.000957736,
0.000487454,
0.000026478,
-0.000425193,
-0.000867558,
-0.001300140,
-0.001722941,
-0.002135959,
-0.002539194,
-0.002932647,
-0.003316043,
-0.003689382,
-0.004052665,
-0.004405890,
-0.004749059,
-0.005082095,
-0.005404999,
-0.005717771,
-0.006020410,
-0.006312917,
-0.006595387,
-0.006867819,
-0.007130213,
-0.007382570,
-0.007624890,
-0.007857438,
-0.008080215,
-0.008293221,
-0.008496456,
-0.008689919,
-0.008874005,
-0.009048713,
-0.009214044,
-0.009369996,
-0.009516571,
-0.009654301,
-0.009783185,
-0.009903224,
-0.010014418,
-0.010116766,
-0.010210893,
-0.010296797,
-0.010374479,
-0.010443940,
-0.010505177,
-0.010558888,
-0.010605072,
-0.010643728,
-0.010674856,
-0.010698458,
-0.010715315,
-0.010725428,
-0.010728798,
-0.010725423,
-0.010715304,
-0.010699232,
-0.010677205,
-0.010649226,
-0.010615292,
-0.010575405,
-0.010530388,
-0.010480241,
-0.010424965,
-0.010364558,
-0.010299021,
-0.010229183,
-0.010155042,
-0.010076600,
-0.009993856,
-0.009906810,
-0.009816282,
-0.009722271,
-0.009624777,
-0.009523801,
-0.009419342,
-0.009312180,
-0.009202315,
-0.009089746,
-0.008974474,
-0.008856498,
-0.008736563,
-0.008614667,
-0.008490811,
-0.008364995,
-0.008237218,
-0.008108174,
-0.007977861,
-0.007846280,
-0.007713431,
-0.007579314,
-0.007444569,
-0.007309196,
-0.007173194,
-0.007036564,
-0.006899306,
-0.006761989,
-0.006624613,
-0.006487177,
-0.006349683,
-0.006212130,
-0.006075018,
-0.005938349,
-0.005802122,
-0.005666337,
-0.005530994,
-0.005396518,
-0.005262909,
-0.005130168,
-0.004998293,
-0.004867286,
-0.004737503,
-0.004608946,
-0.004481613,
-0.004355504,
-0.004230621,
-0.004107247,
-0.003985382,
-0.003865026,
-0.003746179,
-0.003628842,
-0.003513232,
-0.003399350,
-0.003287195,
-0.003176768,
-0.003068069,
-0.002961247,
-0.002856302,
-0.002753233,
-0.002652042,
-0.002552727,
-0.002455380,
-0.002360001,
-0.002266589,
-0.002175144,
-0.002085667,
-0.001998191,
-0.001912714,
-0.001829238,
-0.001747762,
-0.001668286,
-0.001590797,
-0.001515297,
-0.001441785,
-0.001370261,
-0.001300725,
-0.001233120,
-0.001167448,
-0.001103708,
-0.001041899,
-0.000982023,
-0.000923991,
-0.000867804,
-0.000813462,
-0.000760965,
-0.000710313,
-0.000661387,
-0.000614188,
-0.000568714,
-0.000524967,
-0.000482946,
-0.000442512,
-0.000403667,
-0.000366410,
-0.000330740,
-0.000296659,
-0.000264008,
-0.000232788,
-0.000202998,
-0.000174640,
-0.000147712,
-0.000116784,
-0.000081856,
-0.000042928
};
static unsigned audible_frq;

static const unsigned long pokey_frq_ideal =  1789790; /* Hz - True */
#if 0
static const int filter_size_44 = 1274;
static const int filter_size_44_8 = 884;
static const int filter_size_22 = 1239;
static const int filter_size_22_8 = 893;
static const int filter_size_11 = 1305;
static const int filter_size_11_8 = 937;
static const int filter_size_48 = 898;
static const int filter_size_48_8 = 626;
static const int filter_size_8  = 1322;
static const int filter_size_8_8 = 1214;
#endif

/* Flags and quality */
static int snd_flags = 0;
static int snd_quality = 0;

/* Poly tables */
static unsigned char poly4tbl[15];
static unsigned char poly5tbl[31];
static unsigned char poly17tbl[131071];
static unsigned char poly9tbl[511];


struct stPokeyState;

typedef unsigned char (*readout_t)(struct stPokeyState* ps);
typedef void (*event_t)(struct stPokeyState* ps, char p5v, char p4v, char p917v);



/* State variables for single Pokey Chip */
typedef struct stPokeyState
{
    /* Poly positions */
    unsigned int poly4pos;
    unsigned int poly5pos;
    unsigned int poly17pos;
    unsigned int poly9pos;

    /* Change queue */
    unsigned char ovola;
    short qet[1322]; /* maximal length of filter */
    unsigned char qev[1322];
    int qebeg;
    int qeend;

    /* Main divider (64khz/15khz) */
    unsigned char mdivk;    /* 28 for 64khz, 114 for 15khz */

    /* Main switches */
    unsigned char selpoly9;
    unsigned char c0_hf;
    unsigned char c1_f0;
    unsigned char c2_hf;
    unsigned char c3_f2;

    /* Main output state */
    unsigned char outvol_all;
    unsigned char forcero; /* Force readout */

    /* channel 0 state */

    readout_t readout_0;
    event_t event_0;

    unsigned long c0divpos;
    unsigned long c0divstart;   /* AUDF0 recalculated */
    unsigned long c0divstart_p; /* start value when c1_f0 */
    unsigned short c0diva;      /* AUDF0 register */
    unsigned char c0ctl;        /* AUDC0 register */

    unsigned char c0t1;         /* D - 5bit, Q goes to sw3 */
    unsigned char c0t2;         /* D - out sw2, Q goes to sw4 and t3 */
    unsigned char c0t3;         /* D - out t2, q goes to xor */

    unsigned char c0sw1;        /* in1 - 4bit, in2 - 17bit, out goes to sw2 */
    unsigned char c0sw2;        /* in1 - /Q t2, in2 - out sw1, out goes to t2 */
    unsigned char c0sw3;        /* in1 - +5, in2 - Q t1, out goes to C t2 */
    unsigned char c0sw4;        /* hi-pass sw */
    unsigned char c0vo;         /* volume only */

    unsigned char c0stop;       /* channel counter stopped */

    unsigned char vol0;

    unsigned char outvol_0;

    /* channel 1 state */

    readout_t readout_1;
    event_t event_1;

    unsigned long c1divpos;
    unsigned long c1divstart;
    unsigned short c1diva;
    unsigned char c1ctl;

    unsigned char c1t1;
    unsigned char c1t2;
    unsigned char c1t3;

    unsigned char c1sw1;
    unsigned char c1sw2;
    unsigned char c1sw3;
    unsigned char c1sw4;
    unsigned char c1vo;

    unsigned char c1stop;      /* channel counter stopped */

    unsigned char vol1;

    unsigned char outvol_1;

    /* channel 2 state */

    readout_t readout_2;
    event_t event_2;

    unsigned long c2divpos;
    unsigned long c2divstart;
    unsigned long c2divstart_p;     /* start value when c1_f0 */
    unsigned short c2diva;
    unsigned char c2ctl;

    unsigned char c2t1;
    unsigned char c2t2;

    unsigned char c2sw1;
    unsigned char c2sw2;
    unsigned char c2sw3;
    unsigned char c2vo;

    unsigned char c2stop;          /* channel counter stopped */

    unsigned char vol2;

    unsigned char outvol_2;

    /* channel 3 state */

    readout_t readout_3;
    event_t event_3;

    unsigned long c3divpos;
    unsigned long c3divstart;
    unsigned short c3diva;
    unsigned char c3ctl;

    unsigned char c3t1;
    unsigned char c3t2;

    unsigned char c3sw1;
    unsigned char c3sw2;
    unsigned char c3sw3;
    unsigned char c3vo;

    unsigned char c3stop;          /* channel counter stopped */

    unsigned char vol3;

    unsigned char outvol_3;

} PokeyState;

PokeyState pokey_states[NPOKEYS];

/* Forward declarations for ResetPokeyState */

static unsigned char readout0_normal(PokeyState* ps);
static void event0_pure(PokeyState* ps, char p5v, char p4v, char p917v);

static unsigned char readout1_normal(PokeyState* ps);
static void event1_pure(PokeyState* ps, char p5v, char p4v, char p917v);

static unsigned char readout2_normal(PokeyState* ps);
static void event2_pure(PokeyState* ps, char p5v, char p4v, char p917v);

static unsigned char readout3_normal(PokeyState* ps);
static void event3_pure(PokeyState* ps, char p5v, char p4v, char p917v);




void ResetPokeyState(PokeyState* ps)
{
    /* Poly positions */
    ps->poly4pos = 0;
    ps->poly5pos = 0;
    ps->poly9pos = 0;
    ps->poly17pos = 0;

    /* Change queue */
    ps->ovola = 0;
    ps->qebeg = 0;
    ps->qeend = 0;

    /* Global Pokey controls */
    ps->mdivk = 28;

    ps->selpoly9 = 0;
    ps->c0_hf = 0;
    ps->c1_f0 = 0;
    ps->c2_hf = 0;
    ps->c3_f2 = 0;

    ps->outvol_all = 0;
    ps->forcero = 0;

    /* Channel 0 state */
    ps->readout_0 = readout0_normal;
    ps->event_0 = event0_pure;

    ps->c0divpos = 1000;
    ps->c0divstart = 1000;
    ps->c0divstart_p = 1000;
    ps->c0diva = 255;
    ps->c0ctl = 0;

    ps->c0t1 = 0;
    ps->c0t2 = 0;
    ps->c0t3 = 0;

    ps->c0sw1 = 0;
    ps->c0sw2 = 0;
    ps->c0sw3 = 0;
    ps->c0sw4 = 0;
    ps->c0vo = 1;

    ps->c0stop = 1;

    ps->vol0 = 0;

    ps->outvol_0 = 0;


    /* Channel 1 state */
    ps->readout_1 = readout1_normal;
    ps->event_1 = event1_pure;

    ps->c1divpos = 1000;
    ps->c1divstart = 1000;
    ps->c1diva = 255;
    ps->c1ctl = 0;

    ps->c1t1 = 0;
    ps->c1t2 = 0;
    ps->c1t3 = 0;

    ps->c1sw1 = 0;
    ps->c1sw2 = 0;
    ps->c1sw3 = 0;
    ps->c1sw4 = 0;
    ps->c1vo = 1;

    ps->c1stop = 1;

    ps->vol1 = 0;

    ps->outvol_1 = 0;

    /* Channel 2 state */

    ps->readout_2 = readout2_normal;
    ps->event_2 = event2_pure;

    ps->c2divpos = 1000;
    ps->c2divstart = 1000;
    ps->c2divstart_p = 1000;
    ps->c2diva = 255;
    ps->c2ctl = 0;

    ps->c2t1 = 0;
    ps->c2t2 = 0;

    ps->c2sw1 = 0;
    ps->c2sw2 = 0;
    ps->c2sw3 = 0;

    ps->c2vo = 0;

    ps->c2stop = 0;

    ps->vol2 = 0;
    ps->outvol_2 = 0;

    /* Channel 3 state */
    ps->readout_3 = readout3_normal;
    ps->event_3 = event3_pure;

    ps->c3divpos = 1000;
    ps->c3divstart = 1000;
    ps->c3diva = 255;
    ps->c3ctl = 0;

    ps->c3t1 = 0;
    ps->c3t2 = 0;

    ps->c3sw1 = 0;
    ps->c3sw2 = 0;
    ps->c3sw3 = 0;

    ps->c3stop = 1;

    ps->vol3 = 0;

    ps->outvol_3 = 0;
}

int read_resam_all(PokeyState* ps)
{
    int i = ps->qebeg;
    unsigned char avol,bvol;
    int sum;

    short * qet = &ps->qet[0];
    unsigned char * qev = &ps->qev[0];

    if(ps->qebeg == ps->qeend)
    {
        return ps->ovola * filter_data[0]; /* if no events in the queue */
    }

    avol = ps->ovola;
    sum = 0;

    /* Separate two loop cases, for wrap-around and without */
    if(ps->qeend < ps->qebeg) /* With wrap */
    {
        while(i<filter_size)
        {
            bvol = qev[i];
            sum += (avol-bvol)*filter_data[qet[i]];
            avol = bvol;
            ++i;
        }
        i=0;
    }

    /* without wrap */
    while(i<ps->qeend)
    {
        bvol = qev[i];
        sum += (avol-bvol)*filter_data[qet[i]];
        avol = bvol;
        ++i;
    }

    sum += avol*filter_data[0];
    return sum;
}

static void add_change(PokeyState* ps, unsigned char a)
{ 
    //fprintf(stderr,"C\n");	
    int length =  (ps->qeend>=ps->qebeg) ? (ps->qeend-ps->qebeg) : (filter_size-ps->qebeg + ps->qeend);
    if (length>30)
    {
 	   ++ps->qebeg;
	   if(ps->qebeg >= filter_size)
       		 ps->qebeg = 0;
    }
    ps->qev[ps->qeend] = a;
    ps->qet[ps->qeend] = 0;
    ++ps->qeend;
    if(ps->qeend >= filter_size)
        ps->qeend = 0;
}

static void bump_qe_subticks(PokeyState* ps, int subticks)
{
    //fprintf(stderr, "L:%d\n", length);

    /* Remove too old events from the queue while bumping */
    int i = ps->qebeg;
    unsigned char *qev = &ps->qev[0];
    short *qet = &ps->qet[0];
    if(ps->qeend < ps->qebeg) /* Loop with wrap */
    {
        while(i<filter_size)
        {
            qet[i] += subticks;
            if(qet[i] >= filter_size - 1)
            {
                ps->ovola = qev[i];
                ++ps->qebeg;
                if(ps->qebeg >= filter_size)
                    ps->qebeg = 0;
            }
            ++i;
        }
        i=0;
    }
    /* loop without wrap */
    while(i<ps->qeend)
    {
        qet[i] += subticks;
        if(qet[i] >= filter_size - 1)
        {
            ps->ovola = qev[i];
            ++ps->qebeg;
            if(ps->qebeg >= filter_size)
                ps->qebeg = 0;
        }
        ++i;
    }
}



static void build_poly4(void)
{
    unsigned char c;
    unsigned char i;
    unsigned char poly4=1;

    for(i=0; i<15; i++)
    {
        poly4tbl[i] = ~poly4;
        c = ((poly4>>2)&1) ^ ((poly4>>3)&1);
        poly4 = ((poly4<<1)&15) + c;
    }
}

static void build_poly5(void)
{
	unsigned char c;
	unsigned char i;
	unsigned char poly5 = 1;

	for(i = 0; i < 31; i++) {
		poly5tbl[i] = ~poly5; /* Inversion! Attention! */
		c = ((poly5 >> 2) ^ (poly5 >> 4)) & 1;
		poly5 = ((poly5 << 1) & 31) + c;
	}
}

static void build_poly17(void)
{
	unsigned int c;
	unsigned int i;
	unsigned int poly17 = 1;

	for(i = 0; i < 131071; i++) {
		poly17tbl[i] = (unsigned char) poly17;
		c = ((poly17 >> 11) ^ (poly17 >> 16)) & 1;
		poly17 = ((poly17 << 1) & 131071) + c;
	}
}

static void build_poly9(void)
{
	unsigned int c;
	unsigned int i;
	unsigned int poly9 = 1;

	for(i = 0; i < 511; i++) {
		poly9tbl[i] = (unsigned char) poly9;
		c = ((poly9 >> 3) ^ (poly9 >> 8)) & 1;
		poly9 = ((poly9 << 1) & 511) + c;
	}
}

static void advance_polies(PokeyState* ps, unsigned long tacts)
{
    ps->poly4pos = (tacts + ps->poly4pos) % 15;
    ps->poly5pos = (tacts + ps->poly5pos) % 31;
    ps->poly17pos = (tacts + ps->poly17pos) % 131071;
    ps->poly9pos = (tacts + ps->poly9pos) % 511;
}

/***********************************

   READ OUTPUT 0

  ************************************/

static unsigned char readout0_vo(PokeyState* ps)
{
    return 0;//ps->vol0;
}

static unsigned char readout0_hipass(PokeyState* ps)
{
    if(ps->c0t2 ^ ps->c0t3)
        return ps->vol0;
    else return 0;
}

static unsigned char readout0_normal(PokeyState* ps)
{
    if(ps->c0t2)
        return ps->vol0;
    else return 0;
}

/***********************************

   READ OUTPUT 1

  ************************************/

static unsigned char readout1_vo(PokeyState* ps)
{
    return 0;//ps->vol1;
}

static unsigned char readout1_hipass(PokeyState* ps)
{
    if(ps->c1t2 ^ ps->c1t3)
        return ps->vol1;
    else return 0;
}

static unsigned char readout1_normal(PokeyState* ps)
{
    if(ps->c1t2)
        return ps->vol1;
    else return 0;
}

/***********************************

   READ OUTPUT 2

  ************************************/

static unsigned char readout2_vo(PokeyState* ps)
{
    return 0;//ps->vol2;
}

static unsigned char readout2_normal(PokeyState* ps)
{
    if(ps->c2t2)
        return ps->vol2;
    else return 0;
}

/***********************************

   READ OUTPUT 3

  ************************************/

static unsigned char readout3_vo(PokeyState* ps)
{
    return 0;//ps->vol3;
}

static unsigned char readout3_normal(PokeyState* ps)
{
    if(ps->c3t2)
        return ps->vol3;
    else return 0;
}


/***********************************

   EVENT CHANNEL 0

  ************************************/

static void event0_pure(PokeyState* ps, char p5v, char p4v, char p917v)
{
    ps->c0t2 = !ps->c0t2;
    ps->c0t1 = p5v;
}

static void event0_p5(PokeyState* ps, char p5v, char p4v, char p917v)
{
    if(ps->c0t1)
        ps->c0t2 = !ps->c0t2;
    ps->c0t1 = p5v;
}

static void event0_p4(PokeyState* ps, char p5v, char p4v, char p917v)
{
    ps->c0t2 = p4v;
    ps->c0t1 = p5v;
}

static void event0_p917(PokeyState* ps, char p5v, char p4v, char p917v)
{
    ps->c0t2 = p917v;
    ps->c0t1 = p5v;
}

static void event0_p4_p5(PokeyState* ps, char p5v, char p4v, char p917v)
{
    if(ps->c0t1)
        ps->c0t2 = p4v;
    ps->c0t1 = p5v;
}

static void event0_p917_p5(PokeyState* ps, char p5v, char p4v, char p917v)
{
    if(ps->c0t1)
        ps->c0t2 = p917v;
    ps->c0t1 = p5v;
}

/***********************************

   EVENT CHANNEL 1

  ************************************/

static void event1_pure(PokeyState* ps, char p5v, char p4v, char p917v)
{
    ps->c1t2 = !ps->c1t2;
    ps->c1t1 = p5v;
}

static void event1_p5(PokeyState* ps, char p5v, char p4v, char p917v)
{
    if(ps->c1t1)
        ps->c1t2 = !ps->c1t2;
    ps->c1t1 = p5v;
}

static void event1_p4(PokeyState* ps, char p5v, char p4v, char p917v)
{
    ps->c1t2 = p4v;
    ps->c1t1 = p5v;
}

static void event1_p917(PokeyState* ps, char p5v, char p4v, char p917v)
{
    ps->c1t2 = p917v;
    ps->c1t1 = p5v;
}

static void event1_p4_p5(PokeyState* ps, char p5v, char p4v, char p917v)
{
    if(ps->c1t1)
        ps->c1t2 = p4v;
    ps->c1t1 = p5v;
}

static void event1_p917_p5(PokeyState* ps, char p5v, char p4v, char p917v)
{
    if(ps->c1t1)
        ps->c1t2 = p917v;
    ps->c1t1 = p5v;
}

/***********************************

   EVENT CHANNEL 2

  ************************************/

static void event2_pure(PokeyState* ps, char p5v, char p4v, char p917v)
{
    ps->c2t2 = !ps->c2t2;
    ps->c2t1 = p5v;
    /* high-pass clock for channel 0 */
    ps->c0t3 = ps->c0t2;
}

static void event2_p5(PokeyState* ps, char p5v, char p4v, char p917v)
{
    if(ps->c2t1)
        ps->c2t2 = !ps->c2t2;
    ps->c2t1 = p5v;
    /* high-pass clock for channel 0 */
    ps->c0t3 = ps->c0t2;
}

static void event2_p4(PokeyState* ps, char p5v, char p4v, char p917v)
{
    ps->c2t2 = p4v;
    ps->c2t1 = p5v;
    /* high-pass clock for channel 0 */
    ps->c0t3 = ps->c0t2;
}

static void event2_p917(PokeyState* ps, char p5v, char p4v, char p917v)
{
    ps->c2t2 = p917v;
    ps->c2t1 = p5v;
    /* high-pass clock for channel 0 */
    ps->c0t3 = ps->c0t2;
}

static void event2_p4_p5(PokeyState* ps, char p5v, char p4v, char p917v)
{
    if(ps->c2t1)
        ps->c2t2 = p4v;
    ps->c2t1 = p5v;
    /* high-pass clock for channel 0 */
    ps->c0t3 = ps->c0t2;
}

static void event2_p917_p5(PokeyState* ps, char p5v, char p4v, char p917v)
{
    if(ps->c2t1)
        ps->c2t2 = p917v;
    ps->c2t1 = p5v;
    /* high-pass clock for channel 0 */
    ps->c0t3 = ps->c0t2;
}

/***********************************

   EVENT CHANNEL 3

  ************************************/

static void event3_pure(PokeyState* ps, char p5v, char p4v, char p917v)
{
    ps->c3t2 = !ps->c3t2;
    ps->c3t1 = p5v;
    /* high-pass closk for channel 1 */
    ps->c1t3 = ps->c1t2;
}

static void event3_p5(PokeyState* ps, char p5v, char p4v, char p917v)
{
    if(ps->c3t1)
        ps->c3t2 = !ps->c3t2;
    ps->c3t1 = p5v;
    /* high-pass closk for channel 1 */
    ps->c1t3 = ps->c1t2;
}

static void event3_p4(PokeyState* ps, char p5v, char p4v, char p917v)
{
    ps->c3t2 = p4v;
    ps->c3t1 = p5v;
    /* high-pass closk for channel 1 */
    ps->c1t3 = ps->c1t2;
}

static void event3_p917(PokeyState* ps, char p5v, char p4v, char p917v)
{
    ps->c3t2 = p917v;
    ps->c3t1 = p5v;
    /* high-pass closk for channel 1 */
    ps->c1t3 = ps->c1t2;
}

static void event3_p4_p5(PokeyState* ps, char p5v, char p4v, char p917v)
{
    if(ps->c3t1)
        ps->c3t2 = p4v;
    ps->c3t1 = p5v;
    /* high-pass closk for channel 1 */
    ps->c1t3 = ps->c1t2;
}

static void event3_p917_p5(PokeyState* ps, char p5v, char p4v, char p917v)
{
    if(ps->c3t1)
        ps->c3t2 = p917v;
    ps->c3t1 = p5v;
    /* high-pass closk for channel 1 */
    ps->c1t3 = ps->c1t2;
}

static void advance_ticks(PokeyState* ps, unsigned long ticks)
{
    //fprintf(stderr,"A\n");
    unsigned long ta,tbe, tbe0, tbe1, tbe2, tbe3;
    char p5v,p4v,p917v;

    unsigned char outvol_new;
    unsigned char need0=0;
    unsigned char need1=0;
    unsigned char need2=0;
    unsigned char need3=0;

    unsigned char need=0;

    if(ps->forcero)
    {
        ps->forcero = 0;
        outvol_new = ps->outvol_0 + ps->outvol_1 + ps->outvol_2 + ps->outvol_3;
        if(outvol_new != ps->outvol_all)
        {
            ps->outvol_all = outvol_new;
            add_change(ps, outvol_new);
        }
    }

    while(ticks>0)
    {
        tbe0 = ps->c0divpos;
        tbe1 = ps->c1divpos;
        tbe2 = ps->c2divpos;
        tbe3 = ps->c3divpos;

        tbe = ticks+1;

        if(!ps->c0stop && tbe0 < tbe)
            tbe = tbe0;
        if(!ps->c1stop && tbe1 < tbe)
            tbe = tbe1;
        if(!ps->c2stop && tbe2 < tbe)
            tbe = tbe2;
        if(!ps->c3stop && tbe3 < tbe)
            tbe = tbe3;

        if(tbe>ticks)
            ta = ticks;
        else
        {
            ta = tbe;
            need = 1;
        }

        ticks -= ta;

        if(!ps->c0stop) ps->c0divpos -= ta;
        if(!ps->c1stop) ps->c1divpos -= ta;
        if(!ps->c2stop) ps->c2divpos -= ta;
        if(!ps->c3stop) ps->c3divpos -= ta;

        advance_polies(ps,ta);
        bump_qe_subticks(ps,ta);

        if(need)
        {
            p5v = poly5tbl[ps->poly5pos] & 1;
            p4v = poly4tbl[ps->poly4pos] & 1;
            if(ps->selpoly9)
                p917v = poly9tbl[ps->poly9pos] & 1;
            else
                p917v = poly17tbl[ps->poly17pos] & 1;

            if(!ps->c0stop && ta == tbe0)
            {
                ps->event_0(ps,p5v,p4v,p917v);
                ps->c0divpos = ps->c0divstart;
                need0 = 1;
            }
            if(!ps->c1stop && ta == tbe1)
            {
                ps->event_1(ps,p5v,p4v,p917v);
                ps->c1divpos = ps->c1divstart;
                if(ps->c1_f0)
                    ps->c0divpos = ps->c0divstart_p;
                need1 = 1;
            }
            if(!ps->c2stop && ta == tbe2)
            {
                ps->event_2(ps,p5v,p4v,p917v);
                ps->c2divpos = ps->c2divstart;
                need2 = 1;
                if(ps->c0sw4)
                    need0 = 1;
            }
            if(!ps->c3stop && ta == tbe3)
            {
                ps->event_3(ps,p5v,p4v,p917v);
                ps->c3divpos = ps->c3divstart;
                if(ps->c3_f2)
                    ps->c2divpos = ps->c2divstart_p;
                need3 = 1;
                if(ps->c1sw4)
                    need1 = 1;
            }

            if(need0)
            {
                ps->outvol_0 = 2*ps->readout_0(ps);
            }
            if(need1)
            {
                ps->outvol_1 = 2*ps->readout_1(ps);
            }
            if(need2)
            {
                ps->outvol_2 = 2*ps->readout_2(ps);
            }
            if(need3)
            {
                ps->outvol_3 = 2*ps->readout_3(ps);
            }

            outvol_new = ps->outvol_0 + ps->outvol_1 + ps->outvol_2 + ps->outvol_3;
            if(outvol_new != ps->outvol_all)
            {
                ps->outvol_all = outvol_new;
                add_change(ps, outvol_new);
            }
        }
    }
}

static uint8 generate_sample2(PokeyState* ps, int offset)
{
	int sample;
    /*unsigned long ta = (subticks+pokey_frq)/sample_rate;
    subticks = (subticks+pokey_frq)%sample_rate;*/

//if (offset!=0)
//	fprintf(stderr,"O:%d\n", offset*5000000/32);

    advance_ticks(ps, pokey_frq/sample_rate);
    sample = read_resam_all(ps);
//if (sample!=0)
 //   fprintf(stderr,"S:%d\n", sample);
    return (uint8) ((sample*255 + 255*offset*5400000/32)/MAX_SAMPLE/4*3/100000);
/*    static int min =1000000;
    static int max = -100000;
    if (result<min)
	    min = result;
    if (result>max)
	    max = result;
    if (result<-126 || result>127)
    	fprintf(stderr, "result:%d min:%d max:%d\n", result, min, max);
    return (uint8)result;
*/}

static uint8 generate_sample(PokeyState*ps)
{
	return generate_sample2(ps,0);
}

/******************************************
 filter table generator by Krzysztof Nikiel
 ******************************************/




/*****************************************************************************/
/* Module:  Pokey_sound_init()                                               */
/* Purpose: to handle the power-up initialization functions                  */
/*          these functions should only be executed on a cold-restart        */
/*                                                                           */
/* Authors: Michael Borisov, Krzystof Nikiel                                 */
/*                                                                           */
/* Inputs:  freq17 - the value for the '1.79MHz' Pokey audio clock           */
/*          playback_freq - the playback frequency in samples per second     */
/*          num_pokeys - specifies the number of pokey chips to be emulated  */
/*                                                                           */
/* Outputs: Adjusts local globals - no return value                          */
/*                                                                           */
/*****************************************************************************/

void Pokey_process_8(void* sndbuffer, unsigned sndn);
void Pokey_process_16(void* sndbuffer, unsigned sndn);
void Update_pokey_sound_mz(uint16 addr, uint8 val, uint8 chip, uint8 gain);
#ifdef SERIO_SOUND
void Update_serio_sound_mz(int out, UBYTE data);
#endif
#ifdef CONSOLE_SOUND
void Update_consol_sound_mz( int set );
int console_sound_enabled=1;
#endif
#ifdef VOL_ONLY_SOUND
void Update_vol_only_sound_mz( void );
#endif

int Pokey_sound_init_mz(uint32 freq17, uint16 playback_freq, uint8 num_pokeys,
                        int flags, int quality
#ifdef __PLUS
                        , int clear_regs
#endif
                       )
{
//    double cutoff;

    sample_rate = playback_freq;
    snd_flags = flags;
    snd_quality = quality;

    //Update_pokey_sound = Update_pokey_sound_mz;
#ifdef SERIO_SOUND
    //Update_serio_sound = Update_serio_sound_mz;
#endif
#ifdef CONSOLE_SOUND
    //Update_consol_sound = Update_consol_sound_mz;
#endif
#ifdef VOL_ONLY_SOUND
    //Update_vol_only_sound = Update_vol_only_sound_mz;
#endif

#ifdef VOL_ONLY_SOUND
	samp_freq=playback_freq;
#endif  /* VOL_ONLY_SOUND */

	//Pokey_process_ptr = (flags & SND_BIT16) ? Pokey_process_16 : Pokey_process_8;

    switch(playback_freq)
    {
#if 0
    case 44100:
        if(flags & SND_BIT16)
        {
            filter_data = filter_44;
            filter_size = filter_size_44;
        }
        else
        {
            filter_data = filter_44_8;
            filter_size = filter_size_44_8;
        }
        pokey_frq = 1808100; /* 1.02% off ideal */
        audible_frq = 20000; /* ultrasound */
        break;
    case 22050:
        if(flags & SND_BIT16)
        {
            filter_data = filter_22;
            filter_size = filter_size_22;
        }
        else
        {
            filter_data = filter_22_8;
            filter_size = filter_size_22_8;
        }
        pokey_frq = 1786050; /* 0.2% off ideal */
        audible_frq = 10000; /* 30db filter attenuation */
        break;
    case 11025:
        if(flags & SND_BIT16)
        {
            filter_data = filter_11;
            filter_size = filter_size_11;
        }
        else
        {
            filter_data = filter_11_8;
            filter_size = filter_size_11_8;
        }
        pokey_frq = 1786050; /* 0.2% off ideal */
        audible_frq = 4500; /* 30db filter attenuation */
        break;
    case 48000:
        if(flags & SND_BIT16)
        {
            filter_data = filter_48;
            filter_size = filter_size_48;
        }
        else
        {
            filter_data = filter_48_8;
            filter_size = filter_size_48_8;
        }
        pokey_frq = 1776000; /* 0.7% off ideal */
        audible_frq = 20000; /* ultrasound */
        break;
    case 8000:
        if(flags & SND_BIT16)
        {
            filter_data = filter_8;
            filter_size = filter_size_8;
        }
        else
        {
            filter_data = filter_8_8;
            filter_size = filter_size_8_8;
        }
        pokey_frq = 1792000; /* 0.1% off ideal */
        audible_frq = 4000; /* Nyquist, also 30db attn, should be 50 */
        break;
#endif
    default:
        pokey_frq = (int)(((double)pokey_frq_ideal/sample_rate) + 0.5)
          * sample_rate;
	filter_size = 1001;
	//	filter_size=remez_filter_table((double)sample_rate/pokey_frq,
	//				 &cutoff, quality);
	//audible_frq = (unsigned) (cutoff * pokey_frq);
//	fprintf(stderr,"AUD:%d size:%d\n",audible_frq, filter_size);
	audible_frq = 10473;
    }

    build_poly4();
    build_poly5();
    build_poly9();
    build_poly17();

#ifdef __PLUS
	if (clear_regs)
#endif
	{
		ResetPokeyState(pokey_states);
		ResetPokeyState(pokey_states + 1);
	}
	num_cur_pokeys = num_pokeys;

	return 0; /* OK */
}

/*****************************************************************************/
/* Function: Update_pokey_sound()                                            */
/*                                                                           */
/* Inputs:  addr - the address of the parameter to be changed                */
/*          val - the new value to be placed in the specified address        */
/*          gain - specified as an 8-bit fixed point number - use 1 for no   */
/*                 amplification (output is multiplied by gain)              */
/*                                                                           */
/* Outputs: Adjusts local globals - no return value                          */
/*                                                                           */
/*****************************************************************************/

static void Update_readout_0(PokeyState* ps)
{
    if(ps->c0vo)
        ps->readout_0 = readout0_vo;
    else if(ps->c0sw4)
        ps->readout_0 = readout0_hipass;
    else
        ps->readout_0 = readout0_normal;
}

static void Update_readout_1(PokeyState* ps)
{
    if(ps->c1vo)
        ps->readout_1 = readout1_vo;
    else if(ps->c1sw4)
        ps->readout_1 = readout1_hipass;
    else
        ps->readout_1 = readout1_normal;
}

static void Update_readout_2(PokeyState* ps)
{
    if(ps->c2vo)
        ps->readout_2 = readout2_vo;
    else
        ps->readout_2 = readout2_normal;
}

static void Update_readout_3(PokeyState* ps)
{
    if(ps->c3vo)
        ps->readout_3 = readout3_vo;
    else
        ps->readout_3 = readout3_normal;
}

static void Update_event0(PokeyState* ps)
{
    if(ps->c0sw3)
    {
        if(ps->c0sw2)
            ps->event_0 = event0_pure;
        else
        {
            if(ps->c0sw1)
                ps->event_0 = event0_p4;
            else
                ps->event_0 = event0_p917;
        }
    }
    else
    {
        if(ps->c0sw2)
            ps->event_0 = event0_p5;
        else
        {
            if(ps->c0sw1)
                ps->event_0 = event0_p4_p5;
            else
                ps->event_0 = event0_p917_p5;
        }
    }
}

static void Update_event1(PokeyState* ps)
{
    if(ps->c1sw3)
    {
        if(ps->c1sw2)
            ps->event_1 = event1_pure;
        else
        {
            if(ps->c1sw1)
                ps->event_1 = event1_p4;
            else
                ps->event_1 = event1_p917;
        }
    }
    else
    {
        if(ps->c1sw2)
            ps->event_1 = event1_p5;
        else
        {
            if(ps->c1sw1)
                ps->event_1 = event1_p4_p5;
            else
                ps->event_1 = event1_p917_p5;
        }
    }
}

static void Update_event2(PokeyState* ps)
{
    if(ps->c2sw3)
    {
        if(ps->c2sw2)
            ps->event_2 = event2_pure;
        else
        {
            if(ps->c2sw1)
                ps->event_2 = event2_p4;
            else
                ps->event_2 = event2_p917;
        }
    }
    else
    {
        if(ps->c2sw2)
            ps->event_2 = event2_p5;
        else
        {
            if(ps->c2sw1)
                ps->event_2 = event2_p4_p5;
            else
                ps->event_2 = event2_p917_p5;
        }
    }
}

static void Update_event3(PokeyState* ps)
{
    if(ps->c3sw3)
    {
        if(ps->c3sw2)
            ps->event_3 = event3_pure;
        else
        {
            if(ps->c3sw1)
                ps->event_3 = event3_p4;
            else
                ps->event_3 = event3_p917;
        }
    }
    else
    {
        if(ps->c3sw2)
            ps->event_3 = event3_p5;
        else
        {
            if(ps->c3sw1)
                ps->event_3 = event3_p4_p5;
            else
                ps->event_3 = event3_p917_p5;
        }
    }
}

static void Update_c0divstart(PokeyState* ps)
{
    if(ps->c1_f0)
    {
        if(ps->c0_hf)
        {
            ps->c0divstart = 256;
            ps->c0divstart_p = ps->c0diva + 7;
        }
        else
        {
            ps->c0divstart = 256 * ps->mdivk;
            ps->c0divstart_p = (ps->c0diva+1)*ps->mdivk;
        }
    }
    else
    {
        if(ps->c0_hf)
            ps->c0divstart = ps->c0diva + 4;
        else
            ps->c0divstart = (ps->c0diva+1) * ps->mdivk;
    }
}

static void Update_c1divstart(PokeyState* ps)
{
    if(ps->c1_f0)
    {
        if(ps->c0_hf)
            ps->c1divstart = ps->c0diva + 256*ps->c1diva + 7;
        else
            ps->c1divstart = (ps->c0diva + 256*ps->c1diva + 1) * ps->mdivk;
    }
    else
        ps->c1divstart = (ps->c1diva + 1) * ps->mdivk;
}

static void Update_c2divstart(PokeyState* ps)
{
    if(ps->c3_f2)
    {
        if(ps->c2_hf)
        {
            ps->c2divstart = 256;
            ps->c2divstart_p = ps->c2diva + 7;
        }
        else
        {
            ps->c2divstart = 256 * ps->mdivk;
            ps->c2divstart_p = (ps->c2diva+1)*ps->mdivk;
        }
    }
    else
    {
        if(ps->c2_hf)
            ps->c2divstart = ps->c2diva + 4;
        else
            ps->c2divstart = (ps->c2diva+1) * ps->mdivk;
    }
}

static void Update_c3divstart(PokeyState* ps)
{
    if(ps->c3_f2)
    {
        if(ps->c2_hf)
            ps->c3divstart = ps->c2diva + 256*ps->c3diva + 7;
        else
            ps->c3divstart = (ps->c2diva + 256*ps->c3diva + 1) * ps->mdivk;
    }
    else
        ps->c3divstart = (ps->c3diva + 1) * ps->mdivk;
}

static void Update_audctl(PokeyState* ps, unsigned char val)
{
    unsigned char nc0_hf,nc2_hf,nc1_f0,nc3_f2,nc0sw4,nc1sw4,new_divk;
    unsigned char recalc0=0;
    unsigned char recalc1=0;
    unsigned char recalc2=0;
    unsigned char recalc3=0;

    unsigned int cnt0 = 0;
    unsigned int cnt1 = 0;
    unsigned int cnt2 = 0;
    unsigned int cnt3 = 0;

    nc0_hf = (val & 0x40) != 0;
    nc2_hf = (val & 0x20) != 0;
    nc1_f0 = (val & 0x10) != 0;
    nc3_f2 = (val & 0x08) != 0;
    nc0sw4 = (val & 0x04) != 0;
    nc1sw4 = (val & 0x02) != 0;
    if(val & 0x01)
        new_divk = 114;
    else
        new_divk = 28;

    if(new_divk != ps->mdivk)
    {
        recalc0 = recalc1 = recalc2 = recalc3 = 1;
    }
    if(nc1_f0 != ps->c1_f0)
    {
        recalc0 = recalc1 = 1;
    }
    if(nc3_f2 != ps->c3_f2)
    {
        recalc2 = recalc3 = 1;
    }
    if(nc0_hf != ps->c0_hf)
    {
        recalc0 = 1;
        if(nc1_f0)
            recalc1 = 1;
    }
    if(nc2_hf != ps->c2_hf)
    {
        recalc2 = 1;
        if(nc3_f2)
            recalc3 = 1;
    }

    if(recalc0)
    {
        if(ps->c0_hf)
            cnt0 = ps->c0divpos;
        else
            cnt0 = ps->c0divpos/ps->mdivk;
    }
    if(recalc1)
    {
        if(ps->c1_f0)
        {
            if(ps->c0_hf)
                cnt1 = ps->c1divpos/256;
            else
                cnt1 = ps->c1divpos/256/ps->mdivk;
        }
        else
        {
            cnt1 = ps->c1divpos/ps->mdivk;
        }
    }
    if(recalc2)
    {
        if(ps->c2_hf)
            cnt2 = ps->c2divpos;
        else
            cnt2 = ps->c2divpos/ps->mdivk;
    }
    if(recalc3)
    {
        if(ps->c3_f2)
        {
            if(ps->c2_hf)
                cnt3 = ps->c3divpos/256;
            else
                cnt3 = ps->c3divpos/256/ps->mdivk;
        }
    }

    if(recalc0)
    {
        if(nc0_hf)
            ps->c0divpos = cnt0;
        else
            ps->c0divpos = cnt0*new_divk;
    }
    if(recalc1)
    {
        if(nc1_f0)
        {
            if(nc0_hf)
                ps->c1divpos = cnt1*256+cnt0;
            else
                ps->c1divpos = (cnt1*256+cnt0)*new_divk;
        }
        else
        {
            ps->c1divpos = cnt1*new_divk;
        }
    }

    if(recalc2)
    {
        if(nc2_hf)
            ps->c2divpos = cnt2;
        else
            ps->c2divpos = cnt2*new_divk;
    }
    if(recalc3)
    {
        if(nc3_f2)
        {
            if(nc2_hf)
                ps->c3divpos = cnt3*256+cnt2;
            else
                ps->c3divpos = (cnt3*256+cnt2)*new_divk;
        }
    }

    ps->c0_hf = nc0_hf;
    ps->c2_hf = nc2_hf;
    ps->c1_f0 = nc1_f0;
    ps->c3_f2 = nc3_f2;
    ps->c0sw4 = nc0sw4;
    ps->c1sw4 = nc1sw4;
    ps->mdivk = new_divk;
}

static void Update_c0stop(PokeyState* ps)
{
    unsigned long lim = pokey_frq/2/audible_frq;

    unsigned char hfa = 0;
    ps->c0stop = 0;

    if(ps->c0vo || ps->vol0 == 0)
        ps->c0stop = 1;
    else if(!ps->c0sw4 && ps->c0sw3 && ps->c0sw2) /* If channel 0 is a pure tone... */
    {
        if(ps->c1_f0)
        {
            if(ps->c1divstart <= lim)
            {
                ps->c0stop = 1;
                hfa = 1;
            }
        }
        else
        {
            if(ps->c0divstart <= lim)
            {
                ps->c0stop = 1;
                hfa = 1;
            }
        }
    }
    else if(!ps->c0sw4 && ps->c0sw3 && !ps->c0sw2 && ps->c0sw1) /* if channel 0 is poly4... */
    {
        /* period for poly4 signal is 15 cycles */
        if(ps->c1_f0)
        {
            if(ps->c1divstart <= lim*2/15) /* all poly4 signal is above Nyquist */
            {
                ps->c0stop = 1;
                hfa = 1;
            }
        }
        else
        {
            if(ps->c0divstart <= lim*2/15)
            {
                ps->c0stop = 1;
                hfa = 1;
            }
        }
    }

    ps->outvol_0 = 2*ps->readout_0(ps);
    if(hfa)
        ps->outvol_0 = ps->vol0;
}

static void Update_c1stop(PokeyState* ps)
{
    unsigned long lim = pokey_frq/2/audible_frq;

    unsigned char hfa = 0;
    ps->c1stop = 0;

    if(!ps->c1_f0 && (ps->c1vo || ps->vol1 == 0))
        ps->c1stop = 1;
    else if(!ps->c1sw4 && ps->c1sw3 && ps->c1sw2 && ps->c1divstart <= lim) /* If channel 1 is a pure tone */
    {
        ps->c1stop = 1;
        hfa = 1;
    }
    else if(!ps->c1sw4 && ps->c1sw3 && !ps->c1sw2 && ps->c1sw1 && ps->c1divstart <= lim*2/15)  /* all poly4 signal is above Nyquist */
    {
        ps->c1stop = 1;
        hfa = 1;
    }

    ps->outvol_1 = 2*ps->readout_1(ps);
    if(hfa)
        ps->outvol_1 = ps->vol1;
}

static void Update_c2stop(PokeyState* ps)
{
    unsigned long lim = pokey_frq/2/audible_frq;

    unsigned char hfa = 0;
    ps->c2stop = 0;

    if(!ps->c0sw4 && (ps->c2vo || ps->vol2 == 0))
        ps->c2stop = 1;
    /* If channel 2 is a pure tone and no filter for c0... */
    else if(ps->c2sw3 && ps->c2sw2 && !ps->c0sw4)
    {
        if(ps->c3_f2)
        {
            if(ps->c3divstart <= lim)
            {
                ps->c2stop = 1;
                hfa = 1;
            }
        }
        else
        {
            if(ps->c2divstart <= lim)
            {
                ps->c2stop = 1;
                hfa = 1;
            }
        }
    }
    else if(ps->c2sw3 && !ps->c2sw2 && ps->c2sw1 && !ps->c0sw4) /* if channel 2 is poly4 and no filter for c0... */
    {
        /* period for poly4 signal is 15 cycles */
        if(ps->c3_f2)
        {
            if(ps->c3divstart <= lim*2/15) /* all poly4 signal is above Nyquist */
            {
                ps->c2stop = 1;
                hfa = 1;
            }
        }
        else
        {
            if(ps->c2divstart <= lim*2/15)
            {
                ps->c2stop = 1;
                hfa = 1;
            }
        }
    }

    ps->outvol_2 = 2*ps->readout_2(ps);
    if(hfa)
        ps->outvol_2 = ps->vol2;
}

static void Update_c3stop(PokeyState* ps)
{
    unsigned long lim = pokey_frq/2/audible_frq;
    unsigned char hfa = 0;
    ps->c3stop = 0;

    if(!ps->c1sw4 && !ps->c3_f2 && (ps->c3vo || ps->vol3 == 0))
        ps->c3stop = 1;
    /* If channel 3 is a pure tone */
    else if(ps->c3sw3 && ps->c3sw2 && !ps->c1sw4 && ps->c3divstart <= lim)
    {
        ps->c3stop = 1;
        hfa = 1;
    }
    else if(ps->c3sw3 && !ps->c3sw2 && ps->c3sw1 && !ps->c1sw4 && ps->c3divstart <= lim*2/15)  /* all poly4 signal is above Nyquist */
    {
        ps->c3stop = 1;
        hfa = 1;
    }

    ps->outvol_3 = 2*ps->readout_3(ps);
    if(hfa)
        ps->outvol_3 = ps->vol3;
}

void uvo(int chip, int chan,int enabled, int volume);

void Update_pokey_sound_mz(uint16 addr, uint8 val, uint8 chip, uint8 gain)
{
    PokeyState* ps = pokey_states+chip;

    switch(addr & 0x0f)
    {
    case _AUDF1:
        ps->c0diva = val;
        Update_c0divstart(ps);
        if(ps->c1_f0)
        {
            Update_c1divstart(ps);
            Update_c1stop(ps);
        }
        Update_c0stop(ps);
        ps->forcero = 1;
        break;
    case _AUDC1:
        ps->c0sw1 = (val & 0x40) != 0;
        ps->c0sw2 = (val & 0x20) != 0;
        ps->c0sw3 = (val & 0x80) != 0;
        ps->vol0 = val & 0xF;
        ps->c0vo = (val & 0x10) != 0;
	uvo(chip,0,ps->c0vo, ps->vol0);
        Update_readout_0(ps);
        Update_event0(ps);
        Update_c0stop(ps);
        ps->forcero = 1;
        break;
    case _AUDF2:
        ps->c1diva = val;
        Update_c1divstart(ps);
        if(ps->c1_f0)
        {
            Update_c0divstart(ps);
            Update_c0stop(ps);
        }
        Update_c1stop(ps);
        ps->forcero = 1;
        break;
    case _AUDC2:
        ps->c1sw1 = (val & 0x40) != 0;
        ps->c1sw2 = (val & 0x20) != 0;
        ps->c1sw3 = (val & 0x80) != 0;
        ps->vol1 = val & 0xF;
        ps->c1vo = (val & 0x10) != 0;
	uvo(chip,1,ps->c1vo, ps->vol1);
        Update_readout_1(ps);
        Update_event1(ps);
        Update_c1stop(ps);
        ps->forcero = 1;
        break;
    case _AUDF3:
        ps->c2diva = val;
        Update_c2divstart(ps);
        if(ps->c3_f2)
        {
            Update_c3divstart(ps);
            Update_c3stop(ps);
        }
        Update_c2stop(ps);
        ps->forcero = 1;
        break;
    case _AUDC3:
        ps->c2sw1 = (val & 0x40) != 0;
        ps->c2sw2 = (val & 0x20) != 0;
        ps->c2sw3 = (val & 0x80) != 0;
        ps->vol2 = val & 0xF;
        ps->c2vo = (val & 0x10) != 0;
	uvo(chip,2,ps->c2vo, ps->vol2);
        Update_readout_2(ps);
        Update_event2(ps);
        Update_c2stop(ps);
        ps->forcero = 1;
        break;
    case _AUDF4:
        ps->c3diva = val;
        Update_c3divstart(ps);
        if(ps->c3_f2)
        {
            Update_c2divstart(ps);
            Update_c2stop(ps);
        }
        Update_c3stop(ps);
        ps->forcero = 1;
        break;
    case _AUDC4:
        ps->c3sw1 = (val & 0x40) != 0;
        ps->c3sw2 = (val & 0x20) != 0;
        ps->c3sw3 = (val & 0x80) != 0;
        ps->vol3 = val & 0xF;
        ps->c3vo = (val & 0x10) != 0;
	uvo(chip,3,ps->c3vo, ps->vol3);
        Update_readout_3(ps);
        Update_event3(ps);
        Update_c3stop(ps);
        ps->forcero = 1;
        break;
    case _AUDCTL:
        ps->selpoly9 = (val & 0x80) != 0;
        Update_audctl(ps,val);
        Update_readout_0(ps);
        Update_readout_1(ps);
        Update_readout_2(ps);
        Update_readout_3(ps);
        Update_c0divstart(ps);
        Update_c1divstart(ps);
        Update_c2divstart(ps);
        Update_c3divstart(ps);
        Update_c0stop(ps);
        Update_c1stop(ps);
        Update_c2stop(ps);
        Update_c3stop(ps);
        ps->forcero = 1;
        break;
    case _STIMER:
        if(ps->c1_f0)
            ps->c0divpos = ps->c0divstart_p;
        else
            ps->c0divpos = ps->c0divstart;
        ps->c1divpos = ps->c1divstart;
        if(ps->c3_f2)
            ps->c2divpos = ps->c2divstart_p;
        else
            ps->c2divpos = ps->c2divstart;

        ps->c3divpos = ps->c3divstart;
        ps->c0t2 = 1;
        ps->c1t2 = 1;
        ps->c2t2 = 0;
        ps->c3t2 = 0;
        break;
    }
}

void uvo(int chip, int chan,int enabled, int vol)
{
	int chip_offs;

	//hmmm, looks like it half supports 2nd chip
	//don't bother for now...
	if (chip!=0)return;
#ifndef	NO_VOL_ONLY
	chip_offs=4*chip;
	if(enabled)
	{
		sampbuf_lastval+=vol
			-sampbuf_AUDV[chan + chip_offs];

		sampbuf_val[sampbuf_ptr]=sampbuf_lastval;
		sampbuf_AUDV[chan + chip_offs]=vol;
		sampbuf_cnt[sampbuf_ptr]=
			(cpu_clock-sampbuf_last)*128*snd_playback_freq/178979;
		sampbuf_last=cpu_clock;
		sampbuf_ptr++;
		if( sampbuf_ptr>=SAMPBUF_MAX )
			sampbuf_ptr=0;
		if( sampbuf_ptr==sampbuf_rptr )
		{	sampbuf_rptr++;
			if( sampbuf_rptr>=SAMPBUF_MAX )
				sampbuf_rptr=0;
		}
	}
#endif	/* NO_VOL_ONLY */
}

void Pokey_debugreset(uint8 chip)
{
    PokeyState* ps = pokey_states+chip;

    if(ps->c1_f0)
        ps->c0divpos = ps->c0divstart_p;
    else
        ps->c0divpos = ps->c0divstart;
    ps->c1divpos = ps->c1divstart;
    if(ps->c3_f2)
        ps->c2divpos = ps->c2divstart_p;
    else
        ps->c2divpos = ps->c2divstart;
    ps->c3divpos = ps->c3divstart;

    ps->c0t2 = 1;
    ps->c1t2 = 1;
    ps->c2t2 = 1;
    ps->c3t2 = 1;
}

/**************************************************************

           Master gain and DC offset calculation
                 by Michael Borisov

 In order to use the available 8-bit or 16-bit dynamic range
 to full extent, reducing the influence of quantization
 noise while simultaneously avoiding overflows, gain
 and DC offset should be set to appropriate value.

 All Pokey-generated sounds have maximal amplitude of 15.
 When all four channels sound simultaneously and in the
 same phase, amplidudes would add up to 60.

 If Pokey is generating a 'pure tone', it always has a DC
 offset of half its amplitude. For other signals (produced
 by poly generators) DC offset varies, but it is always near
 to half amplitude and never exceeds this value.

 In case that pure tone base frequency is outside of audible
 range (ultrasound frequency for high sample rates and above-
 Nyquist frequency for low sample rates), to speed up the engine,
 the generator is stopped while having only DC offset on the
 output (half of corresponding AUDV value). In order that this
 DC offset can be always represented as integer, AUDV values
 are multiplied by 2 when the generator works.

 Therefore maximum integer value before resampling filters
 would be 60*2 = 120 while having maximum DC offset of 60.
 Resampling does not change the DC offset, therefore we may
 subtract it from the signal either before or after resampling.
 In mzpokeysnd, DC offset is subtracted after resampling, however
 for better understanding in further measurements I assume
 subtracting DC before. So, input range for the resampler
 becomes [-60 .. 60].

 Resampling filter removes some harmonics from the signal as if
 the rectangular wave was Fourier transformed forth-and-back,
 while zeroing all harmonics above cutoff frequency. In case
 of high-frequency pure tone (above samplerate/8), only first
 harmonic of the Fourier transofm will remain. As it
 is known, Fourier-transform of the rectangular function of
 amplitude 1 has first oscillation component of amplitude 4/M_PI.
 Therefore, maximum sample values for filtered rectangular
 signal may exceed the amplitude  of rectangular signal
 by up to 4/M_PI times.

 Since our range before resampler is -60 .. 60, taking into
 account mentioned effect with band limiting, range of values
 on the resampler output appears to be in the following bounds:
 [-60*4/M_PI .. 60*4/M_PI]

 In order to map this into signed 8-bit range [-128 .. 127], we
 should multiply the resampler output by 127/60/4*M_PI.

 As it is common for sound hardware to have 8-bit sound unsigned,
 additional DC offset of 128 must be added.

 For 16-bit case the output range is [-32768 .. 32767], and
 we should multiply the resampler output by 32767/60/4*M_PI

 To make some room for numerical errors, filter ripples and
 quantization noise, so that they do not cause overflows in
 quantization, dynamic range is reduced in mzpokeysnd by
 multiplying the output amplitude with 0.95, reserving 5%
 of the total range for such effects, which is about 0.51db.

 Mentioned gain and DC values were tested with 17kHz audio
 playing synchronously on 4 channels, which showed to be
 utilizing 95% of the sample values range.

 Since any other gain value will be not optimal, I removed
 user gain setting and hard-coded the gain into mzpokeysnd

 ---

 A note from Piotr Fusik:
 I've added support for the key click sound generated by GTIA. Its
 volume seems to be pretty much like 8 on single POKEY's channel.
 So, the volumes now can sum up to 136 (4 channels * 15 * 2
 + 8 * 2 for GTIA), not 120.

 A note from Mark Grebe:
 I've added back in the console and sio sounds from the old
 pokey version.  So, now the volumes can sum up to 152
 (4 channesl * 15 * 2 + 8 * 4 for old sound), not 120 or 136.

 ******************************************************************/


/******************************************************************

          Quantization effects and dithering
              by Michael Borisov

 Quantization error in the signal has an expectation value of half
 the LSB, when the rounding is performed properly. Sometimes they
 express quantization error as a random function with even
 distribution over the range [-0.5 to 0.5]. Spectrum of this function
 is flat, because it's a white noise.

 Power of a discrete signal (including noise) is calculated as
 mean square of its samples. For the mentioned above noise
 this is approximately 0.33. Therefore, in decibels for 8-bit case,
 our noise will have power of 10*log10(0.33/256/256) = -53dB

 Because noise is white, this power of -53dB will be evenly
 distributed over the whole signal band upto Nyquist frequency.
 The larger the band is (higher sampling frequency), less
 is the quantisation noise floor. For 8000Hz noise floor is
 10*log10(0.33/256/256/4000) = -89dB/Hz, and for 44100Hz noise
 floor is 10*log10(0.33/256/256/22050) = -96.4dB/Hz.
 This shows that higher sampling rates are better in sense of
 quantization noise. Moreover, as large part of quantization noise
 in case of 44100Hz will fall into ultrasound and hi-frequency
 area 10-20kHz where human ear is less sensitive, this will
 show up as great improvement in quantization noise performance
 compared to 8000Hz.

 I was plotting spectral analysis for sounds produced by mzpokeysnd
 to check these measures. And it showed up that in 8-bit case
 there is no expected flat noise floor of -89db/Hz for 8000Hz,
 but some distortion spectral peaks had higher amplitude than
 the aliasing peaks in 16-bit case. This was a proof to another
 statement which says that quantization noise tends to become
 correlated with the signal. Correlation is especially strong
 for simple signals generated by Pokey. Correlation means that
 the noise power of -53db is no longer evenly distributed
 across the whole frequency range, but concentrates in larger
 peaks at locations which depend on the Pokey signal.

 To decorrelate quantization distortion and make it again
 white noise, which would improve the sound spectrum, since
 the maximum distortion peaks will have less amplitude,
 dithering is used. Another white noise is added to the signal
 before quantization. Since this added noise is not correlated
 with the signal, it shows itself as a flat noise floor.
 Quantization noise now tries to correlate with the dithering
 noise, but this does not lead to appearance of sharp
 spectral peaks any more :)

 Another thing is that for listening, white noise is better than
 distortion. This is because human hearing has some 'noise
 reduction' system which makes it easier to percept sounds
 on the white noise background.

 From the other point of view, if a signal has high and low
 spectral peaks, it is desirable that there is no distortion
 component with peaks of amplitude comparable to those of
 the true signal. Otherwise, perception of background low-
 amplitude signals will be disrupted. That's why they say
 that dithering extends dynamic range.

 Dithering does not eliminate correlation of quantization noise
 completely. Degree of reduction of this effect depends on
 the dithering noise power. The higher is dithering noise,
 the more quantization noise is decorrelated. But this also
 leads to increase of noise percepted by the listener. So, an
 optimum value should be selected. My experiments show that
 unbiased rand() noise of amplitude 0.25 LSB is doing well.

 Test spectral pictures for 8-bit sound, 8kHz sampling rate,
 dithered, show a noise floor of approx. -87dB/Hz.

 ******************************************************************/

extern int atari_speaker;

void Pokey_process_8(void* sndbuffer, unsigned sndn)
{
    unsigned short i;
    int nsam = sndn;
    uint8 *buffer = (uint8 *) sndbuffer;

    if(num_cur_pokeys<1)
        return; /* module was not initialized */

    /* if there are two pokeys, then the signal is stereo
       we assume even sndn */
    if (stereo_enabled)
    {
    while(nsam >= (int) num_cur_pokeys)
    {
#ifdef VOL_ONLY_SOUND
        if( sampbuf_rptr!=sampbuf_ptr )
            { int l;
            if( sampbuf_cnt[sampbuf_rptr]>0 )
                sampbuf_cnt[sampbuf_rptr]-=1280;
            while(  (l=sampbuf_cnt[sampbuf_rptr])<=0 )
                {	sampout=sampbuf_val[sampbuf_rptr];
                        sampbuf_rptr++;
                        if( sampbuf_rptr>=SAMPBUF_MAX )
                                sampbuf_rptr=0;
                        if( sampbuf_rptr!=sampbuf_ptr )
                            {
                            sampbuf_cnt[sampbuf_rptr]+=l;
                            }
                        else	break;
                }
            }
#endif

#ifdef VOL_ONLY_SOUND
	buffer[0] = generate_sample2(pokey_states,sampout);
#else
	buffer[0] = generate_sample(pokey_states);
#endif
        for(i=1; i<num_cur_pokeys; i++)
	    buffer[i] = generate_sample(pokey_states+i);
        buffer += num_cur_pokeys;
        nsam -= num_cur_pokeys;
    }
    }
    else
    {
    while(nsam >= (int) num_cur_pokeys)
    {
#ifdef VOL_ONLY_SOUND
        if( sampbuf_rptr!=sampbuf_ptr )
            { int l;
            if( sampbuf_cnt[sampbuf_rptr]>0 )
                sampbuf_cnt[sampbuf_rptr]-=1280;
            while(  (l=sampbuf_cnt[sampbuf_rptr])<=0 )
                {	sampout=sampbuf_val[sampbuf_rptr];
                        sampbuf_rptr++;
                        if( sampbuf_rptr>=SAMPBUF_MAX )
                                sampbuf_rptr=0;
                        if( sampbuf_rptr!=sampbuf_ptr )
                            {
                            sampbuf_cnt[sampbuf_rptr]+=l;
                            }
                        else	break;
                }
            }
#endif

#ifdef VOL_ONLY_SOUND
	buffer[1] = buffer[0] = generate_sample2(pokey_states,sampout);
#else
	buffer[1] = buffer[0] = generate_sample(pokey_states);
#endif
        buffer += num_cur_pokeys;
        nsam -= num_cur_pokeys;
    }
    }
}

void Pokey_process_16(void* sndbuffer, unsigned sndn)
{
    unsigned short i;
    int nsam = sndn;
    int16 *buffer = (int16 *) sndbuffer;

    if(num_cur_pokeys<1)
        return; /* module was not initialized */

    /* if there are two pokeys, then the signal is stereo
       we assume even sndn */
    while(nsam >= (int) num_cur_pokeys)
    {
#ifdef VOL_ONLY_SOUND
        if( sampbuf_rptr!=sampbuf_ptr )
            { int l;
            if( sampbuf_cnt[sampbuf_rptr]>0 )
                sampbuf_cnt[sampbuf_rptr]-=1280;
            while(  (l=sampbuf_cnt[sampbuf_rptr])<=0 )
                {	sampout=sampbuf_val[sampbuf_rptr];
                        sampbuf_rptr++;
                        if( sampbuf_rptr>=SAMPBUF_MAX )
                                sampbuf_rptr=0;
                        if( sampbuf_rptr!=sampbuf_ptr )
                            {
                            sampbuf_cnt[sampbuf_rptr]+=l;
                            }
                        else	break;
                }
            }
#endif
#ifdef VOL_ONLY_SOUND
        buffer[0] = (int16)floor((generate_sample(pokey_states) + sampout - MAX_SAMPLE / 2.0)
         * (65535.0 / MAX_SAMPLE / 4 * M_PI * 0.95) + 0.5 + 0.5 * rand() / RAND_MAX - 0.25);
#else
        buffer[0] = (int16)floor((generate_sample(pokey_states) - MAX_SAMPLE / 2.0)
         * (65535.0 / MAX_SAMPLE / 4 * M_PI * 0.95) + 0.5 + 0.5 * rand() / RAND_MAX - 0.25);
#endif
        for(i=1; i<num_cur_pokeys; i++)
        {
            buffer[i] = (int16)floor((generate_sample(pokey_states + i) - MAX_SAMPLE / 2.0)
             * (65535.0 / MAX_SAMPLE / 4 * M_PI * 0.95) + 0.5 + 0.5 * rand() / RAND_MAX - 0.25);
        }
        buffer += num_cur_pokeys;
        nsam -= num_cur_pokeys;
    }
}

#ifdef SERIO_SOUND
void Update_serio_sound_mz( int out, UBYTE data )
{
#ifdef VOL_ONLY_SOUND
   int bits,pv,future;
        if (!serio_sound_enabled) return;

	pv=0;
	future=0;
	bits= (data<<1) | 0x200;
	while( bits )
	{
		sampbuf_lastval-=pv;
		pv=(bits&0x01)*pokey_states[0].vol3;
		sampbuf_lastval+=pv;

	sampbuf_val[sampbuf_ptr]=sampbuf_lastval;
	sampbuf_cnt[sampbuf_ptr]=
		(cpu_clock+future-sampbuf_last)*128*samp_freq/178979;
	sampbuf_last=cpu_clock+future;
	sampbuf_ptr++;
	if( sampbuf_ptr>=SAMPBUF_MAX )
		sampbuf_ptr=0;
	if( sampbuf_ptr==sampbuf_rptr )
	{	sampbuf_rptr++;
		if( sampbuf_rptr>=SAMPBUF_MAX )
			sampbuf_rptr=0;
	}
			/* 1789790/19200 = 93 */
		future+=93;	/* ~ 19200 bit/s - FIXME!!! set speed form AUDF [2] ??? */
		bits>>=1;
	}
	sampbuf_lastval-=pv;
#endif  /* VOL_ONLY_SOUND */
}
#endif /* SERIO_SOUND */

#ifdef CONSOLE_SOUND
void Update_consol_sound_mz( int set )
{
#ifdef VOL_ONLY_SOUND
  static int prev_atari_speaker=0;
  static unsigned int prev_cpu_clock=0;
  int d;
        if (!console_sound_enabled) return;

	if( !set && samp_consol_val==0 )	return;
	sampbuf_lastval-=samp_consol_val;
	if( prev_atari_speaker!=atari_speaker )
	{	samp_consol_val=atari_speaker*8*4;	/* gain */
		prev_cpu_clock=cpu_clock;
	}
	else if( !set )
	{	d=cpu_clock - prev_cpu_clock;
		if( d<114 )
		{	sampbuf_lastval+=samp_consol_val;   return;	}
		while( d>=114 /* CPUL */ )
		{	samp_consol_val=samp_consol_val*99/100;
			d-=114;
		}
		prev_cpu_clock=cpu_clock-d;
	}
	sampbuf_lastval+=samp_consol_val;
	prev_atari_speaker=atari_speaker;

	sampbuf_val[sampbuf_ptr]=sampbuf_lastval;
	sampbuf_cnt[sampbuf_ptr]=
		(cpu_clock-sampbuf_last)*128*samp_freq/178979;
	sampbuf_last=cpu_clock;
	sampbuf_ptr++;
	if( sampbuf_ptr>=SAMPBUF_MAX )
		sampbuf_ptr=0;
	if( sampbuf_ptr==sampbuf_rptr )
	{	sampbuf_rptr++;
		if( sampbuf_rptr>=SAMPBUF_MAX )
			sampbuf_rptr=0;
	}
#endif  /* VOL_ONLY_SOUND */
}
#endif

#ifdef VOL_ONLY_SOUND
void Update_vol_only_sound_mz( void )
{
#ifdef CONSOLE_SOUND
	Update_consol_sound(0);	/* mmm */
#endif /* CONSOLE_SOUND */
}
#endif
