#ifndef FFMPEG_PUBLIC_H_BD29FEBA
#define FFMPEG_PUBLIC_H_BD29FEBA

#include <string.h>

typedef struct ffmpegResult {
    bool success;
	char error_message[255];
} FFmpegResult;

typedef void (*progress_cb_t)(double progress);
typedef void (*info_cb_t)(void*, int, const char*, va_list);

struct ffmpegResult execute_ffmpeg_command(const char** args, progress_cb_t progress_cb, info_cb_t info_cb);

#endif /* end of include guard: FFMPEG_PUBLIC_H_BD29FEBA */
