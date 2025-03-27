#ifndef CODEGEN_H
#define CODEGEN_H

#include "ast.h"

// מייצר קוד Quad מתוך עץ AST שלם (משתמש ב־quad_list)
void generate_from_ast(ASTNode* root);

// מייצר קוד Quad מתוך פקודה (statement)
void generate_statement(ASTNode* node);

// מייצר קוד Quad מתוך ביטוי ומחזיר את המשתנה הזמני שבו מאוחסן התוצאה
char* generate_expression(ASTNode* node);

// יוצר משתנה זמני חדש לשמירת ערכים
char* new_temp();

char* generate_comparison_label(ASTNode* node);

// יוצר תווית (label) חדשה עבור פקודות קפיצה
char* new_label();

#endif // CODEGEN_H

