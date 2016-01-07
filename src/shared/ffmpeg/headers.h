#ifndef HEADERS_H_A9EAF229
#define HEADERS_H_A9EAF229

AVFrame *ff_get_video_buffer(AVFilterLink *link, int w, int h);
int ff_filter_frame(AVFilterLink *link, AVFrame *frame);
AVFilterFormats *ff_make_format_list(const int *fmts);
int ff_set_common_formats(AVFilterContext *ctx, AVFilterFormats *formats);

#endif /* end of include guard: HEADERS_H_A9EAF229 */