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

/* $Id: unixsupport.h 7045 2005-09-06 12:38:32Z doligez $ */

#ifdef HAS_UNISTD
#include <unistd.h>
#endif

#include <string.h>
#include <ctype.h>
#include <math.h>
#include <memory.h>
#include "../../byterun/custom.h"
#include "../../byterun/callback.h"
#include "../../byterun/mlvalues.h"
#include "../../byterun/signals.h"
#include "../../byterun/alloc.h"
#include "../../byterun/memory.h"
#include "../../byterun/fail.h"
#include "../../byterun/io.h"
#include "../../byterun/glue.h"

#define UNIX_BUFFER_SIZE 16384

#define DIR_Val(v) *((DIR **) &Field(v, 0))
CAMLprim value unix_accept(value sock);
CAMLprim value unix_accept(value sock);
CAMLprim value unix_access(value path, value perms);
CAMLprim value unix_inet_addr_of_string(value s);
CAMLprim value unix_inet_addr_of_string(value s);
CAMLprim value unix_alarm(value t);
CAMLprim value unix_bind(value socket, value address);
CAMLprim value unix_bind(value socket, value address);
CAMLprim value unix_chdir(value path);
CAMLprim value unix_chmod(value path, value perm);
CAMLprim value unix_chown(value path, value uid, value gid);
CAMLprim value unix_chroot(value path);
CAMLprim value unix_close(value fd);
CAMLprim value unix_closedir(value vd);
CAMLprim value unix_connect(value socket, value address);
CAMLprim value unix_connect(value socket, value address);
CAMLprim value unix_dup(value fd);
CAMLprim value unix_dup2(value fd1, value fd2);
CAMLprim value unix_dup2(value fd1, value fd2);
CAMLprim value unix_environment(value unit);
CAMLprim value unix_error_message(value err);
CAMLprim value unix_execv(value path, value args);
CAMLprim value unix_execve(value path, value args, value env);
CAMLprim value unix_execvp(value path, value args);
CAMLprim value unix_execvpe(value path, value args, value env);
CAMLprim value unix_exit(value n);
CAMLprim value unix_fchmod(value fd, value perm);
CAMLprim value unix_fchmod(value fd, value perm);
CAMLprim value unix_fchown(value fd, value uid, value gid);
CAMLprim value unix_fchown(value fd, value uid, value gid);
CAMLprim value unix_set_nonblock(value fd);
CAMLprim value unix_clear_nonblock(value fd);
CAMLprim value unix_set_close_on_exec(value fd);
CAMLprim value unix_clear_close_on_exec(value fd);
CAMLprim value unix_set_close_on_exec(value fd);
CAMLprim value unix_clear_close_on_exec(value fd);
CAMLprim value unix_fork(value unit);
CAMLprim value unix_ftruncate(value fd, value len);
CAMLprim value unix_ftruncate_64(value fd, value len);
CAMLprim value unix_ftruncate(value fd, value len);
CAMLprim value unix_ftruncate_64(value fd, value len);
CAMLprim value unix_getaddrinfo(value vnode, value vserv, value vopts);
CAMLprim value unix_getaddrinfo(value vnode, value vserv, value vopts);
CAMLprim value unix_getcwd(value unit);
CAMLprim value unix_getcwd(value unit);
CAMLprim value unix_getcwd(value unit);
CAMLprim value unix_getegid(value unit);
CAMLprim value unix_geteuid(value unit);
CAMLprim value unix_getgid(value unit);
CAMLprim value unix_getgrnam(value name);
CAMLprim value unix_getgrgid(value gid);
CAMLprim value unix_getgroups(value unit);
CAMLprim value unix_getgroups(value unit);
CAMLprim value unix_gethostbyaddr(value a);
CAMLprim value unix_gethostbyname(value name);
CAMLprim value unix_gethostbyaddr(value name);
CAMLprim value unix_gethostbyname(value name);
CAMLprim value unix_gethostname(value unit);
CAMLprim value unix_gethostname(value unit);
CAMLprim value unix_gethostname(value unit);
CAMLprim value unix_getlogin(value unit);
CAMLprim value unix_getnameinfo(value vaddr, value vopts);
CAMLprim value unix_getnameinfo(value vaddr, value vopts);
CAMLprim value unix_getpeername(value sock);
CAMLprim value unix_getpeername(value sock);
CAMLprim value unix_getpid(value unit);
CAMLprim value unix_getppid(value unit);
CAMLprim value unix_getprotobyname(value name);
CAMLprim value unix_getprotobynumber(value proto);
CAMLprim value unix_getprotobynumber(value proto);
CAMLprim value unix_getprotobyname(value name);
CAMLprim value unix_getpwnam(value name);
CAMLprim value unix_getpwuid(value uid);
CAMLprim value unix_getservbyname(value name, value proto);
CAMLprim value unix_getservbyport(value port, value proto);
CAMLprim value unix_getservbyport(value port, value proto);
CAMLprim value unix_getservbyname(value name, value proto);
CAMLprim value unix_getsockname(value sock);
CAMLprim value unix_getsockname(value sock);
CAMLprim value unix_gettimeofday(value unit);
CAMLprim value unix_gettimeofday(value unit);
CAMLprim value unix_getuid(value unit);
CAMLprim value unix_gmtime(value t);
CAMLprim value unix_localtime(value t);
CAMLprim value unix_mktime(value t);
CAMLprim value unix_mktime(value t);
CAMLprim value unix_initgroups(value user, value group);
CAMLprim value unix_initgroups(value user, value group);
CAMLprim value unix_isatty(value fd);
CAMLprim value unix_setitimer(value which, value newval);
CAMLprim value unix_getitimer(value which);
CAMLprim value unix_setitimer(value which, value newval);
CAMLprim value unix_getitimer(value which);
CAMLprim value unix_kill(value pid, value signal);
CAMLprim value unix_link(value path1, value path2);
CAMLprim value unix_listen(value sock, value backlog);
CAMLprim value unix_listen(value sock, value backlog);
CAMLprim value unix_lockf(value fd, value cmd, value span);
CAMLprim value unix_lockf(value fd, value cmd, value span);
CAMLprim value unix_lockf(value fd, value cmd, value span);
CAMLprim value unix_lseek(value fd, value ofs, value cmd);
CAMLprim value unix_lseek_64(value fd, value ofs, value cmd);
CAMLprim value unix_mkdir(value path, value perm);
CAMLprim value unix_mkfifo(value path, value mode);
CAMLprim value unix_mkfifo(value path, value mode);
CAMLprim value unix_mkfifo(value path, value mode);
CAMLprim value unix_nice(value incr);
CAMLprim value unix_open(value path, value flags, value perm);
CAMLprim value unix_opendir(value path);
CAMLprim value unix_pipe(value unit);
CAMLprim value unix_putenv(value name, value val);
CAMLprim value unix_putenv(value name, value val);
CAMLprim value unix_read(value fd, value buf, value ofs, value len);
CAMLprim value unix_readdir(value vd);
CAMLprim value unix_readlink(value path);
CAMLprim value unix_readlink(value path);
CAMLprim value unix_rename(value path1, value path2);
CAMLprim value unix_rewinddir(value vd);
CAMLprim value unix_rewinddir(value d);
CAMLprim value unix_rmdir(value path);
//CAMLprim value unix_select(value readfds, value writefds, value exceptfds);
CAMLprim value unix_select(value readfds, value writefds, value exceptfds, value timeout);
//CAMLprim value unix_recv(value sock, value buff, value ofs, value len);
//CAMLprim value unix_recvfrom(value sock, value buff, value ofs, value len);
//CAMLprim value unix_send(value sock, value buff, value ofs, value len);
//CAMLprim value unix_sendto_native(value sock, value buff, value ofs, value len);
CAMLprim value unix_sendto(value *argv, int argc);
CAMLprim value unix_recv(value sock, value buff, value ofs, value len, value flag);
CAMLprim value unix_recvfrom(value sock, value buff, value ofs, value len, value flags);
CAMLprim value unix_send(value sock, value buff, value ofs, value len, value flags);
CAMLprim value unix_sendto_native(value sock, value buff, value ofs, value len, value flags, value dest);
CAMLprim value unix_sendto(value *argv, int argc);
CAMLprim value unix_setgid(value gid);
CAMLprim value unix_setgroups(value groups);
CAMLprim value unix_setgroups(value groups);
CAMLprim value unix_setsid(value unit);
CAMLprim value unix_setuid(value uid);
CAMLprim value unix_shutdown(value sock, value cmd);
CAMLprim value unix_shutdown(value sock, value cmd);
CAMLprim value unix_sigprocmask(value vaction, value vset);
CAMLprim value unix_sigpending(value unit);
CAMLprim value unix_sigsuspend(value vset);
CAMLprim value unix_sigprocmask(value vaction, value vset);
CAMLprim value unix_sigpending(value unit);
CAMLprim value unix_sigsuspend(value vset);
CAMLprim value unix_sleep(value t);
CAMLprim value unix_socket(value domain, value type, value proto);
CAMLprim value unix_socket(value domain, value type, value proto);
CAMLprim value unix_socketpair(value domain, value type, value proto);
CAMLprim value unix_socketpair(value domain, value type, value proto);
CAMLprim value unix_getsockopt(value vty, value vsocket, value voption);
//CAMLprim value unix_setsockopt(value vty, value vsocket, value voption);
CAMLprim value unix_getsockopt(value vty, value socket, value option);
CAMLprim value unix_setsockopt(value vty, value socket, value option, value val);
CAMLprim value unix_stat(value path);
CAMLprim value unix_lstat(value path);
CAMLprim value unix_fstat(value fd);
CAMLprim value unix_stat_64(value path);
CAMLprim value unix_lstat_64(value path);
CAMLprim value unix_fstat_64(value fd);
CAMLprim value unix_string_of_inet_addr(value a);
CAMLprim value unix_string_of_inet_addr(value a);
CAMLprim value unix_symlink(value path1, value path2);
CAMLprim value unix_symlink(value path1, value path2);
CAMLprim value unix_tcgetattr(value fd);
CAMLprim value unix_tcsetattr(value fd, value when, value arg);
CAMLprim value unix_tcsendbreak(value fd, value delay);
CAMLprim value unix_tcdrain(value fd);
CAMLprim value unix_tcflush(value fd, value queue);
CAMLprim value unix_tcflow(value fd, value action);
CAMLprim value unix_tcgetattr(value fd);
CAMLprim value unix_tcsetattr(value fd, value when, value arg);
CAMLprim value unix_tcsendbreak(value fd, value delay);
CAMLprim value unix_tcdrain(value fd);
CAMLprim value unix_tcflush(value fd, value queue);
CAMLprim value unix_tcflow(value fd, value action);
CAMLprim value unix_time(value unit);
CAMLprim value unix_times(value unit);
CAMLprim value unix_truncate(value path, value len);
CAMLprim value unix_truncate_64(value path, value len);
CAMLprim value unix_truncate(value path, value len);
CAMLprim value unix_truncate_64(value path, value len);
CAMLprim value unix_umask(value perm);
CAMLprim value unix_unlink(value path);
CAMLprim value unix_utimes(value path, value atime, value mtime);
CAMLprim value unix_utimes(value path, value atime, value mtime);
CAMLprim value unix_utimes(value path, value atime, value mtime);
CAMLprim value unix_wait(value unit);
CAMLprim value unix_waitpid(value flags, value pid_req);
CAMLprim value unix_waitpid(value flags, value pid_req);
CAMLprim value unix_write(value fd, value buf, value vofs, value vlen);
CAMLprim value unix_single_write(value fd, value buf, value vofs, value vlen);
