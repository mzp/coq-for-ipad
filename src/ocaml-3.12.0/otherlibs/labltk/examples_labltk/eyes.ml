(***********************************************************************)
(*                                                                     *)
(*                 MLTk, Tcl/Tk interface of Objective Caml            *)
(*                                                                     *)
(*    Francois Rouaix, Francois Pessaux, Jun Furuse and Pierre Weis    *)
(*               projet Cristal, INRIA Rocquencourt                    *)
(*            Jacques Garrigue, Kyoto University RIMS                  *)
(*                                                                     *)
(*  Copyright 2002 Institut National de Recherche en Informatique et   *)
(*  en Automatique and Kyoto University.  All rights reserved.         *)
(*  This file is distributed under the terms of the GNU Library        *)
(*  General Public License, with the special exception on linking      *)
(*  described in file LICENSE found in the Objective Caml source tree. *)
(*                                                                     *)
(***********************************************************************)

(* $Id: eyes.ml 9547 2010-01-22 12:48:24Z doligez $ *)

open Tk

let _ =
  let top = openTk () in
  let fw = Frame.create top in
  pack [fw];
  let c = Canvas.create ~width: 200 ~height: 200 fw in
  let create_eye cx cy wx wy ewx ewy bnd =
    let o2 = Canvas.create_oval
        ~x1:(cx - wx) ~y1:(cy - wy)
        ~x2:(cx + wx) ~y2:(cy + wy)
        ~outline: `Black ~width: 7
        ~fill: `White
        c
    and o = Canvas.create_oval
        ~x1:(cx - ewx) ~y1:(cy - ewy)
        ~x2:(cx + ewx) ~y2:(cy + ewy)
        ~fill:`Black
        c in
    let curx = ref cx
    and cury = ref cy in
    bind ~events:[`Motion] ~extend:true ~fields:[`MouseX; `MouseY]
      ~action:(fun e ->
        let nx, ny =
          let xdiff = e.ev_MouseX - cx
          and ydiff = e.ev_MouseY - cy in
          let diff = sqrt ((float xdiff /. (float wx *. bnd)) ** 2.0 +.
                             (float ydiff /. (float wy *. bnd)) ** 2.0) in
          if diff > 1.0 then
            truncate ((float xdiff) *. (1.0 /. diff)) + cx,
            truncate ((float ydiff) *. (1.0 /. diff)) + cy
          else
            e.ev_MouseX, e.ev_MouseY
        in
        Canvas.move c o ~x: (nx - !curx) ~y: (ny - !cury);
        curx := nx;
        cury := ny)
      c
  in
  create_eye 60 100 30 40 5 6 0.6;
  create_eye 140 100 30 40 5 6 0.6;
  pack [c]

let _ = Printexc.print mainLoop ()
