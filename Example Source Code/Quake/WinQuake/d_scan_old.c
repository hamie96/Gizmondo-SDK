// d_scan.c
// Portable C scan-level rasterization code, all pixel depths.

#include "quakedef.h"
#include "r_local.h"
#include "d_local.h"

unsigned char *r_turb_pbase, *r_turb_pdest;
fixed16_t r_turb_s, r_turb_t, r_turb_sstep, r_turb_tstep;
int *r_turb_turb;
int r_turb_spancount;

void D_DrawTurbulent8Span (void);

/*==============================================
// D_WarpScreen
// this performs a slight compression of the screen at the same time as
// the sine warp, to keep the edges from wrapping
//============================================*/
void D_WarpScreen (void)
{
	int	w, h;
	int	u,v;
	byte *dest;
	int *turb;
	int *col;
	byte **row;
	byte *rowptr[MAXHEIGHT+(AMP2*2)];
	int column[MAXWIDTH+(AMP2*2)];
	float wratio, hratio;
	w = r_refdef.vrect.width;
	h = r_refdef.vrect.height;
	wratio = w / (float)scr_vrect.width;
	hratio = h / (float)scr_vrect.height;
	for (v=0 ; v<scr_vrect.height+AMP2*2 ; v++)
	{
		rowptr[v] = d_viewbuffer + (r_refdef.vrect.y * screenwidth) +
				 (screenwidth * (int)((float)v * hratio * h / (h + AMP2 * 2)));
	}
	for (u=0 ; u<scr_vrect.width+AMP2*2 ; u++)
	{
		column[u] = r_refdef.vrect.x +
				(int)((float)u * wratio * w / (w + AMP2 * 2));
	}
	turb = intsintable + ((int)(cl.time*SPEED)&(CYCLE-1));
	dest = vid.buffer + scr_vrect.y * vid.rowbytes + scr_vrect.x;
	for (v=0 ; v<scr_vrect.height ; v++, dest += vid.rowbytes)
	{
		col = &column[turb[v]];
		row = &rowptr[v];
		for (u=0 ; u<scr_vrect.width ; u+=4)
		{
			dest[u+0] = row[turb[u+0]][col[u+0]];
			dest[u+1] = row[turb[u+1]][col[u+1]];
			dest[u+2] = row[turb[u+2]][col[u+2]];
			dest[u+3] = row[turb[u+3]][col[u+3]];
		}
	}
}

#if	!id386

/*==============================================
// D_DrawTurbulent8Span
//============================================*/
void D_DrawTurbulent8Span (void)
{
	int sturb, tturb;
	do
	{
		sturb = ((r_turb_s + r_turb_turb[(r_turb_t>>16)&(CYCLE-1)])>>16)&63;
		tturb = ((r_turb_t + r_turb_turb[(r_turb_s>>16)&(CYCLE-1)])>>16)&63;
		*r_turb_pdest++ = *(r_turb_pbase + (tturb<<6) + sturb);
		r_turb_s += r_turb_sstep;
		r_turb_t += r_turb_tstep;
	} while (--r_turb_spancount > 0);
}

#endif	// !id386

