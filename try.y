%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *archivo;
extern int yylex();
extern int yyparse();
void yyerror(const char *s);
%}

%token ADD SUB MUL DIV ASSIGN SEMICOLON LPAREN RPAREN INT FLOAT DOUBLE CHAR VOID COLON LBRACE RBRACE TRUE FALSE RETURN IF ELSE WHILE FOR EQ NE GE GT LE LT

%union {
    char *string;
}

%token <string> IDENTIFIER INTEGER

%type <string> expression 
term 
factor 
etype 
funcs 
lastdec 
declaration 
declaration_list 
statements 
statement 
statementsf
boolElement
felements
bcomparator
elseOp
actualizacion
funcCallList
thingThatCanHappen

%%

program : statements {
            printf("%s", $1);
            fprintf(archivo, "%s", $1);
        }
        ;

statements : thingThatCanHappen
           | funcs
           | thingThatCanHappen statements{
                char str[40];
                strcpy(str, $1);
                strcat(str, "\n");
                strcat(str, $2);
                size_t originalStringLength = strlen(str);

                char *copiedString;
                copiedString = (char *)malloc(originalStringLength+1);

                strcpy(copiedString, str);

                $$ = copiedString;
           }
           | funcs statements {
                char str[40];
                strcpy(str, $1);
                strcat(str, "\n");
                strcat(str, $2);
                size_t originalStringLength = strlen(str);

                char *copiedString;
                copiedString = (char *)malloc(originalStringLength+1);

                strcpy(copiedString, str);

                $$ = copiedString;
           }
           ;

funcs : etype IDENTIFIER LPAREN declaration_list RPAREN LBRACE statementsf RBRACE {
            //QUITAR TIPO, PONER DEF, : FINALES
            char str[2048];

            sprintf(str, "%s %s (%s){\n%s\n}\n", $1, $2, $4, $7);

            size_t originalStringLength = strlen(str);

            char *copiedString;
            copiedString = (char *)malloc(originalStringLength+1);

            strcpy(copiedString, str);

            $$ = copiedString;
        }
        ;
statementsf : thingThatCanHappen{
                    char str[40];
                    strcpy(str, "\t");
                    strcat(str, $1);
                    size_t originalStringLength = strlen(str);

                    char *copiedString;
                    copiedString = (char *)malloc(originalStringLength+1);

                    strcpy(copiedString, str);

                    $$ = copiedString;
                }
            | felements{
                    char str[40];
                    strcpy(str, "\t");
                    strcat(str, $1);
                    size_t originalStringLength = strlen(str);

                    char *copiedString;
                    copiedString = (char *)malloc(originalStringLength+1);

                    strcpy(copiedString, str);

                    $$ = copiedString;
                }
            | felements statementsf{
                    char str[40];
                    strcpy(str, "\t");
                    strcat(str, $1);
                    strcat(str, "\n");
                    strcat(str, $2);
                    size_t originalStringLength = strlen(str);

                    char *copiedString;
                    copiedString = (char *)malloc(originalStringLength+1);

                    strcpy(copiedString, str);

                    $$ = copiedString;
            }
            | thingThatCanHappen statementsf {
                    char str[40];
                    strcpy(str, "\t");
                    strcat(str, $1);
                    strcat(str, "\n");
                    strcat(str, $2);
                    size_t originalStringLength = strlen(str);

                    char *copiedString;
                    copiedString = (char *)malloc(originalStringLength+1);

                    strcpy(copiedString, str);

                    $$ = copiedString;
                }
            
            ;
declaration_list : lastdec
                 | declaration declaration_list{
                    char str[40];
                    strcpy(str, $1);
                    strcat(str, ", ");
                    strcat(str, $2);
                    size_t originalStringLength = strlen(str);

                    char *copiedString;
                    copiedString = (char *)malloc(originalStringLength+1);

                    strcpy(copiedString, str);

                    $$ = copiedString;
                 }
                 ;

