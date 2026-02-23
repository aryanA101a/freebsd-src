# This is a narrow musl networking subset, not a standalone libc.  It keeps the
# Linux networking ABI/types and selected resolver/socket code, while local
# shims route allocation, errno, and syscalls through the kboot/libsa runtime.

NO_LIBSA_CFLAGS=	yes

.include <bsd.init.mk>

LIB=	musl
WARNS?=	4


MUSLDIR=	${SRCTOP}/contrib/musl
.if ${MACHINE_ARCH} == "amd64"
MUSL_ARCH=	x86_64
.else
MUSL_ARCH=	${MACHINE_ARCH}
.endif

MUSL_ALLTYPES_H=	musl/bits/alltypes.h
MUSL_SYSCALL_H=	musl/bits/syscall.h
DPSRCS+=	${MUSL_ALLTYPES_H} ${MUSL_SYSCALL_H}
CLEANFILES+=	${MUSL_ALLTYPES_H} ${MUSL_SYSCALL_H}

MUSL_CFLAGS=	-D_XOPEN_SOURCE=700 \
		-include ${.CURDIR}/musl_symbol_renames.h \
		-I${MUSLDIR}/arch/${MUSL_ARCH} \
		-I${MUSLDIR}/arch/generic \
		-I${MUSLDIR}/src/include \
		-I${MUSLDIR}/src/internal \
		-I${.OBJDIR}/musl \
		-I${MUSLDIR}/include \
		-I${MUSLDIR}/src/network

MUSL_PATHS= \
	src/internal \
	src/misc \
	src/multibyte \
	src/network \
	src/select \
	src/stdio \
	src/stdlib \
	src/ctype \
	src/time \
	src/unistd

.for _dir in ${MUSL_PATHS}
.PATH:	${MUSLDIR}/${_dir}
.endfor

MUSL_UPSTREAM_SRCS= \
		bind.c \
		clock_gettime.c \
		close.c \
		connect.c \
		dn_expand.c \
		dns_parse.c \
		__fclose_ca.c \
		__fopen_rb_ca.c \
		getsockname.c \
		inet_aton.c \
		inet_pton.c \
		feof.c \
		fgets.c \
		if_nametoindex.c \
		ioctl.c \
		isalnum.c \
		lookup_ipliteral.c \
		lseek.c \
		mbsrtowcs.c \
		mbstowcs.c \
		internal.c \
		ofl.c \
		poll.c \
		qsort.c \
		qsort_nr.c \
		recvmsg.c \
		resolvconf.c \
		res_msend.c \
		res_mkquery.c \
		setsockopt.c \
		sendmsg.c \
		sendto.c \
		socket.c \
		syscall_ret.c \
		__stdio_close.c \
		__stdio_exit.c \
		__stdio_read.c \
		__stdio_seek.c \
		__toread.c \
		__uflow.c

MUSL_WRAPPER_SRCS= \
		freeaddrinfo_wrapper.c \
		getaddrinfo_wrapper.c \
		lookup_name_wrapper.c

MUSL_STUB_SRCS= \
		lock_stub.c \
		lockfile_stub.c \
		pthread_stub.c \
		vdso_stub.c

MUSL_LOCAL_SRCS= \
		calloc.c \
		errno.c \
		free.c \
		getc.c \
		syscall_cp.c

MUSL_SRCS=	${MUSL_UPSTREAM_SRCS} \
		${MUSL_WRAPPER_SRCS} \
		${MUSL_STUB_SRCS} \
		${MUSL_LOCAL_SRCS}

SRCS=	${MUSL_SRCS}

.for _src in ${MUSL_SRCS}
CFLAGS.${_src}+=	${MUSL_CFLAGS}
CFLAGS.${_src}+=	-Udouble -Ufloat
.endfor

# Generate musl arch headers in the object tree.
${MUSL_ALLTYPES_H}: ${MUSLDIR}/arch/${MUSL_ARCH}/bits/alltypes.h.in \
    ${MUSLDIR}/include/alltypes.h.in \
    ${MUSLDIR}/tools/mkalltypes.sed
	@mkdir -p ${.TARGET:H}
	sed -f ${MUSLDIR}/tools/mkalltypes.sed \
	    ${MUSLDIR}/arch/${MUSL_ARCH}/bits/alltypes.h.in \
	    ${MUSLDIR}/include/alltypes.h.in > ${.TARGET}

${MUSL_SYSCALL_H}: ${MUSLDIR}/arch/${MUSL_ARCH}/bits/syscall.h.in
	@mkdir -p ${.TARGET:H}
	cp ${.ALLSRC} ${.TARGET}
	sed -n -e s/__NR_/SYS_/p < ${.ALLSRC} >> ${.TARGET}

.include <bsd.lib.mk>
