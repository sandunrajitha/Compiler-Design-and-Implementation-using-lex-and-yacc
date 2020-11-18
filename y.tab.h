/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     TRUE = 259,
     FALSE = 260,
     VARIABLE = 261,
     WHILE = 262,
     IF = 263,
     PRINT = 264,
     END = 265,
     DO = 266,
     THEN = 267,
     ELSE = 268,
     OR = 269,
     AND = 270,
     NOT = 271,
     OVER = 272,
     PLUS = 273,
     MINUS = 274,
     MULTI = 275,
     LESS = 276,
     BIGGER = 277,
     EQUAL = 278,
     ASSIGN = 279,
     LESSEQ = 280,
     BIGEQ = 281,
     LAPREN = 282,
     COMMA = 283,
     RPAREN = 284,
     SEMI = 285,
     START = 286,
     IFX = 287,
     NE = 288,
     EQ = 289,
     LE = 290,
     GE = 291,
     UMINUS = 292
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define TRUE 259
#define FALSE 260
#define VARIABLE 261
#define WHILE 262
#define IF 263
#define PRINT 264
#define END 265
#define DO 266
#define THEN 267
#define ELSE 268
#define OR 269
#define AND 270
#define NOT 271
#define OVER 272
#define PLUS 273
#define MINUS 274
#define MULTI 275
#define LESS 276
#define BIGGER 277
#define EQUAL 278
#define ASSIGN 279
#define LESSEQ 280
#define BIGEQ 281
#define LAPREN 282
#define COMMA 283
#define RPAREN 284
#define SEMI 285
#define START 286
#define IFX 287
#define NE 288
#define EQ 289
#define LE 290
#define GE 291
#define UMINUS 292




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 21 "calc.y"
{
    int iValue;                 /* integer value */
    int  bValue;
    char sIndex;                /* symbol table index */
    nodeType *nPtr;             /* node pointer */
}
/* Line 1529 of yacc.c.  */
#line 130 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

