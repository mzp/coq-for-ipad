\" $Id: ocaml.m 10444 2010-05-20 14:06:29Z doligez $

.TH OCAML 1

.SH NAME
ocaml \- The Objective Caml interactive toplevel

.SH SYNOPSIS
.B ocaml
[
.I options
]
[
.I object-files
]
[
.I script-file
]
.SH DESCRIPTION

The
.BR ocaml (1)
command is the toplevel system for Objective Caml,
that permits interactive use of the Objective Caml system through a
read-eval-print loop. In this mode, the system repeatedly reads Caml
phrases from the input, then typechecks, compiles and evaluates
them, then prints the inferred type and result value, if any. The
system prints a # (sharp) prompt before reading each phrase.

A toplevel phrase can span several lines. It is terminated by ;; (a
double-semicolon). The syntax of toplevel phrases is as follows.

The toplevel system is started by the command
.BR ocaml (1).
Phrases are read on standard input, results are printed on standard
output, errors on standard error. End-of-file on standard input
terminates
.BR ocaml (1).

If one or more
.I object-files
(ending in .cmo or .cma) are given, they are loaded silently before
starting the toplevel.

If a
.I script-file
is given, phrases are read silently from the file, errors printed on
standard error.
.BR ocaml (1)
exits after the execution of the last phrase.

.SH OPTIONS

The following command-line options are recognized by
.BR ocaml (1).
.TP
.BI \-I \ directory
Add the given directory to the list of directories searched for
source and compiled files. By default, the current directory is
searched first, then the standard library directory. Directories added
with
.B \-I
are searched after the current directory, in the order in which they
were given on the command line, but before the standard library
directory.
.IP
If the given directory starts with
.BR + ,
it is taken relative to the
standard library directory. For instance,
.B \-I\ +labltk
adds the subdirectory
.B labltk
of the standard library to the search path.
.IP
Directories can also be added to the search path once the toplevel
is running with the
.B #directory
directive.
.TP
.BI \-init \ file
Load the given file instead of the default initialization file.
The default file is
.B .ocamlinit
in the current directory if it exists, otherwise
.B .ocamlinit
in the user's home directory.
.TP
.B \-labels
Labels are not ignored in types, labels may be used in applications,
and labelled parameters can be given in any order.  This is the default.
.TP
.B \-noassert
Do not compile assertion checks.  Note that the special form
.B assert\ false
is always compiled because it is typed specially.
.TP
.B \-nolabels
Ignore non-optional labels in types. Labels cannot be used in
applications, and parameter order becomes strict.
.TP
.B \-noprompt
Do not display any prompt when waiting for input.
.TP
.B \-nostdlib
Do not include the standard library directory in the list of
directories searched for source and compiled files.
.TP
.B \-principal
Check information path during type-checking, to make sure that all
types are derived in a principal way.  When using labelled arguments
and/or polymorphic methods, this flag is required to ensure future
versions of the compiler will be able to infer types correctly, even
if internal algorithms change.
All programs accepted in
.B \-principal
mode are also accepted in the
default mode with equivalent types, but different binary signatures,
and this may slow down type checking; yet it is a good idea to
use it once before publishing source code.
.TP
.B \-rectypes
Allow arbitrary recursive types during type-checking.  By default,
only recursive types where the recursion goes through an object type
are supported.
.TP
.B \-unsafe
Turn bound checking off on array and string accesses (the
.BR v.(i) and s.[i]
constructs). Programs compiled with
.B \-unsafe
are therefore slightly faster, but unsafe: anything can happen if the program
accesses an array or string outside of its bounds.
.TP
.B \-version
Print version string and exit.
.TP
.B \-vnum
Print short version number and exit.
.TP
.BI \-w \ warning-list
Enable or disable warnings according to the argument
.IR warning-list .
See
.BR ocamlc (1)
for the syntax of the
.I warning\-list
argument.
.TP
.BI \-warn-error \ warning-list
Treat as errors the warnings described by the argument
.IR warning\-list .
Note that a warning is not triggered (and not treated as error) if
it is disabled by the
.B \-w
option.  See
.BR ocamlc (1)
for the syntax of the
.I warning\-list
argument.
.TP
.BR \-help \ or \ \-\-help
Display a short usage summary and exit.

.SH ENVIRONMENT VARIABLES
.TP
.B LC_CTYPE
If set to iso_8859_1, accented characters (from the
ISO Latin-1 character set) in string and character literals are
printed as is; otherwise, they are printed as decimal escape sequences.
.TP
.B TERM
When printing error messages, the toplevel system
attempts to underline visually the location of the error. It
consults the TERM variable to determines the type of output terminal
and look up its capabilities in the terminal database.

.SH SEE ALSO
.BR ocamlc (1), \ ocamlopt (1), \ ocamlrun (1).
.br
.IR The\ Objective\ Caml\ user's\ manual ,
chapter "The toplevel system".
