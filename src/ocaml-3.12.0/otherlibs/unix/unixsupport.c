/***********************************************************************/
/*                                                                     */
/*                           Objective Caml                            */
/*                                                                     */
/*            Xavier Leroy, projet Cristal, INRIA Rocquencourt         */
/*                                                                     */
/*  Copyright 1996 Institut National de Recherche en Informatique et   */
/*  en Automatique.  All rights reserved.  This file is distributed    */
/*  under the terms of the GNU Library General Public License, with    */
/*  the special exception on linking described in file ../../LICENSE.  */
/*                                                                     */
/***********************************************************************/

/* $Id: unixsupport.c 9547 2010-01-22 12:48:24Z doligez $ */

#include "unixsupport.h"
#include "cst2constr.h"
#include <errno.h>

#ifndef E2BIG
#define E2BIG (-1)
#endif
#ifndef EACCES
#define EACCES (-1)
#endif
#ifndef EAGAIN
#define EAGAIN (-1)
#endif
#ifndef EBADF
#define EBADF (-1)
#endif
#ifndef EBUSY
#define EBUSY (-1)
#endif
#ifndef ECHILD
#define ECHILD (-1)
#endif
#ifndef EDEADLK
#define EDEADLK (-1)
#endif
#ifndef EDOM
#define EDOM (-1)
#endif
#ifndef EEXIST
#define EEXIST (-1)
#endif

#ifndef EFAULT
#define EFAULT (-1)
#endif
#ifndef EFBIG
#define EFBIG (-1)
#endif
#ifndef EINTR
#define EINTR (-1)
#endif
#ifndef EINVAL
#define EINVAL (-1)
#endif
#ifndef EIO
#define EIO (-1)
#endif
#ifndef EISDIR
#define EISDIR (-1)
#endif
#ifndef EMFILE
#define EMFILE (-1)
#endif
#ifndef EMLINK
#define EMLINK (-1)
#endif
#ifndef ENAMETOOLONG
#define ENAMETOOLONG (-1)
#endif
#ifndef ENFILE
#define ENFILE (-1)
#endif
#ifndef ENODEV
#define ENODEV (-1)
#endif
#ifndef ENOENT
#define ENOENT (-1)
#endif
#ifndef ENOEXEC
#define ENOEXEC (-1)
#endif
#ifndef ENOLCK
#define ENOLCK (-1)
#endif
#ifndef ENOMEM
#define ENOMEM (-1)
#endif
#ifndef ENOSPC
#define ENOSPC (-1)
#endif
#ifndef ENOSYS
#define ENOSYS (-1)
#endif
#ifndef ENOTDIR
#define ENOTDIR (-1)
#endif
#ifndef ENOTEMPTY
#define ENOTEMPTY (-1)
#endif
#ifndef ENOTTY
#define ENOTTY (-1)
#endif
#ifndef ENXIO
#define ENXIO (-1)
#endif
#ifndef EPERM
#define EPERM (-1)
#endif
#ifndef EPIPE
#define EPIPE (-1)
#endif
#ifndef ERANGE
#define ERANGE (-1)
#endif
#ifndef EROFS
#define EROFS (-1)
#endif
#ifndef ESPIPE
#define ESPIPE (-1)
#endif
#ifndef ESRCH
#define ESRCH (-1)
#endif
#ifndef EXDEV
#define EXDEV (-1)
#endif
#ifndef EWOULDBLOCK
#define EWOULDBLOCK (-1)
#endif
#ifndef EINPROGRESS
#define EINPROGRESS (-1)
#endif
#ifndef EALREADY
#define EALREADY (-1)
#endif
#ifndef ENOTSOCK
#define ENOTSOCK (-1)
#endif
#ifndef EDESTADDRREQ
#define EDESTADDRREQ (-1)
#endif
#ifndef EMSGSIZE
#define EMSGSIZE (-1)
#endif
#ifndef EPROTOTYPE
#define EPROTOTYPE (-1)
#endif
#ifndef ENOPROTOOPT
#define ENOPROTOOPT (-1)
#endif
#ifndef EPROTONOSUPPORT
#define EPROTONOSUPPORT (-1)
#endif
#ifndef ESOCKTNOSUPPORT
#define ESOCKTNOSUPPORT (-1)
#endif
#ifndef EOPNOTSUPP
#define EOPNOTSUPP (-1)
#endif
#ifndef EPFNOSUPPORT
#define EPFNOSUPPORT (-1)
#endif
#ifndef EAFNOSUPPORT
#define EAFNOSUPPORT (-1)
#endif
#ifndef EADDRINUSE
#define EADDRINUSE (-1)
#endif
#ifndef EADDRNOTAVAIL
#define EADDRNOTAVAIL (-1)
#endif
#ifndef ENETDOWN
#define ENETDOWN (-1)
#endif
#ifndef ENETUNREACH
#define ENETUNREACH (-1)
#endif
#ifndef ENETRESET
#define ENETRESET (-1)
#endif
#ifndef ECONNABORTED
#define ECONNABORTED (-1)
#endif
#ifndef ECONNRESET
#define ECONNRESET (-1)
#endif
#ifndef ENOBUFS
#define ENOBUFS (-1)
#endif
#ifndef EISCONN
#define EISCONN (-1)
#endif
#ifndef ENOTCONN
#define ENOTCONN (-1)
#endif
#ifndef ESHUTDOWN
#define ESHUTDOWN (-1)
#endif
#ifndef ETOOMANYREFS
#define ETOOMANYREFS (-1)
#endif
#ifndef ETIMEDOUT
#define ETIMEDOUT (-1)
#endif
#ifndef ECONNREFUSED
#define ECONNREFUSED (-1)
#endif
#ifndef EHOSTDOWN
#define EHOSTDOWN (-1)
#endif
#ifndef EHOSTUNREACH
#define EHOSTUNREACH (-1)
#endif
#ifndef ENOTEMPTY
#define ENOTEMPTY (-1)
#endif
#ifndef ELOOP
#define ELOOP (-1)
#endif
#ifndef EOVERFLOW
#define EOVERFLOW (-1)
#endif

