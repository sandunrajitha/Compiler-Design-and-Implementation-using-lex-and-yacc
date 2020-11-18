%{
  #include <stdlib.h>
  #include "calc.h"
  #include "y.tab.h"
  void yyerror(char *);
%}

%%

[a-z,A-Z]     { yylval.sIndex = *yytext - 'a';  return VARIABLE;};
"print"       return PRINT;
"begin"       return START;
"if"          return IF;
"then"        return THEN;
"else"        return ELSE;
"while"       return WHILE;
"do"          return DO;
"and"         return AND;
"or"          return OR;
"true"        {yylval.bValue = 1; return TRUE;};
"false"        {yylval.bValue = 0; return FALSE;};
[1-9][0-9]*   {yylval.iValue = atoi(yytext); return NUMBER;};
"+"           return PLUS;
"-"           return MINUS;
"*"           return MULTI;
"/"           return OVER;
";"           return SEMI;
"<"           return LESS;
">"           return BIGGER;
"="           return EQUAL;
"("           return LAPREN;
")"           return RPAREN;
":="          return ASSIGN;
"<="          return LESSEQ;
">="          return BIGEQ;
[ \t\n]+;
.

%%

int yywrap(void) {
    return 1;
}
