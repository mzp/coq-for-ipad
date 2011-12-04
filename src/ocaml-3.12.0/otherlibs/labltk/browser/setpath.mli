(*************************************************************************)
(*                                                                       *)
(*                Objective Caml LablTk library                          *)
(*                                                                       *)
(*            Jacques Garrigue, Kyoto University RIMS                    *)
(*                                                                       *)
(*   Copyright 1999 Institut National de Recherche en Informatique et    *)
(*   en Automatique and Kyoto University.  All rights reserved.          *)
(*   This file is distributed under the terms of the GNU Library         *)
(*   General Public License, with the special exception on linking       *)
(*   described in file ../../../LICENSE.                                 *)
(*                                                                       *)
(*************************************************************************)

(* $Id: setpath.mli 9547 2010-01-22 12:48:24Z doligez $ *)

open Widget

val add_update_hook : (unit -> unit) -> unit
val exec_update_hooks : unit -> unit
    (* things to do when Config.load_path changes *)

val set : dir:string -> unit
val f : dir:string -> toplevel widget
    (* edit the load path *)
