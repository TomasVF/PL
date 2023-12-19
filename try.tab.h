/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_TRY_TAB_H_INCLUDED
# define YY_YY_TRY_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ADD = 258,                     /* ADD  */
    SUB = 259,                     /* SUB  */
    MUL = 260,                     /* MUL  */
    DIV = 261,                     /* DIV  */
    ASSIGN = 262,                  /* ASSIGN  */
    SEMICOLON = 263,               /* SEMICOLON  */
    LPAREN = 264,                  /* LPAREN  */
    RPAREN = 265,                  /* RPAREN  */
    INT = 266,                     /* INT  */
    FLOAT = 267,                   /* FLOAT  */
    DOUBLE = 268,                  /* DOUBLE  */
    CHAR = 269,                    /* CHAR  */
    VOID = 270,                    /* VOID  */
    COLON = 271,                   /* COLON  */
    LBRACE = 272,                  /* LBRACE  */
    RBRACE = 273,                  /* RBRACE  */
    RETURN = 274,                  /* RETURN  */
    IF = 275,                      /* IF  */
    ELSE = 276,                    /* ELSE  */
    WHILE = 277,                   /* WHILE  */
    FOR = 278,                     /* FOR  */
    EQ = 279,                      /* EQ  */
    NE = 280,                      /* NE  */
    GE = 281,                      /* GE  */
    GT = 282,                      /* GT  */
    LE = 283,                      /* LE  */
    LT = 284,                      /* LT  */
    IDENTIFIER = 285,              /* IDENTIFIER  */
    INTEGER = 286,                 /* INTEGER  */
    CHARVALUE = 287,               /* CHARVALUE  */
    COMENTARIOCONJUNTO = 288,      /* COMENTARIOCONJUNTO  */
    COMENTARIOLINEA = 289          /* COMENTARIOLINEA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ADD 258
#define SUB 259
#define MUL 260
#define DIV 261
#define ASSIGN 262
#define SEMICOLON 263
#define LPAREN 264
#define RPAREN 265
#define INT 266
#define FLOAT 267
#define DOUBLE 268
#define CHAR 269
#define VOID 270
#define COLON 271
#define LBRACE 272
#define RBRACE 273
#define RETURN 274
#define IF 275
#define ELSE 276
#define WHILE 277
#define FOR 278
#define EQ 279
#define NE 280
#define GE 281
#define GT 282
#define LE 283
#define LT 284
#define IDENTIFIER 285
#define INTEGER 286
#define CHARVALUE 287
#define COMENTARIOCONJUNTO 288
#define COMENTARIOLINEA 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 52 "try.y"

    char *string;

#line 139 "try.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TRY_TAB_H_INCLUDED  */
