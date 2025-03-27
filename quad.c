#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quad.h"
#include "ast.h"


QuadList* quad_list= NULL;

// יצירת רשימת Quad ריקה
QuadList* create_quad_list() {
    printf("now we are in create_quad_list\n");
    QuadList* list = (QuadList*)malloc(sizeof(QuadList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// יצירת Quad בודד
Quad* create_quad(Opcode opcode, char* arg1, char* arg2, char* arg3) {
    printf("now we are in create_quad\n");
    Quad* quad = (Quad*)malloc(sizeof(Quad));
    quad->opcode = opcode;
    quad->arg1 = arg1 ? strdup(arg1) : NULL;
    quad->arg2 = arg2 ? strdup(arg2) : NULL;
    quad->arg3 = arg3 ? strdup(arg3) : NULL;
    quad->next = NULL;
    return quad;
}

// הוספת Quad לרשימה
void add_quad(QuadList* list, Quad* quad) {
    printf("now we are in add_quad\n");
   
    if (!list->head) {
        list->head = list->tail = quad;
    } else {
        list->tail->next = quad;
        list->tail = quad;
    }
    list->size++;
}

// הדפסת הקוד הביניים
void print_quad_list(QuadList* list, FILE* out) {
    printf("now we are in print_quad_list\n");
    Quad* curr = list->head;
    int i = 1;
    while (curr) {
        fprintf(out, "%d ", i++);
        switch (curr->opcode) {
            case IASN: fprintf(out, "IASN %s %s\n", curr->arg1, curr->arg2); break;
            case IADD: fprintf(out, "IADD %s %s %s\n", curr->arg1, curr->arg2, curr->arg3); break;
            case ISUB: fprintf(out, "ISUB %s %s %s\n", curr->arg1, curr->arg2, curr->arg3); break;
            case IMLT: fprintf(out, "IMLT %s %s %s\n", curr->arg1, curr->arg2, curr->arg3); break;
            case IDIV: fprintf(out, "IDIV %s %s %s\n", curr->arg1, curr->arg2, curr->arg3); break;
            case IINP: fprintf(out, "IINP %s\n", curr->arg1); break;
            case IPRT: fprintf(out, "IPRT %s\n", curr->arg1); break;
            case IEQL: fprintf(out, "IEQL %s %s %s\n", curr->arg1, curr->arg2, curr->arg3); break;
            case INQL: fprintf(out, "INQL %s %s %s\n", curr->arg1, curr->arg2, curr->arg3); break;
            case ILSS: fprintf(out, "ILSS %s %s %s\n", curr->arg1, curr->arg2, curr->arg3); break;
            case IGRT: fprintf(out, "IGRT %s %s %s\n", curr->arg1, curr->arg2, curr->arg3); break;
            case RASN: fprintf(out, "RASN %s %s\n", curr->arg1, curr->arg2); break;
            case RADD: fprintf(out, "RADD %s %s %s\n", curr->arg1, curr->arg2, curr->arg3); break;
            case RSUB: fprintf(out, "RSUB %s %s %s\n", curr->arg1, curr->arg2, curr->arg3); break;
            case RMLT: fprintf(out, "RMLT %s %s %s\n", curr->arg1, curr->arg2, curr->arg3); break;
            case RDIV: fprintf(out, "RDIV %s %s %s\n", curr->arg1, curr->arg2, curr->arg3); break;
            case RINP: fprintf(out, "RINP %s\n", curr->arg1); break;
            case RPRT: fprintf(out, "RPRT %s\n", curr->arg1); break;
            case REQL: fprintf(out, "REQL %s %s %s\n", curr->arg1, curr->arg2, curr->arg3); break;
            case RNQL: fprintf(out, "RNQL %s %s %s\n", curr->arg1, curr->arg2, curr->arg3); break;
            case RLSS: fprintf(out, "RLSS %s %s %s\n", curr->arg1, curr->arg2, curr->arg3); break;
            case RGRT: fprintf(out, "RGRT %s %s %s\n", curr->arg1, curr->arg2, curr->arg3); break;
            case ITOR: fprintf(out, "ITOR %s %s\n", curr->arg1, curr->arg2); break;
            case RTOI: fprintf(out, "RTOI %s %s\n", curr->arg1, curr->arg2); break;
            case JUMP: fprintf(out, "JUMP %s\n", curr->arg1); break;
            case JMPZ: fprintf(out, "JMPZ %s %s\n", curr->arg1, curr->arg2); break;
            case LABEL: fprintf(out, "%s:\n", curr->arg1); break;
            case HALT: fprintf(out, "HALT\n"); break;
        }
        curr = curr->next;
    }
}

// שחרור זיכרון של רשימת Quad
void free_quad_list(QuadList* list) {
    Quad* curr = list->head;
    while (curr) {
        Quad* next = curr->next;
        free(curr->arg1);
        free(curr->arg2);
        free(curr->arg3);
        free(curr);
        curr = next;
    }
    free(list);
}

