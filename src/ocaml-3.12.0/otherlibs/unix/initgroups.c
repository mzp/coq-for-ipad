/***********************************************************************/
/*                                                                     */
/*                           Objective Caml                            */
/*                                                                     */
/*  Copyright 2009 Institut National de Recherche en Informatique et   */
/*  en Automatique.  All rights reserved.  This file is distributed    */
/*  under the terms of the GNU Library General Public License, with    */
/*  the special exception on linking described in file ../../LICENSE.  */
/*                                                                     */
/***********************************************************************/

/* Contributed by Stephane Glondu <steph@glondu.net> */

/* $Id: initgroups.c 9235 2009-04-16 07:23:35Z xleroy $ */

#include "unixsupport.h"

#ifdef HAS_INITGROUPS

#include <sys/types.h>
#ifdef HAS_UNISTD
#include <unistd.h>
#endif
#include <limits.h>
#include <grp.h>

CAMLprim value unix_initgroups(value user, value group)
{
  if (initgroups(String_val(user), Int_val(group)) == -1) {
    uerror("initgroups", Nothing);
  }
  return Val_unit;
}

#else

CAMLprim value unix_initgroups(value user, value group)
{ invalid_argument("initgroups not implemented"); }

#endif
