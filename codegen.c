#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "quad.h"
#include "codegen.h"

extern QuadList* quad_list;

static int temp_count = 0;
static int label_count = 0;

char* new_temp() {
    char* name = malloc(16);
    sprintf(name, "t%d", temp_count++);
    return name;
}

char* new_label() {
    char* name = malloc(16);
    sprintf(name, "L%d", label_count++);
    return name;
}

int is_int_type(char* var) {
    return (strchr(var, '.') == NULL); 
}

char* generate_expression(ASTNode* node);
void generate_statement(ASTNode* node);
void generate_from_ast(ASTNode* root) {
    if (!root) return;

    printf("Generating from AST...\n");

    
    if (root->left) {
        printf("Processing left node: %s\n", root->left->value);
        generate_from_ast(root->left); 
    }
    printf("Generating statement of type: %d\n", root->type);
    generate_statement(root);  
    if (root->right) {
        printf("Processing right node: %s\n", root->right->value);
        generate_from_ast(root->right);  
    }
    if (root->next) {
        printf("Processing next node: %s\n", root->next->value);
        generate_from_ast(root->next);  
    }


}



void generate_statement(ASTNode* node) {
    if (!node) return;

    switch (node->type) {
        case NODE_STMT_BLOCK:
            generate_statement(node->left);  // חלק ראשון של ה־stmt_block
            generate_statement(node->right); // חלק שני של ה־stmt_block
            break;

        // חזור על כל המקרים האחרים
        case NODE_ASSIGNMENT: {
            char* rhs = generate_expression(node->right);
            Opcode opc = RASN; // ברירת מחדל ל־float
            add_quad(quad_list, create_quad(opc, node->left->value, rhs, NULL));
            free(rhs);
            break;
        }

        // טיפוסי פקודות נוספות כמו INPUT, OUTPUT וכו'
        case NODE_INPUT: {
            add_quad(quad_list, create_quad(RINP, node->value, NULL, NULL));
            break;
        }

        case NODE_OUTPUT: {
            char* val = generate_expression(node->left);
            add_quad(quad_list, create_quad(RPRT, val, NULL, NULL));
            free(val);
            break;
        }

        case NODE_IF: {
            char* false_label = new_label();
            char* end_label = new_label();
            char* cond = generate_expression(node->left);
            add_quad(quad_list, create_quad(JMPZ, false_label, cond, NULL));
            generate_statement(node->right->left); // אם
            add_quad(quad_list, create_quad(JUMP, end_label, NULL, NULL));
            add_quad(quad_list, create_quad(LABEL, false_label, NULL, NULL));
            generate_statement(node->right->right); // else
            add_quad(quad_list, create_quad(LABEL, end_label, NULL, NULL));
            free(cond); free(false_label); free(end_label);
            break;
        }

        case NODE_WHILE: {
            char* start_label = new_label();
            char* end_label = new_label();
            add_quad(quad_list, create_quad(LABEL, start_label, NULL, NULL));
            char* cond = generate_expression(node->left);
            add_quad(quad_list, create_quad(JMPZ, end_label, cond, NULL));
            generate_statement(node->right);
            add_quad(quad_list, create_quad(JUMP, start_label, NULL, NULL));
            add_quad(quad_list, create_quad(LABEL, end_label, NULL, NULL));
            free(start_label); free(end_label); free(cond);
            break;
        }

        default:
            break;
    }
}

char* generate_comparison_label(ASTNode* node) {
    if (strcmp(node->value, "<") == 0) {
        return strdup("less");
    } else if (strcmp(node->value, ">") == 0) {
        return strdup("greater");
    } else if (strcmp(node->value, "==") == 0) {
        return strdup("equal");
    } else if (strcmp(node->value, "<=") == 0) {
        return strdup("lessequal");
    } else if (strcmp(node->value, ">=") == 0) {
        return strdup("greaterequal");
    } else if (strcmp(node->value, "!=") == 0) {
        return strdup("notequal");
    }
    return NULL;  // ברירת מחדל
}


char* generate_expression(ASTNode* node) {
    if (!node) return NULL;

    switch (node->type) {
        case NODE_ID:
        case NODE_NUM:
            return strdup(node->value);

        case NODE_EXPR: {
            char* left = generate_expression(node->left);
            char* right = node->right ? generate_expression(node->right) : NULL;
            char* temp = new_temp();  // עדיין נשתמש ב-temp לשמירה על תוצאה ביניים

            Opcode opc = 0;
            // יצירת Quad עם התווית המתאימה
            if (strcmp(node->value, "+") == 0)
                opc = RADD;
            else if (strcmp(node->value, "-") == 0)
                opc = RSUB;
            else if (strcmp(node->value, "*") == 0)
                opc = RMLT;
            else if (strcmp(node->value, "/") == 0)
                opc = RDIV;
            else if (strcmp(node->value, "==") == 0)
                opc = REQL;
            else if (strcmp(node->value, "!=") == 0)
                opc = RNQL;
            else if (strcmp(node->value, "<") == 0)
                opc = RLSS;
            else if (strcmp(node->value, ">") == 0)
                opc = RGRT;

            // כאשר יש השוואה, נוסיף Quad עם התווית המיוחדת
            if (opc == RLSS || opc == RGRT || opc == REQL || opc == RNQL) {
                char* label = generate_comparison_label(node);  // יצירת התווית המתאימה להשוואה
                add_quad(quad_list, create_quad(opc, label, left, right));
                
                
                free(label);
                
            } else {
                add_quad(quad_list, create_quad(opc, temp, left, right));
            }

            free(left);
            if (right) free(right);
            return temp;
        }

        default:
            return NULL;
    }
}
