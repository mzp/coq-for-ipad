(************************************************************************)
(*  v      *   The Coq Proof Assistant  /  The Coq Development Team     *)
(* <O___,, *   INRIA - CNRS - LIX - LRI - PPS - Copyright 1999-2010     *)
(*   \VV/  **************************************************************)
(*    //   *      This file is distributed under the terms of the       *)
(*         *       GNU Lesser General Public License Version 2.1        *)
(************************************************************************)

(* $Id: Bool_nat.v 13323 2010-07-24 15:57:30Z herbelin $ *)

Require Export Compare_dec.
Require Export Peano_dec.
Require Import Sumbool.

Open Local Scope nat_scope.

Implicit Types m n x y : nat.

(** The decidability of equality and order relations over
    type [nat] give some boolean functions with the adequate specification. *)

Definition notzerop n := sumbool_not _ _ (zerop n).
Definition lt_ge_dec : forall x y, {x < y} + {x >= y} :=
  fun n m => sumbool_not _ _ (le_lt_dec m n).

Definition nat_lt_ge_bool x y := bool_of_sumbool (lt_ge_dec x y).
Definition nat_ge_lt_bool x y :=
  bool_of_sumbool (sumbool_not _ _ (lt_ge_dec x y)).

Definition nat_le_gt_bool x y := bool_of_sumbool (le_gt_dec x y).
Definition nat_gt_le_bool x y :=
  bool_of_sumbool (sumbool_not _ _ (le_gt_dec x y)).

Definition nat_eq_bool x y := bool_of_sumbool (eq_nat_dec x y).
Definition nat_noteq_bool x y :=
  bool_of_sumbool (sumbool_not _ _ (eq_nat_dec x y)).

Definition zerop_bool x := bool_of_sumbool (zerop x).
Definition notzerop_bool x := bool_of_sumbool (notzerop x).