lastdec : etype IDENTIFIER{
            //QUITAR TIPO
            char str[40];
            strcpy(str, $1);
            strcat(str, " ");
            strcat(str, $2);

            size_t originalStringLength = strlen(str);

            char *copiedString;
            copiedString = (char *)malloc(originalStringLength+1);

            strcpy(copiedString, str);

            $$ = copiedString;
}
        ;

declaration : etype IDENTIFIER COLON{
                //QUITAR TIPO
                char str[40];
                strcpy(str, $1);
                strcat(str, $2);
                size_t originalStringLength = strlen(str);

                char *copiedString;
                copiedString = (char *)malloc(originalStringLength+1);

                strcpy(copiedString, str);

                $$ = copiedString;
                }
            ;            


thingThatCanHappen : statement
                    | IDENTIFIER ASSIGN expression SEMICOLON{
                        char str[40];

                        sprintf(str, "%s = %s", $1, $3);
                        
                        size_t originalStringLength = strlen(str);

                        char *copiedString;
                        copiedString = (char *)malloc(originalStringLength+1);

                        strcpy(copiedString, str);

                        $$ = copiedString;
                    }
                    | IDENTIFIER LPAREN funcCallList RPAREN SEMICOLON{
                        char str[40];

                        sprintf(str, "%s(%s)", $1, $3);
                        
                        size_t originalStringLength = strlen(str);

                        char *copiedString;
                        copiedString = (char *)malloc(originalStringLength+1);

                        strcpy(copiedString, str);

                        $$ = copiedString;
                    }
                ;

funcCallList : IDENTIFIER
             | IDENTIFIER COLON funcCallList {
                    char str[40];

                    sprintf(str, "%s, %s", $1, $3);
                    
                    size_t originalStringLength = strlen(str);

                    char *copiedString;
                    copiedString = (char *)malloc(originalStringLength+1);

                    strcpy(copiedString, str);

                    $$ = copiedString;
                }
        
        ;

statement : etype IDENTIFIER ASSIGN expression SEMICOLON {
                //QUITAR TIPO
                char str[40];
                strcpy(str, $1);
                strcat(str, " ");
                strcat(str, $2);
                strcat(str, " = ");
                strcat(str, $4);
                size_t originalStringLength = strlen(str);

                char *copiedString;
                copiedString = (char *)malloc(originalStringLength+1);

                strcpy(copiedString, str);

                $$ = copiedString;
            }
          ;

elseOp : ELSE LBRACE statementsf RBRACE{
            //TODO
            char str[1024];

            sprintf(str, "else{\n%s\n}", $3);

            size_t originalStringLength = strlen(str);

            char *copiedString;
            copiedString = (char *)malloc(originalStringLength+1);

            strcpy(copiedString, str);

            $$ = copiedString;
        }
        ;

felements : IF LPAREN boolElement RPAREN LBRACE statementsf RBRACE elseOp{
            //TODO
            char str[2048];

            sprintf(str, "if(%s){\n%s\n}%s", $3, $6, $8);

            size_t originalStringLength = strlen(str);

            char *copiedString;
            copiedString = (char *)malloc(originalStringLength+1);

            strcpy(copiedString, str);

            $$ = copiedString;
        }

        |IF LPAREN boolElement RPAREN LBRACE statementsf RBRACE{
            //TODO
            char str[2048];

            sprintf(str, "if(%s){\n%s\n}", $3, $6);

            size_t originalStringLength = strlen(str);

            char *copiedString;
            copiedString = (char *)malloc(originalStringLength+1);

            strcpy(copiedString, str);

            $$ = copiedString;
        }

        | WHILE LPAREN boolElement RPAREN LBRACE statementsf RBRACE{
            //TODO
            char str[2048];

            sprintf(str, "while(%s){\n%s\n}", $3, $6);

            size_t originalStringLength = strlen(str);

            char *copiedString;
            copiedString = (char *)malloc(originalStringLength+1);

            strcpy(copiedString, str);

            $$ = copiedString;
        }
        | RETURN expression SEMICOLON{
            char str[40];

            sprintf(str, "return %s", $2);

            size_t originalStringLength = strlen(str);

            char *copiedString;
            copiedString = (char *)malloc(originalStringLength+1);

            strcpy(copiedString, str);

            $$ = copiedString;
        }
        | FOR LPAREN statement boolElement SEMICOLON actualizacion RPAREN LBRACE statementsf RBRACE{
            //TODO
            char str[1024];

            sprintf(str, "for(%s;%s;%s){\n%s\n}", $3, $4, $6, $9);

            size_t originalStringLength = strlen(str);

            char *copiedString;
            copiedString = (char *)malloc(originalStringLength+1);

            strcpy(copiedString, str);

            $$ = copiedString;
        }

        ;

