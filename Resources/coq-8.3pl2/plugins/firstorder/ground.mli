(************************************************************************)
(*  v      *   The Coq Proof Assistant  /  The Coq Development Team     *)
(* <O___,, *   INRIA - CNRS - LIX - LRI - PPS - Copyright 1999-2010     *)
(*   \VV/  **************************************************************)
(*    //   *      This file is distributed under the terms of the       *)
(*         *       GNU Lesser General Public License Version 2.1        *)
(************************************************************************)

(* $Id: ground.mli 13323 2010-07-24 15:57:30Z herbelin $ *)

val ground_tac:     Tacmach.tactic ->
  (Proof_type.goal Tacmach.sigma -> Sequent.t) -> Tacmach.tactic

