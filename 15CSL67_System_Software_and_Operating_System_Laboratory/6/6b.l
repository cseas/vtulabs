%{
    #include <stdio.h>
    #include "y.tab.h"
    extern yylval;
%}

%%
[#][<a-z.>]+ ;
[ \t] ;
[+|-|*|/|=|<|>] {printf("Operator is %s\n", yytext); return OP;}
[0-9]+ {yylval = atoi(yytext); printf("Number is %d\n", yylval); 
    return DIGIT;}
int|char|bool|float|void|for|do|while|if|else|return {
    printf("Keyword is %s\n",yytext); return KEY;}
[a-zA-Z0-9]+ {printf("Identifier is %s\n", yytext); return ID;}
. ;
%%

int yywrap() {
    return 1;
}
