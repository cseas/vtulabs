%{
    #include "y.tab.h"
    extern int yylval;
%}

%%
[0-9]+ {yylval = atoi(yytext); return num;}
[\t] ;
[\n] {return 0;}
. {return yytext[0];}
%%

// no main function

int yywrap() {
    return 1;
}
