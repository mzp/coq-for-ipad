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

(* $Id: events.ml 9270 2009-05-20 11:52:42Z doligez $ *)

(********************************* Events ******************************)

open Instruct

let get_pos ev =
  match ev.ev_kind with
  | Event_before -> ev.ev_loc.Location.loc_start
  | Event_after _ -> ev.ev_loc.Location.loc_end
  | _ -> ev.ev_loc.Location.loc_start
;;


(*** Current events. ***)

(* Event at current position *)
let current_event =
  ref (None : debug_event option)

(* Current position in source. *)
(* Raise `Not_found' if not on an event (beginning or end of program). *)
let get_current_event () =
  match !current_event with
  | None -> raise Not_found
  | Some ev -> ev

let current_event_is_before () =
  match !current_event with
    None ->
      raise Not_found
  | Some {ev_kind = Event_before} ->
      true
  | _ ->
      false
