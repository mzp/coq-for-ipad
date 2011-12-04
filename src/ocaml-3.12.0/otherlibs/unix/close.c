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

/* $Id: close.c 4144 2001-12-07 13:41:02Z xleroy $ */

#include "unixsupport.h"

CAMLprim value unix_close(value fd)
{
  if (close(Int_val(fd)) == -1) uerror("close", Nothing);
  return Val_unit;
}
