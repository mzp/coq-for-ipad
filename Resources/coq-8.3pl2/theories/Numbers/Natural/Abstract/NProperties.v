(************************************************************************)
(*  v      *   The Coq Proof Assistant  /  The Coq Development Team     *)
(* <O___,, *   INRIA - CNRS - LIX - LRI - PPS - Copyright 1999-2010     *)
(*   \VV/  **************************************************************)
(*    //   *      This file is distributed under the terms of the       *)
(*         *       GNU Lesser General Public License Version 2.1        *)
(************************************************************************)

(*i $Id: NProperties.v 13323 2010-07-24 15:57:30Z herbelin $ i*)

Require Export NAxioms NSub.

(** This functor summarizes all known facts about N.
    For the moment it is only an alias to [NSubPropFunct], which
    subsumes all others.
*)

Module Type NPropSig := NSubPropFunct.

Module NPropFunct (N:NAxiomsSig) <: NPropSig N.
 Include NPropSig N.
End NPropFunct.
