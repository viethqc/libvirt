/* glob.h -- Find a path matching a pattern.

   Copyright (C) 2005-2007, 2009-2018 Free Software Foundation, Inc.

   Written by Derek Price <derek@ximbiot.com> & Paul Eggert <eggert@CS.UCLA.EDU>

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, see <https://www.gnu.org/licenses/>.  */

#ifndef _GL_GLOB_H
#define _GL_GLOB_H

#include <libc-config.h>

#include <stddef.h>

/* On some systems, such as AIX 5.1, <sys/stat.h> does a "#define stat stat64".
   Make sure this definition is seen before glob-libc.h defines types that
   rely on 'struct stat'.  */
#include <sys/stat.h>

#ifndef __USE_GNU
# define __USE_GNU    1
#endif


#define glob rpl_glob
#define globfree rpl_globfree
#define glob_pattern_p rpl_glob_pattern_p
#define __glob_pattern_p glob_pattern_p

#define __GLOB_GNULIB 1

/* Now the standard GNU C Library header should work.  */
#include "glob-libc.h"

__BEGIN_DECLS
typedef int (*_gl_glob_errfunc_fn) (const char *, int);
__END_DECLS

#if defined __cplusplus && defined GNULIB_NAMESPACE
# undef glob
# undef globfree
# undef glob_pattern_p
_GL_CXXALIAS_RPL (glob, int, (const char *_Restrict_ __pattern, int __flags,
                              _gl_glob_errfunc_fn __errfunc,
                              glob_t *_Restrict_ __pglob));
_GL_CXXALIAS_RPL (globfree, void, (glob_t *__pglob));
_GL_CXXALIAS_RPL (glob_pattern_p, int, (const char *__pattern, int __quote));
# if 0  /* The C function name is rpl_glob, not glob.  */
_GL_CXXALIASWARN (glob);
_GL_CXXALIASWARN (globfree);
_GL_CXXALIASWARN (glob_pattern_p);
# endif
#endif

#endif /* _GL_GLOB_H */
