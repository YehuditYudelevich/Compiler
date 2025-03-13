#include "ast.h"

// create a new node in the AST
ASTNode *createNode(NodeType type, char *value, ASTNode *left, ASTNode *right) {
    printf("start createNode\n");
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    node->type = type;
    node->value = value ? strdup(value) : NULL;
    node->left = left;
    node->right = right;
    node->next = NULL;
    return node;
}

// append a new node to the end of a list
ASTNode *appendNode(ASTNode *list, ASTNode *newNode) {
    if (!list) return newNode;
    ASTNode *temp = list;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return list;
}

// print the AST (for debugging)
void printAST(ASTNode *node, int indent) {
    if (!node) return;
    for (int i = 0; i < indent; i++) printf("  ");
    printf("%d: %s\n", node->type, node->value ? node->value : "NULL");
    printAST(node->left, indent + 1);
    printAST(node->right, indent + 1);
    printAST(node->next, indent);
}

// free the AST
void freeAST(ASTNode *node) {
    if (!node) return;
    freeAST(node->left);
    freeAST(node->right);
    freeAST(node->next);
    if (node->value) free(node->value);
    free(node);
}
