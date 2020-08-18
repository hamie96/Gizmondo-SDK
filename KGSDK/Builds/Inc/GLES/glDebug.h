#ifndef __gl_h_
#define __gl_h_

#ifdef __cplusplus
extern "C" {
#endif

/*
** Copyright 1991-1993, Silicon Graphics, Inc.
** All Rights Reserved.
** 
** This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics, Inc.;
** the contents of this file may not be disclosed to third parties, copied or
** duplicated in any form, in whole or in part, without the prior written
** permission of Silicon Graphics, Inc.
** 
** RESTRICTED RIGHTS LEGEND:
** Use, duplication or disclosure by the Government is subject to restrictions
** as set forth in subdivision (c)(1)(ii) of the Rights in Technical Data
** and Computer Software clause at DFARS 252.227-7013, and/or in similar or
** successor clauses in the FAR, DOD or NASA FAR Supplement. Unpublished -
** rights reserved under the Copyright Laws of the United States.
*/

#if defined(_LANGUAGE_C) || defined(__cplusplus)

typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef signed char GLbyte;
typedef short GLshort;
typedef int GLint;
typedef int GLsizei;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLuint;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void GLvoid;

static GLboolean __glDebug_InBegin = 0;

static const char* __glDebug_ErrorString[] = {
  "GL_INVALID_ENUM",
  "GL_INVALID_VALUE",
  "GL_INVALID_OPERATION",
  "GL_STACK_OVERFLOW",
  "GL_STACK_UNDERFLOW",
  "GL_OUT_OF_MEMORY",
  "GL_TABLE_TOO_LARGE",
  "GL_TEXTURE_TOO_LARGE_EXT"					      
};

#define __glDebug_ErrorStringMacro(e) \
  ( e == GL_TABLE_TOO_LARGE ? __glDebug_ErrorString[6] : \
    e == GL_TEXTURE_TOO_LARGE_EXT ? __glDebug_ErrorString[7] : \
    __glDebug_ErrorString[e - GL_INVALID_ENUM] )
    

#endif /*defined(_LANGUAGE_C) || defined(__cplusplus)*/


/*************************************************************/

/* Extensions */
#define GL_VERSION_1_1                      1
#define GL_VERSION_1_2                      1
#define GL_ARB_imaging                      1
#define GL_EXT_abgr                         1
#define GL_EXT_blend_color                  1
#define GL_EXT_blend_logic_op               1
#define GL_EXT_blend_minmax                 1
#define GL_EXT_blend_subtract               1
#define GL_EXT_cmyka                        1
#define GL_EXT_convolution                  1
#define GL_EXT_copy_texture                 1
#define GL_EXT_histogram                    1
#define GL_EXT_packed_pixels                1
#define GL_EXT_point_parameters             1
#define GL_EXT_polygon_offset               1
#define GL_EXT_rescale_normal               1
#define GL_EXT_shared_texture_palette       1
#define GL_EXT_subtexture                   1
#define GL_EXT_texture                      1
#define GL_EXT_texture3D                    1
#define GL_EXT_texture_object               1
#define GL_EXT_vertex_array                 1
#define GL_INGR_interlace_read              1
#define GL_SGIS_detail_texture              1
#define GL_SGIS_fog_function                1
#define GL_SGIS_generate_mipmap             1
#define GL_SGIS_multisample                 1
#define GL_SGIS_pixel_texture               1
#define GL_SGIS_point_line_texgen           1
#define GL_SGIS_point_parameters            1
#define GL_SGIS_sharpen_texture             1
#define GL_SGIS_texture4D                   1
#define GL_SGIS_texture_border_clamp        1
#define GL_SGIS_texture_color_mask          1
#define GL_SGIS_texture_edge_clamp          1
#define GL_SGIS_texture_filter4             1
#define GL_SGIS_texture_lod                 1
#define GL_SGIS_texture_select              1
#define GL_SGIX_async                       1
#define GL_SGIX_async_histogram             1
#define GL_SGIX_async_pixel                 1
#define GL_SGIX_blend_alpha_minmax          1
#define GL_SGIX_calligraphic_fragment       1
#define GL_SGIX_clipmap                     1
#define GL_SGIX_convolution_accuracy        1
#define GL_SGIX_depth_texture               1
#define GL_SGIX_flush_raster                1
#define GL_SGIX_fog_offset                  1
#define GL_SGIX_fragment_lighting           1
#define GL_SGIX_framezoom                   1
#define GL_SGIX_icc_texture                 1
#define GL_SGIX_impact_pixel_texture        1
#define GL_SGIX_instruments                 1
#define GL_SGIX_interlace                   1
#define GL_SGIX_ir_instrument1              1
#define GL_SGIX_list_priority               1
#define GL_SGIX_pixel_texture               1
#define GL_SGIX_pixel_tiles                 1
#define GL_SGIX_polynomial_ffd              1
#define GL_SGIX_reference_plane             1
#define GL_SGIX_resample                    1
#define GL_SGIX_scalebias_hint              1
#define GL_SGIX_shadow                      1
#define GL_SGIX_shadow_ambient              1
#define GL_SGIX_sprite                      1
#define GL_SGIX_subsample                   1
#define GL_SGIX_tag_sample_buffer           1
#define GL_SGIX_texture_add_env             1
#define GL_SGIX_texture_coordinate_clamp    1
#define GL_SGIX_texture_lod_bias            1
#define GL_SGIX_texture_multi_buffer        1
#define GL_SGIX_texture_scale_bias          1
#define GL_SGIX_vertex_preclip              1
#define GL_SGIX_ycrcb                       1
#define GL_SGI_color_matrix                 1
#define GL_SGI_color_table                  1
#define GL_SGI_texture_color_table          1

/* AttribMask */
#define GL_CURRENT_BIT                      0x00000001
#define GL_POINT_BIT                        0x00000002
#define GL_LINE_BIT                         0x00000004
#define GL_POLYGON_BIT                      0x00000008
#define GL_POLYGON_STIPPLE_BIT              0x00000010
#define GL_PIXEL_MODE_BIT                   0x00000020
#define GL_LIGHTING_BIT                     0x00000040
#define GL_FOG_BIT                          0x00000080
#define GL_DEPTH_BUFFER_BIT                 0x00000100
#define GL_ACCUM_BUFFER_BIT                 0x00000200
#define GL_STENCIL_BUFFER_BIT               0x00000400
#define GL_VIEWPORT_BIT                     0x00000800
#define GL_TRANSFORM_BIT                    0x00001000
#define GL_ENABLE_BIT                       0x00002000
#define GL_COLOR_BUFFER_BIT                 0x00004000
#define GL_HINT_BIT                         0x00008000
#define GL_EVAL_BIT                         0x00010000
#define GL_LIST_BIT                         0x00020000
#define GL_TEXTURE_BIT                      0x00040000
#define GL_SCISSOR_BIT                      0x00080000
#define GL_ALL_ATTRIB_BITS                  0x000fffff
#define GL_MULTISAMPLE_BIT_EXT              0x20000000

/* ClearBufferMask */
/*      GL_COLOR_BUFFER_BIT */
/*      GL_ACCUM_BUFFER_BIT */
/*      GL_STENCIL_BUFFER_BIT */
/*      GL_DEPTH_BUFFER_BIT */

/* ClientAttribMask */
#define GL_CLIENT_PIXEL_STORE_BIT           0x00000001
#define GL_CLIENT_VERTEX_ARRAY_BIT          0x00000002
#define GL_CLIENT_ALL_ATTRIB_BITS           0xFFFFFFFF

/* Boolean */
#define GL_FALSE                            0
#define GL_TRUE                             1

/* BeginMode */
#define GL_POINTS                           0x0000
#define GL_LINES                            0x0001
#define GL_LINE_LOOP                        0x0002
#define GL_LINE_STRIP                       0x0003
#define GL_TRIANGLES                        0x0004
#define GL_TRIANGLE_STRIP                   0x0005
#define GL_TRIANGLE_FAN                     0x0006
#define GL_QUADS                            0x0007
#define GL_QUAD_STRIP                       0x0008
#define GL_POLYGON                          0x0009

/* AccumOp */
#define GL_ACCUM                            0x0100
#define GL_LOAD                             0x0101
#define GL_RETURN                           0x0102
#define GL_MULT                             0x0103
#define GL_ADD                              0x0104

/* AlphaFunction */
#define GL_NEVER                            0x0200
#define GL_LESS                             0x0201
#define GL_EQUAL                            0x0202
#define GL_LEQUAL                           0x0203
#define GL_GREATER                          0x0204
#define GL_NOTEQUAL                         0x0205
#define GL_GEQUAL                           0x0206
#define GL_ALWAYS                           0x0207

/* BlendingFactorDest */
#define GL_ZERO                             0
#define GL_ONE                              1
#define GL_SRC_COLOR                        0x0300
#define GL_ONE_MINUS_SRC_COLOR              0x0301
#define GL_SRC_ALPHA                        0x0302
#define GL_ONE_MINUS_SRC_ALPHA              0x0303
#define GL_DST_ALPHA                        0x0304
#define GL_ONE_MINUS_DST_ALPHA              0x0305
/*      GL_CONSTANT_COLOR_EXT */
/*      GL_ONE_MINUS_CONSTANT_COLOR_EXT */
/*      GL_CONSTANT_ALPHA_EXT */
/*      GL_ONE_MINUS_CONSTANT_ALPHA_EXT */

/* BlendingFactorSrc */
/*      GL_ZERO */
/*      GL_ONE */
#define GL_DST_COLOR                        0x0306
#define GL_ONE_MINUS_DST_COLOR              0x0307
#define GL_SRC_ALPHA_SATURATE               0x0308
/*      GL_SRC_ALPHA */
/*      GL_ONE_MINUS_SRC_ALPHA */
/*      GL_DST_ALPHA */
/*      GL_ONE_MINUS_DST_ALPHA */
/*      GL_CONSTANT_COLOR_EXT */
/*      GL_ONE_MINUS_CONSTANT_COLOR_EXT */
/*      GL_CONSTANT_ALPHA_EXT */
/*      GL_ONE_MINUS_CONSTANT_ALPHA_EXT */

/* BlendEquationModeEXT */
/*      GL_LOGIC_OP */
/*      GL_FUNC_ADD_EXT */
/*      GL_MIN_EXT */
/*      GL_MAX_EXT */
/*      GL_FUNC_SUBTRACT_EXT */
/*      GL_FUNC_REVERSE_SUBTRACT_EXT */
/*      GL_ALPHA_MIN_SGIX */
/*      GL_ALPHA_MAX_SGIX */

/* ColorMaterialFace */
/*      GL_FRONT */
/*      GL_BACK */
/*      GL_FRONT_AND_BACK */

/* ColorMaterialParameter */
/*      GL_AMBIENT */
/*      GL_DIFFUSE */
/*      GL_SPECULAR */
/*      GL_EMISSION */
/*      GL_AMBIENT_AND_DIFFUSE */

/* ColorPointerType */
/*      GL_BYTE */
/*      GL_UNSIGNED_BYTE */
/*      GL_SHORT */
/*      GL_UNSIGNED_SHORT */
/*      GL_INT */
/*      GL_UNSIGNED_INT */
/*      GL_FLOAT */
/*      GL_DOUBLE */

/* ColorTableParameterPNameSGI */
/*      GL_COLOR_TABLE_SCALE_SGI */
/*      GL_COLOR_TABLE_BIAS_SGI */

/* ColorTableTargetSGI */
/*      GL_COLOR_TABLE_SGI */
/*      GL_POST_CONVOLUTION_COLOR_TABLE_SGI */
/*      GL_POST_COLOR_MATRIX_COLOR_TABLE_SGI */
/*      GL_PROXY_COLOR_TABLE_SGI */
/*      GL_PROXY_POST_CONVOLUTION_COLOR_TABLE_SGI */
/*      GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE_SGI */
/*      GL_TEXTURE_COLOR_TABLE_SGI */
/*      GL_PROXY_TEXTURE_COLOR_TABLE_SGI */

/* ConvolutionBorderModeEXT */
/*      GL_REDUCE_EXT */

/* ConvolutionParameterEXT */
/*      GL_CONVOLUTION_BORDER_MODE_EXT */
/*      GL_CONVOLUTION_FILTER_SCALE_EXT */
/*      GL_CONVOLUTION_FILTER_BIAS_EXT */

/* ConvolutionTargetEXT */
/*      GL_CONVOLUTION_1D_EXT */
/*      GL_CONVOLUTION_2D_EXT */

/* CullFaceMode */
/*      GL_FRONT */
/*      GL_BACK */
/*      GL_FRONT_AND_BACK */

/* DepthFunction */
/*      GL_NEVER */
/*      GL_LESS */
/*      GL_EQUAL */
/*      GL_LEQUAL */
/*      GL_GREATER */
/*      GL_NOTEQUAL */
/*      GL_GEQUAL */
/*      GL_ALWAYS */

/* DrawBufferMode */
#define GL_NONE                             0
#define GL_FRONT_LEFT                       0x0400
#define GL_FRONT_RIGHT                      0x0401
#define GL_BACK_LEFT                        0x0402
#define GL_BACK_RIGHT                       0x0403
#define GL_FRONT                            0x0404
#define GL_BACK                             0x0405
#define GL_LEFT                             0x0406
#define GL_RIGHT                            0x0407
#define GL_FRONT_AND_BACK                   0x0408
#define GL_AUX0                             0x0409
#define GL_AUX1                             0x040A
#define GL_AUX2                             0x040B
#define GL_AUX3                             0x040C

/* EnableCap */
/*      GL_FOG */
/*      GL_LIGHTING */
/*      GL_TEXTURE_1D */
/*      GL_TEXTURE_2D */
/*      GL_LINE_STIPPLE */
/*      GL_POLYGON_STIPPLE */
/*      GL_CULL_FACE */
/*      GL_ALPHA_TEST */
/*      GL_BLEND */
/*      GL_INDEX_LOGIC_OP */
/*      GL_COLOR_LOGIC_OP */
/*      GL_DITHER */
/*      GL_STENCIL_TEST */
/*      GL_DEPTH_TEST */
/*      GL_CLIP_PLANE0 */
/*      GL_CLIP_PLANE1 */
/*      GL_CLIP_PLANE2 */
/*      GL_CLIP_PLANE3 */
/*      GL_CLIP_PLANE4 */
/*      GL_CLIP_PLANE5 */
/*      GL_LIGHT0 */
/*      GL_LIGHT1 */
/*      GL_LIGHT2 */
/*      GL_LIGHT3 */
/*      GL_LIGHT4 */
/*      GL_LIGHT5 */
/*      GL_LIGHT6 */
/*      GL_LIGHT7 */
/*      GL_TEXTURE_GEN_S */
/*      GL_TEXTURE_GEN_T */
/*      GL_TEXTURE_GEN_R */
/*      GL_TEXTURE_GEN_Q */
/*      GL_MAP1_VERTEX_3 */
/*      GL_MAP1_VERTEX_4 */
/*      GL_MAP1_COLOR_4 */
/*      GL_MAP1_INDEX */
/*      GL_MAP1_NORMAL */
/*      GL_MAP1_TEXTURE_COORD_1 */
/*      GL_MAP1_TEXTURE_COORD_2 */
/*      GL_MAP1_TEXTURE_COORD_3 */
/*      GL_MAP1_TEXTURE_COORD_4 */
/*      GL_MAP2_VERTEX_3 */
/*      GL_MAP2_VERTEX_4 */
/*      GL_MAP2_COLOR_4 */
/*      GL_MAP2_INDEX */
/*      GL_MAP2_NORMAL */
/*      GL_MAP2_TEXTURE_COORD_1 */
/*      GL_MAP2_TEXTURE_COORD_2 */
/*      GL_MAP2_TEXTURE_COORD_3 */
/*      GL_MAP2_TEXTURE_COORD_4 */
/*      GL_POINT_SMOOTH */
/*      GL_LINE_SMOOTH */
/*      GL_POLYGON_SMOOTH */
/*      GL_SCISSOR_TEST */
/*      GL_COLOR_MATERIAL */
/*      GL_NORMALIZE */
/*      GL_AUTO_NORMAL */
/*      GL_POLYGON_OFFSET_POINT */
/*      GL_POLYGON_OFFSET_LINE */
/*      GL_POLYGON_OFFSET_FILL */
/*      GL_VERTEX_ARRAY */
/*      GL_NORMAL_ARRAY */
/*      GL_COLOR_ARRAY */
/*      GL_INDEX_ARRAY */
/*      GL_TEXTURE_COORD_ARRAY */
/*      GL_EDGE_FLAG_ARRAY */
/*      GL_CONVOLUTION_1D_EXT */
/*      GL_CONVOLUTION_2D_EXT */
/*      GL_SEPARABLE_2D_EXT */
/*      GL_HISTOGRAM_EXT */
/*      GL_MINMAX_EXT */
/*      GL_RESCALE_NORMAL_EXT */
/*      GL_SHARED_TEXTURE_PALETTE_EXT */
/*      GL_TEXTURE_3D_EXT */
/*      GL_INTERLACE_READ_INGR */
/*      GL_MULTISAMPLE_SGIS */
/*      GL_SAMPLE_ALPHA_TO_MASK_SGIS */
/*      GL_SAMPLE_ALPHA_TO_ONE_SGIS */
/*      GL_SAMPLE_MASK_SGIS */
/*      GL_TEXTURE_4D_SGIS */
/*      GL_ASYNC_HISTOGRAM_SGIX */
/*      GL_ASYNC_TEX_IMAGE_SGIX */
/*      GL_ASYNC_DRAW_PIXELS_SGIX */
/*      GL_ASYNC_READ_PIXELS_SGIX */
/*      GL_CALLIGRAPHIC_FRAGMENT_SGIX */
/*      GL_FOG_OFFSET_SGIX */
/*      GL_FRAGMENT_LIGHTING_SGIX */
/*      GL_FRAGMENT_COLOR_MATERIAL_SGIX */
/*      GL_FRAGMENT_LIGHT0_SGIX */
/*      GL_FRAGMENT_LIGHT1_SGIX */
/*      GL_FRAGMENT_LIGHT2_SGIX */
/*      GL_FRAGMENT_LIGHT3_SGIX */
/*      GL_FRAGMENT_LIGHT4_SGIX */
/*      GL_FRAGMENT_LIGHT5_SGIX */
/*      GL_FRAGMENT_LIGHT6_SGIX */
/*      GL_FRAGMENT_LIGHT7_SGIX */
/*      GL_FRAMEZOOM_SGIX */
/*      GL_INTERLACE_SGIX */
/*      GL_IR_INSTRUMENT1_SGIX */
/*      GL_PIXEL_TEX_GEN_SGIX */
/*      GL_PIXEL_TEXTURE_SGIS */
/*      GL_REFERENCE_PLANE_SGIX */
/*      GL_SPRITE_SGIX */
/*      GL_COLOR_TABLE_SGI */
/*      GL_POST_CONVOLUTION_COLOR_TABLE_SGI */
/*      GL_POST_COLOR_MATRIX_COLOR_TABLE_SGI */
/*      GL_TEXTURE_COLOR_TABLE_SGI */

/* ErrorCode */
#define GL_NO_ERROR                         0
#define GL_INVALID_ENUM                     0x0500
#define GL_INVALID_VALUE                    0x0501
#define GL_INVALID_OPERATION                0x0502
#define GL_STACK_OVERFLOW                   0x0503
#define GL_STACK_UNDERFLOW                  0x0504
#define GL_OUT_OF_MEMORY                    0x0505
/*      GL_TABLE_TOO_LARGE_EXT */
/*      GL_TEXTURE_TOO_LARGE_EXT */

/* FeedbackType */
#define GL_2D                               0x0600
#define GL_3D                               0x0601
#define GL_3D_COLOR                         0x0602
#define GL_3D_COLOR_TEXTURE                 0x0603
#define GL_4D_COLOR_TEXTURE                 0x0604

/* FeedBackToken */
#define GL_PASS_THROUGH_TOKEN               0x0700
#define GL_POINT_TOKEN                      0x0701
#define GL_LINE_TOKEN                       0x0702
#define GL_POLYGON_TOKEN                    0x0703
#define GL_BITMAP_TOKEN                     0x0704
#define GL_DRAW_PIXEL_TOKEN                 0x0705
#define GL_COPY_PIXEL_TOKEN                 0x0706
#define GL_LINE_RESET_TOKEN                 0x0707

/* FfdMaskSGIX */
#define GL_TEXTURE_DEFORMATION_BIT_SGIX     0x00000001
#define GL_GEOMETRY_DEFORMATION_BIT_SGIX    0x00000002

/* FfdTargetSGIX */
/*      GL_GEOMETRY_DEFORMATION_SGIX */
/*      GL_TEXTURE_DEFORMATION_SGIX */

/* FogMode */
/*      GL_LINEAR */
#define GL_EXP                              0x0800
#define GL_EXP2                             0x0801
/*      GL_FOG_FUNC_SGIS */

/* FogParameter */
/*      GL_FOG_COLOR */
/*      GL_FOG_DENSITY */
/*      GL_FOG_END */
/*      GL_FOG_INDEX */
/*      GL_FOG_MODE */
/*      GL_FOG_START */
/*      GL_FOG_OFFSET_VALUE_SGIX */

/* FragmentLightModelParameterSGIX */
/*      GL_FRAGMENT_LIGHT_MODEL_LOCAL_VIEWER_SGIX */
/*      GL_FRAGMENT_LIGHT_MODEL_TWO_SIDE_SGIX */
/*      GL_FRAGMENT_LIGHT_MODEL_AMBIENT_SGIX */
/*      GL_FRAGMENT_LIGHT_MODEL_NORMAL_INTERPOLATION_SGIX */

/* FrontFaceDirection */
#define GL_CW                               0x0900
#define GL_CCW                              0x0901

/* GetColorTableParameterPNameSGI */
/*      GL_COLOR_TABLE_SCALE_SGI */
/*      GL_COLOR_TABLE_BIAS_SGI */
/*      GL_COLOR_TABLE_FORMAT_SGI */
/*      GL_COLOR_TABLE_WIDTH_SGI */
/*      GL_COLOR_TABLE_RED_SIZE_SGI */
/*      GL_COLOR_TABLE_GREEN_SIZE_SGI */
/*      GL_COLOR_TABLE_BLUE_SIZE_SGI */
/*      GL_COLOR_TABLE_ALPHA_SIZE_SGI */
/*      GL_COLOR_TABLE_LUMINANCE_SIZE_SGI */
/*      GL_COLOR_TABLE_INTENSITY_SIZE_SGI */

/* GetConvolutionParameter */
/*      GL_CONVOLUTION_BORDER_MODE_EXT */
/*      GL_CONVOLUTION_FILTER_SCALE_EXT */
/*      GL_CONVOLUTION_FILTER_BIAS_EXT */
/*      GL_CONVOLUTION_FORMAT_EXT */
/*      GL_CONVOLUTION_WIDTH_EXT */
/*      GL_CONVOLUTION_HEIGHT_EXT */
/*      GL_MAX_CONVOLUTION_WIDTH_EXT */
/*      GL_MAX_CONVOLUTION_HEIGHT_EXT */

/* GetHistogramParameterPNameEXT */
/*      GL_HISTOGRAM_WIDTH_EXT */
/*      GL_HISTOGRAM_FORMAT_EXT */
/*      GL_HISTOGRAM_RED_SIZE_EXT */
/*      GL_HISTOGRAM_GREEN_SIZE_EXT */
/*      GL_HISTOGRAM_BLUE_SIZE_EXT */
/*      GL_HISTOGRAM_ALPHA_SIZE_EXT */
/*      GL_HISTOGRAM_LUMINANCE_SIZE_EXT */
/*      GL_HISTOGRAM_SINK_EXT */

/* GetMapQuery */
#define GL_COEFF                            0x0A00
#define GL_ORDER                            0x0A01
#define GL_DOMAIN                           0x0A02

/* GetMinmaxParameterPNameEXT */
/*      GL_MINMAX_FORMAT_EXT */
/*      GL_MINMAX_SINK_EXT */

/* GetPixelMap */
#define GL_PIXEL_MAP_I_TO_I                 0x0C70
#define GL_PIXEL_MAP_S_TO_S                 0x0C71
#define GL_PIXEL_MAP_I_TO_R                 0x0C72
#define GL_PIXEL_MAP_I_TO_G                 0x0C73
#define GL_PIXEL_MAP_I_TO_B                 0x0C74
#define GL_PIXEL_MAP_I_TO_A                 0x0C75
#define GL_PIXEL_MAP_R_TO_R                 0x0C76
#define GL_PIXEL_MAP_G_TO_G                 0x0C77
#define GL_PIXEL_MAP_B_TO_B                 0x0C78
#define GL_PIXEL_MAP_A_TO_A                 0x0C79

/* GetPointervPName */
#define GL_VERTEX_ARRAY_POINTER             0x808E
#define GL_NORMAL_ARRAY_POINTER             0x808F
#define GL_COLOR_ARRAY_POINTER              0x8090
#define GL_INDEX_ARRAY_POINTER              0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER      0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER          0x8093
#define GL_FEEDBACK_BUFFER_POINTER          0x0DF0
#define GL_SELECTION_BUFFER_POINTER         0x0DF3
/*      GL_INSTRUMENT_BUFFER_POINTER_SGIX */

/* GetPName */
#define GL_CURRENT_COLOR                    0x0B00
#define GL_CURRENT_INDEX                    0x0B01
#define GL_CURRENT_NORMAL                   0x0B02
#define GL_CURRENT_TEXTURE_COORDS           0x0B03
#define GL_CURRENT_RASTER_COLOR             0x0B04
#define GL_CURRENT_RASTER_INDEX             0x0B05
#define GL_CURRENT_RASTER_TEXTURE_COORDS    0x0B06
#define GL_CURRENT_RASTER_POSITION          0x0B07
#define GL_CURRENT_RASTER_POSITION_VALID    0x0B08
#define GL_CURRENT_RASTER_DISTANCE          0x0B09
#define GL_POINT_SMOOTH                     0x0B10
#define GL_POINT_SIZE                       0x0B11
#define GL_POINT_SIZE_RANGE                 0x0B12
#define GL_POINT_SIZE_GRANULARITY           0x0B13
#define GL_LINE_SMOOTH                      0x0B20
#define GL_LINE_WIDTH                       0x0B21
#define GL_LINE_WIDTH_RANGE                 0x0B22
#define GL_LINE_WIDTH_GRANULARITY           0x0B23
#define GL_LINE_STIPPLE                     0x0B24
#define GL_LINE_STIPPLE_PATTERN             0x0B25
#define GL_LINE_STIPPLE_REPEAT              0x0B26
/*      GL_SMOOTH_POINT_SIZE_RANGE */
/*      GL_SMOOTH_POINT_SIZE_GRANULARITY */
/*      GL_SMOOTH_LINE_WIDTH_RANGE */
/*      GL_SMOOTH_LINE_WIDTH_GRANULARITY */
/*      GL_ALIASED_POINT_SIZE_RANGE */
/*      GL_ALIASED_LINE_WIDTH_RANGE */
#define GL_LIST_MODE                        0x0B30
#define GL_MAX_LIST_NESTING                 0x0B31
#define GL_LIST_BASE                        0x0B32
#define GL_LIST_INDEX                       0x0B33
#define GL_POLYGON_MODE                     0x0B40
#define GL_POLYGON_SMOOTH                   0x0B41
#define GL_POLYGON_STIPPLE                  0x0B42
#define GL_EDGE_FLAG                        0x0B43
#define GL_CULL_FACE                        0x0B44
#define GL_CULL_FACE_MODE                   0x0B45
#define GL_FRONT_FACE                       0x0B46
#define GL_LIGHTING                         0x0B50
#define GL_LIGHT_MODEL_LOCAL_VIEWER         0x0B51
#define GL_LIGHT_MODEL_TWO_SIDE             0x0B52
#define GL_LIGHT_MODEL_AMBIENT              0x0B53
#define GL_SHADE_MODEL                      0x0B54
#define GL_COLOR_MATERIAL_FACE              0x0B55
#define GL_COLOR_MATERIAL_PARAMETER         0x0B56
#define GL_COLOR_MATERIAL                   0x0B57
#define GL_FOG                              0x0B60
#define GL_FOG_INDEX                        0x0B61
#define GL_FOG_DENSITY                      0x0B62
#define GL_FOG_START                        0x0B63
#define GL_FOG_END                          0x0B64
#define GL_FOG_MODE                         0x0B65
#define GL_FOG_COLOR                        0x0B66
#define GL_DEPTH_RANGE                      0x0B70
#define GL_DEPTH_TEST                       0x0B71
#define GL_DEPTH_WRITEMASK                  0x0B72
#define GL_DEPTH_CLEAR_VALUE                0x0B73
#define GL_DEPTH_FUNC                       0x0B74
#define GL_ACCUM_CLEAR_VALUE                0x0B80
#define GL_STENCIL_TEST                     0x0B90
#define GL_STENCIL_CLEAR_VALUE              0x0B91
#define GL_STENCIL_FUNC                     0x0B92
#define GL_STENCIL_VALUE_MASK               0x0B93
#define GL_STENCIL_FAIL                     0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL          0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS          0x0B96
#define GL_STENCIL_REF                      0x0B97
#define GL_STENCIL_WRITEMASK                0x0B98
#define GL_MATRIX_MODE                      0x0BA0
#define GL_NORMALIZE                        0x0BA1
#define GL_VIEWPORT                         0x0BA2
#define GL_MODELVIEW_STACK_DEPTH            0x0BA3
#define GL_PROJECTION_STACK_DEPTH           0x0BA4
#define GL_TEXTURE_STACK_DEPTH              0x0BA5
#define GL_MODELVIEW_MATRIX                 0x0BA6
#define GL_PROJECTION_MATRIX                0x0BA7
#define GL_TEXTURE_MATRIX                   0x0BA8
#define GL_ATTRIB_STACK_DEPTH               0x0BB0
#define GL_CLIENT_ATTRIB_STACK_DEPTH        0x0BB1
#define GL_ALPHA_TEST                       0x0BC0
#define GL_ALPHA_TEST_FUNC                  0x0BC1
#define GL_ALPHA_TEST_REF                   0x0BC2
#define GL_DITHER                           0x0BD0
#define GL_BLEND_DST                        0x0BE0
#define GL_BLEND_SRC                        0x0BE1
#define GL_BLEND                            0x0BE2
#define GL_LOGIC_OP_MODE                    0x0BF0
#define GL_INDEX_LOGIC_OP                   0x0BF1
#define GL_LOGIC_OP                         0x0BF1
#define GL_COLOR_LOGIC_OP                   0x0BF2
#define GL_AUX_BUFFERS                      0x0C00
#define GL_DRAW_BUFFER                      0x0C01
#define GL_READ_BUFFER                      0x0C02
#define GL_SCISSOR_BOX                      0x0C10
#define GL_SCISSOR_TEST                     0x0C11
#define GL_INDEX_CLEAR_VALUE                0x0C20
#define GL_INDEX_WRITEMASK                  0x0C21
#define GL_COLOR_CLEAR_VALUE                0x0C22
#define GL_COLOR_WRITEMASK                  0x0C23
#define GL_INDEX_MODE                       0x0C30
#define GL_RGBA_MODE                        0x0C31
#define GL_DOUBLEBUFFER                     0x0C32
#define GL_STEREO                           0x0C33
#define GL_RENDER_MODE                      0x0C40
#define GL_PERSPECTIVE_CORRECTION_HINT      0x0C50
#define GL_POINT_SMOOTH_HINT                0x0C51
#define GL_LINE_SMOOTH_HINT                 0x0C52
#define GL_POLYGON_SMOOTH_HINT              0x0C53
#define GL_FOG_HINT                         0x0C54
#define GL_TEXTURE_GEN_S                    0x0C60
#define GL_TEXTURE_GEN_T                    0x0C61
#define GL_TEXTURE_GEN_R                    0x0C62
#define GL_TEXTURE_GEN_Q                    0x0C63
#define GL_PIXEL_MAP_I_TO_I_SIZE            0x0CB0
#define GL_PIXEL_MAP_S_TO_S_SIZE            0x0CB1
#define GL_PIXEL_MAP_I_TO_R_SIZE            0x0CB2
#define GL_PIXEL_MAP_I_TO_G_SIZE            0x0CB3
#define GL_PIXEL_MAP_I_TO_B_SIZE            0x0CB4
#define GL_PIXEL_MAP_I_TO_A_SIZE            0x0CB5
#define GL_PIXEL_MAP_R_TO_R_SIZE            0x0CB6
#define GL_PIXEL_MAP_G_TO_G_SIZE            0x0CB7
#define GL_PIXEL_MAP_B_TO_B_SIZE            0x0CB8
#define GL_PIXEL_MAP_A_TO_A_SIZE            0x0CB9
#define GL_UNPACK_SWAP_BYTES                0x0CF0
#define GL_UNPACK_LSB_FIRST                 0x0CF1
#define GL_UNPACK_ROW_LENGTH                0x0CF2
#define GL_UNPACK_SKIP_ROWS                 0x0CF3
#define GL_UNPACK_SKIP_PIXELS               0x0CF4
#define GL_UNPACK_ALIGNMENT                 0x0CF5
#define GL_PACK_SWAP_BYTES                  0x0D00
#define GL_PACK_LSB_FIRST                   0x0D01
#define GL_PACK_ROW_LENGTH                  0x0D02
#define GL_PACK_SKIP_ROWS                   0x0D03
#define GL_PACK_SKIP_PIXELS                 0x0D04
#define GL_PACK_ALIGNMENT                   0x0D05
#define GL_MAP_COLOR                        0x0D10
#define GL_MAP_STENCIL                      0x0D11
#define GL_INDEX_SHIFT                      0x0D12
#define GL_INDEX_OFFSET                     0x0D13
#define GL_RED_SCALE                        0x0D14
#define GL_RED_BIAS                         0x0D15
#define GL_ZOOM_X                           0x0D16
#define GL_ZOOM_Y                           0x0D17
#define GL_GREEN_SCALE                      0x0D18
#define GL_GREEN_BIAS                       0x0D19
#define GL_BLUE_SCALE                       0x0D1A
#define GL_BLUE_BIAS                        0x0D1B
#define GL_ALPHA_SCALE                      0x0D1C
#define GL_ALPHA_BIAS                       0x0D1D
#define GL_DEPTH_SCALE                      0x0D1E
#define GL_DEPTH_BIAS                       0x0D1F
#define GL_MAX_EVAL_ORDER                   0x0D30
#define GL_MAX_LIGHTS                       0x0D31
#define GL_MAX_CLIP_PLANES                  0x0D32
#define GL_MAX_TEXTURE_SIZE                 0x0D33
#define GL_MAX_PIXEL_MAP_TABLE              0x0D34
#define GL_MAX_ATTRIB_STACK_DEPTH           0x0D35
#define GL_MAX_MODELVIEW_STACK_DEPTH        0x0D36
#define GL_MAX_NAME_STACK_DEPTH             0x0D37
#define GL_MAX_PROJECTION_STACK_DEPTH       0x0D38
#define GL_MAX_TEXTURE_STACK_DEPTH          0x0D39
#define GL_MAX_VIEWPORT_DIMS                0x0D3A
#define GL_MAX_CLIENT_ATTRIB_STACK_DEPTH    0x0D3B
#define GL_SUBPIXEL_BITS                    0x0D50
#define GL_INDEX_BITS                       0x0D51
#define GL_RED_BITS                         0x0D52
#define GL_GREEN_BITS                       0x0D53
#define GL_BLUE_BITS                        0x0D54
#define GL_ALPHA_BITS                       0x0D55
#define GL_DEPTH_BITS                       0x0D56
#define GL_STENCIL_BITS                     0x0D57
#define GL_ACCUM_RED_BITS                   0x0D58
#define GL_ACCUM_GREEN_BITS                 0x0D59
#define GL_ACCUM_BLUE_BITS                  0x0D5A
#define GL_ACCUM_ALPHA_BITS                 0x0D5B
#define GL_NAME_STACK_DEPTH                 0x0D70
#define GL_AUTO_NORMAL                      0x0D80
#define GL_MAP1_COLOR_4                     0x0D90
#define GL_MAP1_INDEX                       0x0D91
#define GL_MAP1_NORMAL                      0x0D92
#define GL_MAP1_TEXTURE_COORD_1             0x0D93
#define GL_MAP1_TEXTURE_COORD_2             0x0D94
#define GL_MAP1_TEXTURE_COORD_3             0x0D95
#define GL_MAP1_TEXTURE_COORD_4             0x0D96
#define GL_MAP1_VERTEX_3                    0x0D97
#define GL_MAP1_VERTEX_4                    0x0D98
#define GL_MAP2_COLOR_4                     0x0DB0
#define GL_MAP2_INDEX                       0x0DB1
#define GL_MAP2_NORMAL                      0x0DB2
#define GL_MAP2_TEXTURE_COORD_1             0x0DB3
#define GL_MAP2_TEXTURE_COORD_2             0x0DB4
#define GL_MAP2_TEXTURE_COORD_3             0x0DB5
#define GL_MAP2_TEXTURE_COORD_4             0x0DB6
#define GL_MAP2_VERTEX_3                    0x0DB7
#define GL_MAP2_VERTEX_4                    0x0DB8
#define GL_MAP1_GRID_DOMAIN                 0x0DD0
#define GL_MAP1_GRID_SEGMENTS               0x0DD1
#define GL_MAP2_GRID_DOMAIN                 0x0DD2
#define GL_MAP2_GRID_SEGMENTS               0x0DD3
#define GL_TEXTURE_1D                       0x0DE0
#define GL_TEXTURE_2D                       0x0DE1
#define GL_FEEDBACK_BUFFER_SIZE             0x0DF1
#define GL_FEEDBACK_BUFFER_TYPE             0x0DF2
#define GL_SELECTION_BUFFER_SIZE            0x0DF4
#define GL_POLYGON_OFFSET_UNITS             0x2A00
#define GL_POLYGON_OFFSET_POINT             0x2A01
#define GL_POLYGON_OFFSET_LINE              0x2A02
#define GL_POLYGON_OFFSET_FILL              0x8037
#define GL_POLYGON_OFFSET_FACTOR            0x8038
#define GL_TEXTURE_BINDING_1D               0x8068
#define GL_TEXTURE_BINDING_2D               0x8069
#define GL_TEXTURE_BINDING_3D               0x806A
#define GL_VERTEX_ARRAY                     0x8074
#define GL_NORMAL_ARRAY                     0x8075
#define GL_COLOR_ARRAY                      0x8076
#define GL_INDEX_ARRAY                      0x8077
#define GL_TEXTURE_COORD_ARRAY              0x8078
#define GL_EDGE_FLAG_ARRAY                  0x8079
#define GL_VERTEX_ARRAY_SIZE                0x807A
#define GL_VERTEX_ARRAY_TYPE                0x807B
#define GL_VERTEX_ARRAY_STRIDE              0x807C
#define GL_NORMAL_ARRAY_TYPE                0x807E
#define GL_NORMAL_ARRAY_STRIDE              0x807F
#define GL_COLOR_ARRAY_SIZE                 0x8081
#define GL_COLOR_ARRAY_TYPE                 0x8082
#define GL_COLOR_ARRAY_STRIDE               0x8083
#define GL_INDEX_ARRAY_TYPE                 0x8085
#define GL_INDEX_ARRAY_STRIDE               0x8086
#define GL_TEXTURE_COORD_ARRAY_SIZE         0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE         0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE       0x808A
#define GL_EDGE_FLAG_ARRAY_STRIDE           0x808C
/*      GL_CLIP_PLANE0 */
/*      GL_CLIP_PLANE1 */
/*      GL_CLIP_PLANE2 */
/*      GL_CLIP_PLANE3 */
/*      GL_CLIP_PLANE4 */
/*      GL_CLIP_PLANE5 */
/*      GL_LIGHT0 */
/*      GL_LIGHT1 */
/*      GL_LIGHT2 */
/*      GL_LIGHT3 */
/*      GL_LIGHT4 */
/*      GL_LIGHT5 */
/*      GL_LIGHT6 */
/*      GL_LIGHT7 */
/*      GL_LIGHT_MODEL_COLOR_CONTROL */
/*      GL_BLEND_COLOR_EXT */
/*      GL_BLEND_EQUATION_EXT */
/*      GL_PACK_CMYK_HINT_EXT */
/*      GL_UNPACK_CMYK_HINT_EXT */
/*      GL_CONVOLUTION_1D_EXT */
/*      GL_CONVOLUTION_2D_EXT */
/*      GL_SEPARABLE_2D_EXT */
/*      GL_POST_CONVOLUTION_RED_SCALE_EXT */
/*      GL_POST_CONVOLUTION_GREEN_SCALE_EXT */
/*      GL_POST_CONVOLUTION_BLUE_SCALE_EXT */
/*      GL_POST_CONVOLUTION_ALPHA_SCALE_EXT */
/*      GL_POST_CONVOLUTION_RED_BIAS_EXT */
/*      GL_POST_CONVOLUTION_GREEN_BIAS_EXT */
/*      GL_POST_CONVOLUTION_BLUE_BIAS_EXT */
/*      GL_POST_CONVOLUTION_ALPHA_BIAS_EXT */
/*      GL_HISTOGRAM_EXT */
/*      GL_MINMAX_EXT */
/*      GL_POLYGON_OFFSET_BIAS_EXT */
/*      GL_RESCALE_NORMAL_EXT */
/*      GL_SHARED_TEXTURE_PALETTE_EXT */
/*      GL_TEXTURE_3D_BINDING_EXT */
/*      GL_PACK_SKIP_IMAGES_EXT */
/*      GL_PACK_IMAGE_HEIGHT_EXT */
/*      GL_UNPACK_SKIP_IMAGES_EXT */
/*      GL_UNPACK_IMAGE_HEIGHT_EXT */
/*      GL_TEXTURE_3D_EXT */
/*      GL_MAX_3D_TEXTURE_SIZE_EXT */
/*      GL_VERTEX_ARRAY_COUNT_EXT */
/*      GL_NORMAL_ARRAY_COUNT_EXT */
/*      GL_COLOR_ARRAY_COUNT_EXT */
/*      GL_INDEX_ARRAY_COUNT_EXT */
/*      GL_TEXTURE_COORD_ARRAY_COUNT_EXT */
/*      GL_EDGE_FLAG_ARRAY_COUNT_EXT */
/*      GL_INTERLACE_READ_INGR */
/*      GL_DETAIL_TEXTURE_2D_BINDING_SGIS */
/*      GL_FOG_FUNC_POINTS_SGIS */
/*      GL_MAX_FOG_FUNC_POINTS_SGIS */
/*      GL_GENERATE_MIPMAP_HINT_SGIS */
/*      GL_MULTISAMPLE_SGIS */
/*      GL_SAMPLE_ALPHA_TO_MASK_SGIS */
/*      GL_SAMPLE_ALPHA_TO_ONE_SGIS */
/*      GL_SAMPLE_MASK_SGIS */
/*      GL_SAMPLE_BUFFERS_SGIS */
/*      GL_SAMPLES_SGIS */
/*      GL_SAMPLE_MASK_VALUE_SGIS */
/*      GL_SAMPLE_MASK_INVERT_SGIS */
/*      GL_SAMPLE_PATTERN_SGIS */
/*      GL_PIXEL_TEXTURE_SGIS */
/*      GL_POINT_SIZE_MIN_SGIS */
/*      GL_POINT_SIZE_MAX_SGIS */
/*      GL_POINT_FADE_THRESHOLD_SIZE_SGIS */
/*      GL_DISTANCE_ATTENUATION_SGIS */
/*      GL_PACK_SKIP_VOLUMES_SGIS */
/*      GL_PACK_IMAGE_DEPTH_SGIS */
/*      GL_UNPACK_SKIP_VOLUMES_SGIS */
/*      GL_UNPACK_IMAGE_DEPTH_SGIS */
/*      GL_TEXTURE_4D_SGIS */
/*      GL_MAX_4D_TEXTURE_SIZE_SGIS */
/*      GL_TEXTURE_4D_BINDING_SGIS */
/*      GL_ASYNC_MARKER_SGIX */
/*      GL_ASYNC_HISTOGRAM_SGIX */
/*      GL_MAX_ASYNC_HISTOGRAM_SGIX */
/*      GL_ASYNC_TEX_IMAGE_SGIX */
/*      GL_ASYNC_DRAW_PIXELS_SGIX */
/*      GL_ASYNC_READ_PIXELS_SGIX */
/*      GL_MAX_ASYNC_TEX_IMAGE_SGIX */
/*      GL_MAX_ASYNC_DRAW_PIXELS_SGIX */
/*      GL_MAX_ASYNC_READ_PIXELS_SGIX */
/*      GL_CALLIGRAPHIC_FRAGMENT_SGIX */
/*      GL_MAX_CLIPMAP_VIRTUAL_DEPTH_SGIX */
/*      GL_MAX_CLIPMAP_DEPTH_SGIX */
/*      GL_CONVOLUTION_HINT_SGIX */
/*      GL_FOG_OFFSET_SGIX */
/*      GL_FOG_OFFSET_VALUE_SGIX */
/*      GL_FRAGMENT_LIGHTING_SGIX */
/*      GL_FRAGMENT_COLOR_MATERIAL_SGIX */
/*      GL_FRAGMENT_COLOR_MATERIAL_FACE_SGIX */
/*      GL_FRAGMENT_COLOR_MATERIAL_PARAMETER_SGIX */
/*      GL_MAX_FRAGMENT_LIGHTS_SGIX */
/*      GL_MAX_ACTIVE_LIGHTS_SGIX */
/*      GL_LIGHT_ENV_MODE_SGIX */
/*      GL_FRAGMENT_LIGHT_MODEL_LOCAL_VIEWER_SGIX */
/*      GL_FRAGMENT_LIGHT_MODEL_TWO_SIDE_SGIX */
/*      GL_FRAGMENT_LIGHT_MODEL_AMBIENT_SGIX */
/*      GL_FRAGMENT_LIGHT_MODEL_NORMAL_INTERPOLATION_SGIX */
/*      GL_FRAGMENT_LIGHT0_SGIX */
/*      GL_FRAMEZOOM_SGIX */
/*      GL_FRAMEZOOM_FACTOR_SGIX */
/*      GL_MAX_FRAMEZOOM_FACTOR_SGIX */
/*      GL_INSTRUMENT_MEASUREMENTS_SGIX */
/*      GL_INTERLACE_SGIX */
/*      GL_IR_INSTRUMENT1_SGIX */
/*      GL_PIXEL_TEX_GEN_SGIX */
/*      GL_PIXEL_TEX_GEN_MODE_SGIX */
/*      GL_PIXEL_TILE_BEST_ALIGNMENT_SGIX */
/*      GL_PIXEL_TILE_CACHE_INCREMENT_SGIX */
/*      GL_PIXEL_TILE_WIDTH_SGIX */
/*      GL_PIXEL_TILE_HEIGHT_SGIX */
/*      GL_PIXEL_TILE_GRID_WIDTH_SGIX */
/*      GL_PIXEL_TILE_GRID_HEIGHT_SGIX */
/*      GL_PIXEL_TILE_GRID_DEPTH_SGIX */
/*      GL_PIXEL_TILE_CACHE_SIZE_SGIX */
/*      GL_DEFORMATIONS_MASK_SGIX */
/*      GL_REFERENCE_PLANE_EQUATION_SGIX */
/*      GL_REFERENCE_PLANE_SGIX */
/*      GL_SCALEBIAS_HINT_SGIX */
/*      GL_SPRITE_SGIX */
/*      GL_SPRITE_MODE_SGIX */
/*      GL_SPRITE_AXIS_SGIX */
/*      GL_SPRITE_TRANSLATION_SGIX */
/*      GL_PACK_SUBSAMPLE_RATE_SGIX */
/*      GL_UNPACK_SUBSAMPLE_RATE_SGIX */
/*      GL_PACK_RESAMPLE_SGIX */
/*      GL_UNPACK_RESAMPLE_SGIX */
/*      GL_POST_TEXTURE_FILTER_BIAS_RANGE_SGIX */
/*      GL_POST_TEXTURE_FILTER_SCALE_RANGE_SGIX */
/*      GL_VERTEX_PRECLIP_SGIX */
/*      GL_VERTEX_PRECLIP_HINT_SGIX */
/*      GL_COLOR_MATRIX_SGI */
/*      GL_COLOR_MATRIX_STACK_DEPTH_SGI */
/*      GL_MAX_COLOR_MATRIX_STACK_DEPTH_SGI */
/*      GL_POST_COLOR_MATRIX_RED_SCALE_SGI */
/*      GL_POST_COLOR_MATRIX_GREEN_SCALE_SGI */
/*      GL_POST_COLOR_MATRIX_BLUE_SCALE_SGI */
/*      GL_POST_COLOR_MATRIX_ALPHA_SCALE_SGI */
/*      GL_POST_COLOR_MATRIX_RED_BIAS_SGI */
/*      GL_POST_COLOR_MATRIX_GREEN_BIAS_SGI */
/*      GL_POST_COLOR_MATRIX_BLUE_BIAS_SGI */
/*      GL_POST_COLOR_MATRIX_ALPHA_BIAS_SGI */
/*      GL_COLOR_TABLE_SGI */
/*      GL_POST_CONVOLUTION_COLOR_TABLE_SGI */
/*      GL_POST_COLOR_MATRIX_COLOR_TABLE_SGI */
/*      GL_TEXTURE_COLOR_TABLE_SGI */

/* GetTextureParameter */
/*      GL_TEXTURE_MAG_FILTER */
/*      GL_TEXTURE_MIN_FILTER */
/*      GL_TEXTURE_WRAP_S */
/*      GL_TEXTURE_WRAP_T */
#define GL_TEXTURE_WIDTH                    0x1000
#define GL_TEXTURE_HEIGHT                   0x1001
#define GL_TEXTURE_INTERNAL_FORMAT          0x1003
#define GL_TEXTURE_COMPONENTS               0x1003
#define GL_TEXTURE_BORDER_COLOR             0x1004
#define GL_TEXTURE_BORDER                   0x1005
#define GL_TEXTURE_RED_SIZE                 0x805C
#define GL_TEXTURE_GREEN_SIZE               0x805D
#define GL_TEXTURE_BLUE_SIZE                0x805E
#define GL_TEXTURE_ALPHA_SIZE               0x805F
#define GL_TEXTURE_LUMINANCE_SIZE           0x8060
#define GL_TEXTURE_INTENSITY_SIZE           0x8061
#define GL_TEXTURE_PRIORITY                 0x8066
#define GL_TEXTURE_RESIDENT                 0x8067
/*      GL_TEXTURE_DEPTH_EXT */
/*      GL_TEXTURE_WRAP_R_EXT */
/*      GL_DETAIL_TEXTURE_LEVEL_SGIS */
/*      GL_DETAIL_TEXTURE_MODE_SGIS */
/*      GL_DETAIL_TEXTURE_FUNC_POINTS_SGIS */
/*      GL_GENERATE_MIPMAP_SGIS */
/*      GL_SHARPEN_TEXTURE_FUNC_POINTS_SGIS */
/*      GL_TEXTURE_FILTER4_SIZE_SGIS */
/*      GL_TEXTURE_MIN_LOD_SGIS */
/*      GL_TEXTURE_MAX_LOD_SGIS */
/*      GL_TEXTURE_BASE_LEVEL_SGIS */
/*      GL_TEXTURE_MAX_LEVEL_SGIS */
/*      GL_DUAL_TEXTURE_SELECT_SGIS */
/*      GL_QUAD_TEXTURE_SELECT_SGIS */
/*      GL_TEXTURE_4DSIZE_SGIS */
/*      GL_TEXTURE_WRAP_Q_SGIS */
/*      GL_TEXTURE_CLIPMAP_CENTER_SGIX */
/*      GL_TEXTURE_CLIPMAP_FRAME_SGIX */
/*      GL_TEXTURE_CLIPMAP_OFFSET_SGIX */
/*      GL_TEXTURE_CLIPMAP_VIRTUAL_DEPTH_SGIX */
/*      GL_TEXTURE_CLIPMAP_LOD_OFFSET_SGIX */
/*      GL_TEXTURE_CLIPMAP_DEPTH_SGIX */
/*      GL_TEXTURE_COMPARE_SGIX */
/*      GL_TEXTURE_COMPARE_OPERATOR_SGIX */
/*      GL_TEXTURE_LEQUAL_R_SGIX */
/*      GL_TEXTURE_GEQUAL_R_SGIX */
/*      GL_SHADOW_AMBIENT_SGIX */
/*      GL_TEXTURE_MAX_CLAMP_S_SGIX */
/*      GL_TEXTURE_MAX_CLAMP_T_SGIX */
/*      GL_TEXTURE_MAX_CLAMP_R_SGIX */
/*      GL_TEXTURE_LOD_BIAS_S_SGIX */
/*      GL_TEXTURE_LOD_BIAS_T_SGIX */
/*      GL_TEXTURE_LOD_BIAS_R_SGIX */
/*      GL_POST_TEXTURE_FILTER_BIAS_SGIX */
/*      GL_POST_TEXTURE_FILTER_SCALE_SGIX */

/* HintMode */
#define GL_DONT_CARE                        0x1100
#define GL_FASTEST                          0x1101
#define GL_NICEST                           0x1102

/* HintTarget */
/*      GL_PERSPECTIVE_CORRECTION_HINT */
/*      GL_POINT_SMOOTH_HINT */
/*      GL_LINE_SMOOTH_HINT */
/*      GL_POLYGON_SMOOTH_HINT */
/*      GL_FOG_HINT */
/*      GL_PACK_CMYK_HINT_EXT */
/*      GL_UNPACK_CMYK_HINT_EXT */
/*      GL_GENERATE_MIPMAP_HINT_SGIS */
/*      GL_CONVOLUTION_HINT_SGIX */
/*      GL_SCALEBIAS_HINT_SGIX */
/*      GL_TEXTURE_MULTI_BUFFER_HINT_SGIX */
/*      GL_VERTEX_PRECLIP_HINT_SGIX */

/* HistogramTargetEXT */
/*      GL_HISTOGRAM_EXT */
/*      GL_PROXY_HISTOGRAM_EXT */

/* IndexPointerType */
/*      GL_SHORT */
/*      GL_INT */
/*      GL_FLOAT */
/*      GL_DOUBLE */

/* LightEnvModeSGIX */
/*      GL_REPLACE */
/*      GL_MODULATE */
/*      GL_ADD */

/* LightEnvParameterSGIX */
/*      GL_LIGHT_ENV_MODE_SGIX */

/* LightModelColorControl */
/*      GL_SINGLE_COLOR */
/*      GL_SEPARATE_SPECULAR_COLOR */

/* LightModelParameter */
/*      GL_LIGHT_MODEL_AMBIENT */
/*      GL_LIGHT_MODEL_LOCAL_VIEWER */
/*      GL_LIGHT_MODEL_TWO_SIDE */
/*      GL_LIGHT_MODEL_COLOR_CONTROL */

/* LightParameter */
#define GL_AMBIENT                          0x1200
#define GL_DIFFUSE                          0x1201
#define GL_SPECULAR                         0x1202
#define GL_POSITION                         0x1203
#define GL_SPOT_DIRECTION                   0x1204
#define GL_SPOT_EXPONENT                    0x1205
#define GL_SPOT_CUTOFF                      0x1206
#define GL_CONSTANT_ATTENUATION             0x1207
#define GL_LINEAR_ATTENUATION               0x1208
#define GL_QUADRATIC_ATTENUATION            0x1209

/* ListMode */
#define GL_COMPILE                          0x1300
#define GL_COMPILE_AND_EXECUTE              0x1301

/* DataType */
#define GL_BYTE                             0x1400
#define GL_UNSIGNED_BYTE                    0x1401
#define GL_SHORT                            0x1402
#define GL_UNSIGNED_SHORT                   0x1403
#define GL_INT                              0x1404
#define GL_UNSIGNED_INT                     0x1405
#define GL_FLOAT                            0x1406
#define GL_2_BYTES                          0x1407
#define GL_3_BYTES                          0x1408
#define GL_4_BYTES                          0x1409
#define GL_DOUBLE                           0x140A
#define GL_DOUBLE_EXT                       0x140A

/* ListNameType */
/*      GL_BYTE */
/*      GL_UNSIGNED_BYTE */
/*      GL_SHORT */
/*      GL_UNSIGNED_SHORT */
/*      GL_INT */
/*      GL_UNSIGNED_INT */
/*      GL_FLOAT */
/*      GL_2_BYTES */
/*      GL_3_BYTES */
/*      GL_4_BYTES */

/* ListParameterName */
/*      GL_LIST_PRIORITY_SGIX */

/* LogicOp */
#define GL_CLEAR                            0x1500
#define GL_AND                              0x1501
#define GL_AND_REVERSE                      0x1502
#define GL_COPY                             0x1503
#define GL_AND_INVERTED                     0x1504
#define GL_NOOP                             0x1505
#define GL_XOR                              0x1506
#define GL_OR                               0x1507
#define GL_NOR                              0x1508
#define GL_EQUIV                            0x1509
#define GL_INVERT                           0x150A
#define GL_OR_REVERSE                       0x150B
#define GL_COPY_INVERTED                    0x150C
#define GL_OR_INVERTED                      0x150D
#define GL_NAND                             0x150E
#define GL_SET                              0x150F

/* MapTarget */
/*      GL_MAP1_COLOR_4 */
/*      GL_MAP1_INDEX */
/*      GL_MAP1_NORMAL */
/*      GL_MAP1_TEXTURE_COORD_1 */
/*      GL_MAP1_TEXTURE_COORD_2 */
/*      GL_MAP1_TEXTURE_COORD_3 */
/*      GL_MAP1_TEXTURE_COORD_4 */
/*      GL_MAP1_VERTEX_3 */
/*      GL_MAP1_VERTEX_4 */
/*      GL_MAP2_COLOR_4 */
/*      GL_MAP2_INDEX */
/*      GL_MAP2_NORMAL */
/*      GL_MAP2_TEXTURE_COORD_1 */
/*      GL_MAP2_TEXTURE_COORD_2 */
/*      GL_MAP2_TEXTURE_COORD_3 */
/*      GL_MAP2_TEXTURE_COORD_4 */
/*      GL_MAP2_VERTEX_3 */
/*      GL_MAP2_VERTEX_4 */
/*      GL_GEOMETRY_DEFORMATION_SGIX */
/*      GL_TEXTURE_DEFORMATION_SGIX */

/* MaterialFace */
/*      GL_FRONT */
/*      GL_BACK */
/*      GL_FRONT_AND_BACK */

/* MaterialParameter */
#define GL_EMISSION                         0x1600
#define GL_SHININESS                        0x1601
#define GL_AMBIENT_AND_DIFFUSE              0x1602
#define GL_COLOR_INDEXES                    0x1603
/*      GL_AMBIENT */
/*      GL_DIFFUSE */
/*      GL_SPECULAR */

/* MatrixMode */
#define GL_MODELVIEW                        0x1700
#define GL_PROJECTION                       0x1701
#define GL_TEXTURE                          0x1702

/* MeshMode1 */
/*      GL_POINT */
/*      GL_LINE */

/* MeshMode2 */
/*      GL_POINT */
/*      GL_LINE */
/*      GL_FILL */

/* MinmaxTargetEXT */
/*      GL_MINMAX_EXT */

/* NormalPointerType */
/*      GL_BYTE */
/*      GL_SHORT */
/*      GL_INT */
/*      GL_FLOAT */
/*      GL_DOUBLE */

/* PixelCopyType */
#define GL_COLOR                            0x1800
#define GL_DEPTH                            0x1801
#define GL_STENCIL                          0x1802

/* PixelFormat */
#define GL_COLOR_INDEX                      0x1900
#define GL_STENCIL_INDEX                    0x1901
#define GL_DEPTH_COMPONENT                  0x1902
#define GL_RED                              0x1903
#define GL_GREEN                            0x1904
#define GL_BLUE                             0x1905
#define GL_ALPHA                            0x1906
#define GL_RGB                              0x1907
#define GL_RGBA                             0x1908
#define GL_LUMINANCE                        0x1909
#define GL_LUMINANCE_ALPHA                  0x190A
/*      GL_ABGR_EXT */
/*      GL_CMYK_EXT */
/*      GL_CMYKA_EXT */
/*      GL_R5_G6_B5_ICC_SGIX */
/*      GL_R5_G6_B5_A8_ICC_SGIX */
/*      GL_ALPHA16_ICC_SGIX */
/*      GL_LUMINANCE16_ICC_SGIX */
/*      GL_LUMINANCE16_ALPHA8_ICC_SGIX */
/*      GL_YCRCB_422_SGIX */
/*      GL_YCRCB_444_SGIX */

/* PixelMap */
/*      GL_PIXEL_MAP_I_TO_I */
/*      GL_PIXEL_MAP_S_TO_S */
/*      GL_PIXEL_MAP_I_TO_R */
/*      GL_PIXEL_MAP_I_TO_G */
/*      GL_PIXEL_MAP_I_TO_B */
/*      GL_PIXEL_MAP_I_TO_A */
/*      GL_PIXEL_MAP_R_TO_R */
/*      GL_PIXEL_MAP_G_TO_G */
/*      GL_PIXEL_MAP_B_TO_B */
/*      GL_PIXEL_MAP_A_TO_A */

/* PixelStoreParameter */
/*      GL_UNPACK_SWAP_BYTES */
/*      GL_UNPACK_LSB_FIRST */
/*      GL_UNPACK_ROW_LENGTH */
/*      GL_UNPACK_SKIP_ROWS */
/*      GL_UNPACK_SKIP_PIXELS */
/*      GL_UNPACK_ALIGNMENT */
/*      GL_PACK_SWAP_BYTES */
/*      GL_PACK_LSB_FIRST */
/*      GL_PACK_ROW_LENGTH */
/*      GL_PACK_SKIP_ROWS */
/*      GL_PACK_SKIP_PIXELS */
/*      GL_PACK_ALIGNMENT */
/*      GL_PACK_SKIP_IMAGES_EXT */
/*      GL_PACK_IMAGE_HEIGHT_EXT */
/*      GL_UNPACK_SKIP_IMAGES_EXT */
/*      GL_UNPACK_IMAGE_HEIGHT_EXT */
/*      GL_PACK_SKIP_VOLUMES_SGIS */
/*      GL_PACK_IMAGE_DEPTH_SGIS */
/*      GL_UNPACK_SKIP_VOLUMES_SGIS */
/*      GL_UNPACK_IMAGE_DEPTH_SGIS */
/*      GL_PIXEL_TILE_WIDTH_SGIX */
/*      GL_PIXEL_TILE_HEIGHT_SGIX */
/*      GL_PIXEL_TILE_GRID_WIDTH_SGIX */
/*      GL_PIXEL_TILE_GRID_HEIGHT_SGIX */
/*      GL_PIXEL_TILE_GRID_DEPTH_SGIX */
/*      GL_PIXEL_TILE_CACHE_SIZE_SGIX */
/*      GL_PACK_SUBSAMPLE_RATE_SGIX */
/*      GL_UNPACK_SUBSAMPLE_RATE_SGIX */
/*      GL_PACK_RESAMPLE_SGIX */
/*      GL_UNPACK_RESAMPLE_SGIX */

/* PixelStoreResampleMode */
/*      GL_RESAMPLE_REPLICATE_SGIX */
/*      GL_RESAMPLE_ZERO_FILL_SGIX */
/*      GL_RESAMPLE_DECIMATE_SGIX */

/* PixelStoreSubsampleRate */
/*      GL_PIXEL_SUBSAMPLE_4444_SGIX */
/*      GL_PIXEL_SUBSAMPLE_2424_SGIX */
/*      GL_PIXEL_SUBSAMPLE_4242_SGIX */

/* PixelTexGenMode */
/*      GL_NONE */
/*      GL_RGB */
/*      GL_RGBA */
/*      GL_LUMINANCE */
/*      GL_LUMINANCE_ALPHA */
/*      GL_PIXEL_TEX_GEN_ALPHA_REPLACE_SGIX */
/*      GL_PIXEL_TEX_GEN_ALPHA_NO_REPLACE_SGIX */
/*      GL_PIXEL_TEX_GEN_ALPHA_MS_SGIX */
/*      GL_PIXEL_TEX_GEN_ALPHA_LS_SGIX */

/* PixelTexGenParameterNameSGIS */
/*      GL_PIXEL_FRAGMENT_RGB_SOURCE_SGIS */
/*      GL_PIXEL_FRAGMENT_ALPHA_SOURCE_SGIS */

/* PixelTransferParameter */
/*      GL_MAP_COLOR */
/*      GL_MAP_STENCIL */
/*      GL_INDEX_SHIFT */
/*      GL_INDEX_OFFSET */
/*      GL_RED_SCALE */
/*      GL_RED_BIAS */
/*      GL_GREEN_SCALE */
/*      GL_GREEN_BIAS */
/*      GL_BLUE_SCALE */
/*      GL_BLUE_BIAS */
/*      GL_ALPHA_SCALE */
/*      GL_ALPHA_BIAS */
/*      GL_DEPTH_SCALE */
/*      GL_DEPTH_BIAS */
/*      GL_POST_CONVOLUTION_RED_SCALE_EXT */
/*      GL_POST_CONVOLUTION_GREEN_SCALE_EXT */
/*      GL_POST_CONVOLUTION_BLUE_SCALE_EXT */
/*      GL_POST_CONVOLUTION_ALPHA_SCALE_EXT */
/*      GL_POST_CONVOLUTION_RED_BIAS_EXT */
/*      GL_POST_CONVOLUTION_GREEN_BIAS_EXT */
/*      GL_POST_CONVOLUTION_BLUE_BIAS_EXT */
/*      GL_POST_CONVOLUTION_ALPHA_BIAS_EXT */
/*      GL_POST_COLOR_MATRIX_RED_SCALE_SGI */
/*      GL_POST_COLOR_MATRIX_GREEN_SCALE_SGI */
/*      GL_POST_COLOR_MATRIX_BLUE_SCALE_SGI */
/*      GL_POST_COLOR_MATRIX_ALPHA_SCALE_SGI */
/*      GL_POST_COLOR_MATRIX_RED_BIAS_SGI */
/*      GL_POST_COLOR_MATRIX_GREEN_BIAS_SGI */
/*      GL_POST_COLOR_MATRIX_BLUE_BIAS_SGI */
/*      GL_POST_COLOR_MATRIX_ALPHA_BIAS_SGI */

/* PixelType */
#define GL_BITMAP                           0x1A00
/*      GL_BYTE */
/*      GL_UNSIGNED_BYTE */
/*      GL_SHORT */
/*      GL_UNSIGNED_SHORT */
/*      GL_INT */
/*      GL_UNSIGNED_INT */
/*      GL_FLOAT */
/*      GL_UNSIGNED_BYTE_3_3_2_EXT */
/*      GL_UNSIGNED_SHORT_4_4_4_4_EXT */
/*      GL_UNSIGNED_SHORT_5_5_5_1_EXT */
/*      GL_UNSIGNED_INT_8_8_8_8_EXT */
/*      GL_UNSIGNED_INT_10_10_10_2_EXT */

/* PointParameterNameSGIS */
/*      GL_POINT_SIZE_MIN_SGIS */
/*      GL_POINT_SIZE_MAX_SGIS */
/*      GL_POINT_FADE_THRESHOLD_SIZE_SGIS */
/*      GL_DISTANCE_ATTENUATION_SGIS */

/* PolygonMode */
#define GL_POINT                            0x1B00
#define GL_LINE                             0x1B01
#define GL_FILL                             0x1B02

/* ReadBufferMode */
/*      GL_FRONT_LEFT */
/*      GL_FRONT_RIGHT */
/*      GL_BACK_LEFT */
/*      GL_BACK_RIGHT */
/*      GL_FRONT */
/*      GL_BACK */
/*      GL_LEFT */
/*      GL_RIGHT */
/*      GL_AUX0 */
/*      GL_AUX1 */
/*      GL_AUX2 */
/*      GL_AUX3 */

/* RenderingMode */
#define GL_RENDER                           0x1C00
#define GL_FEEDBACK                         0x1C01
#define GL_SELECT                           0x1C02

/* SamplePatternPatternSGIS */
/*      GL_1PASS_SGIS */
/*      GL_2PASS_0_SGIS */
/*      GL_2PASS_1_SGIS */
/*      GL_4PASS_0_SGIS */
/*      GL_4PASS_1_SGIS */
/*      GL_4PASS_2_SGIS */
/*      GL_4PASS_3_SGIS */

/* SeparableTargetEXT */
/*      GL_SEPARABLE_2D_EXT */

/* ShadingModel */
#define GL_FLAT                             0x1D00
#define GL_SMOOTH                           0x1D01

/* StencilFunction */
/*      GL_NEVER */
/*      GL_LESS */
/*      GL_EQUAL */
/*      GL_LEQUAL */
/*      GL_GREATER */
/*      GL_NOTEQUAL */
/*      GL_GEQUAL */
/*      GL_ALWAYS */

/* StencilOp */
/*      GL_ZERO */
#define GL_KEEP                             0x1E00
#define GL_REPLACE                          0x1E01
#define GL_INCR                             0x1E02
#define GL_DECR                             0x1E03
/*      GL_INVERT */

/* StringName */
#define GL_VENDOR                           0x1F00
#define GL_RENDERER                         0x1F01
#define GL_VERSION                          0x1F02
#define GL_EXTENSIONS                       0x1F03

/* TexCoordPointerType */
/*      GL_SHORT */
/*      GL_INT */
/*      GL_FLOAT */
/*      GL_DOUBLE */

/* TextureCoordName */
#define GL_S                                0x2000
#define GL_T                                0x2001
#define GL_R                                0x2002
#define GL_Q                                0x2003

/* TextureEnvMode */
#define GL_MODULATE                         0x2100
#define GL_DECAL                            0x2101
/*      GL_BLEND */
/*      GL_REPLACE_EXT */
/*      GL_ADD */
/*      GL_TEXTURE_ENV_BIAS_SGIX */

/* TextureEnvParameter */
#define GL_TEXTURE_ENV_MODE                 0x2200
#define GL_TEXTURE_ENV_COLOR                0x2201

/* TextureEnvTarget */
#define GL_TEXTURE_ENV                      0x2300

/* TextureFilterFuncSGIS */
/*      GL_FILTER4_SGIS */

/* TextureGenMode */
#define GL_EYE_LINEAR                       0x2400
#define GL_OBJECT_LINEAR                    0x2401
#define GL_SPHERE_MAP                       0x2402
/*      GL_EYE_DISTANCE_TO_POINT_SGIS */
/*      GL_OBJECT_DISTANCE_TO_POINT_SGIS */
/*      GL_EYE_DISTANCE_TO_LINE_SGIS */
/*      GL_OBJECT_DISTANCE_TO_LINE_SGIS */

/* TextureGenParameter */
#define GL_TEXTURE_GEN_MODE                 0x2500
#define GL_OBJECT_PLANE                     0x2501
#define GL_EYE_PLANE                        0x2502
/*      GL_EYE_POINT_SGIS */
/*      GL_OBJECT_POINT_SGIS */
/*      GL_EYE_LINE_SGIS */
/*      GL_OBJECT_LINE_SGIS */

/* TextureMagFilter */
#define GL_NEAREST                          0x2600
#define GL_LINEAR                           0x2601
/*      GL_LINEAR_DETAIL_SGIS */
/*      GL_LINEAR_DETAIL_ALPHA_SGIS */
/*      GL_LINEAR_DETAIL_COLOR_SGIS */
/*      GL_LINEAR_SHARPEN_SGIS */
/*      GL_LINEAR_SHARPEN_ALPHA_SGIS */
/*      GL_LINEAR_SHARPEN_COLOR_SGIS */
/*      GL_FILTER4_SGIS */
/*      GL_PIXEL_TEX_GEN_Q_CEILING_SGIX */
/*      GL_PIXEL_TEX_GEN_Q_ROUND_SGIX */
/*      GL_PIXEL_TEX_GEN_Q_FLOOR_SGIX */

/* TextureMinFilter */
/*      GL_NEAREST */
/*      GL_LINEAR */
#define GL_NEAREST_MIPMAP_NEAREST           0x2700
#define GL_LINEAR_MIPMAP_NEAREST            0x2701
#define GL_NEAREST_MIPMAP_LINEAR            0x2702
#define GL_LINEAR_MIPMAP_LINEAR             0x2703
/*      GL_FILTER4_SGIS */
/*      GL_LINEAR_CLIPMAP_LINEAR_SGIX */
/*      GL_NEAREST_CLIPMAP_NEAREST_SGIX */
/*      GL_NEAREST_CLIPMAP_LINEAR_SGIX */
/*      GL_LINEAR_CLIPMAP_NEAREST_SGIX */
/*      GL_PIXEL_TEX_GEN_Q_CEILING_SGIX */
/*      GL_PIXEL_TEX_GEN_Q_ROUND_SGIX */
/*      GL_PIXEL_TEX_GEN_Q_FLOOR_SGIX */

/* TextureParameterName */
#define GL_TEXTURE_MAG_FILTER               0x2800
#define GL_TEXTURE_MIN_FILTER               0x2801
#define GL_TEXTURE_WRAP_S                   0x2802
#define GL_TEXTURE_WRAP_T                   0x2803
/*      GL_TEXTURE_BORDER_COLOR */
/*      GL_TEXTURE_PRIORITY */
/*      GL_TEXTURE_WRAP_R_EXT */
/*      GL_DETAIL_TEXTURE_LEVEL_SGIS */
/*      GL_DETAIL_TEXTURE_MODE_SGIS */
/*      GL_GENERATE_MIPMAP_SGIS */
/*      GL_DUAL_TEXTURE_SELECT_SGIS */
/*      GL_QUAD_TEXTURE_SELECT_SGIS */
/*      GL_TEXTURE_WRAP_Q_SGIS */
/*      GL_TEXTURE_CLIPMAP_CENTER_SGIX */
/*      GL_TEXTURE_CLIPMAP_FRAME_SGIX */
/*      GL_TEXTURE_CLIPMAP_OFFSET_SGIX */
/*      GL_TEXTURE_CLIPMAP_VIRTUAL_DEPTH_SGIX */
/*      GL_TEXTURE_CLIPMAP_LOD_OFFSET_SGIX */
/*      GL_TEXTURE_CLIPMAP_DEPTH_SGIX */
/*      GL_TEXTURE_COMPARE_SGIX */
/*      GL_TEXTURE_COMPARE_OPERATOR_SGIX */
/*      GL_SHADOW_AMBIENT_SGIX */
/*      GL_TEXTURE_MAX_CLAMP_S_SGIX */
/*      GL_TEXTURE_MAX_CLAMP_T_SGIX */
/*      GL_TEXTURE_MAX_CLAMP_R_SGIX */
/*      GL_TEXTURE_LOD_BIAS_S_SGIX */
/*      GL_TEXTURE_LOD_BIAS_T_SGIX */
/*      GL_TEXTURE_LOD_BIAS_R_SGIX */
/*      GL_POST_TEXTURE_FILTER_BIAS_SGIX */
/*      GL_POST_TEXTURE_FILTER_SCALE_SGIX */

/* TextureTarget */
/*      GL_TEXTURE_1D */
/*      GL_TEXTURE_2D */
#define GL_PROXY_TEXTURE_1D                 0x8063
#define GL_PROXY_TEXTURE_2D                 0x8064
/*      GL_TEXTURE_3D_EXT */
/*      GL_PROXY_TEXTURE_3D_EXT */
/*      GL_DETAIL_TEXTURE_2D_SGIS */
/*      GL_TEXTURE_4D_SGIS */
/*      GL_PROXY_TEXTURE_4D_SGIS */
/*      GL_TEXTURE_MIN_LOD_SGIS */
/*      GL_TEXTURE_MAX_LOD_SGIS */
/*      GL_TEXTURE_BASE_LEVEL_SGIS */
/*      GL_TEXTURE_MAX_LEVEL_SGIS */

/* TextureWrapMode */
#define GL_CLAMP                            0x2900
#define GL_REPEAT                           0x2901
/*      GL_CLAMP_TO_BORDER_SGIS */
/*      GL_CLAMP_TO_EDGE_SGIS */

/* PixelInternalFormat */
#define GL_R3_G3_B2                         0x2A10
#define GL_ALPHA4                           0x803B
#define GL_ALPHA8                           0x803C
#define GL_ALPHA12                          0x803D
#define GL_ALPHA16                          0x803E
#define GL_LUMINANCE4                       0x803F
#define GL_LUMINANCE8                       0x8040
#define GL_LUMINANCE12                      0x8041
#define GL_LUMINANCE16                      0x8042
#define GL_LUMINANCE4_ALPHA4                0x8043
#define GL_LUMINANCE6_ALPHA2                0x8044
#define GL_LUMINANCE8_ALPHA8                0x8045
#define GL_LUMINANCE12_ALPHA4               0x8046
#define GL_LUMINANCE12_ALPHA12              0x8047
#define GL_LUMINANCE16_ALPHA16              0x8048
#define GL_INTENSITY                        0x8049
#define GL_INTENSITY4                       0x804A
#define GL_INTENSITY8                       0x804B
#define GL_INTENSITY12                      0x804C
#define GL_INTENSITY16                      0x804D
#define GL_RGB4                             0x804F
#define GL_RGB5                             0x8050
#define GL_RGB8                             0x8051
#define GL_RGB10                            0x8052
#define GL_RGB12                            0x8053
#define GL_RGB16                            0x8054
#define GL_RGBA2                            0x8055
#define GL_RGBA4                            0x8056
#define GL_RGB5_A1                          0x8057
#define GL_RGBA8                            0x8058
#define GL_RGB10_A2                         0x8059
#define GL_RGBA12                           0x805A
#define GL_RGBA16                           0x805B
/*      GL_RGB2_EXT */
/*      GL_DUAL_ALPHA4_SGIS */
/*      GL_DUAL_ALPHA8_SGIS */
/*      GL_DUAL_ALPHA12_SGIS */
/*      GL_DUAL_ALPHA16_SGIS */
/*      GL_DUAL_LUMINANCE4_SGIS */
/*      GL_DUAL_LUMINANCE8_SGIS */
/*      GL_DUAL_LUMINANCE12_SGIS */
/*      GL_DUAL_LUMINANCE16_SGIS */
/*      GL_DUAL_INTENSITY4_SGIS */
/*      GL_DUAL_INTENSITY8_SGIS */
/*      GL_DUAL_INTENSITY12_SGIS */
/*      GL_DUAL_INTENSITY16_SGIS */
/*      GL_DUAL_LUMINANCE_ALPHA4_SGIS */
/*      GL_DUAL_LUMINANCE_ALPHA8_SGIS */
/*      GL_QUAD_ALPHA4_SGIS */
/*      GL_QUAD_ALPHA8_SGIS */
/*      GL_QUAD_LUMINANCE4_SGIS */
/*      GL_QUAD_LUMINANCE8_SGIS */
/*      GL_QUAD_INTENSITY4_SGIS */
/*      GL_QUAD_INTENSITY8_SGIS */
/*      GL_DEPTH_COMPONENT16_SGIX */
/*      GL_DEPTH_COMPONENT24_SGIX */
/*      GL_DEPTH_COMPONENT32_SGIX */
/*      GL_RGB_ICC_SGIX */
/*      GL_RGBA_ICC_SGIX */
/*      GL_ALPHA_ICC_SGIX */
/*      GL_LUMINANCE_ICC_SGIX */
/*      GL_INTENSITY_ICC_SGIX */
/*      GL_LUMINANCE_ALPHA_ICC_SGIX */
/*      GL_R5_G6_B5_ICC_SGIX */
/*      GL_R5_G6_B5_A8_ICC_SGIX */
/*      GL_ALPHA16_ICC_SGIX */
/*      GL_LUMINANCE16_ICC_SGIX */
/*      GL_INTENSITY16_ICC_SGIX */
/*      GL_LUMINANCE16_ALPHA8_ICC_SGIX */

/* InterleavedArrayFormat */
#define GL_V2F                              0x2A20
#define GL_V3F                              0x2A21
#define GL_C4UB_V2F                         0x2A22
#define GL_C4UB_V3F                         0x2A23
#define GL_C3F_V3F                          0x2A24
#define GL_N3F_V3F                          0x2A25
#define GL_C4F_N3F_V3F                      0x2A26
#define GL_T2F_V3F                          0x2A27
#define GL_T4F_V4F                          0x2A28
#define GL_T2F_C4UB_V3F                     0x2A29
#define GL_T2F_C3F_V3F                      0x2A2A
#define GL_T2F_N3F_V3F                      0x2A2B
#define GL_T2F_C4F_N3F_V3F                  0x2A2C
#define GL_T4F_C4F_N3F_V4F                  0x2A2D

/* VertexPointerType */
/*      GL_SHORT */
/*      GL_INT */
/*      GL_FLOAT */
/*      GL_DOUBLE */

/* ClipPlaneName */
#define GL_CLIP_PLANE0                      0x3000
#define GL_CLIP_PLANE1                      0x3001
#define GL_CLIP_PLANE2                      0x3002
#define GL_CLIP_PLANE3                      0x3003
#define GL_CLIP_PLANE4                      0x3004
#define GL_CLIP_PLANE5                      0x3005

/* LightName */
#define GL_LIGHT0                           0x4000
#define GL_LIGHT1                           0x4001
#define GL_LIGHT2                           0x4002
#define GL_LIGHT3                           0x4003
#define GL_LIGHT4                           0x4004
#define GL_LIGHT5                           0x4005
#define GL_LIGHT6                           0x4006
#define GL_LIGHT7                           0x4007
/*      GL_FRAGMENT_LIGHT0_SGIX */
/*      GL_FRAGMENT_LIGHT1_SGIX */
/*      GL_FRAGMENT_LIGHT2_SGIX */
/*      GL_FRAGMENT_LIGHT3_SGIX */
/*      GL_FRAGMENT_LIGHT4_SGIX */
/*      GL_FRAGMENT_LIGHT5_SGIX */
/*      GL_FRAGMENT_LIGHT6_SGIX */
/*      GL_FRAGMENT_LIGHT7_SGIX */

/* EXT_abgr */
#define GL_ABGR_EXT                         0x8000

/* EXT_blend_color */
#define GL_CONSTANT_COLOR                   0x8001
#define GL_CONSTANT_COLOR_EXT               0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR         0x8002
#define GL_ONE_MINUS_CONSTANT_COLOR_EXT     0x8002
#define GL_CONSTANT_ALPHA                   0x8003
#define GL_CONSTANT_ALPHA_EXT               0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA         0x8004
#define GL_ONE_MINUS_CONSTANT_ALPHA_EXT     0x8004
#define GL_BLEND_COLOR                      0x8005
#define GL_BLEND_COLOR_EXT                  0x8005

/* EXT_blend_minmax */
#define GL_FUNC_ADD                         0x8006
#define GL_FUNC_ADD_EXT                     0x8006
#define GL_MIN                              0x8007
#define GL_MIN_EXT                          0x8007
#define GL_MAX                              0x8008
#define GL_MAX_EXT                          0x8008
#define GL_BLEND_EQUATION                   0x8009
#define GL_BLEND_EQUATION_EXT               0x8009

/* EXT_blend_subtract */
#define GL_FUNC_SUBTRACT                    0x800A
#define GL_FUNC_SUBTRACT_EXT                0x800A
#define GL_FUNC_REVERSE_SUBTRACT            0x800B
#define GL_FUNC_REVERSE_SUBTRACT_EXT        0x800B

/* EXT_cmyka */
#define GL_CMYK_EXT                         0x800C
#define GL_CMYKA_EXT                        0x800D
#define GL_PACK_CMYK_HINT_EXT               0x800E
#define GL_UNPACK_CMYK_HINT_EXT             0x800F

/* EXT_convolution */
#define GL_CONVOLUTION_1D                   0x8010
#define GL_CONVOLUTION_1D_EXT               0x8010
#define GL_CONVOLUTION_2D                   0x8011
#define GL_CONVOLUTION_2D_EXT               0x8011
#define GL_SEPARABLE_2D                     0x8012
#define GL_SEPARABLE_2D_EXT                 0x8012
#define GL_CONVOLUTION_BORDER_MODE          0x8013
#define GL_CONVOLUTION_BORDER_MODE_EXT      0x8013
#define GL_CONVOLUTION_FILTER_SCALE         0x8014
#define GL_CONVOLUTION_FILTER_SCALE_EXT     0x8014
#define GL_CONVOLUTION_FILTER_BIAS          0x8015
#define GL_CONVOLUTION_FILTER_BIAS_EXT      0x8015
#define GL_REDUCE                           0x8016
#define GL_REDUCE_EXT                       0x8016
#define GL_CONVOLUTION_FORMAT               0x8017
#define GL_CONVOLUTION_FORMAT_EXT           0x8017
#define GL_CONVOLUTION_WIDTH                0x8018
#define GL_CONVOLUTION_WIDTH_EXT            0x8018
#define GL_CONVOLUTION_HEIGHT               0x8019
#define GL_CONVOLUTION_HEIGHT_EXT           0x8019
#define GL_MAX_CONVOLUTION_WIDTH            0x801A
#define GL_MAX_CONVOLUTION_WIDTH_EXT        0x801A
#define GL_MAX_CONVOLUTION_HEIGHT           0x801B
#define GL_MAX_CONVOLUTION_HEIGHT_EXT       0x801B
#define GL_POST_CONVOLUTION_RED_SCALE       0x801C
#define GL_POST_CONVOLUTION_RED_SCALE_EXT   0x801C
#define GL_POST_CONVOLUTION_GREEN_SCALE     0x801D
#define GL_POST_CONVOLUTION_GREEN_SCALE_EXT 0x801D
#define GL_POST_CONVOLUTION_BLUE_SCALE      0x801E
#define GL_POST_CONVOLUTION_BLUE_SCALE_EXT  0x801E
#define GL_POST_CONVOLUTION_ALPHA_SCALE     0x801F
#define GL_POST_CONVOLUTION_ALPHA_SCALE_EXT 0x801F
#define GL_POST_CONVOLUTION_RED_BIAS        0x8020
#define GL_POST_CONVOLUTION_RED_BIAS_EXT    0x8020
#define GL_POST_CONVOLUTION_GREEN_BIAS      0x8021
#define GL_POST_CONVOLUTION_GREEN_BIAS_EXT  0x8021
#define GL_POST_CONVOLUTION_BLUE_BIAS       0x8022
#define GL_POST_CONVOLUTION_BLUE_BIAS_EXT   0x8022
#define GL_POST_CONVOLUTION_ALPHA_BIAS      0x8023
#define GL_POST_CONVOLUTION_ALPHA_BIAS_EXT  0x8023

/* EXT_histogram */
#define GL_HISTOGRAM                        0x8024
#define GL_HISTOGRAM_EXT                    0x8024
#define GL_PROXY_HISTOGRAM                  0x8025
#define GL_PROXY_HISTOGRAM_EXT              0x8025
#define GL_HISTOGRAM_WIDTH                  0x8026
#define GL_HISTOGRAM_WIDTH_EXT              0x8026
#define GL_HISTOGRAM_FORMAT                 0x8027
#define GL_HISTOGRAM_FORMAT_EXT             0x8027
#define GL_HISTOGRAM_RED_SIZE               0x8028
#define GL_HISTOGRAM_RED_SIZE_EXT           0x8028
#define GL_HISTOGRAM_GREEN_SIZE             0x8029
#define GL_HISTOGRAM_GREEN_SIZE_EXT         0x8029
#define GL_HISTOGRAM_BLUE_SIZE              0x802A
#define GL_HISTOGRAM_BLUE_SIZE_EXT          0x802A
#define GL_HISTOGRAM_ALPHA_SIZE             0x802B
#define GL_HISTOGRAM_ALPHA_SIZE_EXT         0x802B
#define GL_HISTOGRAM_LUMINANCE_SIZE         0x802C
#define GL_HISTOGRAM_LUMINANCE_SIZE_EXT     0x802C
#define GL_HISTOGRAM_SINK                   0x802D
#define GL_HISTOGRAM_SINK_EXT               0x802D
#define GL_MINMAX                           0x802E
#define GL_MINMAX_EXT                       0x802E
#define GL_MINMAX_FORMAT                    0x802F
#define GL_MINMAX_FORMAT_EXT                0x802F
#define GL_MINMAX_SINK                      0x8030
#define GL_MINMAX_SINK_EXT                  0x8030
#define GL_TABLE_TOO_LARGE                  0x8031
#define GL_TABLE_TOO_LARGE_EXT              0x8031

/* EXT_packed_pixels */
#define GL_UNSIGNED_BYTE_3_3_2              0x8032
#define GL_UNSIGNED_BYTE_3_3_2_EXT          0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4           0x8033
#define GL_UNSIGNED_SHORT_4_4_4_4_EXT       0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1           0x8034
#define GL_UNSIGNED_SHORT_5_5_5_1_EXT       0x8034
#define GL_UNSIGNED_INT_8_8_8_8             0x8035
#define GL_UNSIGNED_INT_8_8_8_8_EXT         0x8035
#define GL_UNSIGNED_INT_10_10_10_2          0x8036
#define GL_UNSIGNED_INT_10_10_10_2_EXT      0x8036
#define GL_UNSIGNED_BYTE_2_3_3_REV          0x8362
#define GL_UNSIGNED_BYTE_2_3_3_REV_EXT      0x8362
#define GL_UNSIGNED_SHORT_5_6_5             0x8363
#define GL_UNSIGNED_SHORT_5_6_5_EXT         0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV         0x8364
#define GL_UNSIGNED_SHORT_5_6_5_REV_EXT     0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4_REV       0x8365
#define GL_UNSIGNED_SHORT_4_4_4_4_REV_EXT   0x8365
#define GL_UNSIGNED_SHORT_1_5_5_5_REV       0x8366
#define GL_UNSIGNED_SHORT_1_5_5_5_REV_EXT   0x8366
#define GL_UNSIGNED_INT_8_8_8_8_REV         0x8367
#define GL_UNSIGNED_INT_8_8_8_8_REV_EXT     0x8367
#define GL_UNSIGNED_INT_2_10_10_10_REV      0x8368
#define GL_UNSIGNED_INT_2_10_10_10_REV_EXT  0x8368

/* EXT_polygon_offset */
#define GL_POLYGON_OFFSET_EXT               0x8037
#define GL_POLYGON_OFFSET_FACTOR_EXT        0x8038
#define GL_POLYGON_OFFSET_BIAS_EXT          0x8039

/* EXT_rescale_normal */
#define GL_RESCALE_NORMAL                   0x803A
#define GL_RESCALE_NORMAL_EXT               0x803A

/* EXT_texture */
#define GL_ALPHA4_EXT                       0x803B
#define GL_ALPHA8_EXT                       0x803C
#define GL_ALPHA12_EXT                      0x803D
#define GL_ALPHA16_EXT                      0x803E
#define GL_LUMINANCE4_EXT                   0x803F
#define GL_LUMINANCE8_EXT                   0x8040
#define GL_LUMINANCE12_EXT                  0x8041
#define GL_LUMINANCE16_EXT                  0x8042
#define GL_LUMINANCE4_ALPHA4_EXT            0x8043
#define GL_LUMINANCE6_ALPHA2_EXT            0x8044
#define GL_LUMINANCE8_ALPHA8_EXT            0x8045
#define GL_LUMINANCE12_ALPHA4_EXT           0x8046
#define GL_LUMINANCE12_ALPHA12_EXT          0x8047
#define GL_LUMINANCE16_ALPHA16_EXT          0x8048
#define GL_INTENSITY_EXT                    0x8049
#define GL_INTENSITY4_EXT                   0x804A
#define GL_INTENSITY8_EXT                   0x804B
#define GL_INTENSITY12_EXT                  0x804C
#define GL_INTENSITY16_EXT                  0x804D
#define GL_RGB2_EXT                         0x804E
#define GL_RGB4_EXT                         0x804F
#define GL_RGB5_EXT                         0x8050
#define GL_RGB8_EXT                         0x8051
#define GL_RGB10_EXT                        0x8052
#define GL_RGB12_EXT                        0x8053
#define GL_RGB16_EXT                        0x8054
#define GL_RGBA2_EXT                        0x8055
#define GL_RGBA4_EXT                        0x8056
#define GL_RGB5_A1_EXT                      0x8057
#define GL_RGBA8_EXT                        0x8058
#define GL_RGB10_A2_EXT                     0x8059
#define GL_RGBA12_EXT                       0x805A
#define GL_RGBA16_EXT                       0x805B
#define GL_TEXTURE_RED_SIZE_EXT             0x805C
#define GL_TEXTURE_GREEN_SIZE_EXT           0x805D
#define GL_TEXTURE_BLUE_SIZE_EXT            0x805E
#define GL_TEXTURE_ALPHA_SIZE_EXT           0x805F
#define GL_TEXTURE_LUMINANCE_SIZE_EXT       0x8060
#define GL_TEXTURE_INTENSITY_SIZE_EXT       0x8061
#define GL_REPLACE_EXT                      0x8062
#define GL_PROXY_TEXTURE_1D_EXT             0x8063
#define GL_PROXY_TEXTURE_2D_EXT             0x8064
#define GL_TEXTURE_TOO_LARGE_EXT            0x8065

/* EXT_texture_object */
#define GL_TEXTURE_PRIORITY_EXT             0x8066
#define GL_TEXTURE_RESIDENT_EXT             0x8067
#define GL_TEXTURE_1D_BINDING_EXT           0x8068
#define GL_TEXTURE_2D_BINDING_EXT           0x8069
#define GL_TEXTURE_3D_BINDING_EXT           0x806A

/* EXT_texture3D */
#define GL_PACK_SKIP_IMAGES                 0x806B
#define GL_PACK_SKIP_IMAGES_EXT             0x806B
#define GL_PACK_IMAGE_HEIGHT                0x806C
#define GL_PACK_IMAGE_HEIGHT_EXT            0x806C
#define GL_UNPACK_SKIP_IMAGES               0x806D
#define GL_UNPACK_SKIP_IMAGES_EXT           0x806D
#define GL_UNPACK_IMAGE_HEIGHT              0x806E
#define GL_UNPACK_IMAGE_HEIGHT_EXT          0x806E
#define GL_TEXTURE_3D                       0x806F
#define GL_TEXTURE_3D_EXT                   0x806F
#define GL_PROXY_TEXTURE_3D                 0x8070
#define GL_PROXY_TEXTURE_3D_EXT             0x8070
#define GL_TEXTURE_DEPTH                    0x8071
#define GL_TEXTURE_DEPTH_EXT                0x8071
#define GL_TEXTURE_WRAP_R                   0x8072
#define GL_TEXTURE_WRAP_R_EXT               0x8072
#define GL_MAX_3D_TEXTURE_SIZE              0x8073
#define GL_MAX_3D_TEXTURE_SIZE_EXT          0x8073

/* EXT_vertex_array */
#define GL_VERTEX_ARRAY_EXT                 0x8074
#define GL_NORMAL_ARRAY_EXT                 0x8075
#define GL_COLOR_ARRAY_EXT                  0x8076
#define GL_INDEX_ARRAY_EXT                  0x8077
#define GL_TEXTURE_COORD_ARRAY_EXT          0x8078
#define GL_EDGE_FLAG_ARRAY_EXT              0x8079
#define GL_VERTEX_ARRAY_SIZE_EXT            0x807A
#define GL_VERTEX_ARRAY_TYPE_EXT            0x807B
#define GL_VERTEX_ARRAY_STRIDE_EXT          0x807C
#define GL_VERTEX_ARRAY_COUNT_EXT           0x807D
#define GL_NORMAL_ARRAY_TYPE_EXT            0x807E
#define GL_NORMAL_ARRAY_STRIDE_EXT          0x807F
#define GL_NORMAL_ARRAY_COUNT_EXT           0x8080
#define GL_COLOR_ARRAY_SIZE_EXT             0x8081
#define GL_COLOR_ARRAY_TYPE_EXT             0x8082
#define GL_COLOR_ARRAY_STRIDE_EXT           0x8083
#define GL_COLOR_ARRAY_COUNT_EXT            0x8084
#define GL_INDEX_ARRAY_TYPE_EXT             0x8085
#define GL_INDEX_ARRAY_STRIDE_EXT           0x8086
#define GL_INDEX_ARRAY_COUNT_EXT            0x8087
#define GL_TEXTURE_COORD_ARRAY_SIZE_EXT     0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE_EXT     0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE_EXT   0x808A
#define GL_TEXTURE_COORD_ARRAY_COUNT_EXT    0x808B
#define GL_EDGE_FLAG_ARRAY_STRIDE_EXT       0x808C
#define GL_EDGE_FLAG_ARRAY_COUNT_EXT        0x808D
#define GL_VERTEX_ARRAY_POINTER_EXT         0x808E
#define GL_NORMAL_ARRAY_POINTER_EXT         0x808F
#define GL_COLOR_ARRAY_POINTER_EXT          0x8090
#define GL_INDEX_ARRAY_POINTER_EXT          0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER_EXT  0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER_EXT      0x8093

/* SGIX_interlace */
#define GL_INTERLACE_SGIX                   0x8094

/* SGIS_detail_texture */
#define GL_DETAIL_TEXTURE_2D_SGIS           0x8095
#define GL_DETAIL_TEXTURE_2D_BINDING_SGIS   0x8096
#define GL_LINEAR_DETAIL_SGIS               0x8097
#define GL_LINEAR_DETAIL_ALPHA_SGIS         0x8098
#define GL_LINEAR_DETAIL_COLOR_SGIS         0x8099
#define GL_DETAIL_TEXTURE_LEVEL_SGIS        0x809A
#define GL_DETAIL_TEXTURE_MODE_SGIS         0x809B
#define GL_DETAIL_TEXTURE_FUNC_POINTS_SGIS  0x809C

/* SGIS_multisample */
#define GL_MULTISAMPLE_SGIS                 0x809D
#define GL_SAMPLE_ALPHA_TO_MASK_SGIS        0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_SGIS         0x809F
#define GL_SAMPLE_MASK_SGIS                 0x80A0
#define GL_1PASS_SGIS                       0x80A1
#define GL_2PASS_0_SGIS                     0x80A2
#define GL_2PASS_1_SGIS                     0x80A3
#define GL_4PASS_0_SGIS                     0x80A4
#define GL_4PASS_1_SGIS                     0x80A5
#define GL_4PASS_2_SGIS                     0x80A6
#define GL_4PASS_3_SGIS                     0x80A7
#define GL_SAMPLE_BUFFERS_SGIS              0x80A8
#define GL_SAMPLES_SGIS                     0x80A9
#define GL_SAMPLE_MASK_VALUE_SGIS           0x80AA
#define GL_SAMPLE_MASK_INVERT_SGIS          0x80AB
#define GL_SAMPLE_PATTERN_SGIS              0x80AC

/* SGIS_sharpen_texture */
#define GL_LINEAR_SHARPEN_SGIS              0x80AD
#define GL_LINEAR_SHARPEN_ALPHA_SGIS        0x80AE
#define GL_LINEAR_SHARPEN_COLOR_SGIS        0x80AF
#define GL_SHARPEN_TEXTURE_FUNC_POINTS_SGIS 0x80B0

/* SGI_color_matrix */
#define GL_COLOR_MATRIX                     0x80B1
#define GL_COLOR_MATRIX_SGI                 0x80B1
#define GL_COLOR_MATRIX_STACK_DEPTH         0x80B2
#define GL_COLOR_MATRIX_STACK_DEPTH_SGI     0x80B2
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH     0x80B3
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH_SGI 0x80B3
#define GL_POST_COLOR_MATRIX_RED_SCALE      0x80B4
#define GL_POST_COLOR_MATRIX_RED_SCALE_SGI  0x80B4
#define GL_POST_COLOR_MATRIX_GREEN_SCALE    0x80B5
#define GL_POST_COLOR_MATRIX_GREEN_SCALE_SGI 0x80B5
#define GL_POST_COLOR_MATRIX_BLUE_SCALE     0x80B6
#define GL_POST_COLOR_MATRIX_BLUE_SCALE_SGI 0x80B6
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE    0x80B7
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE_SGI 0x80B7
#define GL_POST_COLOR_MATRIX_RED_BIAS       0x80B8
#define GL_POST_COLOR_MATRIX_RED_BIAS_SGI   0x80B8
#define GL_POST_COLOR_MATRIX_GREEN_BIAS     0x80B9
#define GL_POST_COLOR_MATRIX_GREEN_BIAS_SGI 0x80B9
#define GL_POST_COLOR_MATRIX_BLUE_BIAS      0x80BA
#define GL_POST_COLOR_MATRIX_BLUE_BIAS_SGI  0x80BA
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS     0x80BB
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS_SGI 0x80BB

/* SGI_texture_color_table */
#define GL_TEXTURE_COLOR_TABLE_SGI          0x80BC
#define GL_PROXY_TEXTURE_COLOR_TABLE_SGI    0x80BD

/* SGIX_texture_add_env */
#define GL_TEXTURE_ENV_BIAS_SGIX            0x80BE

/* SGIX_shadow_ambient */
#define GL_SHADOW_AMBIENT_SGIX              0x80BF

/* SGI_color_table */
#define GL_COLOR_TABLE                      0x80D0
#define GL_COLOR_TABLE_SGI                  0x80D0
#define GL_POST_CONVOLUTION_COLOR_TABLE     0x80D1
#define GL_POST_CONVOLUTION_COLOR_TABLE_SGI 0x80D1
#define GL_POST_COLOR_MATRIX_COLOR_TABLE    0x80D2
#define GL_POST_COLOR_MATRIX_COLOR_TABLE_SGI 0x80D2
#define GL_PROXY_COLOR_TABLE                0x80D3
#define GL_PROXY_COLOR_TABLE_SGI            0x80D3
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE 0x80D4
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE_SGI 0x80D4
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE 0x80D5
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE_SGI 0x80D5
#define GL_COLOR_TABLE_SCALE                0x80D6
#define GL_COLOR_TABLE_SCALE_SGI            0x80D6
#define GL_COLOR_TABLE_BIAS                 0x80D7
#define GL_COLOR_TABLE_BIAS_SGI             0x80D7
#define GL_COLOR_TABLE_FORMAT               0x80D8
#define GL_COLOR_TABLE_FORMAT_SGI           0x80D8
#define GL_COLOR_TABLE_WIDTH                0x80D9
#define GL_COLOR_TABLE_WIDTH_SGI            0x80D9
#define GL_COLOR_TABLE_RED_SIZE             0x80DA
#define GL_COLOR_TABLE_RED_SIZE_SGI         0x80DA
#define GL_COLOR_TABLE_GREEN_SIZE           0x80DB
#define GL_COLOR_TABLE_GREEN_SIZE_SGI       0x80DB
#define GL_COLOR_TABLE_BLUE_SIZE            0x80DC
#define GL_COLOR_TABLE_BLUE_SIZE_SGI        0x80DC
#define GL_COLOR_TABLE_ALPHA_SIZE           0x80DD
#define GL_COLOR_TABLE_ALPHA_SIZE_SGI       0x80DD
#define GL_COLOR_TABLE_LUMINANCE_SIZE       0x80DE
#define GL_COLOR_TABLE_LUMINANCE_SIZE_SGI   0x80DE
#define GL_COLOR_TABLE_INTENSITY_SIZE       0x80DF
#define GL_COLOR_TABLE_INTENSITY_SIZE_SGI   0x80DF

/* VERSION_1_2 */
#define GL_BGR                              0x80E0
#define GL_BGRA                             0x80E1

/* VERSION_1_2 */
#define GL_MAX_ELEMENTS_VERTICES            0x80E8
#define GL_MAX_ELEMENTS_INDICES             0x80E9

/* SGIS_texture_select */
#define GL_DUAL_ALPHA4_SGIS                 0x8110
#define GL_DUAL_ALPHA8_SGIS                 0x8111
#define GL_DUAL_ALPHA12_SGIS                0x8112
#define GL_DUAL_ALPHA16_SGIS                0x8113
#define GL_DUAL_LUMINANCE4_SGIS             0x8114
#define GL_DUAL_LUMINANCE8_SGIS             0x8115
#define GL_DUAL_LUMINANCE12_SGIS            0x8116
#define GL_DUAL_LUMINANCE16_SGIS            0x8117
#define GL_DUAL_INTENSITY4_SGIS             0x8118
#define GL_DUAL_INTENSITY8_SGIS             0x8119
#define GL_DUAL_INTENSITY12_SGIS            0x811A
#define GL_DUAL_INTENSITY16_SGIS            0x811B
#define GL_DUAL_LUMINANCE_ALPHA4_SGIS       0x811C
#define GL_DUAL_LUMINANCE_ALPHA8_SGIS       0x811D
#define GL_QUAD_ALPHA4_SGIS                 0x811E
#define GL_QUAD_ALPHA8_SGIS                 0x811F
#define GL_QUAD_LUMINANCE4_SGIS             0x8120
#define GL_QUAD_LUMINANCE8_SGIS             0x8121
#define GL_QUAD_INTENSITY4_SGIS             0x8122
#define GL_QUAD_INTENSITY8_SGIS             0x8123
#define GL_DUAL_TEXTURE_SELECT_SGIS         0x8124
#define GL_QUAD_TEXTURE_SELECT_SGIS         0x8125

/* SGIS_point_parameters */
#define GL_POINT_SIZE_MIN_EXT               0x8126
#define GL_POINT_SIZE_MIN_SGIS              0x8126
#define GL_POINT_SIZE_MAX_EXT               0x8127
#define GL_POINT_SIZE_MAX_SGIS              0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_EXT    0x8128
#define GL_POINT_FADE_THRESHOLD_SIZE_SGIS   0x8128
#define GL_DISTANCE_ATTENUATION_EXT         0x8129
#define GL_DISTANCE_ATTENUATION_SGIS        0x8129

/* SGIS_fog_function */
#define GL_FOG_FUNC_SGIS                    0x812A
#define GL_FOG_FUNC_POINTS_SGIS             0x812B
#define GL_MAX_FOG_FUNC_POINTS_SGIS         0x812C

/* SGIS_texture_border_clamp */
#define GL_CLAMP_TO_BORDER_SGIS             0x812D

/* SGIX_texture_multi_buffer */
#define GL_TEXTURE_MULTI_BUFFER_HINT_SGIX   0x812E

/* SGIS_texture_edge_clamp */
#define GL_CLAMP_TO_EDGE                    0x812F
#define GL_CLAMP_TO_EDGE_SGIS               0x812F

/* SGIS_texture4D */
#define GL_PACK_SKIP_VOLUMES_SGIS           0x8130
#define GL_PACK_IMAGE_DEPTH_SGIS            0x8131
#define GL_UNPACK_SKIP_VOLUMES_SGIS         0x8132
#define GL_UNPACK_IMAGE_DEPTH_SGIS          0x8133
#define GL_TEXTURE_4D_SGIS                  0x8134
#define GL_PROXY_TEXTURE_4D_SGIS            0x8135
#define GL_TEXTURE_4DSIZE_SGIS              0x8136
#define GL_TEXTURE_WRAP_Q_SGIS              0x8137
#define GL_MAX_4D_TEXTURE_SIZE_SGIS         0x8138
#define GL_TEXTURE_4D_BINDING_SGIS          0x814F

/* SGIX_pixel_texture */
#define GL_PIXEL_TEX_GEN_SGIX               0x8139
#define GL_PIXEL_TEX_GEN_MODE_SGIX          0x832B

/* SGIS_texture_lod */
#define GL_TEXTURE_MIN_LOD                  0x813A
#define GL_TEXTURE_MIN_LOD_SGIS             0x813A
#define GL_TEXTURE_MAX_LOD                  0x813B
#define GL_TEXTURE_MAX_LOD_SGIS             0x813B
#define GL_TEXTURE_BASE_LEVEL               0x813C
#define GL_TEXTURE_BASE_LEVEL_SGIS          0x813C
#define GL_TEXTURE_MAX_LEVEL                0x813D
#define GL_TEXTURE_MAX_LEVEL_SGIS           0x813D

/* SGIX_pixel_tiles */
#define GL_PIXEL_TILE_BEST_ALIGNMENT_SGIX   0x813E
#define GL_PIXEL_TILE_CACHE_INCREMENT_SGIX  0x813F
#define GL_PIXEL_TILE_WIDTH_SGIX            0x8140
#define GL_PIXEL_TILE_HEIGHT_SGIX           0x8141
#define GL_PIXEL_TILE_GRID_WIDTH_SGIX       0x8142
#define GL_PIXEL_TILE_GRID_HEIGHT_SGIX      0x8143
#define GL_PIXEL_TILE_GRID_DEPTH_SGIX       0x8144
#define GL_PIXEL_TILE_CACHE_SIZE_SGIX       0x8145

/* SGIS_texture_filter4 */
#define GL_FILTER4_SGIS                     0x8146
#define GL_TEXTURE_FILTER4_SIZE_SGIS        0x8147

/* SGIX_sprite */
#define GL_SPRITE_SGIX                      0x8148
#define GL_SPRITE_MODE_SGIX                 0x8149
#define GL_SPRITE_AXIS_SGIX                 0x814A
#define GL_SPRITE_TRANSLATION_SGIX          0x814B
#define GL_SPRITE_AXIAL_SGIX                0x814C
#define GL_SPRITE_OBJECT_ALIGNED_SGIX       0x814D
#define GL_SPRITE_EYE_ALIGNED_SGIX          0x814E

/* VERSION_1_2 */
#define GL_IGNORE_BORDER                    0x8150
#define GL_CONSTANT_BORDER                  0x8151
#define GL_WRAP_BORDER                      0x8152
#define GL_REPLICATE_BORDER                 0x8153
#define GL_CONVOLUTION_BORDER_COLOR         0x8154

/* SGIX_clipmap */
#define GL_LINEAR_CLIPMAP_LINEAR_SGIX       0x8170
#define GL_TEXTURE_CLIPMAP_CENTER_SGIX      0x8171
#define GL_TEXTURE_CLIPMAP_FRAME_SGIX       0x8172
#define GL_TEXTURE_CLIPMAP_OFFSET_SGIX      0x8173
#define GL_TEXTURE_CLIPMAP_VIRTUAL_DEPTH_SGIX 0x8174
#define GL_TEXTURE_CLIPMAP_LOD_OFFSET_SGIX  0x8175
#define GL_TEXTURE_CLIPMAP_DEPTH_SGIX       0x8176
#define GL_MAX_CLIPMAP_DEPTH_SGIX           0x8177
#define GL_MAX_CLIPMAP_VIRTUAL_DEPTH_SGIX   0x8178
#define GL_NEAREST_CLIPMAP_NEAREST_SGIX     0x844D
#define GL_NEAREST_CLIPMAP_LINEAR_SGIX      0x844E
#define GL_LINEAR_CLIPMAP_NEAREST_SGIX      0x844F

/* SGIX_texture_scale_bias */
#define GL_POST_TEXTURE_FILTER_BIAS_SGIX    0x8179
#define GL_POST_TEXTURE_FILTER_SCALE_SGIX   0x817A
#define GL_POST_TEXTURE_FILTER_BIAS_RANGE_SGIX 0x817B
#define GL_POST_TEXTURE_FILTER_SCALE_RANGE_SGIX 0x817C

/* SGIX_reference_plane */
#define GL_REFERENCE_PLANE_SGIX             0x817D
#define GL_REFERENCE_PLANE_EQUATION_SGIX    0x817E

/* SGIX_ir_instrument1 */
#define GL_IR_INSTRUMENT1_SGIX              0x817F

/* SGIX_instruments */
#define GL_INSTRUMENT_BUFFER_POINTER_SGIX   0x8180
#define GL_INSTRUMENT_MEASUREMENTS_SGIX     0x8181

/* SGIX_list_priority */
#define GL_LIST_PRIORITY_SGIX               0x8182

/* SGIX_calligraphic_fragment */
#define GL_CALLIGRAPHIC_FRAGMENT_SGIX       0x8183

/* SGIX_impact_pixel_texture */
#define GL_PIXEL_TEX_GEN_Q_CEILING_SGIX     0x8184
#define GL_PIXEL_TEX_GEN_Q_ROUND_SGIX       0x8185
#define GL_PIXEL_TEX_GEN_Q_FLOOR_SGIX       0x8186
#define GL_PIXEL_TEX_GEN_ALPHA_REPLACE_SGIX 0x8187
#define GL_PIXEL_TEX_GEN_ALPHA_NO_REPLACE_SGIX 0x8188
#define GL_PIXEL_TEX_GEN_ALPHA_LS_SGIX      0x8189
#define GL_PIXEL_TEX_GEN_ALPHA_MS_SGIX      0x818A

/* SGIX_framezoom */
#define GL_FRAMEZOOM_SGIX                   0x818B
#define GL_FRAMEZOOM_FACTOR_SGIX            0x818C
#define GL_MAX_FRAMEZOOM_FACTOR_SGIX        0x818D

/* SGIX_texture_lod_bias */
#define GL_TEXTURE_LOD_BIAS_S_SGIX          0x818E
#define GL_TEXTURE_LOD_BIAS_T_SGIX          0x818F
#define GL_TEXTURE_LOD_BIAS_R_SGIX          0x8190

/* SGIS_generate_mipmap */
#define GL_GENERATE_MIPMAP_SGIS             0x8191
#define GL_GENERATE_MIPMAP_HINT_SGIS        0x8192

/* SGIX_polynomial_ffd */
#define GL_GEOMETRY_DEFORMATION_SGIX        0x8194
#define GL_TEXTURE_DEFORMATION_SGIX         0x8195
#define GL_DEFORMATIONS_MASK_SGIX           0x8196
#define GL_MAX_DEFORMATION_ORDER_SGIX       0x8197

/* SGIX_fog_offset */
#define GL_FOG_OFFSET_SGIX                  0x8198
#define GL_FOG_OFFSET_VALUE_SGIX            0x8199

/* SGIX_shadow */
#define GL_TEXTURE_COMPARE_SGIX             0x819A
#define GL_TEXTURE_COMPARE_OPERATOR_SGIX    0x819B
#define GL_TEXTURE_LEQUAL_R_SGIX            0x819C
#define GL_TEXTURE_GEQUAL_R_SGIX            0x819D

/* SGIX_depth_texture */
#define GL_DEPTH_COMPONENT16_SGIX           0x81A5
#define GL_DEPTH_COMPONENT24_SGIX           0x81A6
#define GL_DEPTH_COMPONENT32_SGIX           0x81A7

/* SGIX_ycrcb */
#define GL_YCRCB_422_SGIX                   0x81BB
#define GL_YCRCB_444_SGIX                   0x81BC
#define GL_TEXTURE_COLOR_WRITEMASK_SGIS     0x81EF

/* SGIS_point_line_texgen */
#define GL_EYE_DISTANCE_TO_POINT_SGIS       0x81F0
#define GL_OBJECT_DISTANCE_TO_POINT_SGIS    0x81F1
#define GL_EYE_DISTANCE_TO_LINE_SGIS        0x81F2
#define GL_OBJECT_DISTANCE_TO_LINE_SGIS     0x81F3
#define GL_EYE_POINT_SGIS                   0x81F4
#define GL_OBJECT_POINT_SGIS                0x81F5
#define GL_EYE_LINE_SGIS                    0x81F6
#define GL_OBJECT_LINE_SGIS                 0x81F7

/* VERSION_1_2 */
#define GL_LIGHT_MODEL_COLOR_CONTROL        0x81F8
#define GL_SINGLE_COLOR                     0x81F9
#define GL_SEPARATE_SPECULAR_COLOR          0x81FA

/* EXT_shared_texture_palette */
#define GL_SHARED_TEXTURE_PALETTE_EXT       0x81FB

/* SGIX_convolution_accuracy */
#define GL_CONVOLUTION_HINT_SGIX            0x8316

/* SGIX_blend_alpha_minmax */
#define GL_ALPHA_MIN_SGIX                   0x8320
#define GL_ALPHA_MAX_SGIX                   0x8321

/* SGIX_scalebias_hint */
#define GL_SCALEBIAS_HINT_SGIX              0x8322

/* SGIX_async */
#define GL_ASYNC_MARKER_SGIX                0x8329

/* SGIX_async_histogram */
#define GL_ASYNC_HISTOGRAM_SGIX             0x832C
#define GL_MAX_ASYNC_HISTOGRAM_SGIX         0x832D

/* SGIS_pixel_texture */
#define GL_PIXEL_TEXTURE_SGIS               0x8353
#define GL_PIXEL_FRAGMENT_RGB_SOURCE_SGIS   0x8354
#define GL_PIXEL_FRAGMENT_ALPHA_SOURCE_SGIS 0x8355
#define GL_PIXEL_GROUP_COLOR_SGIS           0x8356

/* SGIX_async_pixel */
#define GL_ASYNC_TEX_IMAGE_SGIX             0x835C
#define GL_ASYNC_DRAW_PIXELS_SGIX           0x835D
#define GL_ASYNC_READ_PIXELS_SGIX           0x835E
#define GL_MAX_ASYNC_TEX_IMAGE_SGIX         0x835F
#define GL_MAX_ASYNC_DRAW_PIXELS_SGIX       0x8360
#define GL_MAX_ASYNC_READ_PIXELS_SGIX       0x8361

/* SGIX_texture_coordinate_clamp */
#define GL_TEXTURE_MAX_CLAMP_S_SGIX         0x8369
#define GL_TEXTURE_MAX_CLAMP_T_SGIX         0x836A
#define GL_TEXTURE_MAX_CLAMP_R_SGIX         0x836B

/* SGIX_vertex_preclip */
#define GL_VERTEX_PRECLIP_SGIX              0x83EE
#define GL_VERTEX_PRECLIP_HINT_SGIX         0x83EF

/* SGIX_fragment_lighting */
#define GL_FRAGMENT_LIGHTING_SGIX           0x8400
#define GL_FRAGMENT_COLOR_MATERIAL_SGIX     0x8401
#define GL_FRAGMENT_COLOR_MATERIAL_FACE_SGIX 0x8402
#define GL_FRAGMENT_COLOR_MATERIAL_PARAMETER_SGIX 0x8403
#define GL_MAX_FRAGMENT_LIGHTS_SGIX         0x8404
#define GL_MAX_ACTIVE_LIGHTS_SGIX           0x8405
#define GL_CURRENT_RASTER_NORMAL_SGIX       0x8406
#define GL_LIGHT_ENV_MODE_SGIX              0x8407
#define GL_FRAGMENT_LIGHT_MODEL_LOCAL_VIEWER_SGIX 0x8408
#define GL_FRAGMENT_LIGHT_MODEL_TWO_SIDE_SGIX 0x8409
#define GL_FRAGMENT_LIGHT_MODEL_AMBIENT_SGIX 0x840A
#define GL_FRAGMENT_LIGHT_MODEL_NORMAL_INTERPOLATION_SGIX 0x840B
#define GL_FRAGMENT_LIGHT0_SGIX             0x840C
#define GL_FRAGMENT_LIGHT1_SGIX             0x840D
#define GL_FRAGMENT_LIGHT2_SGIX             0x840E
#define GL_FRAGMENT_LIGHT3_SGIX             0x840F
#define GL_FRAGMENT_LIGHT4_SGIX             0x8410
#define GL_FRAGMENT_LIGHT5_SGIX             0x8411
#define GL_FRAGMENT_LIGHT6_SGIX             0x8412
#define GL_FRAGMENT_LIGHT7_SGIX             0x8413

/* SGIX_resample */
#define GL_PACK_RESAMPLE_SGIX               0x842C
#define GL_UNPACK_RESAMPLE_SGIX             0x842D
#define GL_RESAMPLE_REPLICATE_SGIX          0x842E
#define GL_RESAMPLE_ZERO_FILL_SGIX          0x842F
#define GL_RESAMPLE_DECIMATE_SGIX           0x8430

/* SGIX_icc_texture */
#define GL_RGB_ICC_SGIX                     0x8460
#define GL_RGBA_ICC_SGIX                    0x8461
#define GL_ALPHA_ICC_SGIX                   0x8462
#define GL_LUMINANCE_ICC_SGIX               0x8463
#define GL_INTENSITY_ICC_SGIX               0x8464
#define GL_LUMINANCE_ALPHA_ICC_SGIX         0x8465
#define GL_R5_G6_B5_ICC_SGIX                0x8466
#define GL_R5_G6_B5_A8_ICC_SGIX             0x8467
#define GL_ALPHA16_ICC_SGIX                 0x8468
#define GL_LUMINANCE16_ICC_SGIX             0x8469
#define GL_INTENSITY16_ICC_SGIX             0x846A
#define GL_LUMINANCE16_ALPHA8_ICC_SGIX      0x846B

/* VERSION_1_2 */
#define GL_SMOOTH_POINT_SIZE_RANGE          0x0B12
#define GL_SMOOTH_POINT_SIZE_GRANULARITY    0x0B13
#define GL_SMOOTH_LINE_WIDTH_RANGE          0x0B22
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY    0x0B23
#define GL_ALIASED_POINT_SIZE_RANGE         0x846D
#define GL_ALIASED_LINE_WIDTH_RANGE         0x846E

/* INGR_interlace_read */
#define GL_INTERLACE_READ_INGR              0x8568

/* SGIX_subsample */
#define GL_PACK_SUBSAMPLE_RATE_SGIX         0x85A0
#define GL_UNPACK_SUBSAMPLE_RATE_SGIX       0x85A1
#define GL_PIXEL_SUBSAMPLE_4444_SGIX        0x85A2
#define GL_PIXEL_SUBSAMPLE_2424_SGIX        0x85A3
#define GL_PIXEL_SUBSAMPLE_4242_SGIX        0x85A4

/*************************************************************/


#if defined(_LANGUAGE_C) || defined(__cplusplus)

extern void glAccum (GLenum op, GLfloat value);
#define glAccum( op, value ) \
  glAccum( op, value );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glAccum( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #op, #value, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glAlphaFunc (GLenum func, GLclampf ref);
#define glAlphaFunc( func, ref ) \
  glAlphaFunc( func, ref );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glAlphaFunc( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #func, #ref, __glDebug_ErrorStringMacro(_e) ); \
  }

extern GLboolean glAreTexturesResident (GLsizei n, const GLuint *textures, GLboolean *residences);
static GLboolean __glDebug_GLboolean;
#define glAreTexturesResident( n, textures, residences ) \
  __glDebug_GLboolean = glAreTexturesResident( n, textures, residences );
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glAreTexturesResident( %s, %s, %s ) returned %d with error: %s\n", \
	      __FILE__, __LINE__, \
	      #n, #textures, #residences, __glDebug_GLboolean, \
              __glDebug_ErrorStringMacro(_e) ); \
  }
    
extern GLboolean glAreTexturesResidentEXT (GLsizei n, const GLuint *textures, GLboolean *residences);
#define glAreTexturesResidentEXT( n, textures, residences ) \
  __glDebug_GLboolean = glAreTexturesResidentEXT( n, textures, residences );
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glAreTexturesResidentEXT( %s, %s, %s ) returned %d with error: %s\n", \
	      __FILE__, __LINE__, \
	      #n, #textures, #residences, __glDebug_GLboolean, \
              __glDebug_ErrorStringMacro(_e) ); \
  }
    
extern void glArrayElement (GLint i);
#define glArrayElement( i ) \
  glArrayElement( i ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glArrayElement( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #i, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glArrayElementEXT (GLint i);
#define glArrayElementEXT( i ) \
  glArrayElementEXT( i ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glArrayElementEXT( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #i, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glAsyncMarkerSGIX (GLuint marker);
#define glAsyncMarkerSGIX( marker ) \
  glAsyncMarkerSGIX( marker );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glAsyncMarkerSGIX( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #marker, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glBegin (GLenum mode);
#define glBegin( mode ) \
  if ( __glDebug_InBegin ) { \
    printf( "[%s:%d] glBegin( %s ) called between glBegin()/glEnd() pair\n", \
	    __FILE__, __LINE__, #mode ); \
  } else { \
    __glDebug_InBegin = GL_TRUE; \
    glBegin( mode ); \
  }

extern void glBindTexture (GLenum target, GLuint texture);
#define glBindTexture( target, texture ) \
  glBindTexture( target, texture );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glBindTexture( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #texture, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glBindTextureEXT (GLenum target, GLuint texture);
#define glBindTextureEXT( target, texture ) \
  glBindTextureEXT( target, texture );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glBindTextureEXT( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #texture, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glBitmap (GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
#define glBitmap( width, height, xorig, yorig, xmove, ymove, bitmap ) \
  glBitmap( width, height, xorig, yorig, xmove, ymove, bitmap );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glBitmap( %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #width, #height, #xorig, #yorig, #xmove, #ymove, #bitmap, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glBlendColor (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
#define glBlendColor( red, green, blue, alpha ) \
  glBlendColor( red, green, blue, alpha );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glBlendColor( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #red, #green, #blue, #alpha, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glBlendColorEXT (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
#define glBlendColorEXT( red, green, blue, alpha ) \
  glBlendColorEXT( red, green, blue, alpha );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glBlendColorEXT( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #red, #green, #blue, #alpha, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glBlendEquation (GLenum mode);
#define glBlendEquation( mode ) \
  glBlendEquation( mode );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glBlendEquation( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #mode, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glBlendEquationEXT (GLenum mode);
#define glBlendEquationEXT( mode ) \
  glBlendEquationEXT( mode );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glBlendEquationEXT( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #mode, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glBlendFunc (GLenum sfactor, GLenum dfactor);
#define glBlendFunc( sfactor, dfactor ) \
  glBlendFunc( sfactor, dfactor );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glBlendFunc( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #sfactor, #dfactor, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glCallList (GLuint list);
#define glCallList( list ) \
  glCallList( list ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glCallList( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #list, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glCallLists (GLsizei n, GLenum type, const GLvoid *lists);
#define glCallLists( n, type, lists ) \
  glCallLists( n, type, lists ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glCallLists( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #n, #type, #lists, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glClear (GLbitfield mask);
#define glClear( mask ) \
  glClear( mask );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glClear( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #mask, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glClearAccum (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#define glClearAccum( red, green, blue, alpha ) \
  glClearAccum( red, green, blue, alpha );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glClearAccum( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #red, #green, #blue, #alpha, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glClearColor (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
#define glClearColor( red, green, blue, alpha ) \
  glClearColor( red, green, blue, alpha );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glClearColor( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #red, #green, #blue, #alpha, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glClearDepth (GLclampd depth);
#define glClearDepth( depth ) \
  glClearDepth( depth );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glClearDepth( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #depth, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glClearIndex (GLfloat c);
#define glClearIndex( c ) \
  glClearIndex( c );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glClearIndex( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #c, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glClearStencil (GLint s);
#define glClearStencil( s ) \
  glClearStencil( s );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glClearStencil( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #s, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glClipPlane (GLenum plane, const GLdouble *equation);
#define glClipPlane( plane, equation ) \
  glClipPlane( plane, equation );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glClipPlane( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #plane, #equation, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor3b (GLbyte red, GLbyte green, GLbyte blue);
#define glColor3b( red, green, blue ) \
  glColor3b( red, green, blue ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor3b( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #red, #green, #blue, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor3bv (const GLbyte *v);
#define glColor3bv( v ) \
  glColor3bv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor3bv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor3d (GLdouble red, GLdouble green, GLdouble blue);
#define glColor3d( red, green, blue ) \
  glColor3d( red, green, blue ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor3d( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #red, #green, #blue, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor3dv (const GLdouble *v);
#define glColor3dv( v ) \
  glColor3dv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor3dv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor3f (GLfloat red, GLfloat green, GLfloat blue);
#define glColor3f( red, green, blue ) \
  glColor3f( red, green, blue ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor3f( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #red, #green, #blue, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor3fv (const GLfloat *v);
#define glColor3fv( v ) \
  glColor3fv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor3fv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor3i (GLint red, GLint green, GLint blue);
#define glColor3i( red, green, blue ) \
  glColor3i( red, green, blue ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor3i( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #red, #green, #blue, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor3iv (const GLint *v);
#define glColor3iv( v ) \
  glColor3iv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor3iv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor3s (GLshort red, GLshort green, GLshort blue);
#define glColor3s( red, green, blue ) \
  glColor3s( red, green, blue ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor3s( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #red, #green, #blue, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor3sv (const GLshort *v);
#define glColor3sv( v ) \
  glColor3sv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor3sv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor3ub (GLubyte red, GLubyte green, GLubyte blue);
#define glColor3ub( red, green, blue ) \
  glColor3ub( red, green, blue ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor3ub( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #red, #green, #blue, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor3ubv (const GLubyte *v);
#define glColor3ubv( v ) \
  glColor3ubv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor3ubv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor3ui (GLuint red, GLuint green, GLuint blue);
#define glColor3ui( red, green, blue ) \
  glColor3ui( red, green, blue ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor3ui( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #red, #green, #blue, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor3uiv (const GLuint *v);
#define glColor3uiv( v ) \
  glColor3uiv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor3uiv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor3us (GLushort red, GLushort green, GLushort blue);
#define glColor3us( red, green, blue ) \
  glColor3us( red, green, blue ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor3us( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #red, #green, #blue, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor3usv (const GLushort *v);
#define glColor3usv( v ) \
  glColor3usv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor3usv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor4b (GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
#define glColor4b( red, green, blue, alpha ) \
  glColor4b( red, green, blue, alpha ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor4b( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #red, #green, #blue, #alpha, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor4bv (const GLbyte *v);
#define glColor4bv( v ) \
  glColor4bv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor4bv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor4d (GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
#define glColor4d( red, green, blue, alpha ) \
  glColor4d( red, green, blue, alpha ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor4d( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #red, #green, #blue, #alpha, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor4dv (const GLdouble *v);
#define glColor4dv( v ) \
  glColor4dv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor4dv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor4f (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#define glColor4f( red, green, blue, alpha ) \
  glColor4f( red, green, blue, alpha ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor4f( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #red, #green, #blue, #alpha, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor4fv (const GLfloat *v);
#define glColor4fv( v ) \
  glColor4fv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor4fv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor4i (GLint red, GLint green, GLint blue, GLint alpha);
#define glColor4i( red, green, blue, alpha ) \
  glColor4i( red, green, blue, alpha ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor4i( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #red, #green, #blue, #alpha, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor4iv (const GLint *v);
#define glColor4iv( v ) \
  glColor4iv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor4iv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor4s (GLshort red, GLshort green, GLshort blue, GLshort alpha);
#define glColor4s( red, green, blue, alpha ) \
  glColor4s( red, green, blue, alpha ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor4s( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #red, #green, #blue, #alpha, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor4sv (const GLshort *v);
#define glColor4sv( v ) \
  glColor4sv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor4sv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor4ub (GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
#define glColor4ub( red, green, blue, alpha ) \
  glColor4ub( red, green, blue, alpha ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor4ub( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #red, #green, #blue, #alpha, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor4ubv (const GLubyte *v);
#define glColor4ubv( v ) \
  glColor4ubv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor4ubv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor4ui (GLuint red, GLuint green, GLuint blue, GLuint alpha);
#define glColor4ui( red, green, blue, alpha ) \
  glColor4ui( red, green, blue, alpha ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor4ui( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #red, #green, #blue, #alpha, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor4uiv (const GLuint *v);
#define glColor4uiv( v ) \
  glColor4uiv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor4uiv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor4us (GLushort red, GLushort green, GLushort blue, GLushort alpha);
#define glColor4us( red, green, blue, alpha ) \
  glColor4us( red, green, blue, alpha ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor4us( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #red, #green, #blue, #alpha, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColor4usv (const GLushort *v);
#define glColor4usv( v ) \
  glColor4usv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColor4usv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColorMask (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
#define glColorMask( red, green, blue, alpha ) \
  glColorMask( red, green, blue, alpha );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColorMask( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #red, #green, #blue, #alpha, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColorMaterial (GLenum face, GLenum mode);
#define glColorMaterial( face, mode ) \
  glColorMaterial( face, mode );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColorMaterial( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #face, #mode, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColorPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
#define glColorPointer( size, type, stride, pointer ) \
  glColorPointer( size, type, stride, pointer );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColorPointer( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #size, #type, #stride, #pointer, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColorPointerEXT (GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
#define glColorPointerEXT( size, type, stride, count, pointer ) \
  glColorPointerEXT( size, type, stride, count, pointer );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColorPointerEXT( %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #size, #type, #stride, #count, #pointer, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColorSubTable (GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *data);
#define glColorSubTable( target, start, count, format, type, data ) \
  glColorSubTable( target, start, count, format, type, data );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColorSubTable( %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #start, #count, #format, #type, #data, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColorTable (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table);
#define glColorTable( target, internalformat, width, format, type, table ) \
  glColorTable( target, internalformat, width, format, type, table );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColorTable( %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #internalformat, #width, #format, #type, #table, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColorTableParameterfv (GLenum target, GLenum pname, const GLfloat *params);
#define glColorTableParameterfv( target, pname, params ) \
  glColorTableParameterfv( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColorTableParameterfv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColorTableParameterfvSGI (GLenum target, GLenum pname, const GLfloat *params);
#define glColorTableParameterfvSGI( target, pname, params ) \
  glColorTableParameterfvSGI( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColorTableParameterfvSGI( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColorTableParameteriv (GLenum target, GLenum pname, const GLint *params);
#define glColorTableParameteriv( target, pname, params ) \
  glColorTableParameteriv( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColorTableParameteriv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColorTableParameterivSGI (GLenum target, GLenum pname, const GLint *params);
#define glColorTableParameterivSGI( target, pname, params ) \
  glColorTableParameterivSGI( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColorTableParameterivSGI( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glColorTableSGI (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table);
#define glColorTableSGI( target, internalformat, width, format, type, table ) \
  glColorTableSGI( target, internalformat, width, format, type, table );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glColorTableSGI( %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #internalformat, #width, #format, #type, #table, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glConvolutionFilter1D (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *image);
#define glConvolutionFilter1D( target, internalformat, width, format, type, image ) \
  glConvolutionFilter1D( target, internalformat, width, format, type, image );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glConvolutionFilter1D( %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #internalformat, #width, #format, #type, #image, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glConvolutionFilter1DEXT (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *image);
#define glConvolutionFilter1DEXT( target, internalformat, width, format, type, image ) \
  glConvolutionFilter1DEXT( target, internalformat, width, format, type, image );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glConvolutionFilter1DEXT( %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #internalformat, #width, #format, #type, #image, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glConvolutionFilter2D (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *image);
#define glConvolutionFilter2D( target, internalformat, width, height, format, type, image ) \
  glConvolutionFilter2D( target, internalformat, width, height, format, type, image );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glConvolutionFilter2D( %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #internalformat, #width, #height, #format, #type, #image, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glConvolutionFilter2DEXT (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *image);
#define glConvolutionFilter2DEXT( target, internalformat, width, height, format, type, image ) \
  glConvolutionFilter2DEXT( target, internalformat, width, height, format, type, image );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glConvolutionFilter2DEXT( %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #internalformat, #width, #height, #format, #type, #image, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glConvolutionParameterf (GLenum target, GLenum pname, GLfloat params);
#define glConvolutionParameterf( target, pname, params ) \
  glConvolutionParameterf( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glConvolutionParameterf( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glConvolutionParameterfEXT (GLenum target, GLenum pname, GLfloat params);
#define glConvolutionParameterfEXT( target, pname, params ) \
  glConvolutionParameterfEXT( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glConvolutionParameterfEXT( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glConvolutionParameterfv (GLenum target, GLenum pname, const GLfloat *params);
#define glConvolutionParameterfv( target, pname, params ) \
  glConvolutionParameterfv( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glConvolutionParameterfv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glConvolutionParameterfvEXT (GLenum target, GLenum pname, const GLfloat *params);
#define glConvolutionParameterfvEXT( target, pname, params ) \
  glConvolutionParameterfvEXT( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glConvolutionParameterfvEXT( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glConvolutionParameteri (GLenum target, GLenum pname, GLint params);
#define glConvolutionParameteri( target, pname, params ) \
  glConvolutionParameteri( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glConvolutionParameteri( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glConvolutionParameteriEXT (GLenum target, GLenum pname, GLint params);
#define glConvolutionParameteriEXT( target, pname, params ) \
  glConvolutionParameteriEXT( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glConvolutionParameteriEXT( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glConvolutionParameteriv (GLenum target, GLenum pname, const GLint *params);
#define glConvolutionParameteriv( target, pname, params ) \
  glConvolutionParameteriv( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glConvolutionParameteriv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glConvolutionParameterivEXT (GLenum target, GLenum pname, const GLint *params);
#define glConvolutionParameterivEXT( target, pname, params ) \
  glConvolutionParameterivEXT( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glConvolutionParameterivEXT( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glCopyColorSubTable (GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
#define glCopyColorSubTable( target, start, x, y, width ) \
  glCopyColorSubTable( target, start, x, y, width );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glCopyColorSubTable( %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #start, #x, #y, #width, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glCopyColorTable (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
#define glCopyColorTable( target, internalformat, x, y, width ) \
  glCopyColorTable( target, internalformat, x, y, width );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glCopyColorTable( %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #internalformat, #x, #y, #width, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glCopyColorTableSGI (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
#define glCopyColorTableSGI( target, internalformat, x, y, width ) \
  glCopyColorTableSGI( target, internalformat, x, y, width );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glCopyColorTableSGI( %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #internalformat, #x, #y, #width, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glCopyConvolutionFilter1D (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
#define glCopyConvolutionFilter1D( target, internalformat, x, y, width ) \
  glCopyConvolutionFilter1D( target, internalformat, x, y, width );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glCopyConvolutionFilter1D( %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #internalformat, #x, #y, #width, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glCopyConvolutionFilter1DEXT (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
#define glCopyConvolutionFilter1DEXT( target, internalformat, x, y, width ) \
  glCopyConvolutionFilter1DEXT( target, internalformat, x, y, width );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glCopyConvolutionFilter1DEXT( %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #internalformat, #x, #y, #width, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glCopyConvolutionFilter2D (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyConvolutionFilter2D( target, internalformat, x, y, width, height ) \
  glCopyConvolutionFilter2D( target, internalformat, x, y, width, height );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glCopyConvolutionFilter2D( %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #internalformat, #x, #y, #width, #height, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glCopyConvolutionFilter2DEXT (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyConvolutionFilter2DEXT( target, internalformat, x, y, width, height ) \
  glCopyConvolutionFilter2DEXT( target, internalformat, x, y, width, height );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glCopyConvolutionFilter2DEXT( %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #internalformat, #x, #y, #width, #height, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glCopyPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
#define glCopyPixels( x, y, width, height, type ) \
  glCopyPixels( x, y, width, height, type );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glCopyPixels( %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, #width, #height, #type, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glCopyTexImage1D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
#define glCopyTexImage1D( target, level, internalformat, x, y, width, border ) \
  glCopyTexImage1D( target, level, internalformat, x, y, width, border );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glCopyTexImage1D( %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #level, #internalformat, #x, #y, #width, #border, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glCopyTexImage1DEXT (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
#define glCopyTexImage1DEXT( target, level, internalformat, x, y, width, border ) \
  glCopyTexImage1DEXT( target, level, internalformat, x, y, width, border );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glCopyTexImage1DEXT( %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #level, #internalformat, #x, #y, #width, #border, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glCopyTexImage2D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
#define glCopyTexImage2D( target, level, internalformat, x, y, width, height, border ) \
  glCopyTexImage2D( target, level, internalformat, x, y, width, height, border );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glCopyTexImage2D( %s, %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #level, #internalformat, #x, #y, #width, #height, #border, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glCopyTexImage2DEXT (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
#define glCopyTexImage2DEXT( target, level, internalformat, x, y, width, height, border ) \
  glCopyTexImage2DEXT( target, level, internalformat, x, y, width, height, border );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glCopyTexImage2DEXT( %s, %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #level, #internalformat, #x, #y, #width, #height, #border, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glCopyTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
#define glCopyTexSubImage1D( target, level, xoffset, x, y, width ) \
  glCopyTexSubImage1D( target, level, xoffset, x, y, width );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glCopyTexSubImage1D( %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #level, #xoffset, #x, #y, #width, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glCopyTexSubImage1DEXT (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
#define glCopyTexSubImage1DEXT( target, level, xoffset, x, y, width ) \
  glCopyTexSubImage1DEXT( target, level, xoffset, x, y, width );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glCopyTexSubImage1DEXT( %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #level, #xoffset, #x, #y, #width, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glCopyTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTexSubImage2D( target, level, xoffset, yoffset, x, y, width, height ) \
  glCopyTexSubImage2D( target, level, xoffset, yoffset, x, y, width, height );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glCopyTexSubImage2D( %s, %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #level, #xoffset, #yoffset, #x, #y, #width, #height, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glCopyTexSubImage2DEXT (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTexSubImage2DEXT( target, level, xoffset, yoffset, x, y, width, height ) \
  glCopyTexSubImage2DEXT( target, level, xoffset, yoffset, x, y, width, height );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glCopyTexSubImage2DEXT( %s, %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #level, #xoffset, #yoffset, #x, #y, #width, #height, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glCopyTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTexSubImage3D( target, level, xoffset, yoffset, zoffset, x, y, width, height ) \
  glCopyTexSubImage3D( target, level, xoffset, yoffset, zoffset, x, y, width, height );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glCopyTexSubImage3D( %s, %s, %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #level, #xoffset, #yoffset, #zoffset, #x, #y, #width, #height, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glCopyTexSubImage3DEXT (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTexSubImage3DEXT( target, level, xoffset, yoffset, zoffset, x, y, width, height ) \
  glCopyTexSubImage3DEXT( target, level, xoffset, yoffset, zoffset, x, y, width, height );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glCopyTexSubImage3DEXT( %s, %s, %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #level, #xoffset, #yoffset, #zoffset, #x, #y, #width, #height, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glCullFace (GLenum mode);
#define glCullFace( mode ) \
  glCullFace( mode );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glCullFace( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #mode, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glDeformSGIX (GLbitfield mask);
#define glDeformSGIX( mask ) \
  glDeformSGIX( mask );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glDeformSGIX( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #mask, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glDeformationMap3dSGIX (GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble w1, GLdouble w2, GLint wstride, GLint worder, const GLdouble *points);
#define glDeformationMap3dSGIX( target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, w1, w2, wstride, worder, points ) \
  glDeformationMap3dSGIX( target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, w1, w2, wstride, worder, points );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glDeformationMap3dSGIX( %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #u1, #u2, #ustride, #uorder, #v1, #v2, #vstride, #vorder, #w1, #w2, #wstride, #worder, #points, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glDeformationMap3fSGIX (GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat w1, GLfloat w2, GLint wstride, GLint worder, const GLfloat *points);
#define glDeformationMap3fSGIX( target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, w1, w2, wstride, worder, points ) \
  glDeformationMap3fSGIX( target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, w1, w2, wstride, worder, points );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glDeformationMap3fSGIX( %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #u1, #u2, #ustride, #uorder, #v1, #v2, #vstride, #vorder, #w1, #w2, #wstride, #worder, #points, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glDeleteAsyncMarkersSGIX (GLuint marker, GLsizei range);
#define glDeleteAsyncMarkersSGIX( marker, range ) \
  glDeleteAsyncMarkersSGIX( marker, range );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glDeleteAsyncMarkersSGIX( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #marker, #range, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glDeleteLists (GLuint list, GLsizei range);
#define glDeleteLists( list, range ) \
  glDeleteLists( list, range );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glDeleteLists( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #list, #range, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glDeleteTextures (GLsizei n, const GLuint *textures);
#define glDeleteTextures( n, textures ) \
  glDeleteTextures( n, textures );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glDeleteTextures( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #n, #textures, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glDeleteTexturesEXT (GLsizei n, const GLuint *textures);
#define glDeleteTexturesEXT( n, textures ) \
  glDeleteTexturesEXT( n, textures );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glDeleteTexturesEXT( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #n, #textures, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glDepthFunc (GLenum func);
#define glDepthFunc( func ) \
  glDepthFunc( func );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glDepthFunc( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #func, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glDepthMask (GLboolean flag);
#define glDepthMask( flag ) \
  glDepthMask( flag );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glDepthMask( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #flag, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glDepthRange (GLclampd near, GLclampd far);
#define glDepthRange( near, far ) \
  glDepthRange( near, far );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glDepthRange( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #near, #far, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glDetailTexFuncSGIS (GLenum target, GLsizei n, const GLfloat *points);
#define glDetailTexFuncSGIS( target, n, points ) \
  glDetailTexFuncSGIS( target, n, points );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glDetailTexFuncSGIS( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #n, #points, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glDisable (GLenum cap);
#define glDisable( cap ) \
  glDisable( cap );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glDisable( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #cap, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glDisableClientState (GLenum array);
#define glDisableClientState( array ) \
  glDisableClientState( array );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glDisableClientState( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #array, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glDrawArrays (GLenum mode, GLint first, GLsizei count);
#define glDrawArrays( mode, first, count ) \
  glDrawArrays( mode, first, count );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glDrawArrays( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #mode, #first, #count, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glDrawArraysEXT (GLenum mode, GLint first, GLsizei count);
#define glDrawArraysEXT( mode, first, count ) \
  glDrawArraysEXT( mode, first, count );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glDrawArraysEXT( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #mode, #first, #count, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glDrawBuffer (GLenum mode);
#define glDrawBuffer( mode ) \
  glDrawBuffer( mode );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glDrawBuffer( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #mode, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glDrawElements (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
#define glDrawElements( mode, count, type, indices ) \
  glDrawElements( mode, count, type, indices );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glDrawElements( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #mode, #count, #type, #indices, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glDrawPixels (GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
#define glDrawPixels( width, height, format, type, pixels ) \
  glDrawPixels( width, height, format, type, pixels );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glDrawPixels( %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #width, #height, #format, #type, #pixels, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glDrawRangeElements (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices);
#define glDrawRangeElements( mode, start, end, count, type, indices ) \
  glDrawRangeElements( mode, start, end, count, type, indices );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glDrawRangeElements( %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #mode, #start, #end, #count, #type, #indices, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glEdgeFlag (GLboolean flag);
#define glEdgeFlag( flag ) \
  glEdgeFlag( flag ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glEdgeFlag( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #flag, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glEdgeFlagPointer (GLsizei stride, const GLboolean *pointer);
#define glEdgeFlagPointer( stride, pointer ) \
  glEdgeFlagPointer( stride, pointer ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glEdgeFlagPointer( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #stride, #pointer, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glEdgeFlagPointerEXT (GLsizei stride, GLsizei count, const GLboolean *pointer);
#define glEdgeFlagPointerEXT( stride, count, pointer ) \
  glEdgeFlagPointerEXT( stride, count, pointer ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glEdgeFlagPointerEXT( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #stride, #count, #pointer, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glEdgeFlagv (const GLboolean *flag);
#define glEdgeFlagv( flag ) \
  glEdgeFlagv( flag ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glEdgeFlagv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #flag, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glEnable (GLenum cap);
#define glEnable( cap ) \
  glEnable( cap );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glEnable( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #cap, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glEnableClientState (GLenum array);
#define glEnableClientState( array ) \
  glEnableClientState( array );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glEnableClientState( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #array, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glEnd (void);
#define glEnd() \
  if ( !__glDebug_InBegin ) { \
    printf( "[%s:%d] glEnd() called outside glBegin()/glEnd() pair\n", \
	    __FILE__, __LINE__ ); \
  } else { \
    __glDebug_InBegin = GL_FALSE; \
    glEnd(); \
  }
	    
extern void glEndList (void);
#define glEnd() \
  if ( !__glDebug_InBegin ) { \
    printf( "[%s:%d] glEnd() called outside glBegin()/glEnd() pair\n", \
	    __FILE__, __LINE__ ); \
  } else { \
    __glDebug_InBegin = GL_FALSE; \
    glEnd(); \
  }
	    
extern void glEvalCoord1d (GLdouble u);
#define glEvalCoord1d( u ) \
  glEvalCoord1d( u ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glEvalCoord1d( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #u, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glEvalCoord1dv (const GLdouble *u);
#define glEvalCoord1dv( u ) \
  glEvalCoord1dv( u ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glEvalCoord1dv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #u, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glEvalCoord1f (GLfloat u);
#define glEvalCoord1f( u ) \
  glEvalCoord1f( u ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glEvalCoord1f( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #u, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glEvalCoord1fv (const GLfloat *u);
#define glEvalCoord1fv( u ) \
  glEvalCoord1fv( u ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glEvalCoord1fv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #u, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glEvalCoord2d (GLdouble u, GLdouble v);
#define glEvalCoord2d( u, v ) \
  glEvalCoord2d( u, v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glEvalCoord2d( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #u, #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glEvalCoord2dv (const GLdouble *u);
#define glEvalCoord2dv( u ) \
  glEvalCoord2dv( u ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glEvalCoord2dv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #u, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glEvalCoord2f (GLfloat u, GLfloat v);
#define glEvalCoord2f( u, v ) \
  glEvalCoord2f( u, v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glEvalCoord2f( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #u, #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glEvalCoord2fv (const GLfloat *u);
#define glEvalCoord2fv( u ) \
  glEvalCoord2fv( u ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glEvalCoord2fv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #u, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glEvalMesh1 (GLenum mode, GLint i1, GLint i2);
#define glEvalMesh1( mode, i1, i2 ) \
  glEvalMesh1( mode, i1, i2 );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glEvalMesh1( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #mode, #i1, #i2, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glEvalMesh2 (GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
#define glEvalMesh2( mode, i1, i2, j1, j2 ) \
  glEvalMesh2( mode, i1, i2, j1, j2 );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glEvalMesh2( %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #mode, #i1, #i2, #j1, #j2, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glEvalPoint1 (GLint i);
#define glEvalPoint1( i ) \
  glEvalPoint1( i ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glEvalPoint1( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #i, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glEvalPoint2 (GLint i, GLint j);
#define glEvalPoint2( i, j ) \
  glEvalPoint2( i, j ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glEvalPoint2( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #i, #j, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glFeedbackBuffer (GLsizei size, GLenum type, GLfloat *buffer);
#define glFeedbackBuffer( size, type, buffer ) \
  glFeedbackBuffer( size, type, buffer );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glFeedbackBuffer( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #size, #type, #buffer, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glFinish (void);
#define glFinish() \
  glFinish();  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glFinish() returned an error: %s\n", \
              __FILE__, __LINE__, \
	      __glDebug_ErrorStringMacro(_e) ); \
  }

extern GLint glFinishAsyncSGIX (GLuint *markerp);
static GLint __glDebug_GLint;
#define glFinishAsyncSGIX( markerp ) \
  __glDebug_GLint = glFinishAsyncSGIX( markerp );
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glFinishAsyncSGIX( %s ) returned %d with error: %s\n", \
	      __FILE__, __LINE__, \
	      #markerp, __glDebug_GLint, \
              __glDebug_ErrorStringMacro(_e) ); \
  }
    
extern void glFlush (void);
#define glFlush() \
  glFlush();  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glFlush() returned an error: %s\n", \
              __FILE__, __LINE__, \
	      __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glFlushRasterSGIX (void);
#define glFlushRasterSGIX() \
  glFlushRasterSGIX();  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glFlushRasterSGIX() returned an error: %s\n", \
              __FILE__, __LINE__, \
	      __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glFogFuncSGIS (GLsizei n, const GLfloat *points);
#define glFogFuncSGIS( n, points ) \
  glFogFuncSGIS( n, points );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glFogFuncSGIS( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #n, #points, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glFogf (GLenum pname, GLfloat param);
#define glFogf( pname, param ) \
  glFogf( pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glFogf( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glFogfv (GLenum pname, const GLfloat *params);
#define glFogfv( pname, params ) \
  glFogfv( pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glFogfv( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glFogi (GLenum pname, GLint param);
#define glFogi( pname, param ) \
  glFogi( pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glFogi( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glFogiv (GLenum pname, const GLint *params);
#define glFogiv( pname, params ) \
  glFogiv( pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glFogiv( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glFragmentColorMaterialSGIX (GLenum face, GLenum mode);
#define glFragmentColorMaterialSGIX( face, mode ) \
  glFragmentColorMaterialSGIX( face, mode );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glFragmentColorMaterialSGIX( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #face, #mode, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glFragmentLightModelfSGIX (GLenum pname, GLfloat param);
#define glFragmentLightModelfSGIX( pname, param ) \
  glFragmentLightModelfSGIX( pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glFragmentLightModelfSGIX( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glFragmentLightModelfvSGIX (GLenum pname, const GLfloat *params);
#define glFragmentLightModelfvSGIX( pname, params ) \
  glFragmentLightModelfvSGIX( pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glFragmentLightModelfvSGIX( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glFragmentLightModeliSGIX (GLenum pname, GLint param);
#define glFragmentLightModeliSGIX( pname, param ) \
  glFragmentLightModeliSGIX( pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glFragmentLightModeliSGIX( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glFragmentLightModelivSGIX (GLenum pname, const GLint *params);
#define glFragmentLightModelivSGIX( pname, params ) \
  glFragmentLightModelivSGIX( pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glFragmentLightModelivSGIX( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glFragmentLightfSGIX (GLenum light, GLenum pname, GLfloat param);
#define glFragmentLightfSGIX( light, pname, param ) \
  glFragmentLightfSGIX( light, pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glFragmentLightfSGIX( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #light, #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glFragmentLightfvSGIX (GLenum light, GLenum pname, const GLfloat *params);
#define glFragmentLightfvSGIX( light, pname, params ) \
  glFragmentLightfvSGIX( light, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glFragmentLightfvSGIX( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #light, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glFragmentLightiSGIX (GLenum light, GLenum pname, GLint param);
#define glFragmentLightiSGIX( light, pname, param ) \
  glFragmentLightiSGIX( light, pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glFragmentLightiSGIX( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #light, #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glFragmentLightivSGIX (GLenum light, GLenum pname, const GLint *params);
#define glFragmentLightivSGIX( light, pname, params ) \
  glFragmentLightivSGIX( light, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glFragmentLightivSGIX( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #light, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glFragmentMaterialfSGIX (GLenum face, GLenum pname, GLfloat param);
#define glFragmentMaterialfSGIX( face, pname, param ) \
  glFragmentMaterialfSGIX( face, pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glFragmentMaterialfSGIX( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #face, #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glFragmentMaterialfvSGIX (GLenum face, GLenum pname, const GLfloat *params);
#define glFragmentMaterialfvSGIX( face, pname, params ) \
  glFragmentMaterialfvSGIX( face, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glFragmentMaterialfvSGIX( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #face, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glFragmentMaterialiSGIX (GLenum face, GLenum pname, GLint param);
#define glFragmentMaterialiSGIX( face, pname, param ) \
  glFragmentMaterialiSGIX( face, pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glFragmentMaterialiSGIX( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #face, #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glFragmentMaterialivSGIX (GLenum face, GLenum pname, const GLint *params);
#define glFragmentMaterialivSGIX( face, pname, params ) \
  glFragmentMaterialivSGIX( face, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glFragmentMaterialivSGIX( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #face, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glFrameZoomSGIX (GLint factor);
#define glFrameZoomSGIX( factor ) \
  glFrameZoomSGIX( factor );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glFrameZoomSGIX( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #factor, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glFrontFace (GLenum mode);
#define glFrontFace( mode ) \
  glFrontFace( mode );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glFrontFace( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #mode, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glFrustum (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far);
#define glFrustum( left, right, bottom, top, near, far ) \
  glFrustum( left, right, bottom, top, near, far );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glFrustum( %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #left, #right, #bottom, #top, #near, #far, __glDebug_ErrorStringMacro(_e) ); \
  }

extern GLuint glGenAsyncMarkersSGIX (GLsizei range);
static GLuint __glDebug_GLuint;
#define glGenAsyncMarkersSGIX( range ) \
  __glDebug_GLuint = glGenAsyncMarkersSGIX( range );
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGenAsyncMarkersSGIX( %s ) returned %d with error: %s\n", \
	      __FILE__, __LINE__, \
	      #range, __glDebug_GLuint, \
              __glDebug_ErrorStringMacro(_e) ); \
  }
    
extern GLuint glGenLists (GLsizei range);
#define glGenLists( range ) \
  __glDebug_GLuint = glGenLists( range );
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGenLists( %s ) returned %d with error: %s\n", \
	      __FILE__, __LINE__, \
	      #range, __glDebug_GLuint, \
              __glDebug_ErrorStringMacro(_e) ); \
  }
    
extern void glGenTextures (GLsizei n, GLuint *textures);
#define glGenTextures( n, textures ) \
  glGenTextures( n, textures );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGenTextures( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #n, #textures, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGenTexturesEXT (GLsizei n, GLuint *textures);
#define glGenTexturesEXT( n, textures ) \
  glGenTexturesEXT( n, textures );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGenTexturesEXT( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #n, #textures, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetBooleanv (GLenum pname, GLboolean *params);
#define glGetBooleanv( pname, params ) \
  glGetBooleanv( pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetBooleanv( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetClipPlane (GLenum plane, GLdouble *equation);
#define glGetClipPlane( plane, equation ) \
  glGetClipPlane( plane, equation );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetClipPlane( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #plane, #equation, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetColorTable (GLenum target, GLenum format, GLenum type, GLvoid *table);
#define glGetColorTable( target, format, type, table ) \
  glGetColorTable( target, format, type, table );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetColorTable( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #format, #type, #table, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetColorTableParameterfv (GLenum target, GLenum pname, GLfloat *params);
#define glGetColorTableParameterfv( target, pname, params ) \
  glGetColorTableParameterfv( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetColorTableParameterfv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetColorTableParameterfvSGI (GLenum target, GLenum pname, GLfloat *params);
#define glGetColorTableParameterfvSGI( target, pname, params ) \
  glGetColorTableParameterfvSGI( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetColorTableParameterfvSGI( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetColorTableParameteriv (GLenum target, GLenum pname, GLint *params);
#define glGetColorTableParameteriv( target, pname, params ) \
  glGetColorTableParameteriv( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetColorTableParameteriv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetColorTableParameterivSGI (GLenum target, GLenum pname, GLint *params);
#define glGetColorTableParameterivSGI( target, pname, params ) \
  glGetColorTableParameterivSGI( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetColorTableParameterivSGI( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetColorTableSGI (GLenum target, GLenum format, GLenum type, GLvoid *table);
#define glGetColorTableSGI( target, format, type, table ) \
  glGetColorTableSGI( target, format, type, table );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetColorTableSGI( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #format, #type, #table, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetConvolutionFilter (GLenum target, GLenum format, GLenum type, GLvoid *image);
#define glGetConvolutionFilter( target, format, type, image ) \
  glGetConvolutionFilter( target, format, type, image );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetConvolutionFilter( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #format, #type, #image, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetConvolutionFilterEXT (GLenum target, GLenum format, GLenum type, GLvoid *image);
#define glGetConvolutionFilterEXT( target, format, type, image ) \
  glGetConvolutionFilterEXT( target, format, type, image );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetConvolutionFilterEXT( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #format, #type, #image, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetConvolutionParameterfv (GLenum target, GLenum pname, GLfloat *params);
#define glGetConvolutionParameterfv( target, pname, params ) \
  glGetConvolutionParameterfv( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetConvolutionParameterfv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetConvolutionParameterfvEXT (GLenum target, GLenum pname, GLfloat *params);
#define glGetConvolutionParameterfvEXT( target, pname, params ) \
  glGetConvolutionParameterfvEXT( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetConvolutionParameterfvEXT( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetConvolutionParameteriv (GLenum target, GLenum pname, GLint *params);
#define glGetConvolutionParameteriv( target, pname, params ) \
  glGetConvolutionParameteriv( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetConvolutionParameteriv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetConvolutionParameterivEXT (GLenum target, GLenum pname, GLint *params);
#define glGetConvolutionParameterivEXT( target, pname, params ) \
  glGetConvolutionParameterivEXT( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetConvolutionParameterivEXT( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetDetailTexFuncSGIS (GLenum target, GLfloat *points);
#define glGetDetailTexFuncSGIS( target, points ) \
  glGetDetailTexFuncSGIS( target, points );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetDetailTexFuncSGIS( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #points, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetDoublev (GLenum pname, GLdouble *params);
#define glGetDoublev( pname, params ) \
  glGetDoublev( pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetDoublev( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern GLenum glGetError (void);
extern void glGetFloatv (GLenum pname, GLfloat *params);
#define glGetFloatv( pname, params ) \
  glGetFloatv( pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetFloatv( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetFogFuncSGIS (const GLfloat *points);
#define glGetFogFuncSGIS( points ) \
  glGetFogFuncSGIS( points );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetFogFuncSGIS( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #points, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetFragmentLightfvSGIX (GLenum light, GLenum pname, GLfloat *params);
#define glGetFragmentLightfvSGIX( light, pname, params ) \
  glGetFragmentLightfvSGIX( light, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetFragmentLightfvSGIX( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #light, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetFragmentLightivSGIX (GLenum light, GLenum pname, GLint *params);
#define glGetFragmentLightivSGIX( light, pname, params ) \
  glGetFragmentLightivSGIX( light, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetFragmentLightivSGIX( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #light, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetFragmentMaterialfvSGIX (GLenum face, GLenum pname, GLfloat *params);
#define glGetFragmentMaterialfvSGIX( face, pname, params ) \
  glGetFragmentMaterialfvSGIX( face, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetFragmentMaterialfvSGIX( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #face, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetFragmentMaterialivSGIX (GLenum face, GLenum pname, GLint *params);
#define glGetFragmentMaterialivSGIX( face, pname, params ) \
  glGetFragmentMaterialivSGIX( face, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetFragmentMaterialivSGIX( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #face, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetHistogram (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
#define glGetHistogram( target, reset, format, type, values ) \
  glGetHistogram( target, reset, format, type, values );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetHistogram( %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #reset, #format, #type, #values, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetHistogramEXT (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
#define glGetHistogramEXT( target, reset, format, type, values ) \
  glGetHistogramEXT( target, reset, format, type, values );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetHistogramEXT( %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #reset, #format, #type, #values, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetHistogramParameterfv (GLenum target, GLenum pname, GLfloat *params);
#define glGetHistogramParameterfv( target, pname, params ) \
  glGetHistogramParameterfv( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetHistogramParameterfv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetHistogramParameterfvEXT (GLenum target, GLenum pname, GLfloat *params);
#define glGetHistogramParameterfvEXT( target, pname, params ) \
  glGetHistogramParameterfvEXT( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetHistogramParameterfvEXT( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetHistogramParameteriv (GLenum target, GLenum pname, GLint *params);
#define glGetHistogramParameteriv( target, pname, params ) \
  glGetHistogramParameteriv( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetHistogramParameteriv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetHistogramParameterivEXT (GLenum target, GLenum pname, GLint *params);
#define glGetHistogramParameterivEXT( target, pname, params ) \
  glGetHistogramParameterivEXT( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetHistogramParameterivEXT( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern GLint glGetInstrumentsSGIX (void);
#define glGetInstrumentsSGIX() \
  __glDebug_GLint = glGetInstrumentsSGIX();
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetInstrumentsSGIX() returned %d with error: %s\n", \
	      __FILE__, __LINE__, \
	      __glDebug_GLint, \
              __glDebug_ErrorStringMacro(_e) ); \
  }
    
extern void glGetIntegerv (GLenum pname, GLint *params);
#define glGetIntegerv( pname, params ) \
  glGetIntegerv( pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetIntegerv( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetLightfv (GLenum light, GLenum pname, GLfloat *params);
#define glGetLightfv( light, pname, params ) \
  glGetLightfv( light, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetLightfv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #light, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetLightiv (GLenum light, GLenum pname, GLint *params);
#define glGetLightiv( light, pname, params ) \
  glGetLightiv( light, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetLightiv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #light, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetListParameterfvSGIX (GLuint list, GLenum pname, GLfloat *params);
#define glGetListParameterfvSGIX( list, pname, params ) \
  glGetListParameterfvSGIX( list, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetListParameterfvSGIX( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #list, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetListParameterivSGIX (GLuint list, GLenum pname, GLint *params);
#define glGetListParameterivSGIX( list, pname, params ) \
  glGetListParameterivSGIX( list, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetListParameterivSGIX( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #list, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetMapdv (GLenum target, GLenum query, GLdouble *v);
#define glGetMapdv( target, query, v ) \
  glGetMapdv( target, query, v );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetMapdv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #query, #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetMapfv (GLenum target, GLenum query, GLfloat *v);
#define glGetMapfv( target, query, v ) \
  glGetMapfv( target, query, v );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetMapfv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #query, #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetMapiv (GLenum target, GLenum query, GLint *v);
#define glGetMapiv( target, query, v ) \
  glGetMapiv( target, query, v );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetMapiv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #query, #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetMaterialfv (GLenum face, GLenum pname, GLfloat *params);
#define glGetMaterialfv( face, pname, params ) \
  glGetMaterialfv( face, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetMaterialfv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #face, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetMaterialiv (GLenum face, GLenum pname, GLint *params);
#define glGetMaterialiv( face, pname, params ) \
  glGetMaterialiv( face, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetMaterialiv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #face, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetMinmax (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
#define glGetMinmax( target, reset, format, type, values ) \
  glGetMinmax( target, reset, format, type, values );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetMinmax( %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #reset, #format, #type, #values, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetMinmaxEXT (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
#define glGetMinmaxEXT( target, reset, format, type, values ) \
  glGetMinmaxEXT( target, reset, format, type, values );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetMinmaxEXT( %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #reset, #format, #type, #values, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetMinmaxParameterfv (GLenum target, GLenum pname, GLfloat *params);
#define glGetMinmaxParameterfv( target, pname, params ) \
  glGetMinmaxParameterfv( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetMinmaxParameterfv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetMinmaxParameterfvEXT (GLenum target, GLenum pname, GLfloat *params);
#define glGetMinmaxParameterfvEXT( target, pname, params ) \
  glGetMinmaxParameterfvEXT( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetMinmaxParameterfvEXT( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetMinmaxParameteriv (GLenum target, GLenum pname, GLint *params);
#define glGetMinmaxParameteriv( target, pname, params ) \
  glGetMinmaxParameteriv( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetMinmaxParameteriv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetMinmaxParameterivEXT (GLenum target, GLenum pname, GLint *params);
#define glGetMinmaxParameterivEXT( target, pname, params ) \
  glGetMinmaxParameterivEXT( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetMinmaxParameterivEXT( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetPixelMapfv (GLenum map, GLfloat *values);
#define glGetPixelMapfv( map, values ) \
  glGetPixelMapfv( map, values );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetPixelMapfv( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #map, #values, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetPixelMapuiv (GLenum map, GLuint *values);
#define glGetPixelMapuiv( map, values ) \
  glGetPixelMapuiv( map, values );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetPixelMapuiv( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #map, #values, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetPixelMapusv (GLenum map, GLushort *values);
#define glGetPixelMapusv( map, values ) \
  glGetPixelMapusv( map, values );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetPixelMapusv( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #map, #values, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetPixelTexGenParameterfvSGIS (GLenum pname, GLfloat *params);
#define glGetPixelTexGenParameterfvSGIS( pname, params ) \
  glGetPixelTexGenParameterfvSGIS( pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetPixelTexGenParameterfvSGIS( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetPixelTexGenParameterivSGIS (GLenum pname, GLint *params);
#define glGetPixelTexGenParameterivSGIS( pname, params ) \
  glGetPixelTexGenParameterivSGIS( pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetPixelTexGenParameterivSGIS( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetPointerv (GLenum pname, GLvoid* *params);
#define glGetPointerv( pname, params ) \
  glGetPointerv( pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetPointerv( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetPointervEXT (GLenum pname, GLvoid* *params);
#define glGetPointerv( pname, params ) \
  glGetPointerv( pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetPointerv( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetPolygonStipple (GLubyte *mask);
#define glGetPolygonStipple( mask ) \
  glGetPolygonStipple( mask );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetPolygonStipple( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #mask, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetSeparableFilter (GLenum target, GLenum format, GLenum type, GLvoid *row, GLvoid *column, GLvoid *span);
#define glGetSeparableFilter( target, format, type, row, column, span ) \
  glGetSeparableFilter( target, format, type, row, column, span );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetSeparableFilter( %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #format, #type, #row, #column, #span, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetSeparableFilterEXT (GLenum target, GLenum format, GLenum type, GLvoid *row, GLvoid *column, GLvoid *span);
#define glGetSeparableFilterEXT( target, format, type, row, column, span ) \
  glGetSeparableFilterEXT( target, format, type, row, column, span );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetSeparableFilterEXT( %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #format, #type, #row, #column, #span, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetSharpenTexFuncSGIS (GLenum target, GLfloat *points);
#define glGetSharpenTexFuncSGIS( target, points ) \
  glGetSharpenTexFuncSGIS( target, points );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetSharpenTexFuncSGIS( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #points, __glDebug_ErrorStringMacro(_e) ); \
  }

extern const GLubyte * glGetString (GLenum name);
static const GLubyte * __glDebug_GLubyte ;
#define glGetString( name ) \
  __glDebug_GLubyte  = glGetString( name );
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetString( %s ) returned  with error: %s\n", \
	      __FILE__, __LINE__, \
	      #name, __glDebug_GLubyte , \
              __glDebug_ErrorStringMacro(_e) ); \
  }
    
extern void glGetTexEnvfv (GLenum target, GLenum pname, GLfloat *params);
#define glGetTexEnvfv( target, pname, params ) \
  glGetTexEnvfv( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetTexEnvfv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetTexEnviv (GLenum target, GLenum pname, GLint *params);
#define glGetTexEnviv( target, pname, params ) \
  glGetTexEnviv( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetTexEnviv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetTexFilterFuncSGIS (GLenum target, GLenum filter, GLfloat *weights);
#define glGetTexFilterFuncSGIS( target, filter, weights ) \
  glGetTexFilterFuncSGIS( target, filter, weights );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetTexFilterFuncSGIS( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #filter, #weights, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetTexGendv (GLenum coord, GLenum pname, GLdouble *params);
#define glGetTexGendv( coord, pname, params ) \
  glGetTexGendv( coord, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetTexGendv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #coord, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetTexGenfv (GLenum coord, GLenum pname, GLfloat *params);
#define glGetTexGenfv( coord, pname, params ) \
  glGetTexGenfv( coord, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetTexGenfv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #coord, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetTexGeniv (GLenum coord, GLenum pname, GLint *params);
#define glGetTexGeniv( coord, pname, params ) \
  glGetTexGeniv( coord, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetTexGeniv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #coord, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetTexImage (GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels);
#define glGetTexImage( target, level, format, type, pixels ) \
  glGetTexImage( target, level, format, type, pixels );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetTexImage( %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #level, #format, #type, #pixels, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetTexLevelParameterfv (GLenum target, GLint level, GLenum pname, GLfloat *params);
#define glGetTexLevelParameterfv( target, level, pname, params ) \
  glGetTexLevelParameterfv( target, level, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetTexLevelParameterfv( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #level, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetTexLevelParameteriv (GLenum target, GLint level, GLenum pname, GLint *params);
#define glGetTexLevelParameteriv( target, level, pname, params ) \
  glGetTexLevelParameteriv( target, level, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetTexLevelParameteriv( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #level, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetTexParameterfv (GLenum target, GLenum pname, GLfloat *params);
#define glGetTexParameterfv( target, pname, params ) \
  glGetTexParameterfv( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetTexParameterfv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glGetTexParameteriv (GLenum target, GLenum pname, GLint *params);
#define glGetTexParameteriv( target, pname, params ) \
  glGetTexParameteriv( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glGetTexParameteriv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glHint (GLenum target, GLenum mode);
#define glHint( target, mode ) \
  glHint( target, mode );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glHint( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #mode, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glHistogram (GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
#define glHistogram( target, width, internalformat, sink ) \
  glHistogram( target, width, internalformat, sink );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glHistogram( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #width, #internalformat, #sink, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glHistogramEXT (GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
#define glHistogramEXT( target, width, internalformat, sink ) \
  glHistogramEXT( target, width, internalformat, sink );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glHistogramEXT( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #width, #internalformat, #sink, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glIndexMask (GLuint mask);
#define glIndexMask( mask ) \
  glIndexMask( mask );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glIndexMask( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #mask, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glIndexPointer (GLenum type, GLsizei stride, const GLvoid *pointer);
#define glIndexPointer( type, stride, pointer ) \
  glIndexPointer( type, stride, pointer );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glIndexPointer( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #type, #stride, #pointer, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glIndexPointerEXT (GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
#define glIndexPointerEXT( type, stride, count, pointer ) \
  glIndexPointerEXT( type, stride, count, pointer );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glIndexPointerEXT( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #type, #stride, #count, #pointer, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glIndexd (GLdouble c);
#define glIndexd( c ) \
  glIndexd( c ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glIndexd( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #c, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glIndexdv (const GLdouble *c);
#define glIndexdv( c ) \
  glIndexdv( c ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glIndexdv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #c, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glIndexf (GLfloat c);
#define glIndexf( c ) \
  glIndexf( c ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glIndexf( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #c, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glIndexfv (const GLfloat *c);
#define glIndexfv( c ) \
  glIndexfv( c ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glIndexfv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #c, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glIndexi (GLint c);
#define glIndexi( c ) \
  glIndexi( c ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glIndexi( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #c, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glIndexiv (const GLint *c);
#define glIndexiv( c ) \
  glIndexiv( c ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glIndexiv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #c, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glIndexs (GLshort c);
#define glIndexs( c ) \
  glIndexs( c ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glIndexs( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #c, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glIndexsv (const GLshort *c);
#define glIndexsv( c ) \
  glIndexsv( c ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glIndexsv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #c, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glIndexub (GLubyte c);
#define glIndexub( c ) \
  glIndexub( c ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glIndexub( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #c, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glIndexubv (const GLubyte *c);
#define glIndexubv( c ) \
  glIndexubv( c ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glIndexubv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #c, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glInitNames (void);
#define glInitNames() \
  glInitNames();  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glInitNames() returned an error: %s\n", \
              __FILE__, __LINE__, \
	      __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glInstrumentsBufferSGIX (GLsizei size, GLint *buffer);
#define glInstrumentsBufferSGIX( size, buffer ) \
  glInstrumentsBufferSGIX( size, buffer );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glInstrumentsBufferSGIX( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #size, #buffer, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glInterleavedArrays (GLenum format, GLsizei stride, const GLvoid *pointer);
#define glInterleavedArrays( format, stride, pointer ) \
  glInterleavedArrays( format, stride, pointer );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glInterleavedArrays( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #format, #stride, #pointer, __glDebug_ErrorStringMacro(_e) ); \
  }

extern GLboolean glIsAsyncMarkerSGIX (GLuint marker);
#define glIsAsyncMarkerSGIX( marker ) \
  __glDebug_GLboolean = glIsAsyncMarkerSGIX( marker );
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glIsAsyncMarkerSGIX( %s ) returned %d with error: %s\n", \
	      __FILE__, __LINE__, \
	      #marker, __glDebug_GLboolean, \
              __glDebug_ErrorStringMacro(_e) ); \
  }
    
extern GLboolean glIsEnabled (GLenum cap);
#define glIsEnabled( cap ) \
  __glDebug_GLboolean = glIsEnabled( cap );
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glIsEnabled( %s ) returned %d with error: %s\n", \
	      __FILE__, __LINE__, \
	      #cap, __glDebug_GLboolean, \
              __glDebug_ErrorStringMacro(_e) ); \
  }
    
extern GLboolean glIsList (GLuint list);
#define glIsList( list ) \
  __glDebug_GLboolean = glIsList( list );
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glIsList( %s ) returned %d with error: %s\n", \
	      __FILE__, __LINE__, \
	      #list, __glDebug_GLboolean, \
              __glDebug_ErrorStringMacro(_e) ); \
  }
    
extern GLboolean glIsTexture (GLuint texture);
#define glIsTexture( texture ) \
  __glDebug_GLboolean = glIsTexture( texture );
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glIsTexture( %s ) returned %d with error: %s\n", \
	      __FILE__, __LINE__, \
	      #texture, __glDebug_GLboolean, \
              __glDebug_ErrorStringMacro(_e) ); \
  }
    
extern GLboolean glIsTextureEXT (GLuint texture);
#define glIsTextureEXT( texture ) \
  __glDebug_GLboolean = glIsTextureEXT( texture );
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glIsTextureEXT( %s ) returned %d with error: %s\n", \
	      __FILE__, __LINE__, \
	      #texture, __glDebug_GLboolean, \
              __glDebug_ErrorStringMacro(_e) ); \
  }
    
extern void glLightEnviSGIX (GLenum pname, GLint param);
#define glLightEnviSGIX( pname, param ) \
  glLightEnviSGIX( pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glLightEnviSGIX( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glLightModelf (GLenum pname, GLfloat param);
#define glLightModelf( pname, param ) \
  glLightModelf( pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glLightModelf( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glLightModelfv (GLenum pname, const GLfloat *params);
#define glLightModelfv( pname, params ) \
  glLightModelfv( pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glLightModelfv( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glLightModeli (GLenum pname, GLint param);
#define glLightModeli( pname, param ) \
  glLightModeli( pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glLightModeli( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glLightModeliv (GLenum pname, const GLint *params);
#define glLightModeliv( pname, params ) \
  glLightModeliv( pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glLightModeliv( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glLightf (GLenum light, GLenum pname, GLfloat param);
#define glLightf( light, pname, param ) \
  glLightf( light, pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glLightf( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #light, #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glLightfv (GLenum light, GLenum pname, const GLfloat *params);
#define glLightfv( light, pname, params ) \
  glLightfv( light, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glLightfv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #light, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glLighti (GLenum light, GLenum pname, GLint param);
#define glLighti( light, pname, param ) \
  glLighti( light, pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glLighti( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #light, #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glLightiv (GLenum light, GLenum pname, const GLint *params);
#define glLightiv( light, pname, params ) \
  glLightiv( light, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glLightiv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #light, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glLineStipple (GLint factor, GLushort pattern);
#define glLineStipple( factor, pattern ) \
  glLineStipple( factor, pattern );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glLineStipple( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #factor, #pattern, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glLineWidth (GLfloat width);
#define glLineWidth( width ) \
  glLineWidth( width );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glLineWidth( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #width, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glListBase (GLuint base);
#define glListBase( base ) \
  glListBase( base );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glListBase( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #base, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glListParameterfSGIX (GLuint list, GLenum pname, GLfloat param);
#define glListParameterfSGIX( list, pname, param ) \
  glListParameterfSGIX( list, pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glListParameterfSGIX( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #list, #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glListParameterfvSGIX (GLuint list, GLenum pname, const GLfloat *params);
#define glListParameterfvSGIX( list, pname, params ) \
  glListParameterfvSGIX( list, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glListParameterfvSGIX( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #list, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glListParameteriSGIX (GLuint list, GLenum pname, GLint param);
#define glListParameteriSGIX( list, pname, param ) \
  glListParameteriSGIX( list, pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glListParameteriSGIX( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #list, #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glListParameterivSGIX (GLuint list, GLenum pname, const GLint *params);
#define glListParameterivSGIX( list, pname, params ) \
  glListParameterivSGIX( list, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glListParameterivSGIX( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #list, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glLoadIdentity (void);
#define glLoadIdentity() \
  glLoadIdentity();  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glLoadIdentity() returned an error: %s\n", \
              __FILE__, __LINE__, \
	      __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glLoadIdentityDeformationMapSGIX (GLbitfield mask);
#define glLoadIdentityDeformationMapSGIX( mask ) \
  glLoadIdentityDeformationMapSGIX( mask );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glLoadIdentityDeformationMapSGIX( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #mask, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glLoadMatrixd (const GLdouble *m);
#define glLoadMatrixd( m ) \
  glLoadMatrixd( m );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glLoadMatrixd( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #m, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glLoadMatrixf (const GLfloat *m);
#define glLoadMatrixf( m ) \
  glLoadMatrixf( m );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glLoadMatrixf( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #m, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glLoadName (GLuint name);
#define glLoadName( name ) \
  glLoadName( name );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glLoadName( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #name, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glLogicOp (GLenum opcode);
#define glLogicOp( opcode ) \
  glLogicOp( opcode );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glLogicOp( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #opcode, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glMap1d (GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
#define glMap1d( target, u1, u2, stride, order, points ) \
  glMap1d( target, u1, u2, stride, order, points );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glMap1d( %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #u1, #u2, #stride, #order, #points, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glMap1f (GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
#define glMap1f( target, u1, u2, stride, order, points ) \
  glMap1f( target, u1, u2, stride, order, points );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glMap1f( %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #u1, #u2, #stride, #order, #points, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glMap2d (GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
#define glMap2d( target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points ) \
  glMap2d( target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glMap2d( %s, %s, %s, %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #u1, #u2, #ustride, #uorder, #v1, #v2, #vstride, #vorder, #points, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glMap2f (GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
#define glMap2f( target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points ) \
  glMap2f( target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glMap2f( %s, %s, %s, %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #u1, #u2, #ustride, #uorder, #v1, #v2, #vstride, #vorder, #points, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glMapGrid1d (GLint un, GLdouble u1, GLdouble u2);
#define glMapGrid1d( un, u1, u2 ) \
  glMapGrid1d( un, u1, u2 );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glMapGrid1d( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #un, #u1, #u2, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glMapGrid1f (GLint un, GLfloat u1, GLfloat u2);
#define glMapGrid1f( un, u1, u2 ) \
  glMapGrid1f( un, u1, u2 );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glMapGrid1f( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #un, #u1, #u2, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glMapGrid2d (GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
#define glMapGrid2d( un, u1, u2, vn, v1, v2 ) \
  glMapGrid2d( un, u1, u2, vn, v1, v2 );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glMapGrid2d( %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #un, #u1, #u2, #vn, #v1, #v2, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glMapGrid2f (GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
#define glMapGrid2f( un, u1, u2, vn, v1, v2 ) \
  glMapGrid2f( un, u1, u2, vn, v1, v2 );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glMapGrid2f( %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #un, #u1, #u2, #vn, #v1, #v2, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glMaterialf (GLenum face, GLenum pname, GLfloat param);
#define glMaterialf( face, pname, param ) \
  glMaterialf( face, pname, param ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glMaterialf( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #face, #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glMaterialfv (GLenum face, GLenum pname, const GLfloat *params);
#define glMaterialfv( face, pname, params ) \
  glMaterialfv( face, pname, params ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glMaterialfv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #face, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glMateriali (GLenum face, GLenum pname, GLint param);
#define glMateriali( face, pname, param ) \
  glMateriali( face, pname, param ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glMateriali( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #face, #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glMaterialiv (GLenum face, GLenum pname, const GLint *params);
#define glMaterialiv( face, pname, params ) \
  glMaterialiv( face, pname, params ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glMaterialiv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #face, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glMatrixMode (GLenum mode);
#define glMatrixMode( mode ) \
  glMatrixMode( mode );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glMatrixMode( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #mode, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glMinmax (GLenum target, GLenum internalformat, GLboolean sink);
#define glMinmax( target, internalformat, sink ) \
  glMinmax( target, internalformat, sink );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glMinmax( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #internalformat, #sink, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glMinmaxEXT (GLenum target, GLenum internalformat, GLboolean sink);
#define glMinmaxEXT( target, internalformat, sink ) \
  glMinmaxEXT( target, internalformat, sink );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glMinmaxEXT( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #internalformat, #sink, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glMultMatrixd (const GLdouble *m);
#define glMultMatrixd( m ) \
  glMultMatrixd( m );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glMultMatrixd( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #m, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glMultMatrixf (const GLfloat *m);
#define glMultMatrixf( m ) \
  glMultMatrixf( m );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glMultMatrixf( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #m, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glNewList (GLuint list, GLenum mode);
#define glNewList( list, mode ) \
  glNewList( list, mode );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glNewList( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #list, #mode, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glNormal3b (GLbyte nx, GLbyte ny, GLbyte nz);
#define glNormal3b( nx, ny, nz ) \
  glNormal3b( nx, ny, nz ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glNormal3b( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #nx, #ny, #nz, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glNormal3bv (const GLbyte *v);
#define glNormal3bv( v ) \
  glNormal3bv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glNormal3bv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glNormal3d (GLdouble nx, GLdouble ny, GLdouble nz);
#define glNormal3d( nx, ny, nz ) \
  glNormal3d( nx, ny, nz ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glNormal3d( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #nx, #ny, #nz, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glNormal3dv (const GLdouble *v);
#define glNormal3dv( v ) \
  glNormal3dv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glNormal3dv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glNormal3f (GLfloat nx, GLfloat ny, GLfloat nz);
#define glNormal3f( nx, ny, nz ) \
  glNormal3f( nx, ny, nz ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glNormal3f( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #nx, #ny, #nz, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glNormal3fv (const GLfloat *v);
#define glNormal3fv( v ) \
  glNormal3fv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glNormal3fv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glNormal3i (GLint nx, GLint ny, GLint nz);
#define glNormal3i( nx, ny, nz ) \
  glNormal3i( nx, ny, nz ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glNormal3i( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #nx, #ny, #nz, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glNormal3iv (const GLint *v);
#define glNormal3iv( v ) \
  glNormal3iv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glNormal3iv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glNormal3s (GLshort nx, GLshort ny, GLshort nz);
#define glNormal3s( nx, ny, nz ) \
  glNormal3s( nx, ny, nz ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glNormal3s( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #nx, #ny, #nz, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glNormal3sv (const GLshort *v);
#define glNormal3sv( v ) \
  glNormal3sv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glNormal3sv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glNormalPointer (GLenum type, GLsizei stride, const GLvoid *pointer);
#define glNormalPointer( type, stride, pointer ) \
  glNormalPointer( type, stride, pointer );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glNormalPointer( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #type, #stride, #pointer, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glNormalPointerEXT (GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
#define glNormalPointerEXT( type, stride, count, pointer ) \
  glNormalPointerEXT( type, stride, count, pointer );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glNormalPointerEXT( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #type, #stride, #count, #pointer, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glOrtho (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far);
#define glOrtho( left, right, bottom, top, near, far ) \
  glOrtho( left, right, bottom, top, near, far );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glOrtho( %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #left, #right, #bottom, #top, #near, #far, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPassThrough (GLfloat token);
#define glPassThrough( token ) \
  glPassThrough( token );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPassThrough( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #token, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPixelMapfv (GLenum map, GLint mapsize, const GLfloat *values);
#define glPixelMapfv( map, mapsize, values ) \
  glPixelMapfv( map, mapsize, values );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPixelMapfv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #map, #mapsize, #values, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPixelMapuiv (GLenum map, GLint mapsize, const GLuint *values);
#define glPixelMapuiv( map, mapsize, values ) \
  glPixelMapuiv( map, mapsize, values );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPixelMapuiv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #map, #mapsize, #values, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPixelMapusv (GLenum map, GLint mapsize, const GLushort *values);
#define glPixelMapusv( map, mapsize, values ) \
  glPixelMapusv( map, mapsize, values );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPixelMapusv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #map, #mapsize, #values, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPixelStoref (GLenum pname, GLfloat param);
#define glPixelStoref( pname, param ) \
  glPixelStoref( pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPixelStoref( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPixelStorei (GLenum pname, GLint param);
#define glPixelStorei( pname, param ) \
  glPixelStorei( pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPixelStorei( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPixelTexGenParameterfSGIS (GLenum pname, GLfloat param);
#define glPixelTexGenParameterfSGIS( pname, param ) \
  glPixelTexGenParameterfSGIS( pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPixelTexGenParameterfSGIS( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPixelTexGenParameterfvSGIS (GLenum pname, const GLfloat *params);
#define glPixelTexGenParameterfvSGIS( pname, params ) \
  glPixelTexGenParameterfvSGIS( pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPixelTexGenParameterfvSGIS( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPixelTexGenParameteriSGIS (GLenum pname, GLint param);
#define glPixelTexGenParameteriSGIS( pname, param ) \
  glPixelTexGenParameteriSGIS( pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPixelTexGenParameteriSGIS( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPixelTexGenParameterivSGIS (GLenum pname, const GLint *params);
#define glPixelTexGenParameterivSGIS( pname, params ) \
  glPixelTexGenParameterivSGIS( pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPixelTexGenParameterivSGIS( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPixelTexGenSGIX (GLenum mode);
#define glPixelTexGenSGIX( mode ) \
  glPixelTexGenSGIX( mode );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPixelTexGenSGIX( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #mode, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPixelTransferf (GLenum pname, GLfloat param);
#define glPixelTransferf( pname, param ) \
  glPixelTransferf( pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPixelTransferf( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPixelTransferi (GLenum pname, GLint param);
#define glPixelTransferi( pname, param ) \
  glPixelTransferi( pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPixelTransferi( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPixelZoom (GLfloat xfactor, GLfloat yfactor);
#define glPixelZoom( xfactor, yfactor ) \
  glPixelZoom( xfactor, yfactor );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPixelZoom( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #xfactor, #yfactor, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPointParameterfEXT (GLenum pname, GLfloat param);
#define glPointParameterfEXT( pname, param ) \
  glPointParameterfEXT( pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPointParameterfEXT( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPointParameterfSGIS (GLenum pname, GLfloat param);
#define glPointParameterfSGIS( pname, param ) \
  glPointParameterfSGIS( pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPointParameterfSGIS( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPointParameterfvEXT (GLenum pname, const GLfloat *params);
#define glPointParameterfvEXT( pname, params ) \
  glPointParameterfvEXT( pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPointParameterfvEXT( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPointParameterfvSGIS (GLenum pname, const GLfloat *params);
#define glPointParameterfvSGIS( pname, params ) \
  glPointParameterfvSGIS( pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPointParameterfvSGIS( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPointSize (GLfloat size);
#define glPointSize( size ) \
  glPointSize( size );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPointSize( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #size, __glDebug_ErrorStringMacro(_e) ); \
  }

extern GLint glPollAsyncSGIX (GLuint *markerp);
#define glPollAsyncSGIX( markerp ) \
  __glDebug_GLint = glPollAsyncSGIX( markerp );
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPollAsyncSGIX( %s ) returned %d with error: %s\n", \
	      __FILE__, __LINE__, \
	      #markerp, __glDebug_GLint, \
              __glDebug_ErrorStringMacro(_e) ); \
  }
    
extern GLint glPollInstrumentsSGIX (GLint *marker_p);
#define glPollInstrumentsSGIX( marker_p ) \
  __glDebug_GLint = glPollInstrumentsSGIX( marker_p );
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPollInstrumentsSGIX( %s ) returned %d with error: %s\n", \
	      __FILE__, __LINE__, \
	      #marker_p, __glDebug_GLint, \
              __glDebug_ErrorStringMacro(_e) ); \
  }
    
extern void glPolygonMode (GLenum face, GLenum mode);
#define glPolygonMode( face, mode ) \
  glPolygonMode( face, mode );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPolygonMode( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #face, #mode, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPolygonOffset (GLfloat factor, GLfloat units);
#define glPolygonOffset( factor, units ) \
  glPolygonOffset( factor, units );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPolygonOffset( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #factor, #units, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPolygonOffsetEXT (GLfloat factor, GLfloat bias);
#define glPolygonOffsetEXT( factor, bias ) \
  glPolygonOffsetEXT( factor, bias );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPolygonOffsetEXT( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #factor, #bias, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPolygonStipple (const GLubyte *mask);
#define glPolygonStipple( mask ) \
  glPolygonStipple( mask );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPolygonStipple( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #mask, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPopAttrib (void);
#define glPopAttrib() \
  glPopAttrib();  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPopAttrib() returned an error: %s\n", \
              __FILE__, __LINE__, \
	      __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPopClientAttrib (void);
#define glPopClientAttrib() \
  glPopClientAttrib();  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPopClientAttrib() returned an error: %s\n", \
              __FILE__, __LINE__, \
	      __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPopMatrix (void);
#define glPopMatrix() \
  glPopMatrix();  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPopMatrix() returned an error: %s\n", \
              __FILE__, __LINE__, \
	      __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPopName (void);
#define glPopName() \
  glPopName();  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPopName() returned an error: %s\n", \
              __FILE__, __LINE__, \
	      __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPrioritizeTextures (GLsizei n, const GLuint *textures, const GLclampf *priorities);
#define glPrioritizeTextures( n, textures, priorities ) \
  glPrioritizeTextures( n, textures, priorities );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPrioritizeTextures( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #n, #textures, #priorities, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPrioritizeTexturesEXT (GLsizei n, const GLuint *textures, const GLclampf *priorities);
#define glPrioritizeTexturesEXT( n, textures, priorities ) \
  glPrioritizeTexturesEXT( n, textures, priorities );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPrioritizeTexturesEXT( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #n, #textures, #priorities, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPushAttrib (GLbitfield mask);
#define glPushAttrib( mask ) \
  glPushAttrib( mask );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPushAttrib( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #mask, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPushClientAttrib (GLbitfield mask);
#define glPushClientAttrib( mask ) \
  glPushClientAttrib( mask );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPushClientAttrib( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #mask, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPushMatrix (void);
#define glPushMatrix() \
  glPushMatrix();  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPushMatrix() returned an error: %s\n", \
              __FILE__, __LINE__, \
	      __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glPushName (GLuint name);
#define glPushName( name ) \
  glPushName( name );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glPushName( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #name, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRasterPos2d (GLdouble x, GLdouble y);
#define glRasterPos2d( x, y ) \
  glRasterPos2d( x, y );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRasterPos2d( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRasterPos2dv (const GLdouble *v);
#define glRasterPos2dv( v ) \
  glRasterPos2dv( v );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRasterPos2dv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRasterPos2f (GLfloat x, GLfloat y);
#define glRasterPos2f( x, y ) \
  glRasterPos2f( x, y );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRasterPos2f( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRasterPos2fv (const GLfloat *v);
#define glRasterPos2fv( v ) \
  glRasterPos2fv( v );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRasterPos2fv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRasterPos2i (GLint x, GLint y);
#define glRasterPos2i( x, y ) \
  glRasterPos2i( x, y );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRasterPos2i( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRasterPos2iv (const GLint *v);
#define glRasterPos2iv( v ) \
  glRasterPos2iv( v );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRasterPos2iv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRasterPos2s (GLshort x, GLshort y);
#define glRasterPos2s( x, y ) \
  glRasterPos2s( x, y );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRasterPos2s( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRasterPos2sv (const GLshort *v);
#define glRasterPos2sv( v ) \
  glRasterPos2sv( v );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRasterPos2sv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRasterPos3d (GLdouble x, GLdouble y, GLdouble z);
#define glRasterPos3d( x, y, z ) \
  glRasterPos3d( x, y, z );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRasterPos3d( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, #z, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRasterPos3dv (const GLdouble *v);
#define glRasterPos3dv( v ) \
  glRasterPos3dv( v );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRasterPos3dv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRasterPos3f (GLfloat x, GLfloat y, GLfloat z);
#define glRasterPos3f( x, y, z ) \
  glRasterPos3f( x, y, z );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRasterPos3f( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, #z, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRasterPos3fv (const GLfloat *v);
#define glRasterPos3fv( v ) \
  glRasterPos3fv( v );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRasterPos3fv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRasterPos3i (GLint x, GLint y, GLint z);
#define glRasterPos3i( x, y, z ) \
  glRasterPos3i( x, y, z );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRasterPos3i( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, #z, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRasterPos3iv (const GLint *v);
#define glRasterPos3iv( v ) \
  glRasterPos3iv( v );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRasterPos3iv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRasterPos3s (GLshort x, GLshort y, GLshort z);
#define glRasterPos3s( x, y, z ) \
  glRasterPos3s( x, y, z );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRasterPos3s( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, #z, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRasterPos3sv (const GLshort *v);
#define glRasterPos3sv( v ) \
  glRasterPos3sv( v );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRasterPos3sv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRasterPos4d (GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glRasterPos4d( x, y, z, w ) \
  glRasterPos4d( x, y, z, w );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRasterPos4d( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, #z, #w, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRasterPos4dv (const GLdouble *v);
#define glRasterPos4dv( v ) \
  glRasterPos4dv( v );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRasterPos4dv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRasterPos4f (GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#define glRasterPos4f( x, y, z, w ) \
  glRasterPos4f( x, y, z, w );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRasterPos4f( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, #z, #w, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRasterPos4fv (const GLfloat *v);
#define glRasterPos4fv( v ) \
  glRasterPos4fv( v );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRasterPos4fv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRasterPos4i (GLint x, GLint y, GLint z, GLint w);
#define glRasterPos4i( x, y, z, w ) \
  glRasterPos4i( x, y, z, w );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRasterPos4i( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, #z, #w, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRasterPos4iv (const GLint *v);
#define glRasterPos4iv( v ) \
  glRasterPos4iv( v );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRasterPos4iv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRasterPos4s (GLshort x, GLshort y, GLshort z, GLshort w);
#define glRasterPos4s( x, y, z, w ) \
  glRasterPos4s( x, y, z, w );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRasterPos4s( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, #z, #w, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRasterPos4sv (const GLshort *v);
#define glRasterPos4sv( v ) \
  glRasterPos4sv( v );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRasterPos4sv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glReadBuffer (GLenum mode);
#define glReadBuffer( mode ) \
  glReadBuffer( mode );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glReadBuffer( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #mode, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glReadInstrumentsSGIX (GLint marker);
#define glReadInstrumentsSGIX( marker ) \
  glReadInstrumentsSGIX( marker );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glReadInstrumentsSGIX( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #marker, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glReadPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
#define glReadPixels( x, y, width, height, format, type, pixels ) \
  glReadPixels( x, y, width, height, format, type, pixels );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glReadPixels( %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, #width, #height, #format, #type, #pixels, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRectd (GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
#define glRectd( x1, y1, x2, y2 ) \
  glRectd( x1, y1, x2, y2 );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRectd( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x1, #y1, #x2, #y2, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRectdv (const GLdouble *v1, const GLdouble *v2);
#define glRectdv( v1, v2 ) \
  glRectdv( v1, v2 );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRectdv( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v1, #v2, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRectf (GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
#define glRectf( x1, y1, x2, y2 ) \
  glRectf( x1, y1, x2, y2 );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRectf( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x1, #y1, #x2, #y2, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRectfv (const GLfloat *v1, const GLfloat *v2);
#define glRectfv( v1, v2 ) \
  glRectfv( v1, v2 );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRectfv( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v1, #v2, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRecti (GLint x1, GLint y1, GLint x2, GLint y2);
#define glRecti( x1, y1, x2, y2 ) \
  glRecti( x1, y1, x2, y2 );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRecti( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x1, #y1, #x2, #y2, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRectiv (const GLint *v1, const GLint *v2);
#define glRectiv( v1, v2 ) \
  glRectiv( v1, v2 );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRectiv( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v1, #v2, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRects (GLshort x1, GLshort y1, GLshort x2, GLshort y2);
#define glRects( x1, y1, x2, y2 ) \
  glRects( x1, y1, x2, y2 );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRects( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x1, #y1, #x2, #y2, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRectsv (const GLshort *v1, const GLshort *v2);
#define glRectsv( v1, v2 ) \
  glRectsv( v1, v2 );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRectsv( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v1, #v2, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glReferencePlaneSGIX (const GLdouble *equation);
#define glReferencePlaneSGIX( equation ) \
  glReferencePlaneSGIX( equation );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glReferencePlaneSGIX( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #equation, __glDebug_ErrorStringMacro(_e) ); \
  }

extern GLint glRenderMode (GLenum mode);
#define glRenderMode( mode ) \
  __glDebug_GLint = glRenderMode( mode );
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRenderMode( %s ) returned %d with error: %s\n", \
	      __FILE__, __LINE__, \
	      #mode, __glDebug_GLint, \
              __glDebug_ErrorStringMacro(_e) ); \
  }
    
extern void glResetHistogram (GLenum target);
#define glResetHistogram( target ) \
  glResetHistogram( target );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glResetHistogram( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glResetHistogramEXT (GLenum target);
#define glResetHistogramEXT( target ) \
  glResetHistogramEXT( target );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glResetHistogramEXT( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glResetMinmax (GLenum target);
#define glResetMinmax( target ) \
  glResetMinmax( target );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glResetMinmax( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glResetMinmaxEXT (GLenum target);
#define glResetMinmaxEXT( target ) \
  glResetMinmaxEXT( target );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glResetMinmaxEXT( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRotated (GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
#define glRotated( angle, x, y, z ) \
  glRotated( angle, x, y, z );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRotated( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #angle, #x, #y, #z, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glRotatef (GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
#define glRotatef( angle, x, y, z ) \
  glRotatef( angle, x, y, z );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glRotatef( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #angle, #x, #y, #z, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glSampleMaskSGIS (GLclampf value, GLboolean invert);
#define glSampleMaskSGIS( value, invert ) \
  glSampleMaskSGIS( value, invert );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glSampleMaskSGIS( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #value, #invert, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glSamplePatternSGIS (GLenum pattern);
#define glSamplePatternSGIS( pattern ) \
  glSamplePatternSGIS( pattern );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glSamplePatternSGIS( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pattern, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glScaled (GLdouble x, GLdouble y, GLdouble z);
#define glScaled( x, y, z ) \
  glScaled( x, y, z );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glScaled( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, #z, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glScalef (GLfloat x, GLfloat y, GLfloat z);
#define glScalef( x, y, z ) \
  glScalef( x, y, z );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glScalef( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, #z, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glScissor (GLint x, GLint y, GLsizei width, GLsizei height);
#define glScissor( x, y, width, height ) \
  glScissor( x, y, width, height );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glScissor( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, #width, #height, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glSelectBuffer (GLsizei size, GLuint *buffer);
#define glSelectBuffer( size, buffer ) \
  glSelectBuffer( size, buffer );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glSelectBuffer( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #size, #buffer, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glSeparableFilter2D (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *row, const GLvoid *column);
#define glSeparableFilter2D( target, internalformat, width, height, format, type, row, column ) \
  glSeparableFilter2D( target, internalformat, width, height, format, type, row, column );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glSeparableFilter2D( %s, %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #internalformat, #width, #height, #format, #type, #row, #column, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glSeparableFilter2DEXT (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *row, const GLvoid *column);
#define glSeparableFilter2DEXT( target, internalformat, width, height, format, type, row, column ) \
  glSeparableFilter2DEXT( target, internalformat, width, height, format, type, row, column );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glSeparableFilter2DEXT( %s, %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #internalformat, #width, #height, #format, #type, #row, #column, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glShadeModel (GLenum mode);
#define glShadeModel( mode ) \
  glShadeModel( mode );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glShadeModel( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #mode, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glSharpenTexFuncSGIS (GLenum target, GLsizei n, const GLfloat *points);
#define glSharpenTexFuncSGIS( target, n, points ) \
  glSharpenTexFuncSGIS( target, n, points );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glSharpenTexFuncSGIS( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #n, #points, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glSpriteParameterfSGIX (GLenum pname, GLfloat param);
#define glSpriteParameterfSGIX( pname, param ) \
  glSpriteParameterfSGIX( pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glSpriteParameterfSGIX( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glSpriteParameterfvSGIX (GLenum pname, const GLfloat *params);
#define glSpriteParameterfvSGIX( pname, params ) \
  glSpriteParameterfvSGIX( pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glSpriteParameterfvSGIX( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glSpriteParameteriSGIX (GLenum pname, GLint param);
#define glSpriteParameteriSGIX( pname, param ) \
  glSpriteParameteriSGIX( pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glSpriteParameteriSGIX( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glSpriteParameterivSGIX (GLenum pname, const GLint *params);
#define glSpriteParameterivSGIX( pname, params ) \
  glSpriteParameterivSGIX( pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glSpriteParameterivSGIX( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glStartInstrumentsSGIX (void);
#define glStartInstrumentsSGIX() \
  glStartInstrumentsSGIX();  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glStartInstrumentsSGIX() returned an error: %s\n", \
              __FILE__, __LINE__, \
	      __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glStencilFunc (GLenum func, GLint ref, GLuint mask);
#define glStencilFunc( func, ref, mask ) \
  glStencilFunc( func, ref, mask );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glStencilFunc( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #func, #ref, #mask, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glStencilMask (GLuint mask);
#define glStencilMask( mask ) \
  glStencilMask( mask );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glStencilMask( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #mask, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glStencilOp (GLenum fail, GLenum zfail, GLenum zpass);
#define glStencilOp( fail, zfail, zpass ) \
  glStencilOp( fail, zfail, zpass );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glStencilOp( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #fail, #zfail, #zpass, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glStopInstrumentsSGIX (GLint marker);
#define glStopInstrumentsSGIX( marker ) \
  glStopInstrumentsSGIX( marker );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glStopInstrumentsSGIX( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #marker, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTagSampleBufferSGIX (void);
#define glTagSampleBufferSGIX() \
  glTagSampleBufferSGIX();  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTagSampleBufferSGIX() returned an error: %s\n", \
              __FILE__, __LINE__, \
	      __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord1d (GLdouble s);
#define glTexCoord1d( s ) \
  glTexCoord1d( s ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord1d( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #s, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord1dv (const GLdouble *v);
#define glTexCoord1dv( v ) \
  glTexCoord1dv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord1dv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord1f (GLfloat s);
#define glTexCoord1f( s ) \
  glTexCoord1f( s ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord1f( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #s, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord1fv (const GLfloat *v);
#define glTexCoord1fv( v ) \
  glTexCoord1fv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord1fv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord1i (GLint s);
#define glTexCoord1i( s ) \
  glTexCoord1i( s ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord1i( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #s, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord1iv (const GLint *v);
#define glTexCoord1iv( v ) \
  glTexCoord1iv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord1iv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord1s (GLshort s);
#define glTexCoord1s( s ) \
  glTexCoord1s( s ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord1s( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #s, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord1sv (const GLshort *v);
#define glTexCoord1sv( v ) \
  glTexCoord1sv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord1sv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord2d (GLdouble s, GLdouble t);
#define glTexCoord2d( s, t ) \
  glTexCoord2d( s, t ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord2d( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #s, #t, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord2dv (const GLdouble *v);
#define glTexCoord2dv( v ) \
  glTexCoord2dv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord2dv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord2f (GLfloat s, GLfloat t);
#define glTexCoord2f( s, t ) \
  glTexCoord2f( s, t ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord2f( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #s, #t, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord2fv (const GLfloat *v);
#define glTexCoord2fv( v ) \
  glTexCoord2fv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord2fv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord2i (GLint s, GLint t);
#define glTexCoord2i( s, t ) \
  glTexCoord2i( s, t ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord2i( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #s, #t, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord2iv (const GLint *v);
#define glTexCoord2iv( v ) \
  glTexCoord2iv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord2iv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord2s (GLshort s, GLshort t);
#define glTexCoord2s( s, t ) \
  glTexCoord2s( s, t ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord2s( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #s, #t, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord2sv (const GLshort *v);
#define glTexCoord2sv( v ) \
  glTexCoord2sv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord2sv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord3d (GLdouble s, GLdouble t, GLdouble r);
#define glTexCoord3d( s, t, r ) \
  glTexCoord3d( s, t, r ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord3d( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #s, #t, #r, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord3dv (const GLdouble *v);
#define glTexCoord3dv( v ) \
  glTexCoord3dv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord3dv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord3f (GLfloat s, GLfloat t, GLfloat r);
#define glTexCoord3f( s, t, r ) \
  glTexCoord3f( s, t, r ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord3f( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #s, #t, #r, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord3fv (const GLfloat *v);
#define glTexCoord3fv( v ) \
  glTexCoord3fv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord3fv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord3i (GLint s, GLint t, GLint r);
#define glTexCoord3i( s, t, r ) \
  glTexCoord3i( s, t, r ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord3i( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #s, #t, #r, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord3iv (const GLint *v);
#define glTexCoord3iv( v ) \
  glTexCoord3iv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord3iv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord3s (GLshort s, GLshort t, GLshort r);
#define glTexCoord3s( s, t, r ) \
  glTexCoord3s( s, t, r ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord3s( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #s, #t, #r, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord3sv (const GLshort *v);
#define glTexCoord3sv( v ) \
  glTexCoord3sv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord3sv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord4d (GLdouble s, GLdouble t, GLdouble r, GLdouble q);
#define glTexCoord4d( s, t, r, q ) \
  glTexCoord4d( s, t, r, q ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord4d( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #s, #t, #r, #q, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord4dv (const GLdouble *v);
#define glTexCoord4dv( v ) \
  glTexCoord4dv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord4dv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord4f (GLfloat s, GLfloat t, GLfloat r, GLfloat q);
#define glTexCoord4f( s, t, r, q ) \
  glTexCoord4f( s, t, r, q ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord4f( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #s, #t, #r, #q, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord4fv (const GLfloat *v);
#define glTexCoord4fv( v ) \
  glTexCoord4fv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord4fv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord4i (GLint s, GLint t, GLint r, GLint q);
#define glTexCoord4i( s, t, r, q ) \
  glTexCoord4i( s, t, r, q ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord4i( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #s, #t, #r, #q, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord4iv (const GLint *v);
#define glTexCoord4iv( v ) \
  glTexCoord4iv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord4iv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord4s (GLshort s, GLshort t, GLshort r, GLshort q);
#define glTexCoord4s( s, t, r, q ) \
  glTexCoord4s( s, t, r, q ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord4s( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #s, #t, #r, #q, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoord4sv (const GLshort *v);
#define glTexCoord4sv( v ) \
  glTexCoord4sv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoord4sv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoordPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
#define glTexCoordPointer( size, type, stride, pointer ) \
  glTexCoordPointer( size, type, stride, pointer );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoordPointer( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #size, #type, #stride, #pointer, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexCoordPointerEXT (GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
#define glTexCoordPointerEXT( size, type, stride, count, pointer ) \
  glTexCoordPointerEXT( size, type, stride, count, pointer );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexCoordPointerEXT( %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #size, #type, #stride, #count, #pointer, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexEnvf (GLenum target, GLenum pname, GLfloat param);
#define glTexEnvf( target, pname, param ) \
  glTexEnvf( target, pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexEnvf( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexEnvfv (GLenum target, GLenum pname, const GLfloat *params);
#define glTexEnvfv( target, pname, params ) \
  glTexEnvfv( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexEnvfv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexEnvi (GLenum target, GLenum pname, GLint param);
#define glTexEnvi( target, pname, param ) \
  glTexEnvi( target, pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexEnvi( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexEnviv (GLenum target, GLenum pname, const GLint *params);
#define glTexEnviv( target, pname, params ) \
  glTexEnviv( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexEnviv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexFilterFuncSGIS (GLenum target, GLenum filter, GLsizei n, const GLfloat *weights);
#define glTexFilterFuncSGIS( target, filter, n, weights ) \
  glTexFilterFuncSGIS( target, filter, n, weights );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexFilterFuncSGIS( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #filter, #n, #weights, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexGend (GLenum coord, GLenum pname, GLdouble param);
#define glTexGend( coord, pname, param ) \
  glTexGend( coord, pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexGend( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #coord, #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexGendv (GLenum coord, GLenum pname, const GLdouble *params);
#define glTexGendv( coord, pname, params ) \
  glTexGendv( coord, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexGendv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #coord, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexGenf (GLenum coord, GLenum pname, GLfloat param);
#define glTexGenf( coord, pname, param ) \
  glTexGenf( coord, pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexGenf( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #coord, #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexGenfv (GLenum coord, GLenum pname, const GLfloat *params);
#define glTexGenfv( coord, pname, params ) \
  glTexGenfv( coord, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexGenfv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #coord, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexGeni (GLenum coord, GLenum pname, GLint param);
#define glTexGeni( coord, pname, param ) \
  glTexGeni( coord, pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexGeni( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #coord, #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexGeniv (GLenum coord, GLenum pname, const GLint *params);
#define glTexGeniv( coord, pname, params ) \
  glTexGeniv( coord, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexGeniv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #coord, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexImage1D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
#define glTexImage1D( target, level, internalformat, width, border, format, type, pixels ) \
  glTexImage1D( target, level, internalformat, width, border, format, type, pixels );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexImage1D( %s, %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #level, #internalformat, #width, #border, #format, #type, #pixels, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexImage2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
#define glTexImage2D( target, level, internalformat, width, height, border, format, type, pixels ) \
  glTexImage2D( target, level, internalformat, width, height, border, format, type, pixels );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexImage2D( %s, %s, %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #level, #internalformat, #width, #height, #border, #format, #type, #pixels, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexImage3D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
#define glTexImage3D( target, level, internalformat, width, height, depth, border, format, type, pixels ) \
  glTexImage3D( target, level, internalformat, width, height, depth, border, format, type, pixels );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexImage3D( %s, %s, %s, %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #level, #internalformat, #width, #height, #depth, #border, #format, #type, #pixels, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexImage3DEXT (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
#define glTexImage3DEXT( target, level, internalformat, width, height, depth, border, format, type, pixels ) \
  glTexImage3DEXT( target, level, internalformat, width, height, depth, border, format, type, pixels );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexImage3DEXT( %s, %s, %s, %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #level, #internalformat, #width, #height, #depth, #border, #format, #type, #pixels, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexImage4DSGIS (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
#define glTexImage4DSGIS( target, level, internalformat, width, height, depth, size4d, border, format, type, pixels ) \
  glTexImage4DSGIS( target, level, internalformat, width, height, depth, size4d, border, format, type, pixels );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexImage4DSGIS( %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #level, #internalformat, #width, #height, #depth, #size4d, #border, #format, #type, #pixels, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexParameterf (GLenum target, GLenum pname, GLfloat param);
#define glTexParameterf( target, pname, param ) \
  glTexParameterf( target, pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexParameterf( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexParameterfv (GLenum target, GLenum pname, const GLfloat *params);
#define glTexParameterfv( target, pname, params ) \
  glTexParameterfv( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexParameterfv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexParameteri (GLenum target, GLenum pname, GLint param);
#define glTexParameteri( target, pname, param ) \
  glTexParameteri( target, pname, param );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexParameteri( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #param, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexParameteriv (GLenum target, GLenum pname, const GLint *params);
#define glTexParameteriv( target, pname, params ) \
  glTexParameteriv( target, pname, params );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexParameteriv( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #pname, #params, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
#define glTexSubImage1D( target, level, xoffset, width, format, type, pixels ) \
  glTexSubImage1D( target, level, xoffset, width, format, type, pixels );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexSubImage1D( %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #level, #xoffset, #width, #format, #type, #pixels, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexSubImage1DEXT (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
#define glTexSubImage1DEXT( target, level, xoffset, width, format, type, pixels ) \
  glTexSubImage1DEXT( target, level, xoffset, width, format, type, pixels );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexSubImage1DEXT( %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #level, #xoffset, #width, #format, #type, #pixels, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
#define glTexSubImage2D( target, level, xoffset, yoffset, width, height, format, type, pixels ) \
  glTexSubImage2D( target, level, xoffset, yoffset, width, height, format, type, pixels );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexSubImage2D( %s, %s, %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #level, #xoffset, #yoffset, #width, #height, #format, #type, #pixels, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexSubImage2DEXT (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
#define glTexSubImage2DEXT( target, level, xoffset, yoffset, width, height, format, type, pixels ) \
  glTexSubImage2DEXT( target, level, xoffset, yoffset, width, height, format, type, pixels );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexSubImage2DEXT( %s, %s, %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #level, #xoffset, #yoffset, #width, #height, #format, #type, #pixels, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels);
#define glTexSubImage3D( target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels ) \
  glTexSubImage3D( target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexSubImage3D( %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #level, #xoffset, #yoffset, #zoffset, #width, #height, #depth, #format, #type, #pixels, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexSubImage3DEXT (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels);
#define glTexSubImage3DEXT( target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels ) \
  glTexSubImage3DEXT( target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexSubImage3DEXT( %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #level, #xoffset, #yoffset, #zoffset, #width, #height, #depth, #format, #type, #pixels, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTexSubImage4DSGIS (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint woffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLenum format, GLenum type, const GLvoid *pixels);
#define glTexSubImage4DSGIS( target, level, xoffset, yoffset, zoffset, woffset, width, height, depth, size4d, format, type, pixels ) \
  glTexSubImage4DSGIS( target, level, xoffset, yoffset, zoffset, woffset, width, height, depth, size4d, format, type, pixels );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTexSubImage4DSGIS( %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #target, #level, #xoffset, #yoffset, #zoffset, #woffset, #width, #height, #depth, #size4d, #format, #type, #pixels, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTextureColorMaskSGIS (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
#define glTextureColorMaskSGIS( red, green, blue, alpha ) \
  glTextureColorMaskSGIS( red, green, blue, alpha );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTextureColorMaskSGIS( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #red, #green, #blue, #alpha, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTranslated (GLdouble x, GLdouble y, GLdouble z);
#define glTranslated( x, y, z ) \
  glTranslated( x, y, z );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTranslated( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, #z, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glTranslatef (GLfloat x, GLfloat y, GLfloat z);
#define glTranslatef( x, y, z ) \
  glTranslatef( x, y, z );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glTranslatef( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, #z, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glVertex2d (GLdouble x, GLdouble y);
#define glVertex2d( x, y ) \
  glVertex2d( x, y ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glVertex2d( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glVertex2dv (const GLdouble *v);
#define glVertex2dv( v ) \
  glVertex2dv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glVertex2dv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glVertex2f (GLfloat x, GLfloat y);
#define glVertex2f( x, y ) \
  glVertex2f( x, y ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glVertex2f( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glVertex2fv (const GLfloat *v);
#define glVertex2fv( v ) \
  glVertex2fv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glVertex2fv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glVertex2i (GLint x, GLint y);
#define glVertex2i( x, y ) \
  glVertex2i( x, y ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glVertex2i( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glVertex2iv (const GLint *v);
#define glVertex2iv( v ) \
  glVertex2iv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glVertex2iv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glVertex2s (GLshort x, GLshort y);
#define glVertex2s( x, y ) \
  glVertex2s( x, y ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glVertex2s( %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glVertex2sv (const GLshort *v);
#define glVertex2sv( v ) \
  glVertex2sv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glVertex2sv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glVertex3d (GLdouble x, GLdouble y, GLdouble z);
#define glVertex3d( x, y, z ) \
  glVertex3d( x, y, z ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glVertex3d( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, #z, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glVertex3dv (const GLdouble *v);
#define glVertex3dv( v ) \
  glVertex3dv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glVertex3dv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glVertex3f (GLfloat x, GLfloat y, GLfloat z);
#define glVertex3f( x, y, z ) \
  glVertex3f( x, y, z ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glVertex3f( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, #z, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glVertex3fv (const GLfloat *v);
#define glVertex3fv( v ) \
  glVertex3fv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glVertex3fv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glVertex3i (GLint x, GLint y, GLint z);
#define glVertex3i( x, y, z ) \
  glVertex3i( x, y, z ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glVertex3i( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, #z, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glVertex3iv (const GLint *v);
#define glVertex3iv( v ) \
  glVertex3iv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glVertex3iv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glVertex3s (GLshort x, GLshort y, GLshort z);
#define glVertex3s( x, y, z ) \
  glVertex3s( x, y, z ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glVertex3s( %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, #z, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glVertex3sv (const GLshort *v);
#define glVertex3sv( v ) \
  glVertex3sv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glVertex3sv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glVertex4d (GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glVertex4d( x, y, z, w ) \
  glVertex4d( x, y, z, w ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glVertex4d( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, #z, #w, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glVertex4dv (const GLdouble *v);
#define glVertex4dv( v ) \
  glVertex4dv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glVertex4dv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glVertex4f (GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#define glVertex4f( x, y, z, w ) \
  glVertex4f( x, y, z, w ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glVertex4f( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, #z, #w, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glVertex4fv (const GLfloat *v);
#define glVertex4fv( v ) \
  glVertex4fv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glVertex4fv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glVertex4i (GLint x, GLint y, GLint z, GLint w);
#define glVertex4i( x, y, z, w ) \
  glVertex4i( x, y, z, w ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glVertex4i( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, #z, #w, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glVertex4iv (const GLint *v);
#define glVertex4iv( v ) \
  glVertex4iv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glVertex4iv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glVertex4s (GLshort x, GLshort y, GLshort z, GLshort w);
#define glVertex4s( x, y, z, w ) \
  glVertex4s( x, y, z, w ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glVertex4s( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, #z, #w, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glVertex4sv (const GLshort *v);
#define glVertex4sv( v ) \
  glVertex4sv( v ); \
  if ( !__glDebug_InBegin ) \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glVertex4sv( %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #v, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glVertexPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
#define glVertexPointer( size, type, stride, pointer ) \
  glVertexPointer( size, type, stride, pointer );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glVertexPointer( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #size, #type, #stride, #pointer, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glVertexPointerEXT (GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
#define glVertexPointerEXT( size, type, stride, count, pointer ) \
  glVertexPointerEXT( size, type, stride, count, pointer );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glVertexPointerEXT( %s, %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #size, #type, #stride, #count, #pointer, __glDebug_ErrorStringMacro(_e) ); \
  }

extern void glViewport (GLint x, GLint y, GLsizei width, GLsizei height);
#define glViewport( x, y, width, height ) \
  glViewport( x, y, width, height );  \
  { GLenum _e; \
    while ( (_e = glGetError()) != GL_NO_ERROR ) \
      printf( "[%s:%d] glViewport( %s, %s, %s, %s ) returned an error: %s\n", \
              __FILE__, __LINE__, \
	      #x, #y, #width, #height, __glDebug_ErrorStringMacro(_e) ); \
  }


#endif /*defined(_LANGUAGE_C) || defined(__cplusplus)*/

#ifdef __GL_FUTURE
#include "GL/glfuture.h"
#endif /*__GL_FUTURE*/

#ifdef __cplusplus
}
#endif

#endif /* __gl_h_ */
