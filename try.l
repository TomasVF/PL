%{
#include <stdlib.h>
#include "try.tab.h"
%}

%%

[ \t\n]                       ; /* Ignoring whitespace */
"int"                       { return INT; }
"float"                     { return FLOAT; }
"double"                    { return DOUBLE; }
"char"                      { return CHAR; }
"void"                      { return VOID; }
"("                         { return LPAREN; }
")"                         { return RPAREN; }
"{"                         { return LBRACE; }
"}"                         { return RBRACE; }
"+"                         { return ADD; }
"-"                         { return SUB; }
"*"                         { return MUL; }
"/"                         { return DIV; }
"="                         { return ASSIGN; }
";"                         { return SEMICOLON; }
","                         { return COLON; }
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
[a-zA-Z][a-zA-Z0-9_]*       { yylval.string=strdup(yytext); return IDENTIFIER; }
([0-9]+"."[0-9]+|[0-9]+)           { yylval.string=strdup(yytext); return INTEGER; }


.                           { }

%%

int yywrap(void) {
    return 1;
}
