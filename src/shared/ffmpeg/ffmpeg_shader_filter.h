#ifndef FFMPEG_SHADER_FILTER_H_0BDC1454
#define FFMPEG_SHADER_FILTER_H_0BDC1454
#define __STDC_CONSTANT_MACROS

#ifdef __cplusplus
extern "C" {
#else
#include <stdbool.h>
#endif

#include "libavfilter/avfilter.h"
#include "./headers.h"

int avfilter_vf_shader_query_formats(AVFilterContext *ctx);
int avfilter_vf_shader_filter_frame(AVFilterLink *inlink, AVFrame *in);
extern AVFilter ff_vf_shader;

#ifdef __cplusplus
}
#endif

#endif /* end of include guard: FFMPEG_SHADER_FILTER_H_0BDC1454 */