int error_table[] = {
  E2BIG, EACCES, EAGAIN, EBADF, EBUSY, ECHILD, EDEADLK, EDOM,
  EEXIST, EFAULT, EFBIG, EINTR, EINVAL, EIO, EISDIR, EMFILE, EMLINK,
  ENAMETOOLONG, ENFILE, ENODEV, ENOENT, ENOEXEC, ENOLCK, ENOMEM, ENOSPC,
  ENOSYS, ENOTDIR, ENOTEMPTY, ENOTTY, ENXIO, EPERM, EPIPE, ERANGE,
  EROFS, ESPIPE, ESRCH, EXDEV, EWOULDBLOCK, EINPROGRESS, EALREADY,
  ENOTSOCK, EDESTADDRREQ, EMSGSIZE, EPROTOTYPE, ENOPROTOOPT,
  EPROTONOSUPPORT, ESOCKTNOSUPPORT, EOPNOTSUPP, EPFNOSUPPORT,
  EAFNOSUPPORT, EADDRINUSE, EADDRNOTAVAIL, ENETDOWN, ENETUNREACH,
  ENETRESET, ECONNABORTED, ECONNRESET, ENOBUFS, EISCONN, ENOTCONN,
  ESHUTDOWN, ETOOMANYREFS, ETIMEDOUT, ECONNREFUSED, EHOSTDOWN,
  EHOSTUNREACH, ELOOP, EOVERFLOW /*, EUNKNOWNERR */
};

static value * unix_error_exn = NULL;

value unix_error_of_code (int errcode)
{
  int errconstr;
  value err;

  errconstr =
      cst_to_constr(errcode, error_table, sizeof(error_table)/sizeof(int), -1);
  if (errconstr == Val_int(-1)) {
    err = alloc_small(1, 0);
    Field(err, 0) = Val_int(errcode);
  } else {
    err = errconstr;
  }
  return err;
}

void unix_error(int errcode, char *cmdname, value cmdarg)
{
  value res;
  value name = Val_unit, err = Val_unit, arg = Val_unit;

  Begin_roots3 (name, err, arg);
    arg = cmdarg == Nothing ? copy_string("") : cmdarg;
    name = copy_string(cmdname);
    err = unix_error_of_code (errcode);
    if (unix_error_exn == NULL) {
      unix_error_exn = caml_named_value("Unix.Unix_error");
      if (unix_error_exn == NULL)
        invalid_argument("Exception Unix.Unix_error not initialized, please link unix.cma");
    }
    res = alloc_small(4, 0);
    Field(res, 0) = *unix_error_exn;
    Field(res, 1) = err;
    Field(res, 2) = name;
    Field(res, 3) = arg;
  End_roots();
  mlraise(res);
}

