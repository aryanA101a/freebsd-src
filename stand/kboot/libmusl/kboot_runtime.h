#pragma once

#include <stddef.h>

extern int errno;

void *Calloc(size_t, size_t, const char *, int);
void Free(void *, const char *, int);
long host_syscall(int, ...);
