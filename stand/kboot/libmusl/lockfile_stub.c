#include "stdio_impl.h"

/* kboot is single-threaded, so musl stdio file locks can be no-ops. */
hidden int
__lockfile(FILE *f)
{
	(void)f;
	return (0);
}

hidden void
__unlockfile(FILE *f)
{
	(void)f;
}