void uerror(char *cmdname, value cmdarg)
{
  unix_error(errno, cmdname, cmdarg);
}

struct camlsyms unix_camlsyms[] = {
"unix_accept", unix_accept,
"unix_accept", unix_accept,
"unix_access", unix_access,
"unix_inet_addr_of_string", unix_inet_addr_of_string,
"unix_inet_addr_of_string", unix_inet_addr_of_string,
"unix_alarm", unix_alarm,
"unix_bind", unix_bind,
"unix_bind", unix_bind,
"unix_chdir", unix_chdir,
"unix_chmod", unix_chmod,
"unix_chown", unix_chown,
"unix_chroot", unix_chroot,
"unix_close", unix_close,
"unix_closedir", unix_closedir,
"unix_connect", unix_connect,
"unix_connect", unix_connect,
"unix_dup", unix_dup,
"unix_dup2", unix_dup2,
"unix_dup2", unix_dup2,
"unix_environment", unix_environment,
"unix_error_message", unix_error_message,
"unix_execv", unix_execv,
"unix_execve", unix_execve,
"unix_execvp", unix_execvp,
"unix_execvpe", unix_execvpe,
"unix_exit", unix_exit,
"unix_fchmod", unix_fchmod,
"unix_fchmod", unix_fchmod,
"unix_fchown", unix_fchown,
"unix_fchown", unix_fchown,
"unix_set_nonblock", unix_set_nonblock,
"unix_clear_nonblock", unix_clear_nonblock,
"unix_set_close_on_exec", unix_set_close_on_exec,
"unix_clear_close_on_exec", unix_clear_close_on_exec,
"unix_set_close_on_exec", unix_set_close_on_exec,
"unix_clear_close_on_exec", unix_clear_close_on_exec,
"unix_fork", unix_fork,
"unix_ftruncate", unix_ftruncate,
"unix_ftruncate_64", unix_ftruncate_64,
"unix_ftruncate", unix_ftruncate,
"unix_ftruncate_64", unix_ftruncate_64,
"unix_getaddrinfo", unix_getaddrinfo,
"unix_getaddrinfo", unix_getaddrinfo,
"unix_getcwd", unix_getcwd,
"unix_getcwd", unix_getcwd,
"unix_getcwd", unix_getcwd,
"unix_getegid", unix_getegid,
"unix_geteuid", unix_geteuid,
"unix_getgid", unix_getgid,
"unix_getgrnam", unix_getgrnam,
"unix_getgrgid", unix_getgrgid,
"unix_getgroups", unix_getgroups,
"unix_getgroups", unix_getgroups,
"unix_gethostbyaddr", unix_gethostbyaddr,
"unix_gethostbyname", unix_gethostbyname,
"unix_gethostbyaddr", unix_gethostbyaddr,
"unix_gethostbyname", unix_gethostbyname,
"unix_gethostname", unix_gethostname,
"unix_gethostname", unix_gethostname,
"unix_gethostname", unix_gethostname,
"unix_getlogin", unix_getlogin,
"unix_getnameinfo", unix_getnameinfo,
"unix_getnameinfo", unix_getnameinfo,
"unix_getpeername", unix_getpeername,
"unix_getpeername", unix_getpeername,
"unix_getpid", unix_getpid,
"unix_getppid", unix_getppid,
"unix_getprotobyname", unix_getprotobyname,
"unix_getprotobynumber", unix_getprotobynumber,
"unix_getprotobynumber", unix_getprotobynumber,
"unix_getprotobyname", unix_getprotobyname,
"unix_getpwnam", unix_getpwnam,
"unix_getpwuid", unix_getpwuid,
"unix_getservbyname", unix_getservbyname,
"unix_getservbyport", unix_getservbyport,
"unix_getservbyport", unix_getservbyport,
"unix_getservbyname", unix_getservbyname,
"unix_getsockname", unix_getsockname,
"unix_getsockname", unix_getsockname,
"unix_gettimeofday", unix_gettimeofday,
"unix_gettimeofday", unix_gettimeofday,
"unix_getuid", unix_getuid,
"unix_gmtime", unix_gmtime,
"unix_localtime", unix_localtime,
"unix_mktime", unix_mktime,
"unix_mktime", unix_mktime,
"unix_initgroups", unix_initgroups,
"unix_initgroups", unix_initgroups,
"unix_isatty", unix_isatty,
"unix_setitimer", unix_setitimer,
"unix_getitimer", unix_getitimer,
"unix_setitimer", unix_setitimer,
"unix_getitimer", unix_getitimer,
"unix_kill", unix_kill,
"unix_link", unix_link,
"unix_listen", unix_listen,
"unix_listen", unix_listen,
"unix_lockf", unix_lockf,
"unix_lockf", unix_lockf,
"unix_lockf", unix_lockf,
"unix_lseek", unix_lseek,
"unix_lseek_64", unix_lseek_64,
"unix_mkdir", unix_mkdir,
"unix_mkfifo", unix_mkfifo,
"unix_mkfifo", unix_mkfifo,
"unix_mkfifo", unix_mkfifo,
"unix_nice", unix_nice,
"unix_open", unix_open,
"unix_opendir", unix_opendir,
"unix_pipe", unix_pipe,
"unix_putenv", unix_putenv,
"unix_putenv", unix_putenv,
"unix_read", unix_read,
"unix_readdir", unix_readdir,
"unix_readlink", unix_readlink,
"unix_readlink", unix_readlink,
"unix_rename", unix_rename,
"unix_rewinddir", unix_rewinddir,
"unix_rewinddir", unix_rewinddir,
"unix_rmdir", unix_rmdir,
"unix_select", unix_select,
"unix_select", unix_select,
"unix_recv", unix_recv,
"unix_recvfrom", unix_recvfrom,
"unix_send", unix_send,
"unix_sendto_native", unix_sendto_native,
"unix_sendto", unix_sendto,
"unix_recv", unix_recv,
"unix_recvfrom", unix_recvfrom,
"unix_send", unix_send,
"unix_sendto_native", unix_sendto_native,
"unix_sendto", unix_sendto,
"unix_setgid", unix_setgid,
"unix_setgroups", unix_setgroups,
"unix_setgroups", unix_setgroups,
"unix_setsid", unix_setsid,
"unix_setuid", unix_setuid,
"unix_shutdown", unix_shutdown,
"unix_shutdown", unix_shutdown,
"unix_sigprocmask", unix_sigprocmask,
"unix_sigpending", unix_sigpending,
"unix_sigsuspend", unix_sigsuspend,
"unix_sigprocmask", unix_sigprocmask,
"unix_sigpending", unix_sigpending,
"unix_sigsuspend", unix_sigsuspend,
"unix_sleep", unix_sleep,
"unix_socket", unix_socket,
"unix_socket", unix_socket,
"unix_socketpair", unix_socketpair,
"unix_socketpair", unix_socketpair,
"unix_getsockopt", unix_getsockopt,
"unix_setsockopt", unix_setsockopt,
"unix_getsockopt", unix_getsockopt,
"unix_setsockopt", unix_setsockopt,
"unix_stat", unix_stat,
"unix_lstat", unix_lstat,
"unix_fstat", unix_fstat,
"unix_stat_64", unix_stat_64,
"unix_lstat_64", unix_lstat_64,
"unix_fstat_64", unix_fstat_64,
"unix_string_of_inet_addr", unix_string_of_inet_addr,
"unix_string_of_inet_addr", unix_string_of_inet_addr,
"unix_symlink", unix_symlink,
"unix_symlink", unix_symlink,
"unix_tcgetattr", unix_tcgetattr,
"unix_tcsetattr", unix_tcsetattr,
"unix_tcsendbreak", unix_tcsendbreak,
"unix_tcdrain", unix_tcdrain,
"unix_tcflush", unix_tcflush,
"unix_tcflow", unix_tcflow,
"unix_tcgetattr", unix_tcgetattr,
"unix_tcsetattr", unix_tcsetattr,
"unix_tcsendbreak", unix_tcsendbreak,
"unix_tcdrain", unix_tcdrain,
"unix_tcflush", unix_tcflush,
"unix_tcflow", unix_tcflow,
"unix_time", unix_time,
"unix_times", unix_times,
"unix_truncate", unix_truncate,
"unix_truncate_64", unix_truncate_64,
"unix_truncate", unix_truncate,
"unix_truncate_64", unix_truncate_64,
"unix_umask", unix_umask,
"unix_unlink", unix_unlink,
"unix_utimes", unix_utimes,
"unix_utimes", unix_utimes,
"unix_utimes", unix_utimes,
"unix_wait", unix_wait,
"unix_waitpid", unix_waitpid,
"unix_waitpid", unix_waitpid,
"unix_write", unix_write,
"unix_single_write", unix_single_write,
	"", 0};
