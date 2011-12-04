(***********************************************************************)
(*                                                                     *)
(*                           Objective Caml                            *)
(*                                                                     *)
(*            Xavier Leroy, projet Cristal, INRIA Rocquencourt         *)
(*                                                                     *)
(*  Copyright 1996 Institut National de Recherche en Informatique et   *)
(*  en Automatique.  All rights reserved.  This file is distributed    *)
(*  under the terms of the Q Public License version 1.0.               *)
(*                                                                     *)
(***********************************************************************)

(* $Id: emit.mli 2553 1999-11-17 18:59:06Z xleroy $ *)

(* Generation of assembly code *)

val fundecl: Linearize.fundecl -> unit
val data: Cmm.data_item list -> unit
val begin_assembly: unit -> unit
val end_assembly: unit -> unit
