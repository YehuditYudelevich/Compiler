%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"

int num_line = 1;  
%}

%option noyywrap

%x COMMENT  

%%

[0-9]+ { 
    printf("LEXER: Token NUM (%s)\n", yytext);
    yylval.str = strdup(yytext);
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
    yylval.str = strdup(yytext);
    return ID;
}

","  { printf("LEXER: Token COMMA\n"); return ','; }
":"  { printf("LEXER: Token COLON\n"); return COLON; }
";"  { printf("LEXER: Token SEMICOLON\n"); return SEMICOLON; }
"("  { printf("LEXER: Token LPAREN\n"); return LPAREN; }
")"  { printf("LEXER: Token RPAREN\n"); return RPAREN; }
"{"  { printf("LEXER: Token LBRACE\n"); return LBRACE; }
"}"  { printf("LEXER: Token RBRACE\n"); return RBRACE; }
"="  { printf("LEXER: Token EQUAL\n"); return EQUAL; }

"!"  { printf("LEXER: Token NOT\n"); return NOT; }
"&&" { printf("LEXER: Token AND\n"); return AND; }
"||" { printf("LEXER: Token OR\n"); return OR; }

"cast<int>"|"cast<float>" { 
    printf("LEXER: Token CAST (%s)\n", yytext);
    yylval.str = strdup(yytext);
    return CAST; 
}

"=="|"!="|"<"|">"|"<="|">=" { 
    printf("LEXER: Token RELOP (%s)\n", yytext);
    yylval.str = strdup(yytext);
    return RELOP; 
}

"+"|"-" { 
    printf("LEXER: Token ADDOP (%s)\n", yytext);
    yylval.str = strdup(yytext);
    return ADDOP; 
}

"*"|"/" { 
    printf("LEXER: Token MULOP (%s)\n", yytext);
    yylval.str = strdup(yytext);
    return MULOP; 
}


"/*" { BEGIN(COMMENT); }

<COMMENT>[^*\n]* {  }
<COMMENT>"*"+[^*/] {  }
<COMMENT>"*"+"/" { BEGIN(INITIAL); }  
<COMMENT>\n { num_line++; }  

[ \t]+    {  }
[\n]+     { num_line += yyleng; }

. { 
    fprintf(stderr, "LEXER ERROR: תו לא חוקי '%c' בשורה %d\n", yytext[0], num_line);
    return -1;
}

%%


