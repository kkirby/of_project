#include "ffmpeg_shader_filter.h"

static const AVFilterPad avfilter_vf_shader_inputs[] = {
    {
        .name = "default",
        .type = AVMEDIA_TYPE_VIDEO,
		.filter_frame = avfilter_vf_shader_filter_frame,
    },
    { NULL }
};

static const AVFilterPad avfilter_vf_shader_outputs[] = {
    {
        .name = "default",
        .type = AVMEDIA_TYPE_VIDEO,
    },
    { NULL }
};

AVFilter ff_vf_shader = {
    .name        = "shader",
    .description = "Applies a shader to video frames.",
    .inputs      = avfilter_vf_shader_inputs,
    .outputs     = avfilter_vf_shader_outputs,
	.query_formats = avfilter_vf_shader_query_formats,
};
