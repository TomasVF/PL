%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *archivo;
int nTabs;
extern int yylex();
extern int yyparse();
extern int line_num;
void yyerror(const char *s);

void addTab(){
    nTabs++;
}
%}

%token ADD SUB MUL DIV ASSIGN SEMICOLON LPAREN RPAREN INT FLOAT DOUBLE CHAR VOID COLON LBRACE RBRACE RETURN IF ELSE WHILE FOR EQ NE GE GT LE LT

%union {
    char *string;
}

%token <string> IDENTIFIER INTEGER CHARVALUE

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
           | error_handling{exit(2);} // New rule for error handling
           | felements{printf("Error de compilación en la línea: %d", line_num);
                        exit(2);}
           ;

error_handling : IDENTIFIER{printf("Error de compilación en la línea: %d", line_num);
                        exit(2);}
            | COLON{printf("Error de compilación en la línea: %d", line_num);
                        exit(2);}
            | etype {printf("Error de compilación en la línea: %d", line_num);
                        exit(2);}
            | bcomparator {printf("Error de compilación en la línea: %d", line_num);
                        exit(2);}
            | SUB{printf("Error de compilación en la línea: %d", line_num);
                        exit(2);}
            | LPAREN{printf("Error de compilación en la línea: %d", line_num);
                exit(2);}
            | RPAREN{printf("Error de compilación en la línea: %d", line_num);
                exit(2);}
            | ADD{printf("Error de compilación en la línea: %d", line_num);
                exit(2);}
            | LBRACE{printf("Error de compilación en la línea: %d", line_num);
                exit(2);}
            | RBRACE{printf("Error de compilación en la línea: %d", line_num);
                exit(2);}
            | DIV{printf("Error de compilación en la línea: %d", line_num);
                exit(2);}
            | MUL{printf("Error de compilación en la línea: %d", line_num);
                exit(2);}
            | ASSIGN{printf("Error de compilación en la línea: %d", line_num);
                exit(2);}
            ;

lbrace : LBRACE{nTabs++;}
    ;

rbrace : RBRACE{nTabs--;}
    ;


funcs : etype IDENTIFIER LPAREN declaration_list RPAREN lbrace statementsf rbrace {



            //QUITAR TIPO, PONER DEF, : FINALES
            char str[2048];

            if(strcmp($2, "main")==0){
                sprintf(str, "def %s(%s):\n%s\n%s", $2, $4, $7, "\nif __name__ == '__main__':\n\tmain()\n");
            }else{
                sprintf(str, "def %s(%s):\n%s\n", $2, $4, $7);
            }

            size_t originalStringLength = strlen(str);

            char *copiedString;
            copiedString = (char *)malloc(originalStringLength+1);

            strcpy(copiedString, str);



            $$ = copiedString;
        }
        ;
