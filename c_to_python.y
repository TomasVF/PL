%{
#include <stdio.h>
#include <stdlib.h>
extern int yylex();
extern int yyparse();
void yyerror(const char *s);
%}

%token ADD SUB MUL DIV ASSIGN SEMICOLON INTEGER IDENTIFIER LPAREN RPAREN LBRACE RBRACE
%token INT FLOAT DOUBLE CHAR VOID MAIN RETURN IF ELSE WHILE FOR EQ NE GE GT LE LT

%%
program : declaration_list 
        | declaration_list function
        ;

declaration_list : declaration
                 | declaration_list declaration
                 ;

declaration : type_specifier IDENTIFIER SEMICOLON
            ;

type_specifier : INT
               | FLOAT
               | DOUBLE
               | CHAR
               | VOID
               ;

function : type_specifier MAIN LPAREN RPAREN compound_stmt
         | type_specifier IDENTIFIER LPAREN RPAREN compound_stmt
         ;

compound_stmt : LBRACE RBRACE
              | LBRACE statement_list RBRACE
              ;

statement_list : statement
               | statement_list statement
               ;

statement : expression_stmt
          | compound_stmt
          | selection_stmt
          | iteration_stmt
          | return_stmt
          ;

expression_stmt : SEMICOLON
                | expression SEMICOLON
                ;

expression : IDENTIFIER ASSIGN expression
           | simple_expression
           ;

simple_expression : additive_expression
                  | simple_expression EQ additive_expression
                  | simple_expression NE additive_expression
                  | simple_expression GE additive_expression
                  | simple_expression GT additive_expression
                  | simple_expression LE additive_expression
                  | simple_expression LT additive_expression
                  ;

additive_expression : term
                    | additive_expression ADD term
                    | additive_expression SUB term
                    ;

term : factor
     | term MUL factor
     | term DIV factor
     ;

factor : IDENTIFIER
       | INTEGER
       | LPAREN expression RPAREN
       ;

selection_stmt : IF LPAREN expression RPAREN statement
               | IF LPAREN expression RPAREN statement ELSE statement
               ;

iteration_stmt : WHILE LPAREN expression RPAREN statement
               | FOR LPAREN expression_stmt expression_stmt expression RPAREN statement
               ;

return_stmt : RETURN SEMICOLON
            | RETURN expression SEMICOLON
            ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    yyparse();
    return 0;
}
