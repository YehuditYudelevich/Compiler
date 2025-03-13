#include "ast.h"

// יצירת צומת חדש בעץ
ASTNode *createNode(NodeType type, char *value, ASTNode *left, ASTNode *right) {
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    node->type = type;
    node->value = value ? strdup(value) : NULL;
    node->left = left;
    node->right = right;
    node->next = NULL;
    return node;
}

// הוספת צומת לרשימה (משמש לרשימות של פקודות)
ASTNode *appendNode(ASTNode *list, ASTNode *newNode) {
    if (!list) return newNode;
    ASTNode *temp = list;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return list;
}

// הדפסת עץ (לניפוי שגיאות ובדיקה)
void printAST(ASTNode *node, int indent) {
    if (!node) return;
    for (int i = 0; i < indent; i++) printf("  ");
    printf("%d: %s\n", node->type, node->value ? node->value : "NULL");
    printAST(node->left, indent + 1);
    printAST(node->right, indent + 1);
    printAST(node->next, indent);
}

// שחרור זיכרון של העץ
void freeAST(ASTNode *node) {
    if (!node) return;
    freeAST(node->left);
    freeAST(node->right);
    freeAST(node->next);
    if (node->value) free(node->value);
    free(node);
}
