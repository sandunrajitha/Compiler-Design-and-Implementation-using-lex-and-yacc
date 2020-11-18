%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "calc.h"

/* prototypes */
nodeType *opr(int oper, int nops, ...);
nodeType *id(int i);
nodeType *con(int value);
nodeType *boole(int value);
void freeNode(nodeType *p);
int ex(nodeType *p);
int yylex(void);

void yyerror(char *s);
int sym[26];                  

%}

%union {
    int iValue;                 /* integer value */
    int  bValue;
    char sIndex;                /* symbol table index */
    nodeType *nPtr;             /* node pointer */
};

%token <iValue> NUMBER
%token <bValue> TRUE FALSE
%token <sIndex> VARIABLE
%token WHILE IF PRINT END DO THEN ELSE OR AND NOT OVER PLUS MINUS MULTI LESS BIGGER EQUAL ASSIGN LESSEQ BIGEQ LAPREN COMMA RPAREN SEMI START
%nonassoc IFX
%nonassoc ELSE

%left GE LE EQ NE LESS BIGGER
%left PLUS MINUS
%left MULTI OVER
%nonassoc UMINUS

%type <nPtr> expitem boolreln stmnt explist


%%

prgmbody      : 
                stmntlist                           { exit(0); }
              ;

stmntlist     : 
                stmntlist stmnt                     { ex($2); freeNode($2); }
              | /* NULL */
              ;

stmnt         : 
                PRINT expitem SEMI                  { $$ = opr(PRINT, 1, $2,SEMI); }
              | START explist END                   { $$ = $2; }
              | WHILE expitem DO stmnt              { $$ = opr(WHILE, 2, $2, $4); }
              | IF expitem THEN stmnt               { $$ = opr(IF, 2, $2, $4); }
              | IF expitem THEN stmnt ELSE stmnt    { $$ = opr(IF, 3, $2, $4, $6); }
              | VARIABLE ASSIGN expitem SEMI        { $$ = opr(ASSIGN, 2, id($1), $3); }
              ;

explist       :       
                expitem                             { $$ = $1; }
              | explist SEMI expitem               { $$ = opr(SEMI, 2, $1, $3); }
              ;

expitem :       
                NUMBER                              { $$ = con($1); }
              | expitem PLUS expitem                { $$ = opr(PLUS, 2, $1, $3); }
              | expitem MINUS expitem               { $$ = opr(MINUS, 2, $1, $3); }
              | expitem MULTI expitem               { $$ = opr(MULTI, 2, $1, $3); }
              | expitem OVER expitem                { $$ = opr(OVER, 2, $1, $3); }
              | FALSE                               { $$ = boole($1); }
              | TRUE                                { $$ = boole($1); }
              | VARIABLE                            { $$ = id($1); }
              | boolreln
              | LAPREN expitem RPAREN               { $$ = $2; }
              | expitem OR expitem
              | expitem AND expitem
              | NOT expitem
              ;

boolreln :      
                expitem LESS expitem                { $$ = opr(LESS, 2, $1, $3); }
              | expitem LESSEQ expitem              { $$ = opr(LESSEQ, 2, $1, $3); }
              | expitem EQUAL expitem               { $$ = opr(EQUAL, 2, $1, $3); }
              | expitem BIGEQ expitem               { $$ = opr(BIGEQ, 2, $1, $3); }
              | expitem BIGGER expitem              { $$ = opr(BIGGER, 2, $1, $3); }
              ;

%%

nodeType *con(int value) {
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeCon;
    p->con.value = value;

    return p;
}

nodeType *boole(int boo) {
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeBoolean;
    p->boole.boo = boo;

    return p;
}

nodeType *id(int i) {
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeId;
    p->id.i = i;

    return p;
}

nodeType *opr(int oper, int nops, ...) {
    va_list ap;
    nodeType *p;
    int i;

    /* allocate node, extending op array */
    if ((p = malloc(sizeof(nodeType) + (nops-1) * sizeof(nodeType *))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    return p;
}

void freeNode(nodeType *p) {
    int i;

    if (!p) return;
    if (p->type == typeOpr) {
        for (i = 0; i < p->opr.nops; i++)
            freeNode(p->opr.op[i]);
    }
    free (p);
}

void yyerror(char *s) {
    fprintf(stdout, "%s\n", s);
}

int main(void) {
    yyparse();
    return 0;
}
