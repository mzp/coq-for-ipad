type token =
  | Tident of (string)
  | Tchar of (int)
  | Tstring of (string)
  | Taction of (Syntax.location)
  | Trule
  | Tparse
  | Tparse_shortest
  | Tand
  | Tequal
  | Tend
  | Tor
  | Tunderscore
  | Teof
  | Tlbracket
  | Trbracket
  | Tstar
  | Tmaybe
  | Tplus
  | Tlparen
  | Trparen
  | Tcaret
  | Tdash
  | Tlet
  | Tas
  | Tsharp

val lexer_definition :
  (Lexing.lexbuf  -> token) -> Lexing.lexbuf -> Syntax.lexer_definition
