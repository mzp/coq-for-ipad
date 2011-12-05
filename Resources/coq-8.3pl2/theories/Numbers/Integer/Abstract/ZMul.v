(************************************************************************)
(*  v      *   The Coq Proof Assistant  /  The Coq Development Team     *)
(* <O___,, *   INRIA - CNRS - LIX - LRI - PPS - Copyright 1999-2010     *)
(*   \VV/  **************************************************************)
(*    //   *      This file is distributed under the terms of the       *)
(*         *       GNU Lesser General Public License Version 2.1        *)
(************************************************************************)
(*                      Evgeny Makarov, INRIA, 2007                     *)
(************************************************************************)

(*i $Id: ZMul.v 13323 2010-07-24 15:57:30Z herbelin $ i*)

Require Export ZAdd.

Module ZMulPropFunct (Import Z : ZAxiomsSig').
Include ZAddPropFunct Z.

(** A note on naming: right (correspondingly, left) distributivity
    happens when the sum is multiplied by a number on the right
    (left), not when the sum itself is the right (left) factor in the
    product (see planetmath.org and mathworld.wolfram.com). In the old
    library BinInt, distributivity over subtraction was named
    correctly, but distributivity over addition was named
    incorrectly. The names in Isabelle/HOL library are also
    incorrect. *)

(** Theorems that are either not valid on N or have different proofs
    on N and Z *)

Theorem mul_pred_r : forall n m, n * (P m) == n * m - n.
Proof.
intros n m.
rewrite <- (succ_pred m) at 2.
now rewrite mul_succ_r, <- add_sub_assoc, sub_diag, add_0_r.
Qed.

Theorem mul_pred_l : forall n m, (P n) * m == n * m - m.
Proof.
intros n m; rewrite (mul_comm (P n) m), (mul_comm n m). apply mul_pred_r.
Qed.

Theorem mul_opp_l : forall n m, (- n) * m == - (n * m).
Proof.
intros n m. apply -> add_move_0_r.
now rewrite <- mul_add_distr_r, add_opp_diag_l, mul_0_l.
Qed.

Theorem mul_opp_r : forall n m, n * (- m) == - (n * m).
Proof.
intros n m; rewrite (mul_comm n (- m)), (mul_comm n m); apply mul_opp_l.
Qed.

Theorem mul_opp_opp : forall n m, (- n) * (- m) == n * m.
Proof.
intros n m; now rewrite mul_opp_l, mul_opp_r, opp_involutive.
Qed.

Theorem mul_sub_distr_l : forall n m p, n * (m - p) == n * m - n * p.
Proof.
intros n m p. do 2 rewrite <- add_opp_r. rewrite mul_add_distr_l.
now rewrite mul_opp_r.
Qed.

Theorem mul_sub_distr_r : forall n m p, (n - m) * p == n * p - m * p.
Proof.
intros n m p; rewrite (mul_comm (n - m) p), (mul_comm n p), (mul_comm m p);
now apply mul_sub_distr_l.
Qed.

End ZMulPropFunct.

