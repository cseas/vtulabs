%{
    #include<stdio.h>
    int id=0, op=0, paran=0;
%}

%%
[0-9]+ {id++; printf("Identifier is %s\n", yytext);}
[+*] {op++; printf("Operator is %s\n", yytext);}
[(] {paran++;}
[)] {paran--;}
%%

int main() {
    printf("Enter arithmetic expression:\n");
    yylex();
    // Press Ctrl^D while executing to end lex parsing

    if(paran==0 && id == op+1 && op>0) {
        printf("Valid expression\n");
        printf("No. of identifiers = %d\n", id);
        printf("No. of operators = %d\n", op);
    } else
        printf("Invalid expression\n");
    return 0;
}

int yywrap() {
    return 1;
}
