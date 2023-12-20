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

char* substituteString(const char *str) {
    int len = strlen(str);
    char *result = (char*)malloc(3 * len * sizeof(char)); // Allocate memory for the result
    
    if (result == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    
    int j = 0;
    int formatFlag = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] == '%' && i < len - 1) {
            result[j++] = '{';
            result[j++] = '}';
            ++i; // Skip the next character
            ++i;
        }

        if (formatFlag) {
            result[j++] = '.';
            result[j++] = 'f';
            result[j++] = 'o';
            result[j++] = 'r';
            result[j++] = 'm';
            result[j++] = 'a';
            result[j++] = 't';
            result[j++] = '(';
            // Adding the rest of the string in the parenthesis
            for (; i < len; ++i) {
                result[j++] = str[i];
            }
            result[j++] = ')';
            break; // Exit the loop as we've handled the entire string
        } else if (i > 0 && str[i - 1] == '"' && str[i] == ',') {
            formatFlag = 1;
        } else {
            result[j++] = str[i];
        }
    }
    result[j] = '\0'; // Null-terminate the result string
    
    return result;
}

char * getSubstringAfter(const char *inputString, const char *searchString) {
    char *output = (char *)malloc(1024);
    const char *startPtr = strstr(inputString, searchString);

    if (startPtr != NULL) {
        startPtr += strlen(searchString);
        strcpy(output, startPtr);
    } else {
        strcpy(output, "");
    }
    return output;
}

char * extractSubstring(const char *inputString, const char *startMarker, const char *endMarker) {
    char *output = (char *)malloc(1024);
    const char *startPtr = strstr(inputString, startMarker);
    
    if (startPtr != NULL) {
        startPtr += strlen(startMarker);
        const char *endPtr = strstr(startPtr, endMarker);
        
        if (endPtr != NULL) {
            size_t length = endPtr - startPtr;
            strncpy(output, startPtr, length);
            output[length] = '\0';
        }
    }
    return output;
}

%}

%token ADD SUB MUL DIV ASSIGN SEMICOLON LPAREN RPAREN INT FLOAT DOUBLE CHAR VOID COLON LBRACE RBRACE RETURN IF ELSE WHILE FOR EQ NE GE GT LE LT

%union {
    char *string;
}

%token <string> IDENTIFIER INTEGER CHARVALUE COMENTARIOCONJUNTO COMENTARIOLINEA PRINT

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
boolElement
felements
bcomparator
elseOp
actualizacion
funcCallList
thingThatCanHappen
loopsAndThings

%%

program : statements {
            printf("%s", $1);
            fprintf(archivo, "%s", $1);
        }
        ;

statements : thingThatCanHappen
           | funcs
           | COMENTARIOCONJUNTO{
                char str[40];
                strcpy(str, "\"\"\"");
                strcat(str, extractSubstring($1, "/*", "*/"));
                strcat(str, "\"\"\"\n");
                size_t originalStringLength = strlen(str);

                char *copiedString;
                copiedString = (char *)malloc(originalStringLength+1);

                strcpy(copiedString, str);

                $$ = copiedString;
           }
           | COMENTARIOCONJUNTO statements{
                char str[40];
                strcpy(str, "\"\"\"");
                strcat(str, extractSubstring($1, "/*", "*/"));
                strcat(str, "\"\"\"\n");
                strcat(str, $2);
                size_t originalStringLength = strlen(str);

                char *copiedString;
                copiedString = (char *)malloc(originalStringLength+1);

                strcpy(copiedString, str);

                $$ = copiedString;
           }
           | COMENTARIOLINEA{
                char str[40];
                strcpy(str, "#");
                strcat(str, getSubstringAfter($1, "//"));
                strcat(str, "\n");
                size_t originalStringLength = strlen(str);

                char *copiedString;
                copiedString = (char *)malloc(originalStringLength+1);

                strcpy(copiedString, str);

                $$ = copiedString;
           }
           | COMENTARIOLINEA statements{
                char str[40];
                strcpy(str, "#");
                strcat(str, getSubstringAfter($1, "//"));
                strcat(str, "\n");
                strcat(str, $2);
                size_t originalStringLength = strlen(str);

                char *copiedString;
                copiedString = (char *)malloc(originalStringLength+1);

                strcpy(copiedString, str);

                $$ = copiedString;
           }
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
           | error_handling{exit(2);} 
           | loopsAndThings{printf("No se pueden escribir estas cosas fuera de funciones: %d\n", line_num);
                        exit(2);}
           ;

