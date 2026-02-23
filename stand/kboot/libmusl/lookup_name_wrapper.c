#define __fopen_rb_ca kboot_lookup_name_no_hosts

#include "lookup_name.c"

#undef __fopen_rb_ca

FILE *
kboot_lookup_name_no_hosts(const char *path, FILE *f, unsigned char *buf,
    size_t len)
{
	(void)path;
	(void)f;
	(void)buf;
	(void)len;

	errno = ENOENT;
	return (NULL);
}
