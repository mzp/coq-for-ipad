#!/bin/sh
#########################################################################
#                                                                       #
#                            Objective Caml                             #
#                                                                       #
#            Damien Doligez, projet Para, INRIA Rocquencourt            #
#                                                                       #
#   Copyright 1999 Institut National de Recherche en Informatique et    #
#   en Automatique.  All rights reserved.  This file is distributed     #
#   under the terms of the Q Public License version 1.0.                #
#                                                                       #
#########################################################################

# $Id: ocamlmktop.tpl 10443 2010-05-20 09:44:25Z doligez $

exec %%BINDIR%%/ocamlc -linkall toplevellib.cma "$@" topstart.cmo
