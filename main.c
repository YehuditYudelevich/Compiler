#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"
#include "quad.h"
#include "codegen.h"      


extern FILE *yyin;
extern int yyparse();
extern void yyrestart(FILE *input_file);
extern ASTNode *root;     

extern QuadList* quad_list;


int main(int argc, char *argv[]) {
    printf("Starting...\n");

    if (argc != 2) {
        printf("To use, write in the console: %s <file_name>\n", argv[0]);
        return 1;
    }

    // בדיקת שם הקובץ
    int len = strlen(argv[1]);
    if (len < 3 || strcmp(argv[1] + len - 3, ".ou") != 0) {
        printf("Error: file must have a .ou extension\n");
        return 1;
    }

    // פתיחת קובץ
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: can't open the file\n");
        return 1;
    }

    yyin = file;
    yyrestart(yyin);

    printf("Parsing...\n");
    if (yyparse() == 0) {
        printf("Parsing successful!\n");

        // יצירת רשימת Quad
        quad_list = create_quad_list();
        printf("we created quad_list\n");
        

        printf("root->type: %d\n", root->type);
        if(root->left != NULL){
            printf("the value of root->left is: %s\n", root->left->value);
        }
        if(root->right != NULL){
            printf("the value of root->right is: %s\n", root->right->value);
        }
        while(root->next != NULL){

            printf("root->type: %d\n", root->type);
            root = root->next;
        }
        // יצירת קוד ביניים מה־AST
        generate_from_ast(root);
        printf("we generated from ast\n");
        print_quad_list(quad_list, stdout);

        // שמירת קובץ Quad
        char output_name[256];
        strncpy(output_name, argv[1], len - 3);
        output_name[len - 3] = '\0';
        strcat(output_name, ".qud");

        FILE *out = fopen(output_name, "w");
        if (out) {
            print_quad_list(quad_list, out);
            fclose(out);
            printf("Quad code saved to: %s\n", output_name);
        } else {
            printf("Error: couldn't write to .qud file\n");
        }

        
        free_quad_list(quad_list);
        
    }

    fclose(file);
    return 0;
}
