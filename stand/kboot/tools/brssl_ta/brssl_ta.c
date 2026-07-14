// Derived from contrib/bearssl/tools/*.c, for generating compile-time trust anchors from ca certificates.

#include <stdlib.h>
#include <string.h>

#include "brssl.h"

static int
is_ign(int c)
{
	if (c == 0)
		return 0;
	if (c <= 32 || c == '-' || c == '_' || c == '.' ||
	    c == '/' || c == '+' || c == ':')
		return 1;
	return 0;
}

static int
next_char(const char **ps, const char *limit)
{
	for (;;) {
		int c;

		if (*ps == limit)
			return 0;
		c = *(*ps)++;
		if (c == 0)
			return 0;
		if (c >= 'A' && c <= 'Z')
			c += 'a' - 'A';
		if (!is_ign(c))
			return c;
	}
}

static int
eqstr_chunk(const char *s1, size_t s1_len, const char *s2, size_t s2_len)
{
	const char *lim1, *lim2;

	lim1 = s1 + s1_len;
	lim2 = s2 + s2_len;
	for (;;) {
		int c1, c2;

		c1 = next_char(&s1, lim1);
		c2 = next_char(&s2, lim2);
		if (c1 != c2)
			return 0;
		if (c1 == 0)
			return 1;
	}
}

int
eqstr(const char *s1, const char *s2)
{
	return eqstr_chunk(s1, strlen(s1), s2, strlen(s2));
}

int
main(int argc, char *argv[])
{
	return (do_ta(argc - 1, argv + 1) < 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}
