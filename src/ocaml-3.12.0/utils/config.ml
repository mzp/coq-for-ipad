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

(* $Id: config.mlp 10424 2010-05-19 11:29:38Z xleroy $ *)

(***********************************************************************)
(**                                                                   **)
(**               WARNING WARNING WARNING                             **)
(**                                                                   **)
(** When you change this file, you must make the parallel change      **)
(** in config.mlbuild                                                 **)
(**                                                                   **)
(***********************************************************************)


(* The main OCaml version string has moved to ../VERSION *)
let version = Sys.ocaml_version

let standard_library_default = "/var/mobile/ocaml-3.12.0/lib/ocaml"

let standard_library =
  try
    Sys.getenv "OCAMLLIB"
  with Not_found ->
  try
    Sys.getenv "CAMLLIB"
  with Not_found ->
    standard_library_default

let standard_runtime = "/var/mobile/ocaml-3.12.0/bin/ocamlrun"
let ccomp_type = "cc"
let bytecomp_c_compiler = "/Developer/Platforms/iPhoneOS.platform/Developer/usr/bin/arm-apple-darwin10-gcc-4.2.1 -I/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.0.sdk/usr/lib/gcc/arm-apple-darwin10/4.2.1/include/ -I/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.0.sdk/usr/include/ -isysroot /Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.0.sdk -fno-defer-pop -no-cpp-precomp -Wall -D_FILE_OFFSET_BITS=64 -D_REENTRANT "
let bytecomp_c_libraries = "-lcurses -lpthread"
let native_c_compiler = "/Developer/Platforms/iPhoneOS.platform/Developer/usr/bin/arm-apple-darwin10-gcc-4.2.1 -I/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.0.sdk/usr/lib/gcc/arm-apple-darwin10/4.2.1/include/ -I/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.0.sdk/usr/include/ -isysroot /Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.0.sdk -D_FILE_OFFSET_BITS=64 -D_REENTRANT"
let native_c_libraries = ""
let native_pack_linker = "/Developer/Platforms/iPhoneOS.platform//Developer/usr/bin/ld -r  -o "
let ranlib = "ranlib"
let cc_profile = "-pg"
let mkdll = "/Developer/Platforms/iPhoneOS.platform/Developer/usr/bin/arm-apple-darwin10-gcc-4.2.1 -I/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.0.sdk/usr/lib/gcc/arm-apple-darwin10/4.2.1/include/ -I/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.0.sdk/usr/include/ -isysroot /Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.0.sdk -bundle -flat_namespace -undefined suppress"
let mkexe = "/Developer/Platforms/iPhoneOS.platform/Developer/usr/bin/arm-apple-darwin10-gcc-4.2.1 -I/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.0.sdk/usr/lib/gcc/arm-apple-darwin10/4.2.1/include/ -I/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.0.sdk/usr/include/ -isysroot /Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.0.sdk"
let mkmaindll = "/Developer/Platforms/iPhoneOS.platform/Developer/usr/bin/arm-apple-darwin10-gcc-4.2.1 -I/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.0.sdk/usr/lib/gcc/arm-apple-darwin10/4.2.1/include/ -I/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.0.sdk/usr/include/ -isysroot /Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.0.sdk -bundle -flat_namespace -undefined suppress"

let exec_magic_number = "Caml1999X008"
and cmi_magic_number = "Caml1999I012"
and cmo_magic_number = "Caml1999O007"
and cma_magic_number = "Caml1999A008"
and cmx_magic_number = "Caml1999Y011"
and cmxa_magic_number = "Caml1999Z010"
and ast_impl_magic_number = "Caml1999M013"
and ast_intf_magic_number = "Caml1999N012"
and cmxs_magic_number = "Caml2007D001"

let load_path = ref ([] : string list)

let interface_suffix = ref ".mli"

let max_tag = 245
(* This is normally the same as in obj.ml, but we have to define it
   separately because it can differ when we're in the middle of a
   bootstrapping phase. *)
let lazy_tag = 246

let max_young_wosize = 256
let stack_threshold = 256 (* see byterun/config.h *)

let architecture = "arm"
let model = "default"
let system = "macosx"

let asm = "/Developer/Platforms/iPhoneOS.platform/Developer/usr/bin/arm-apple-darwin10-gcc-4.2.1 -I/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.0.sdk/usr/lib/gcc/arm-apple-darwin10/4.2.1/include/ -I/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.0.sdk/usr/include/ -isysroot /Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.0.sdk -c"

let ext_obj = ".o"
let ext_asm = ".s"
let ext_lib = ".a"
let ext_dll = ".so"

let default_executable_name =
  match Sys.os_type with
    "Unix" -> "a.out"
  | "Win32" | "Cygwin" -> "camlprog.exe"
  | _ -> "camlprog"

let systhread_supported = true;;

let print_config oc =
  let p name valu = Printf.fprintf oc "%s: %s\n" name valu in
  let p_bool name valu = Printf.fprintf oc "%s: %B\n" name valu in
  p "version" version;
  p "standard_library_default" standard_library_default;
  p "standard_library" standard_library;
  p "standard_runtime" standard_runtime;
  p "ccomp_type" ccomp_type;
  p "bytecomp_c_compiler" bytecomp_c_compiler;
  p "bytecomp_c_libraries" bytecomp_c_libraries;
  p "native_c_compiler" native_c_compiler;
  p "native_c_libraries" native_c_libraries;
  p "native_pack_linker" native_pack_linker;
  p "ranlib" ranlib;
  p "cc_profile" cc_profile;
  p "architecture" architecture;
  p "model" model;
  p "system" system;
  p "asm" asm;
  p "ext_obj" ext_obj;
  p "ext_asm" ext_asm;
  p "ext_lib" ext_lib;
  p "ext_dll" ext_dll;
  p "os_type" Sys.os_type;
  p "default_executable_name" default_executable_name;
  p_bool "systhread_supported" systhread_supported;
  flush oc;
;;
