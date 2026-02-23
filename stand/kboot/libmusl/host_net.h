#pragma once

#include <sys/socket.h>

#include <netinet/in.h>

#include <arpa/inet.h>
#include <netdb.h>

#define HOST_AF_UNSPEC	 AF_UNSPEC
#define HOST_AF_INET	 AF_INET
#define HOST_AF_INET6	 AF_INET6
#define HOST_SOCK_STREAM SOCK_STREAM
#define HOST_IPPROTO_TCP IPPROTO_TCP

typedef socklen_t host_socklen_t;
typedef sa_family_t host_sa_family_t;
typedef in_port_t host_in_port_t;
typedef in_addr_t host_in_addr_t;

typedef struct addrinfo host_addrinfo;
typedef struct in_addr host_in_addr;
typedef struct in6_addr host_in6_addr;
typedef struct sockaddr host_sockaddr;
typedef struct sockaddr_in host_sockaddr_in;
typedef struct sockaddr_in6 host_sockaddr_in6;

int host_getaddrinfo(const char *node, const char *service,
    const host_addrinfo *hints, host_addrinfo **res);
void host_freeaddrinfo(host_addrinfo *res);

static inline uint16_t
host_htons(uint16_t n)
{
	return (htons(n));
}

static inline int
host_inet_aton(const char *s, host_in_addr *addr)
{
	return (inet_aton(s, addr));
}
