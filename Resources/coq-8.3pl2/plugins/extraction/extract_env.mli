(************************************************************************)
(*  v      *   The Coq Proof Assistant  /  The Coq Development Team     *)
(* <O___,, *   INRIA - CNRS - LIX - LRI - PPS - Copyright 1999-2010     *)
(*   \VV/  **************************************************************)
(*    //   *      This file is distributed under the terms of the       *)
(*         *       GNU Lesser General Public License Version 2.1        *)
(************************************************************************)

(*i $Id: extract_env.mli 13323 2010-07-24 15:57:30Z herbelin $ i*)

(*s This module declares the extraction commands. *)

open Names
open Libnames

val simple_extraction : reference -> unit
val full_extraction : string option -> reference list -> unit
val extraction_library : bool -> identifier -> unit

(* For debug / external output via coqtop.byte + Drop : *)

val mono_environment :
 global_reference list -> module_path list -> Miniml.ml_structure
