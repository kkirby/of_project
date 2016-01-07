#include "ofMain.h"
#include "ofxCv.h"

#include "ffmpeg_shader_filter.h"


extern "C" int avfilter_vf_shader_query_formats(AVFilterContext *ctx)
{
    static const enum AVPixelFormat pix_fmts[] = {
        AV_PIX_FMT_BGR24, AV_PIX_FMT_BGRA, AV_PIX_FMT_GRAY8, AV_PIX_FMT_NONE
    };
    AVFilterFormats *fmts_list = ff_make_format_list((const int*)pix_fmts);
    if (!fmts_list)
        return -1;
    return ff_set_common_formats(ctx, fmts_list);
}

extern "C" int avfilter_vf_shader_filter_frame(AVFilterLink *inlink, AVFrame *in)
{
	AVFilterContext *ctx = inlink->dst;
	AVFilterLink *outlink= inlink->dst->outputs[0];
	AVFrame *out;

	out = ff_get_video_buffer(outlink, outlink->w, outlink->h);
	if (!out) {
		av_frame_free(&in);
		return AVERROR(ENOMEM);
	}
	av_frame_copy_props(out, in);
	
    IplImage *tmpimg;
    int depth, channels_nb;

    if      (inlink->format == AV_PIX_FMT_GRAY8) { depth = IPL_DEPTH_8U;  channels_nb = 1; }
    else if (inlink->format == AV_PIX_FMT_BGRA)  { depth = IPL_DEPTH_8U;  channels_nb = 4; }
    else if (inlink->format == AV_PIX_FMT_BGR24) { depth = IPL_DEPTH_8U;  channels_nb = 3; }

    tmpimg = cvCreateImageHeader((CvSize){in->width, in->height}, depth, channels_nb);
	tmpimg->imageData = tmpimg->imageDataOrigin = (char*)out->data[0];
    tmpimg->dataOrder = IPL_DATA_ORDER_PIXEL;
    tmpimg->origin    = IPL_ORIGIN_TL;
    tmpimg->widthStep = out->linesize[0];
	cv::Mat m = cv::cvarrToMat(tmpimg); 
	
	ofImage img;
	img.setUseTexture(false);
	img.load("overlay2.png");
	cv::Mat imgMat = ofxCv::toCv(img);
	cv::Mat imgMat2;
	imgMat.convertTo(imgMat2,m.type());
	IplImage abc(imgMat2);
	out->linesize[0] = abc.widthStep;
	out->data[0] = (uint8_t*)abc.imageData;
	av_frame_free(&in);
	return ff_filter_frame(outlink, out);
}