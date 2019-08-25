#include<stdio.h>
#include<string.h>

/*
 FIRST(A)={a}
 FIRST(B)={b#}
 FOLLOW(A)={$}
 FOLLOW(B)={a}
 
 Parser Table Entry
 M[A,a]=A->aBa
 M[B,a]=B->#
 M[B,b]=B->bB
 */

struct FT {
	char nonT;
	char set[20];
};

struct FT first[10], follow[10];

/*char parser_table[2][3][10]={{"A->aBa","",""},
							 {"B->#","B->bB",""},
							};*/

char parser_table[2][3][10];							
char termminal_list[3]={"ab$"};
int n; // number of productions 
char stack[50];
int top=-1;

char* strrev(char *str) {
    int i=0, j = strlen(str) - 1;

    char tmp;
    while (i < j) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
    return str;
}

int getFollowIndex(char x) {
	int i;
	for(i=0;i<n;i++) {
		if(follow[i].nonT == x)
			break;
	}
	return i;
}

int getTerminalIndex(char x) {
	int i;
	for(i=0; i<strlen(termminal_list); i++) {
		if(termminal_list[i]==x)
			break;
	}
	return i;
}

void push(char x) {
	stack[++top] = x;
}

void pop() {
	stack[top]='\0';
	top--;
}

void check_input(char expr[30]) {
	int i,j,row,col;
	char prod[20], *token, ch, StackTop, temp[2], rprod[20];
	temp[1]='\0';

	for(i=0; expr[i]!='$';) {
		ch = expr[i];
		StackTop = stack[top];
		temp[0] = StackTop;
		
        if(strstr(termminal_list,temp)!=NULL || StackTop =='$' ) {
			if(strstr(termminal_list,temp)!=NULL ) {
				pop();
				i++;
			}
		} else {
			if(strstr(termminal_list,temp)==NULL) {
				row = getFollowIndex(StackTop);
				col = getTerminalIndex(ch);
				strcpy(prod, parser_table[row][col]);
				
                printf("\nM[%d,%d]  M[%c,%c] = %s",row,col,StackTop,ch,prod);
					
                strcpy(rprod,strrev(prod));
				token = strtok(rprod,">");
				
				if(strstr(rprod,"#")!=NULL) {
					pop();
				} else {
					pop();
					for(j=0;j<strlen(token);j++)
						push(token[j]);
				} // end else
			} // end if
		} // end else
	} // end for
	
    if(expr[i]==stack[top])
		printf("\n ch = %c StackTop = %c  %s is Accepted\n",expr[i],stack[top],expr);
	else
		printf("\n ch = %c StackTop = %c  %s is Not Accepted",expr[i],stack[top],expr);
}

void init() {
	stack[0]='\0';
	top=-1;
}

int main() {
	char production[10][20],Ind_prod[30][20],inputString[30];
	int i,j,n_Ind=0,ch;
	char t,T;
	
    n = 2;
    fflush(stdin);
	
    for(i=0;i<n;i++) {
		printf("Enter production %d: ",i);
		gets(production[i]);
		fflush(stdin);
	}

	printf("\nFirst Set\n");
	for (i=0;i<n;i++) {
		first[i].nonT = production[i][0];
		printf("Enter First(%c): ",first[i].nonT);
		gets(first[i].set);
		fflush(stdin);
	}

	printf("\nFollow Set\n");
    for (i=0; i<n; i++) {
		follow[i].nonT = first[i].nonT;
		printf("Enter Follow(%c): ",follow[i].nonT);
		gets(follow[i].set);
		fflush(stdin);
	}
	
    printf("\nIf no entry, enter err\n");
    for(i=0;i<2;i++)
	    for (j=0;j<3;j++) {
		    T = first[i].nonT;
		    t = termminal_list[j];
		    printf("M[%d,%d] M[%c,%c] = ",i,j,T,t) ;
		    gets(parser_table[i][j]);
		    fflush(stdin);
	    }
    
	init();
	push('$');
	push(production[0][0]);
	printf("\nStack %s",stack);
	printf("\nEnter the input \t");
	gets(inputString);
		
    check_input(inputString);
}
