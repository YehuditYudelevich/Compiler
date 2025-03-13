%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"
#include "ast.h"
extern int yylex();
extern int yylineno;     
extern char *yytext;
void yyerror(const char *s);
ASTNode *root;

%}
%union {
    char *str;          // עבור מזהים ומספרים
    struct ASTNode *node; // עבור צמתים ב-AST
}
%token <str> ID NUM
%token RELOP ADDOP MULOP AND OR NOT CAST
%token BREAK CASE DEFAULT ELSE FLOAT IF INPUT INT OUTPUT SWITCH WHILE
%token LPAREN RPAREN LBRACE RBRACE COLON SEMICOLON EQUAL 
%type <str> RELOP ADDOP MULOP AND OR NOT CAST
%type <node> program declarations declaration idlist type stmt_block stmtlist stmt
%type <node> assignment_stmt input_stmt output_stmt if_stmt while_stmt switch_stmt break_stmt
%type <node> caselist boolexpr boolterm boolfactor expression term factor


%%

program : declarations stmt_block { 
    root=createNode(NODE_PROGRAM, "program", $1, $2);
    printf("AST succeess!\n");
    printAST(root,0);
    $$ = root;

}
        ;

declarations : declarations declaration { $$ = appendNode($1, $2); }
             | { $$ = NULL; }
             ;

declaration : idlist COLON type SEMICOLON{
    $$ = createNode(NODE_DECLARATION, $3, $1, NULL);
}
            ;

idlist : idlist ',' ID { $$ = appendNode($1, createNode(NODE_ID, $3, NULL, NULL)); }
       | ID { $$ = createNode(NODE_ID, $1, NULL, NULL); }
       ;

type : INT { $$ = NULL; }
     | FLOAT { $$ = NULL; }
     ;



stmt_block : LBRACE stmtlist RBRACE { $$ = createNode(NODE_STMT_BLOCK, "stmt_block", $2, NULL); }
           ;


stmtlist : stmtlist stmt { $$ = appendNode($1, $2); }
         | { $$ = NULL; }
         ;


stmt : assignment_stmt  { $$ = $1; }
     | input_stmt { $$ = $1; }
     | output_stmt { $$ = $1; }
     | if_stmt { $$ = $1; }
     | while_stmt { $$ = $1; }
     | switch_stmt { $$ = $1; }
     | break_stmt { $$ = $1; }
     | stmt_block { $$ = $1; }
     ;


assignment_stmt : ID EQUAL expression SEMICOLON{
     $$ = createNode(NODE_ASSIGNMENT, $1, createNode(NODE_ID, $1, NULL, NULL), $3);
}
                ;


input_stmt : INPUT LPAREN ID RPAREN SEMICOLON{
    $$ = createNode(NODE_INPUT, $3, NULL, NULL);
}
           ;

output_stmt : OUTPUT LPAREN expression RPAREN SEMICOLON{
    $$ = createNode(NODE_OUTPUT, NULL, $3, NULL);
}
            ;


if_stmt : IF LPAREN boolexpr RPAREN stmt ELSE stmt{
    $$ = createNode(NODE_IF, NULL, $3, createNode(NODE_STMT_BLOCK, "if-else", $5, $7));
}
        ;


while_stmt : WHILE LPAREN boolexpr RPAREN stmt{
    $$ = createNode(NODE_WHILE, NULL, $3, $5);
}
           ;


switch_stmt : SWITCH LPAREN expression RPAREN LBRACE caselist DEFAULT COLON stmtlist RBRACE{
    $$ = createNode(NODE_SWITCH, NULL, $3, appendNode($6, createNode(NODE_CASE, "default", $9, NULL)));
}
            ;


break_stmt : BREAK SEMICOLON{
    $$ = createNode(NODE_BREAK, "break", NULL, NULL); 
}
           ;

caselist : caselist CASE NUM COLON stmtlist { $$ = appendNode($1, createNode(NODE_CASE, $3, $5, NULL)); }
         | { $$ = NULL; }
         ;


boolexpr : boolexpr OR boolterm { $$ = createNode(NODE_EXPR, strdup($2), $1, $3); }
         | boolterm { $$ = $1; }
         ;

boolterm : boolterm AND boolfactor { $$ = createNode(NODE_EXPR, strdup($2), $1, $3); }
         | boolfactor { $$ = $1; }
         ;

boolfactor : NOT LPAREN boolexpr RPAREN { $$ = createNode(NODE_EXPR, strdup($1), $3, NULL); }
           | expression RELOP expression { $$ = createNode(NODE_EXPR, strdup($2), $1, $3); }
           ;

expression : expression ADDOP term { $$ = createNode(NODE_EXPR, strdup($2), $1, $3); }
           | term { $$ = $1; }
           ;

term : term MULOP factor { $$ = createNode(NODE_EXPR, strdup($2), $1, $3); }
     | factor { $$ = $1; }
     ;


factor : LPAREN expression RPAREN { $$ = $2; }
       | CAST LPAREN expression RPAREN { $$ = createNode(NODE_EXPR, "cast", $3, NULL); }
       | ID { $$ = createNode(NODE_ID, $1, NULL, NULL); }
       | NUM  { $$ = createNode(NODE_NUM, $1, NULL, NULL); }
       ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax error at line %d: %s\n", yylineno, s);
    fprintf(stderr, "Last token read: '%s'\n", yytext);
}