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

/* $Id: lseek.c 10223 2010-04-01 07:36:49Z shinwell $ */

#include <errno.h>
#include <sys/types.h>
#include "unixsupport.h"

#include <unistd.h>

#ifndef EOVERFLOW
#define EOVERFLOW ERANGE
#endif

static int seek_command_table[] = {
  SEEK_SET, SEEK_CUR, SEEK_END
};

CAMLprim value unix_lseek(value fd, value ofs, value cmd)
{
  file_offset ret;
  caml_enter_blocking_section();
  ret = lseek(Int_val(fd), Long_val(ofs),
                       seek_command_table[Int_val(cmd)]);
  caml_leave_blocking_section();
  if (ret == -1) uerror("lseek", Nothing);
  if (ret > Max_long) unix_error(EOVERFLOW, "lseek", Nothing);
  return Val_long(ret);
}

CAMLprim value unix_lseek_64(value fd, value ofs, value cmd)
{
  file_offset ret;
  /* [ofs] is an Int64, which is stored as a custom block; we must therefore
     extract its contents before dropping the runtime lock, or it might be
     moved. */
  file_offset ofs_c = File_offset_val(ofs);
  caml_enter_blocking_section();
  ret = lseek(Int_val(fd), ofs_c, seek_command_table[Int_val(cmd)]);
  caml_leave_blocking_section();
  if (ret == -1) uerror("lseek", Nothing);
  return Val_file_offset(ret);
}
