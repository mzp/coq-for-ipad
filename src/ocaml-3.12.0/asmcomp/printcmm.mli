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

(* $Id: printcmm.mli 3123 2000-04-21 08:13:22Z weis $ *)

(* Pretty-printing of C-- code *)

open Format

val machtype_component : formatter -> Cmm.machtype_component -> unit
val machtype : formatter -> Cmm.machtype_component array -> unit
val comparison : Cmm.comparison -> string
val chunk : Cmm.memory_chunk -> string
val operation : Cmm.operation -> string
val expression : formatter -> Cmm.expression -> unit
val fundecl : formatter -> Cmm.fundecl -> unit
val data : formatter -> Cmm.data_item list -> unit
val phrase : formatter -> Cmm.phrase -> unit
