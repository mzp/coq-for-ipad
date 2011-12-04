(***********************************************************************)
(*                                                                     *)
(*                           Objective Caml                            *)
(*                                                                     *)
(*          Jerome Vouillon, projet Cristal, INRIA Rocquencourt        *)
(*          Objective Caml port by John Malecki and Xavier Leroy       *)
(*                                                                     *)
(*  Copyright 1996 Institut National de Recherche en Informatique et   *)
(*  en Automatique.  All rights reserved.  This file is distributed    *)
(*  under the terms of the Q Public License version 1.0.               *)
(*                                                                     *)
(***********************************************************************)

(* $Id: debugger_config.mli 9547 2010-01-22 12:48:24Z doligez $ *)

(********************** Configuration file *****************************)

exception Toplevel

(*** Miscellaneous parameters. ***)

val debugger_prompt : string
val event_mark_before : string
val event_mark_after : string
val shell : string
val runtime_program : string
val history_size : int ref
val load_path_for : (string, string list) Hashtbl.t

(*** Time travel paramaters. ***)

val checkpoint_big_step : int64 ref
val checkpoint_small_step : int64 ref
val checkpoint_max_count : int ref
val make_checkpoints : bool ref