/*==============================================
// Turbulent8
//============================================*/
void Turbulent8 (espan_t *pspan)
{
	int	count;
	fixed16_t snext, tnext;
	float sdivz, tdivz, zi, z, du, dv, spancountminus1;
	float sdivz16stepu, tdivz16stepu, zi16stepu;
	r_turb_turb = sintable + ((int)(cl.time*SPEED)&(CYCLE-1));
	r_turb_sstep = 0;	// keep compiler happy
	r_turb_tstep = 0;	// ditto
	r_turb_pbase = (unsigned char *)cacheblock;
	sdivz16stepu = d_sdivzstepu * 16;
	tdivz16stepu = d_tdivzstepu * 16;
	zi16stepu = d_zistepu * 16;
	do
	{
		r_turb_pdest = (unsigned char *)((byte *)d_viewbuffer +
				(screenwidth * pspan->v) + pspan->u);
		count = pspan->count;
		// calculate the initial s/z, t/z, 1/z, s, and t and clamp
		du = (float)pspan->u;
		dv = (float)pspan->v;
		sdivz = d_sdivzorigin + dv*d_sdivzstepv + du*d_sdivzstepu;
		tdivz = d_tdivzorigin + dv*d_tdivzstepv + du*d_tdivzstepu;
		zi = d_ziorigin + dv*d_zistepv + du*d_zistepu;
		z = (float)0x10000 / zi;	// prescale to 16.16 fixed-point
		r_turb_s = (int)(sdivz * z) + sadjust;
		if (r_turb_s > bbextents) r_turb_s = bbextents;
		else if (r_turb_s < 0) r_turb_s = 0;
		r_turb_t = (int)(tdivz * z) + tadjust;
		if (r_turb_t > bbextentt) r_turb_t = bbextentt;
		else if (r_turb_t < 0) r_turb_t = 0;
		do
		{
		// calculate s and t at the far end of the span
			if (count >= 16) r_turb_spancount = 16;
			else r_turb_spancount = count;
			count -= r_turb_spancount;
			if (count)
			{
				// calculate s/z, t/z, zi->fixed s and t at far end of span,
				// calculate s and t steps across span by shifting
				sdivz += sdivz16stepu;
				tdivz += tdivz16stepu;
				zi += zi16stepu;
				z = (float)0x10000 / zi;	// prescale to 16.16 fixed-point
				snext = (int)(sdivz * z) + sadjust;
				if (snext > bbextents) snext = bbextents;
				else if (snext < 16) snext = 16;
				tnext = (int)(tdivz * z) + tadjust;
				if (tnext > bbextentt) tnext = bbextentt;
				else if (tnext < 16) tnext = 16; // guard against round-off error on <0 steps
				r_turb_sstep = (snext - r_turb_s) >> 4;
				r_turb_tstep = (tnext - r_turb_t) >> 4;
			}
			else
			{
				// calculate s/z, t/z, zi->fixed s and t at last pixel in span (so
				// can't step off polygon), clamp, calculate s and t steps across
				// span by division, biasing steps low so we don't run off the
				// texture
				spancountminus1 = (float)(r_turb_spancount - 1);
				sdivz += d_sdivzstepu * spancountminus1;
				tdivz += d_tdivzstepu * spancountminus1;
				zi += d_zistepu * spancountminus1;
				z = (float)0x10000 / zi;	// prescale to 16.16 fixed-point
				snext = (int)(sdivz * z) + sadjust;
				if (snext > bbextents) snext = bbextents;
				else if (snext < 16) snext = 16;
				tnext = (int)(tdivz * z) + tadjust;
				if (tnext > bbextentt) tnext = bbextentt;
				else if (tnext < 16) tnext = 16; // guard against round-off error on <0 steps
				if (r_turb_spancount > 1)
				{
					r_turb_sstep = (snext - r_turb_s) / (r_turb_spancount - 1);
					r_turb_tstep = (tnext - r_turb_t) / (r_turb_spancount - 1);
				}
			}
			r_turb_s = r_turb_s & ((CYCLE<<16)-1);
			r_turb_t = r_turb_t & ((CYCLE<<16)-1);
			D_DrawTurbulent8Span ();
			r_turb_s = snext;
			r_turb_t = tnext;
		} while (count > 0);
	} while ((pspan = pspan->pnext) != NULL);
}

#if	!id386

static int sdivzorig, sdivzstepv, sdivzstepu;
static int tdivzorig, tdivzstepv, tdivzstepu;
static int ziorig, zistepv, zistepu;
static float last = 0;

/*==============================================
// UpdateFixedPointVars
//============================================*/
void UpdateFixedPointVars( int all )
{
	// JB: Store texture transformation matrix in fixed point vars
	if (all)
	{
		sdivzorig = (int)(4194304.0f * d_sdivzorigin); // 10.22 fixed point
		tdivzorig = (int)(4194304.0f * d_tdivzorigin);
		sdivzstepv = (int)(4194304.0f * d_sdivzstepv);
		tdivzstepv = (int)(4194304.0f * d_tdivzstepv);
		sdivzstepu = (int)(4194304.0f * d_sdivzstepu);
		tdivzstepu = (int)(4194304.0f * d_tdivzstepu);
	}
	ziorig = (int)(4194304.0f * d_ziorigin);  // 10.22 fixed point
	zistepv = (int)(4194304.0f * d_zistepv ); 
	zistepu = (int)(4194304.0f * d_zistepu ); 
	last = d_zistepv;
}

