%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"



int num_line = 1;


int op_attribute = 0; 


int count_newlines(char *s) {
    int count = 0;
    while (*s) if (*s++ == '\n') count++;
    return count;
}
%}

%%


[0-9]+ { 
    printf("LEXER: Token NUM (%s)\n", yytext);  
    return NUM; 
}

"break"    { printf("LEXER: Token BREAK\n"); return BREAK; }
"case"     { printf("LEXER: Token CASE\n"); return CASE; }
"default"  { printf("LEXER: Token DEFAULT\n"); return DEFAULT; }
"else"     { printf("LEXER: Token ELSE\n"); return ELSE; }
"float"    { printf("LEXER: Token FLOAT\n"); return FLOAT; }
"if"       { printf("LEXER: Token IF\n"); return IF; }
"input"    { printf("LEXER: Token INPUT\n"); return INPUT; }
"int"      { printf("LEXER: Token INT\n"); return INT; }
"output"   { printf("LEXER: Token OUTPUT\n"); return OUTPUT; }
"switch"   { printf("LEXER: Token SWITCH\n"); return SWITCH; }
"while"    { printf("LEXER: Token WHILE\n"); return WHILE; }


[a-zA-Z_][a-zA-Z0-9_]* {
    printf("LEXER: Token ID (%s)\n", yytext);
    return ID;
}

","  { printf("LEXER: Token COMMA\n"); return ','; }
":"  { printf("LEXER: Token COLON\n"); return COLON; }
";"  { printf("LEXER: Token SEMICOLON\n"); return SEMICOLON; }


"!"  { return NOT; }
"&&" { return AND; }
"||" { return OR; }
"cast<int>"|"cast<float>" { return CAST; }
"=="|"!="|"<"|">"|"<="|">=" { op_attribute = yytext[0]; return RELOP; }
"(" { return LPAREN; }
")" { return RPAREN; }
"{" { return LBRACE; }
"}" { return RBRACE; }
":" { return COLON; }
";" { return SEMICOLON; }
"=" { return EQUAL; }
"+"|"-" { op_attribute = yytext[0]; return ADDOP; }
"*"|"/" { op_attribute = yytext[0]; return MULOP; }


[ \t]+            { /* התעלמות מרווחים */ }
[\n]+             { num_line += yyleng; }
"/*"([^*]|\*+[^*/])*\*+"/" { num_line += count_newlines(yytext); }


. { printf("there is an un valid char %c in line %d", yytext[0], num_line);
    return -1; }

%%
int yywrap() { return 0; }