statementsf : thingThatCanHappen{
                    char str[40];
                    if(nTabs > 0){
                        strcpy(str, "\t");
                        for(int i = 1; i<nTabs;i++){
                            strcat(str, "\t");
                        }
                    }
                    strcat(str, $1);
                    size_t originalStringLength = strlen(str);

                    char *copiedString;
                    copiedString = (char *)malloc(originalStringLength+1);

                    strcpy(copiedString, str);

                    $$ = copiedString;
                }
            | felements{
                    char str[40];
                    if(nTabs > 0){
                        strcpy(str, "\t");
                        for(int i = 1; i<nTabs;i++){
                            strcat(str, "\t");
                        }
                    }
                    strcat(str, $1);
                    size_t originalStringLength = strlen(str);

                    char *copiedString;
                    copiedString = (char *)malloc(originalStringLength+1);

                    strcpy(copiedString, str);

                    $$ = copiedString;
                }
            | felements statementsf{
                    char str[40];
                    if(nTabs > 0){
                        strcpy(str, "\t");
                        for(int i = 1; i<nTabs;i++){
                            strcat(str, "\t");
                        }
                    }
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
                    if(nTabs > 0){
                        strcpy(str, "\t");
                        for(int i = 1; i<nTabs;i++){
                            strcat(str, "\t");
                        }
                    }
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
                 |{
                    $$ = "";
                 }
                 ;

lastdec : etype IDENTIFIER{
            //QUITAR TIPO
            char str[40];
            strcpy(str, $2);

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
                strcpy(str, $2);
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

funcCallList : expression
             | CHARVALUE
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
                strcpy(str, $2);
                strcat(str, " = ");
                strcat(str, $4);
                size_t originalStringLength = strlen(str);

                char *copiedString;
                copiedString = (char *)malloc(originalStringLength+1);

                strcpy(copiedString, str);

                $$ = copiedString;
            }
            | etype IDENTIFIER ASSIGN CHARVALUE SEMICOLON {
                //QUITAR TIPO
                char str[40];
                strcpy(str, $2);
                strcat(str, " = ");
                strcat(str, $4);
                size_t originalStringLength = strlen(str);

                char *copiedString;
                copiedString = (char *)malloc(originalStringLength+1);

                strcpy(copiedString, str);

                $$ = copiedString;
            }
          ;

elseOp : ELSE lbrace statementsf rbrace{
            //TODO
            char str[1024];

            sprintf(str, "else:\n%s\n", $3);

            size_t originalStringLength = strlen(str);

            char *copiedString;
            copiedString = (char *)malloc(originalStringLength+1);

            strcpy(copiedString, str);

            $$ = copiedString;
        }
        ;

felements : IF LPAREN boolElement RPAREN lbrace statementsf rbrace elseOp{
            //TODO
            char str[2048];

            sprintf(str, "if(%s):\n%s\n", $3, $6);

            if(nTabs > 0){
                for(int i = 0; i<nTabs;i++){
                    strcat(str, "\t");
                }
                strcat(str, $8);
            }

            size_t originalStringLength = strlen(str);

            char *copiedString;
            copiedString = (char *)malloc(originalStringLength+1);

            strcpy(copiedString, str);

            $$ = copiedString;
        }

        |IF LPAREN boolElement RPAREN lbrace statementsf rbrace{
            //TODO
            char str[2048];

            sprintf(str, "if(%s):\n%s\n", $3, $6);

            size_t originalStringLength = strlen(str);

            char *copiedString;
            copiedString = (char *)malloc(originalStringLength+1);

            strcpy(copiedString, str);

            $$ = copiedString;
        }

        | WHILE LPAREN boolElement RPAREN lbrace statementsf rbrace{
            //TODO
            char str[2048];

            sprintf(str, "while(%s):\n%s\n", $3, $6);

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
        | FOR LPAREN statement boolElement SEMICOLON actualizacion RPAREN lbrace statementsf rbrace{

            char delimitador[] = "= ";
            char *nombreVariable = strtok($3, delimitador);
            char *valorInicial = strtok(NULL, delimitador);


            //TODO
            char str[1024];

            int aumento = 0;
            if(strstr($6, "++") != NULL){
                aumento = 1;
            }else if(strstr($6, "--") != NULL){
                aumento = 0;
            }


            //vamos a hacer como si siempre es i++ o i--
            if (strstr($4, "<=") != NULL) {
                char delimitador2[] = "<=";
                char *nombreVariable2 = strtok($4, delimitador2);
                char *valorCondicion = strtok(NULL, delimitador2);
                if(atoi(valorInicial)==0 && aumento){
                    sprintf(str, "for %s in range(%d):\n%s\n", nombreVariable, (atoi(valorCondicion)+1), $9);
                }else if(aumento){
                    sprintf(str, "for %s in range(%s, %d):\n%s\n", nombreVariable, valorInicial, (atoi(valorCondicion)+1), $9);
                }else{
                    yyerror("No tiene sentido usar un for disminuyendo con <=");
                    exit(2);
                }
            } else if (strstr($4, ">=") != NULL) {
                char delimitador2[] = "<=";
                char *nombreVariable2 = strtok($4, delimitador2);
                char *valorCondicion = strtok(NULL, delimitador2);
                if(aumento){
                    yyerror("No tiene sentido usar un for aumentando con >=");
                    exit(2);
                }
                sprintf(str, "for %s in range(%s, %d, -1):\n%s\n", nombreVariable, valorInicial, (atoi(valorCondicion)-1), $9);
            } else if (strstr($4, "<") != NULL) {
                char delimitador2[] = "<";
                char *nombreVariable2 = strtok($4, delimitador2);
                char *valorCondicion = strtok(NULL, delimitador2);
                if(atoi(valorInicial)==0 && aumento){
                    sprintf(str, "for %s in range(%s):\n%s\n", nombreVariable, valorCondicion, $9);
                }else if(aumento){
                    sprintf(str, "for %s in range(%s, %s):\n%s\n", nombreVariable, valorInicial, valorCondicion, $9);
                }else{
                    yyerror("No tiene sentido usar un for disminuyendo con <");
                    exit(2);
                }
            } else if (strstr($4, ">") != NULL) {
                char delimitador2[] = "<=";
                char *nombreVariable2 = strtok($4, delimitador2);
                char *valorCondicion = strtok(NULL, delimitador2);
                if(aumento){
                    yyerror("No tiene sentido usar un for aumentando con >");
                    exit(2);
                }
                sprintf(str, "for %s in range(%s, %s, -1):\n%s\n", nombreVariable, valorInicial, valorCondicion, $9);
            }if (strstr($4, "==") != NULL) {
                yyerror("No tiene sentido usar un for con ==, usa un while");
                exit(2);
            }if (strstr($4, "!=") != NULL) {
                yyerror("No tiene sentido usar un for con !=, usa un while");
                exit(2);
            }

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

