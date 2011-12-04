(***********************************************************************)
(*                                                                     *)
(*                           Objective Caml                            *)
(*                                                                     *)
(*          Damien Doligez, projet Gallium, INRIA Rocquencourt         *)
(*                                                                     *)
(*  Copyright 2007 Institut National de Recherche en Informatique et   *)
(*  en Automatique.  All rights reserved.  This file is distributed    *)
(*  under the terms of the Q Public License version 1.0.               *)
(*                                                                     *)
(***********************************************************************)

(* $Id: annot.mli 8958 2008-07-29 15:42:44Z doligez $ *)

(* Data types for annotations (Stypes.ml) *)

type call = Tail | Stack | Inline;;

type ident =
  | Iref_internal of Location.t (* defining occurrence *)
  | Iref_external
  | Idef of Location.t          (* scope *)
;;
