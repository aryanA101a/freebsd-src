#pragma once

#include "http.h"

struct http_file_sink {
	sink_t sink;
	int fd;
};

void http_file_sink_init(struct http_file_sink *fs);
