#pragma once

#define HOST_AF_UNSPEC		0
#define HOST_AF_INET		2
#define HOST_AF_INET6		10
#define HOST_SOCK_STREAM	1
#define HOST_IPPROTO_TCP	6
#define HOST_CLOCK_MONOTONIC	1
#define HOST_EINTR		4
#define HOST_EAGAIN		11

typedef unsigned int host_socklen_t;
typedef unsigned short host_sa_family_t;
typedef unsigned short host_in_port_t;
typedef unsigned int host_in_addr_t;

typedef struct host_in_addr {
	host_in_addr_t s_addr;
} host_in_addr;

typedef struct host_in6_addr {
	union {
		unsigned char __s6_addr[16];
		unsigned short __s6_addr16[8];
		unsigned int __s6_addr32[4];
	} __in6_union;
} host_in6_addr;

typedef struct host_sockaddr {
	host_sa_family_t sa_family;
	char sa_data[14];
} host_sockaddr;

typedef struct host_sockaddr_in {
	host_sa_family_t sin_family;
	host_in_port_t sin_port;
	host_in_addr sin_addr;
	unsigned char sin_zero[8];
} host_sockaddr_in;

typedef struct host_sockaddr_in6 {
	host_sa_family_t sin6_family;
	host_in_port_t sin6_port;
	unsigned int sin6_flowinfo;
	host_in6_addr sin6_addr;
	unsigned int sin6_scope_id;
} host_sockaddr_in6;

typedef struct host_addrinfo {
	int ai_flags;
	int ai_family;
	int ai_socktype;
	int ai_protocol;
	host_socklen_t ai_addrlen;
	host_sockaddr *ai_addr;
	char *ai_canonname;
	struct host_addrinfo *ai_next;
} host_addrinfo;

int host_getaddrinfo(const char *node, const char *service,
    const host_addrinfo *hints, host_addrinfo **res);
void host_freeaddrinfo(host_addrinfo *res);
