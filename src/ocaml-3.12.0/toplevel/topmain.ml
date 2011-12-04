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

(* $Id: topmain.ml 10444 2010-05-20 14:06:29Z doligez $ *)

open Clflags

let usage = "Usage: ocaml <options> <object-files> [script-file]\noptions are:"

let preload_objects = ref []

let prepare ppf =
  Toploop.set_paths ();
  try
    let res =
      List.for_all (Topdirs.load_file ppf) (List.rev !preload_objects) in
    !Toploop.toplevel_startup_hook ();
    res
  with x ->
    try Errors.report_error ppf x; false
    with x ->
      Format.fprintf ppf "Uncaught exception: %s\n" (Printexc.to_string x);
      false

let file_argument name =
  let ppf = Format.err_formatter in
  if Filename.check_suffix name ".cmo" || Filename.check_suffix name ".cma"
  then preload_objects := name :: !preload_objects
  else
    begin
      let newargs = Array.sub Sys.argv !Arg.current
                              (Array.length Sys.argv - !Arg.current)
      in
      if prepare ppf && Toploop.run_script ppf name newargs
      then exit 0
      else exit 2
    end

let print_version () =
  Printf.printf "The Objective Caml toplevel, version %s\n" Sys.ocaml_version;
  exit 0;
;;

let print_version_num () =
  Printf.printf "%s\n" Sys.ocaml_version;
  exit 0;
;;

module Options = Main_args.Make_bytetop_options (struct
  let set r () = r := true
  let clear r () = r := false

  let _I dir =
    let dir = Misc.expand_directory Config.standard_library dir in
    include_dirs := dir :: !include_dirs
  let _init s = init_file := Some s
  let _labels = clear classic
  let _no_app_funct = clear applicative_functors
  let _noassert = set noassert
  let _nolabels = set classic
  let _noprompt = set noprompt
  let _nostdlib = set no_std_include
  let _principal = set principal
  let _rectypes = set recursive_types
  let _strict_sequence = set strict_sequence
  let _unsafe = set fast
  let _version () = print_version ()
  let _vnum () = print_version_num ()
  let _w s = Warnings.parse_options false s
  let _warn_error s = Warnings.parse_options true s
  let _warn_help = Warnings.help_warnings
  let _dparsetree = set dump_parsetree
  let _drawlambda = set dump_rawlambda
  let _dlambda = set dump_lambda
  let _dinstr = set dump_instr

  let anonymous s = file_argument s
end);;


let main () =
  Arg.parse Options.list file_argument usage;
  if not (prepare Format.err_formatter) then exit 2;
  Toploop.loop Format.std_formatter
