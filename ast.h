#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// type of node in the AST
typedef enum { 
    NODE_PROGRAM, NODE_DECLARATION, NODE_STMT_BLOCK, NODE_ASSIGNMENT, 
    NODE_INPUT, NODE_OUTPUT, NODE_IF, NODE_WHILE, NODE_SWITCH, NODE_CASE, 
    NODE_BREAK, NODE_EXPR, NODE_NUM, NODE_ID ,NODE_EMPTY
} NodeType;

// AST node
typedef struct ASTNode {
    NodeType type;
    char *value;
    struct ASTNode *left;
    struct ASTNode *right;
    struct ASTNode *next;  // for lists
} ASTNode;

// functions for AST 
ASTNode *createNode(NodeType type, char *value, ASTNode *left, ASTNode *right);
ASTNode *appendNode(ASTNode *list, ASTNode *newNode);
void printAST(ASTNode *node, int indent);
void freeAST(ASTNode *node);

#endif
