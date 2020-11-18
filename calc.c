#include <stdio.h>
#include "calc.h"
#include "y.tab.h"

int ex(nodeType *p) {
    if (!p) return 0;
    switch(p->type) {
    case typeCon:       return p->con.value;
    case typeBoolean:   return p->boole.boo;
    case typeId:        return sym[p->id.i];
    case typeOpr:
        switch(p->opr.oper) {
        case WHILE:     while(ex(p->opr.op[0])) ex(p->opr.op[1]); return 0;
        case IF:        if (ex(p->opr.op[0]))
                            ex(p->opr.op[1]);
                        else if (p->opr.nops > 2)
                            ex(p->opr.op[2]);
                        return 0;
        case PRINT:     printf("%d\n", ex(p->opr.op[0])); return 0;
        case SEMI:      ex(p->opr.op[0]); return ex(p->opr.op[1]);
        case ASSIGN:    return sym[p->opr.op[0]->id.i] = ex(p->opr.op[1]);
        case PLUS:      return ex(p->opr.op[0]) + ex(p->opr.op[1]);
        case MINUS:     return ex(p->opr.op[0]) - ex(p->opr.op[1]);
        case MULTI:     return ex(p->opr.op[0]) * ex(p->opr.op[1]);
        case OVER:      return ex(p->opr.op[0]) / ex(p->opr.op[1]);
        case LESS:      return ex(p->opr.op[0]) < ex(p->opr.op[1]);
        case BIGGER:    return ex(p->opr.op[0]) > ex(p->opr.op[1]);
        case BIGEQ:     return ex(p->opr.op[0]) >= ex(p->opr.op[1]);
        case LESSEQ:    return ex(p->opr.op[0]) <= ex(p->opr.op[1]);
        /*case NE:        return ex(p->opr.op[0]) != ex(p->opr.op[1]);*/
        case EQUAL:        return ex(p->opr.op[0]) == ex(p->opr.op[1]);
        }
    }
    return 0;
}
