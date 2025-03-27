#include <stdio.h>  
#include <stdlib.h>
#ifndef QUAD_H
#define QUAD_H

typedef enum {
    IASN, IADD, ISUB, IMLT, IDIV,
    IINP, IPRT,
    IEQL, INQL, ILSS, IGRT,

    RASN, RADD, RSUB, RMLT, RDIV,
    RINP, RPRT,
    REQL, RNQL, RLSS, RGRT,

    ITOR, RTOI,
    JUMP, JMPZ,
    LABEL, HALT
} Opcode;

typedef struct Quad {
    Opcode opcode;
    char *arg1;
    char *arg2;
    char *arg3;
    struct Quad *next;
} Quad;

typedef struct {
    Quad *head;
    Quad *tail;
    int size;
} QuadList;

QuadList* create_quad_list();
void add_quad(QuadList* list, Quad* quad);
Quad* create_quad(Opcode opcode, char* arg1, char* arg2, char* arg3);
void print_quad_list(QuadList* list, FILE* out);
void free_quad_list(QuadList* list);

#endif

