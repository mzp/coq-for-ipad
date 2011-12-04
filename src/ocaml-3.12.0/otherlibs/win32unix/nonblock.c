/***********************************************************************/
/*                                                                     */
/*                           Objective Caml                            */
/*                                                                     */
/*            Xavier Leroy, projet Cristal, INRIA Rocquencourt         */
/*                                                                     */
/*  Copyright 2002 Institut National de Recherche en Informatique et   */
/*  en Automatique.  All rights reserved.  This file is distributed    */
/*  under the terms of the GNU Library General Public License, with    */
/*  the special exception on linking described in file ../../LICENSE.  */
/*                                                                     */
/***********************************************************************/

/* $Id: nonblock.c 10467 2010-05-25 13:01:06Z xleroy $ */

#include <mlvalues.h>
#include <signals.h>
#include "unixsupport.h"

CAMLprim value unix_set_nonblock(socket)
     value socket;
{
  u_long non_block = 1;

  if (ioctlsocket(Socket_val(socket), FIONBIO, &non_block) != 0) {
    win32_maperr(WSAGetLastError());
    uerror("unix_set_nonblock", Nothing);
  }
  Flags_fd_val(socket) = Flags_fd_val(socket) | FLAGS_FD_IS_BLOCKING;
  return Val_unit;
}

CAMLprim value unix_clear_nonblock(socket)
     value socket;
{
  u_long non_block = 0;

  if (ioctlsocket(Socket_val(socket), FIONBIO, &non_block) != 0) {
    win32_maperr(WSAGetLastError());
    uerror("unix_clear_nonblock", Nothing);
  }
  Flags_fd_val(socket) = Flags_fd_val(socket) & ~FLAGS_FD_IS_BLOCKING;
  return Val_unit;
}