error_handling : IDENTIFIER{printf("Nombre de variable en lugar erróneo, línea: %d\n", line_num);
                        exit(2);}
            | COLON{printf("Símbolo , en lugar erróneo, línea: %d\n", line_num);
                        exit(2);}
            | etype {printf("Identificador de tipo en lugar erróneo, línea: %d\n", line_num);
                        exit(2);}
            | bcomparator {printf("Comparador en lugar erróneo, línea: %d\n", line_num);
                        exit(2);}
            | SUB{printf("Símbolo - en lugar erróneo, línea: %d\n", line_num);
                        exit(2);}
            | LPAREN{printf("Símbolo ( en lugar erróneo, línea: %d\n", line_num);
                exit(2);}
            | RPAREN{printf("Símbolo ) en lugar erróneo, línea: %d\n", line_num);
                exit(2);}
            | ADD{printf("Símbolo + en lugar erróneo, línea: %d\n", line_num);
                exit(2);}
            | LBRACE{printf("Símbolo { en lugar erróneo, línea: %d\n", line_num);
                exit(2);}
            | DIV{printf("Símbolo / en lugar erróneo, línea: %d\n", line_num);
                exit(2);}
            | MUL{printf("Símbolo * en lugar erróneo, línea: %d\n", line_num);
                exit(2);}
            | ASSIGN{printf("Símbolo = en lugar erróneo, línea: %d\n", line_num);
                exit(2);}
            ;

lbrace : LBRACE{nTabs++;}
    ;

rbrace : RBRACE{nTabs--;}
    ;


funcs : etype IDENTIFIER LPAREN declaration_list RPAREN lbrace felements rbrace {



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
        |VOID IDENTIFIER LPAREN declaration_list RPAREN lbrace felements rbrace {



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

elseOp : ELSE lbrace felements rbrace{
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

loopsAndThings : IF LPAREN boolElement RPAREN lbrace felements rbrace elseOp{
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

        |IF LPAREN boolElement RPAREN lbrace felements rbrace{
            //TODO
            char str[2048];

            sprintf(str, "if(%s):\n%s\n", $3, $6);

            size_t originalStringLength = strlen(str);

            char *copiedString;
            copiedString = (char *)malloc(originalStringLength+1);

            strcpy(copiedString, str);

            $$ = copiedString;
        }

        | WHILE LPAREN boolElement RPAREN lbrace felements rbrace{
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
        | FOR LPAREN statement boolElement SEMICOLON actualizacion RPAREN lbrace felements rbrace{

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

felements : thingThatCanHappen{
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
        | PRINT SEMICOLON{
                    char end[2024];
                    if(nTabs > 0){
                        strcpy(end, "\t");
                        for(int i = 1; i<nTabs;i++){
                            strcat(end, "\t");
                        }
                    }
                    char *modifiedString = substituteString(extractSubstring($1,"(", ")"));
                    strcat(end, "print(");
                    strcat(end, modifiedString);
                    strcat(end, ")");
                    size_t originalStringLength = strlen(end);

                    char *copiedString;
                    copiedString = (char *)malloc(originalStringLength+1);

                    strcpy(copiedString, end);

                    $$ = copiedString;
                }
        | loopsAndThings{
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
        | PRINT SEMICOLON felements{
                    char end[2024];
                    if(nTabs > 0){
                        strcpy(end, "\t");
                        for(int i = 1; i<nTabs;i++){
                            strcat(end, "\t");
                        }
                    }
                    char *modifiedString = substituteString(extractSubstring($1,"(", ")"));
                    printf("\nES esto: %s\n", modifiedString);
                    strcat(end, "print(");
                    strcat(end, modifiedString);
                    strcat(end, ")");
                    strcat(end, "\n");
                    strcat(end, $3);
                    size_t originalStringLength = strlen(end);

                    char *copiedString;
                    copiedString = (char *)malloc(originalStringLength+1);

                    strcpy(copiedString, end);

                    $$ = copiedString;
                }
        | thingThatCanHappen felements{
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
        | loopsAndThings felements{
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
            | error_handling{exit(2);} 

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
    fprintf(stderr, "Error: de compilacion en la linea: %d\n", line_num);
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

