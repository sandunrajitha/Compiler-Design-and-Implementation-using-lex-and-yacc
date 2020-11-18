#include <stdio.h>
#include "calc.h"
#include "y.tab.h"

static int lbl;

int ex(nodeType *p) {
    int lbl1, lbl2;

    if (!p) return 0;
    switch(p->type) {
    case typeCon:       
        printf("%d", p->con.value); 
        break;

    case typeBoolean:
        printf("%c", p->boole.boo);
        break;

    case typeId:       
        printf("%c", p->id.i + 'a'); 
        break;

    case typeOpr:
        switch(p->opr.oper) {


        case WHILE:     printf("while ("); ex(p->opr.op[0]); 
                        printf(") {"); ex(p->opr.op[1]);
                        printf("}");
                        break;

        case IF:        printf("if ("); ex(p->opr.op[0]);
                        printf(") {"); ex(p->opr.op[1]);
                        printf(" }");
                        if (p->opr.nops > 2)
                            printf(" else { "); ex(p->opr.op[2]);
                            printf(" }");
                        break;

        case PRINT:     printf("console.log( ");
                        ex(p->opr.op[0]);
                        printf(" )");
                        break;

        case SEMI:      ex(p->opr.op[0]);
                        printf(" ; ");
                        ex(p->opr.op[1]);
                        break;

        case ASSIGN:    printf("var ");
                        printf("%c = ", p->opr.op[0]->id.i + 'a');
                        ex(p->opr.op[1]);
                        break;

        case PLUS:      ex(p->opr.op[0]);
                        printf(" + ");
                        ex(p->opr.op[1]);
                        break;

        case MINUS:     ex(p->opr.op[0]);
                        printf(" - ");
                        ex(p->opr.op[1]);
                        break;

        case MULTI:     ex(p->opr.op[0]);
                        printf(" * ");
                        ex(p->opr.op[1]);
                        break;

        case OVER:      ex(p->opr.op[0]);
                        printf(" / ");
                        ex(p->opr.op[1]);
                        break;

        case LESS:      ex(p->opr.op[0]);
                        printf(" < ");
                        ex(p->opr.op[1]);
                        break;

        case BIGGER:    ex(p->opr.op[0]);
                        printf(" > ");
                        ex(p->opr.op[1]);
                        break;

        case BIGEQ:     ex(p->opr.op[0]);
                        printf(" >= ");
                        ex(p->opr.op[1]);
                        break;

        case LESSEQ:    ex(p->opr.op[0]);
                        printf(" <= ");
                        ex(p->opr.op[1]);
                        break;

        /*case NE:        return ex(p->opr.op[0]) != ex(p->opr.op[1]);*/
        case EQUAL:     ex(p->opr.op[0]);
                        printf(" === ");
                        ex(p->opr.op[1]);
                        break;
        }
    }
    return 0;
}
