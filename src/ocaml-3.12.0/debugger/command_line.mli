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

(* $Id: command_line.mli 2919 2000-03-07 18:22:19Z weis $ *)

(************************ Reading and executing commands ***************)

open Lexing;;
open Format;;

val interprete_line : formatter -> string -> bool;;
val line_loop : formatter -> lexbuf -> unit;;
