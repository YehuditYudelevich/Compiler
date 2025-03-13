%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
#include "ast.h"
extern int yylex();
extern int yylineno;     
extern char *yytext;
void yyerror(const char *s);
ASTNode *root;

// פונקציה שמונעת קריסת strdup אם NULL
char* strdup_safe(const char *s) {
    return s ? strdup(s) : strdup("UNKNOWN");
}
%}

%union {
    char *str;         
    struct ASTNode *node; 
}

%token <str> ID NUM
%token <str> RELOP ADDOP MULOP AND OR NOT CAST
%token BREAK CASE DEFAULT ELSE FLOAT IF INPUT INT OUTPUT SWITCH WHILE
%token LPAREN RPAREN LBRACE RBRACE COLON SEMICOLON EQUAL 

%type <node> program declarations declaration idlist stmt_block stmtlist stmt
%type <node> assignment_stmt input_stmt output_stmt if_stmt while_stmt switch_stmt break_stmt
%type <node> caselist boolexpr boolterm boolfactor expression term factor
%type <str> type

%%

program : declarations stmt_block { 
    printf("[DEBUG] Creating program node\n");
    root = createNode(NODE_PROGRAM, "program", $1, $2);
    printf("\U0001F44C AST נבנה בהצלחה!\n");
    printAST(root, 0);
    $$ = root;
};

declarations : declarations declaration { $$ = appendNode($1, $2); }
             | { $$ = NULL; };

declaration : idlist COLON type SEMICOLON {
    printf("[DEBUG] Creating declaration node (%s)\n", $3);
    $$ = createNode(NODE_DECLARATION, strdup_safe($3), $1, NULL);
};

idlist : idlist ',' ID { 
    printf("[DEBUG] Appending ID: %s\n", $3);
    $$ = appendNode($1, createNode(NODE_ID, strdup_safe($3), NULL, NULL)); 
}
       | ID { 
    printf("[DEBUG] Creating ID node: %s\n", $1);
    $$ = createNode(NODE_ID, strdup_safe($1), NULL, NULL); 
};

type : INT { $$ = strdup("int"); }
     | FLOAT { $$ = strdup("float"); };

stmt_block : LBRACE stmtlist RBRACE { $$ = createNode(NODE_STMT_BLOCK, "stmt_block", $2, NULL); };

stmtlist : stmtlist stmt { $$ = appendNode($1, $2); }
         | { $$ = NULL; };

stmt : assignment_stmt { $$ = $1; }
     | input_stmt { $$ = $1; }
     | output_stmt { $$ = $1; }
     | if_stmt { $$ = $1; }
     | while_stmt { $$ = $1; }
     | switch_stmt { $$ = $1; }
     | break_stmt { $$ = $1; }
     | stmt_block { $$ = $1; };

assignment_stmt : ID EQUAL expression SEMICOLON {
     printf("[DEBUG] Creating assignment: %s = ...\n", $1);
     $$ = createNode(NODE_ASSIGNMENT, strdup_safe($1), createNode(NODE_ID, strdup_safe($1), NULL, NULL), $3);
};

input_stmt : INPUT LPAREN ID RPAREN SEMICOLON {
    printf("[DEBUG] Creating input statement for: %s\n", $3);
    $$ = createNode(NODE_INPUT, strdup_safe($3), NULL, NULL);
};

output_stmt : OUTPUT LPAREN expression RPAREN SEMICOLON {
    printf("[DEBUG] Creating output statement\n");
    $$ = createNode(NODE_OUTPUT, NULL, $3, NULL);
};

if_stmt : IF LPAREN boolexpr RPAREN stmt ELSE stmt {
    printf("[DEBUG] Creating if-else statement\n");
    $$ = createNode(NODE_IF, "if-else", $3, 
                    createNode(NODE_STMT_BLOCK, "if-body", $5 ? $5 : createNode(NODE_EMPTY, "EMPTY_BLOCK", NULL, NULL),
                                                        $7 ? $7 : createNode(NODE_EMPTY, "EMPTY_BLOCK", NULL, NULL)));
};

while_stmt : WHILE LPAREN boolexpr RPAREN stmt {
    printf("[DEBUG] Creating while loop\n");
    $$ = createNode(NODE_WHILE, "while-loop", $3, 
                    $5 ? $5 : createNode(NODE_EMPTY, "EMPTY_BLOCK", NULL, NULL));
};

switch_stmt : SWITCH LPAREN expression RPAREN LBRACE caselist DEFAULT COLON stmtlist RBRACE {
    printf("[DEBUG] Creating switch statement\n");
    $$ = createNode(NODE_SWITCH, "switch", $3, 
                    appendNode($6, createNode(NODE_CASE, "default", $9 ? $9 : createNode(NODE_EMPTY, "EMPTY_BLOCK", NULL, NULL), NULL)));
};

break_stmt : BREAK SEMICOLON {
    printf("[DEBUG] Creating break statement\n");
    $$ = createNode(NODE_BREAK, "break", NULL, NULL); 
};

caselist : caselist CASE NUM COLON stmtlist { 
    printf("[DEBUG] Creating case: %s\n", $3);
    $$ = appendNode($1, createNode(NODE_CASE, strdup_safe($3), $5 ? $5 : createNode(NODE_EMPTY, "EMPTY_BLOCK", NULL, NULL), NULL)); 
}
         | { $$ = NULL; };

boolexpr : boolexpr OR boolterm { $$ = createNode(NODE_EXPR, strdup_safe($2), $1, $3); }
         | boolterm { $$ = $1; };

boolterm : boolterm AND boolfactor { $$ = createNode(NODE_EXPR, strdup_safe($2), $1, $3); }
         | boolfactor { $$ = $1; };

boolfactor : NOT LPAREN boolexpr RPAREN { $$ = createNode(NODE_EXPR, strdup_safe($1), $3, NULL); }
           | expression RELOP expression { $$ = createNode(NODE_EXPR, strdup_safe($2), $1, $3); };

expression : expression ADDOP term { $$ = createNode(NODE_EXPR, strdup_safe($2), $1, $3); }
           | term { $$ = $1; };

term : term MULOP factor { $$ = createNode(NODE_EXPR, strdup_safe($2), $1, $3); }
     | factor { $$ = $1; };

factor : LPAREN expression RPAREN { $$ = $2; }
       | CAST LPAREN expression RPAREN { $$ = createNode(NODE_EXPR, "cast", $3, NULL); }
       | ID { $$ = createNode(NODE_ID, strdup_safe($1), NULL, NULL); }
       | NUM { $$ = createNode(NODE_NUM, strdup_safe($1), NULL, NULL); };

%%

void yyerror(const char *s) {
    fprintf(stderr, "\U0001F6A8 Syntax error at line %d: %s\n", yylineno, s);
    fprintf(stderr, "Last token read: '%s'\n", yytext);
}
