/* Copyright (C) 2013 the GSS-PROXY contributors, see COPYING for license */

#ifndef _GP_SELINUX_H_
#define _GP_SELINUX_H_

typedef char * SEC_CTX;

#ifdef HAVE_SELINUX

#include <selinux/context.h>
#define SELINUX_CTX context_t
#include <selinux/selinux.h>

#define SELINUX_context_new context_new
#define SELINUX_context_free context_free
#define SELINUX_context_str context_str
#define SELINUX_context_type_get context_type_get
#define SELINUX_context_user_get context_user_get
#define SELINUX_context_role_get context_role_get
#define SELINUX_context_range_get context_range_get
#define SELINUX_getpeercon getpeercon
#define SELINUX_freecon freecon

#else /* not HAVE_SELINUX */

#define SELINUX_CTX void *
#define SEC_CTX void *

#define SELINUX_context_new(x) NULL
#define SELINUX_context_free(x) (x) = NULL
#define SELINUX_context_dummy_get(x) "<SELinux not compiled in>"
#define SELINUX_context_str SELINUX_context_dummy_get
#define SELINUX_context_type_get SELINUX_context_dummy_get
#define SELINUX_context_user_get SELINUX_context_dummy_get
#define SELINUX_context_role_get SELINUX_context_dummy_get
#define SELINUX_context_range_get SELINUX_context_dummy_get

#include <errno.h>
#define SELINUX_getpeercon(x, y) -1; do { \
    *(y) = NULL; \
    errno = ENOTSUP; \
} while(0)

#define SELINUX_freecon(x) (x) = NULL

#endif /* done HAVE_SELINUX */

#endif  /*_GP_SELINUX_H_ */
