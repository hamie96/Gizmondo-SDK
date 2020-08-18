#ifndef __glext_h_
#define __glext_h_

#ifdef __cplusplus
extern "C" {
#endif

/* -------------------- extensions -------------------- */

#define GL_OES_query_matrix               1
#define GL_EXT_texture_lod_bias           1
#define GL_EXT_texture_compression_dxt1   1
#define GL_SGIS_texture_lod               1

/* GL_EXT_bgra */
#define GL_BGR_EXT                        0x80E0
#define GL_BGRA_EXT                       0x80E1

/* SGIS_texture_lod */
#define GL_TEXTURE_MIN_LOD_SGIS           0x813A
#define GL_TEXTURE_MAX_LOD_SGIS           0x813B
#define GL_TEXTURE_BASE_LEVEL_SGIS        0x813C
#define GL_TEXTURE_MAX_LEVEL_SGIS         0x813D

/* GL_EXT_texture_compression_dxt1 */
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT   0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT  0x83F1

/* EXT_texture_lod_bias */
#define GL_MAX_TEXTURE_LOD_BIAS_EXT       0x84FD
#define GL_TEXTURE_FILTER_CONTROL_EXT     0x8500
#define GL_TEXTURE_LOD_BIAS_EXT           0x8501

/* OES_query_matrix */
GLAPI GLbitfield APIENTRY glQueryMatrixxOES (GLfixed mantissa[16], GLint exponent[16]);

#ifdef __cplusplus
}
#endif

#endif /* __glext_h_ */
