#include "ffmpeg.h"
extern "C" {
#include "libffmpeg/ffmpeg.h"
}

#include "ofMain.h"
#include <mutex>

typedef const char* arg_t;

std::mutex g_ffmpeg_mutex;
progress_cb_cpp_t g_progress_cb;
info_cb_cpp_t g_info_cb;

void g_progress_cb_c(double progress){
	if(g_progress_cb){
		g_progress_cb(progress);
	}
}

void g_info_cb_c(void* ptr,int level,const char* fmt,va_list args){
	if(g_info_cb){
		g_info_cb(ptr,level,fmt,args);
	}
}

ffmpegResult threadedFunction(
	std::vector<const char*> args,
	progress_cb_cpp_t progress_cb,
	info_cb_cpp_t info_cb
){
	std::lock_guard<std::mutex> guard(g_ffmpeg_mutex);
	g_progress_cb = progress_cb;
	g_info_cb = info_cb;
	arg_t* args_c = (arg_t*)malloc(sizeof(arg_t*) * args.size() + 2);
	args_c[0] = "ffmpeg";
	args_c[args.size() + 1] = NULL;
	for(unsigned int i = 0; i < args.size(); i++){
		args_c[i + 1] = args[i];
	}
	ffmpegResult result = execute_ffmpeg_command(args_c,&g_progress_cb_c,&g_info_cb_c);
	free(args_c);
	return result;
}

std::future<ffmpegResult> do_ffmpeg(
	std::vector<const char*> args,
	progress_cb_cpp_t progress_cb,
	info_cb_cpp_t info_cb
){
	return std::async(threadedFunction,args,progress_cb,info_cb);
}