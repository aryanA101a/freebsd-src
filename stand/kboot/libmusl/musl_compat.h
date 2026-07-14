#pragma once

#include "host_net.h"

#include <sys/types.h>

#define POLLIN		0x001
#define POLLOUT		0x004
#define POLLERR		0x008
#define POLLHUP		0x010
#define POLLNVAL	0x020

#define F_GETFL		3
#define F_SETFL		4
#define O_NONBLOCK	04000

typedef unsigned long nfds_t;

struct pollfd {
	int	fd;
	short	events;
	short	revents;
};

struct timespec;

const char	*gai_strerror(int);
int		socket(int, int, int);
int		connect(int, const struct host_sockaddr *, host_socklen_t);
int		clock_gettime(int, struct timespec *);
int		poll(struct pollfd *, nfds_t, int);
ssize_t		recv(int, void *, size_t, int);
ssize_t		send(int, const void *, size_t, int);
int		fcntl(int, int, ...);
int		getentropy(void *, size_t);
