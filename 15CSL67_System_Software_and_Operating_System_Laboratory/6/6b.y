%{
    #include <stdio.h>
    #include <stdlib.h>
    int id=0, dig=0, key=0, op=0;
%}

%token DIGIT ID KEY OP

%%
input: DIGIT input { dig++; }
| ID input { id++; }
| KEY input { key++; }
| OP input {op++;}
| DIGIT { dig++; }
| ID { id++; }
| KEY { key++; }
| OP { op++;}
;
%%

extern int yylex();
extern int yyparse();
extern FILE *yyin;

int main() {
    FILE *myfile = fopen("sample.c", "r");
    
    if (!myfile) {
        printf("Can't open sample.c!");
        return -1;
    }

    yyin = myfile;
    do {
        yyparse();
    } while (!feof(yyin));

    printf("Numbers = %d\nKeywords = %d\nIdentifiers = %d\nOperators = %d\n",
        dig, key, id, op);
    
    return 0;
}

void yyerror() {
    printf("Parse error! Message: ");
    exit(-1);
}
