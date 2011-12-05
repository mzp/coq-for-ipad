(************************************************************************)
(*  v      *   The Coq Proof Assistant  /  The Coq Development Team     *)
(* <O___,, *   INRIA - CNRS - LIX - LRI - PPS - Copyright 1999-2010     *)
(*   \VV/  **************************************************************)
(*    //   *      This file is distributed under the terms of the       *)
(*         *       GNU Lesser General Public License Version 2.1        *)
(************************************************************************)

(*i $Id: instances.mli 13323 2010-07-24 15:57:30Z herbelin $ i*)

open Term
open Tacmach
open Names
open Libnames
open Rules

val collect_quantified : Sequent.t -> Formula.t list * Sequent.t

val give_instances : Formula.t list -> Sequent.t ->
  (Unify.instance * global_reference) list

val quantified_tac : Formula.t list -> seqtac with_backtracking




