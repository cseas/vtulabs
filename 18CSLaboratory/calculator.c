#include<stdio.h>

int main()

{
	float a,b;
	char A;
	printf("enter two numbers\n");
	scanf("%f %f",&a,&b);
	printf("enter the operator \n");
	scanf("%s",&A);
switch(A)
{
	case '+' :
	printf("sum is :%f",a+b);
	break;
	case '-' :
	printf("diff is : %f",a-b);
	break;
	case '*' :
	printf("prod is : %f",a*b);
	break;
	case '/' :
	printf("div is : %f",a/b);
	break;
	default :
	printf("enter the  appropriate operaor");
}
return 0;

}