/*==============================================
// D_DrawSpans8
//============================================*/
void D_DrawSpans8 (espan_t *pspan)
{
	int i, count;
	unsigned char *pbase, *pdest;
	fixed16_t s1, s2, t1, t2;
	int zi, sdivz, tdivz, sstep, tstep;
	pbase = (unsigned char *)cacheblock;
	// Recalc fixed point values
	UpdateFixedPointVars( 1 );
	do
	{
		pdest = (unsigned char *)((byte *)d_viewbuffer + (screenwidth * pspan->v) + pspan->u);
		count = pspan->count;
		// calculate the initial s/z, t/z, 1/z, s, and t and clamp
		sdivz = sdivzorig + pspan->v * sdivzstepv + pspan->u * sdivzstepu;
		tdivz = tdivzorig + pspan->v * tdivzstepv + pspan->u * tdivzstepu;
		zi = ziorig + pspan->v * zistepv + pspan->u * zistepu;
		if (zi == 0) zi = 1;
		s1 = (((sdivz << 8) / zi) << 8) + sadjust;
		if (s1 > bbextents) s1 = bbextents; else if (s1 < 0) s1 = 0;
		t1 = (((tdivz << 8) / zi) << 8) + tadjust;
		if (t1 > bbextentt) t1 = bbextentt; else if (t1 < 0) t1 = 0;
		// calculate final s/z, t/z, 1/z, s, and t and clamp
		sdivz += sdivzstepu * (count - 1);
		tdivz += tdivzstepu * (count - 1);
		zi += zistepu * (count - 1);
		if (zi == 0) zi = 1;
		s2 = (((sdivz << 8) / zi) << 8) + sadjust;
		if (s2 > bbextents) s2 = bbextents; else if (s2 < 8) s2 = 8;
		t2 = (((tdivz << 8) / zi) << 8) + tadjust;
		if (t2 > bbextentt) t2 = bbextentt; else if (t2 < 8) t2 = 8;
		if (count > 1)
		{
			sstep = (s2 - s1) / (count - 1);
			tstep = (t2 - t1) / (count - 1);
		}
		// Draw span
		for ( i = 0; i < count; i++ )
		{
			*pdest++ = *(pbase + (s1 >> 16) + (t1 >> 16) * cachewidth);
			s1 += sstep;
			t1 += tstep;
		}
	} while ((pspan = pspan->pnext) != NULL);
}

#endif

#if	!id386

/*==============================================
// D_DrawZSpans
//============================================*/
void D_DrawZSpans (espan_t *pspan)
{
	int count, doublecount, izistep;
	int izi;
	short *pdest;
	unsigned ltemp;
	// Recalc fixed point values
	UpdateFixedPointVars( 0 );
	izistep = zistepu << 9;
	do
	{
		pdest = d_pzbuffer + (d_zwidth * pspan->v) + pspan->u;
		count = pspan->count;
		// calculate the initial 1/z
		izi = (ziorig + pspan->v * zistepv + pspan->u * zistepu) << 9; // 1.31 fixed point
		if ((long)pdest & 0x02)
		{
			*pdest++ = (short)(izi >> 16);
			izi += izistep;
			count--;
		}
		if ((doublecount = count >> 1) > 0)
		{
			do
			{
				ltemp = izi >> 16;
				izi += izistep;
				ltemp |= izi & 0xFFFF0000;
				izi += izistep;
				*(int *)pdest = ltemp;
				pdest += 2;
			} while (--doublecount > 0);
		}
		if (count & 1) *pdest = (short)(izi >> 16);

	} while ((pspan = pspan->pnext) != NULL);
}

#endif

