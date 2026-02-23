#include "stdio_impl.h"

/*
 * kboot is single-threaded, so use getc_unlocked() instead of musl's
 * pthread-aware locking path.
 */
int
getc(FILE *f)
{
	return (getc_unlocked(f));
}

weak_alias(getc, _IO_getc);
