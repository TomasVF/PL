%{
#include <stdio.h>
#include "y.tab.h"
%}

%%

"+"                         { return ADD; }
"-"                         { return SUB; }
"*"                         { return MUL; }
"/"                         { return DIV; }
"="                         { return ASSIGN; }
";"                         { return SEMICOLON; }
[a-zA-Z_][a-zA-Z0-9_]*     { yylval.sval = yytext; return IDENTIFIER; }
[0-9]+                      { yylval.ival = atoi(yytext); return INTEGER; }
"("                         { return LPAREN; }
")"                         { return RPAREN; }
"{"                         { return LBRACE; }
"}"                         { return RBRACE; }
"int"                       { return INT; }
"float"                     { return FLOAT; }
"double"                    { return DOUBLE; }
"char"                      { return CHAR; }
"void"                      { return VOID; }
"main"                      { return MAIN; }
"return"                    { return RETURN; }
"if"                        { return IF; }
"else"                      { return ELSE; }
"while"                     { return WHILE; }
"for"                       { return FOR; }
"=="                        { return EQ; }
"!="                        { return NE; }
">="                        { return GE; }
">"                         { return GT; }
"<="                        { return LE; }
"<"                         { return LT; }
[ \t\n]                     ; /* Ignoring whitespace */
.                           { return *yytext; }

%%

int yywrap(void) {
    return 1;
}