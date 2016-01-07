#pragma once

#include "ofMain.h"
extern "C" {
#include "libffmpeg/ffmpeg.h"
}
#include <functional>
#include <vector>
#include <future>

typedef std::function<void(double)> progress_cb_cpp_t;
typedef std::function<void(void*,int,const char*,va_list)> info_cb_cpp_t;

std::future<ffmpegResult> do_ffmpeg(std::vector<const char*> args,progress_cb_cpp_t progress_cb,info_cb_cpp_t info_cb);