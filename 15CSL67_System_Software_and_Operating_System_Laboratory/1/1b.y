%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%token num
%left '+''-'
%left '*''/'

%%
input:e {printf("Result = %d\n", $1); exit(0);}
e:e'+'e {$$ = $1 + $3;}
e:e'-'e {$$ = $1 - $3;}
e:e'*'e {$$ = $1 * $3;}
e:e'/'e {if($3 == 0) {printf("Divide by zero error\n"); exit(0);}
         else $$ = $1 / $3;}
e:'('e')' {$$ = $2;}
e:num {$$ = $1;}
%%

int main() {
    printf("Enter arithmetic expression:\n");
    yyparse();
}

int yyerror() {
    printf("Error\n");
    exit(0);
}
