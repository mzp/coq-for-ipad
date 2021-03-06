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

/* $Id: getgroups.c 6824 2005-03-24 17:20:54Z doligez $ */

#include "unixsupport.h"

#ifdef HAS_GETGROUPS

#include <sys/types.h>
#ifdef HAS_UNISTD
#include <unistd.h>
#endif
#include <limits.h>

CAMLprim value unix_getgroups(value unit)
{
  gid_t gidset[NGROUPS_MAX];
  int n;
  value res;
  int i;

  n = getgroups(NGROUPS_MAX, gidset);
  if (n == -1) uerror("getgroups", Nothing);
  res = alloc_tuple(n);
  for (i = 0; i < n; i++)
    Field(res, i) = Val_int(gidset[i]);
  return res;
}

#else

CAMLprim value unix_getgroups(value unit)
{ invalid_argument("getgroups not implemented"); }

#endif