actualizacion : IDENTIFIER ADD ADD{
                    char str[40];

                    sprintf(str, "%s++", $1);

                    size_t originalStringLength = strlen(str);

                    char *copiedString;
                    copiedString = (char *)malloc(originalStringLength+1);

                    strcpy(copiedString, str);

                    $$ = copiedString;
                }
                | IDENTIFIER SUB SUB{
                    char str[40];

                    sprintf(str, "%s--", $1);

                    size_t originalStringLength = strlen(str);

                    char *copiedString;
                    copiedString = (char *)malloc(originalStringLength+1);

                    strcpy(copiedString, str);

                    $$ = copiedString;
                }
                | IDENTIFIER ASSIGN expression{
                    char str[100];

                    sprintf(str, "%s = %s", $1, $3);

                    size_t originalStringLength = strlen(str);

                    char *copiedString;
                    copiedString = (char *)malloc(originalStringLength+1);

                    strcpy(copiedString, str);

                    $$ = copiedString;
                }

boolElement : IDENTIFIER bcomparator expression{
                char str[40];
                strcpy(str, $1);
                strcat(str, $2);
                strcat(str, $3);
                size_t originalStringLength = strlen(str);

                char *copiedString;
                copiedString = (char *)malloc(originalStringLength+1);

                strcpy(copiedString, str);

                $$ = copiedString;
            }
            | IDENTIFIER
        
        ;
bcomparator : EQ {
            $$ = "==";
        }
        |  NE {
            $$ = "!=";
        }
        |  GE {
            $$ = ">=";
        }
        |  GT {
            $$ = ">";
        }
        |  LE {
            $$ = "<=";
        }
        |  LT {
            $$ = "<";
        }
    ;

expression : term 
           | expression ADD term {
                char str[40];
                strcpy(str, $1);
                strcat(str, " + ");
                strcat(str, $3);

                size_t originalStringLength = strlen(str);

                char *copiedString;
                copiedString = (char *)malloc(originalStringLength+1);

                strcpy(copiedString, str);

                $$ = copiedString;
            }
           | expression SUB term {
                char str[40];
                strcpy(str, $1);
                strcat(str, " - ");
                strcat(str, $3);

                size_t originalStringLength = strlen(str);

                char *copiedString;
                copiedString = (char *)malloc(originalStringLength+1);

                strcpy(copiedString, str);

                $$ = copiedString;
            }
           ;

term : factor 
     | term MUL factor {
        char str[40];
        strcpy(str, $1);
        strcat(str, " * ");
        strcat(str, $3);

        size_t originalStringLength = strlen(str);

        char *copiedString;
        copiedString = (char *)malloc(originalStringLength+1);

        strcpy(copiedString, str);

        $$ = copiedString;
        }
     | term DIV factor {
        char str[40];
        strcpy(str, $1);
        strcat(str, " / ");
        strcat(str, $3);

        size_t originalStringLength = strlen(str);

        char *copiedString;
        copiedString = (char *)malloc(originalStringLength+1);

        strcpy(copiedString, str);


        $$ = copiedString;
        }
     ;

factor : IDENTIFIER 
       | INTEGER 
       | LPAREN expression RPAREN {
            $$ = $2;
        }
       ;
       // Eliminar esta parte, no se necesitan tipos
etype : INT {
            $$ = "int";
        }
        |  FLOAT {
            $$ = "float";
        }
        |  DOUBLE {
            $$ = "double";
        }
        |  CHAR {
            $$ = "char";
        }
    ;


%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    
    archivo = fopen("archivo.py", "w");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    yyparse();

    fclose(archivo);
    return 0;
}

