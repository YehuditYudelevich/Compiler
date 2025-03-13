#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern FILE *yyin;
extern int yyparse();
extern void yyrestart(FILE *input_file);

int main(int argc, char *argv[]) {
    printf("Starting...\n");
    if (argc != 2) {
        printf("To use, write in the console: %s <file_name>\n", argv[0]);
        return 1;
    }
   
    
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: cant open the file\n");
        return 1;
    }
    int len=strlen(argv[1]);
    if(len<3){
        printf("Error: the file name is not valid\n");
        return 1;
    }
    if(strcmp(argv[1] + len - 3, ".ou") != 0){
        printf("Error: the file name is not valid does NOT have a .ou extension\n");
        return 1;
    }  
    yyin = file;
    yyrestart(yyin);
    printf("Parsing...\n");
    if(yyparse() == 0){
        printf("Parsing successful!\n");
        fclose(file);
        return 0;
    }
    fclose(file);
    return 0;
        
    
    
}