typedef enum { typeCon, typeId, typeOpr, typeBoolean } nodeEnum;

/* constants */
typedef struct {
    int value;                  /* value of constant */
} conNodeType;

typedef struct {
    int boo;                  /* value of constant */
} booNodeType;

/* identifiers */
typedef struct {
    int i;                      /* subscript to sym array */
} idNodeType;

/* operators */
typedef struct {
    int oper;                   /* operator */
    int nops;                   /* number of operands */
    struct nodeTypeTag *op[1];	/* operands, extended at runtime */
} oprNodeType;

typedef struct nodeTypeTag {
    nodeEnum type;              /* type of node */

    union {
        conNodeType con;        /* constants */
        idNodeType id;          /* identifiers */
        oprNodeType opr;        /* operators */
        booNodeType boole;
    };
} nodeType;

extern int sym[26];
