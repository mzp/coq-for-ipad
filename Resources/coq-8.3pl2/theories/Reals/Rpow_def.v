(************************************************************************)
(*  v      *   The Coq Proof Assistant  /  The Coq Development Team     *)
(* <O___,, *   INRIA - CNRS - LIX - LRI - PPS - Copyright 1999-2010     *)
(*   \VV/  **************************************************************)
(*    //   *      This file is distributed under the terms of the       *)
(*         *       GNU Lesser General Public License Version 2.1        *)
(************************************************************************)

(* $Id: Rpow_def.v 13323 2010-07-24 15:57:30Z herbelin $ *)

Require Import Rdefinitions.

Fixpoint pow (r:R) (n:nat) : R :=
  match n with
    | O => R1
    | S n => Rmult r (pow r n)
  end.
