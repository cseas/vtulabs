#include<stdio.h>
int main()
{
	float n,temp,sqr;
	printf("enter a number\n");
	scanf("%f",&n);
	sqr = n/2;
     temp=0;
	while(temp!=sqr)
{		temp = sqr;
		sqr = (n/sqr + sqr)/2;

	}
	printf("%f is squareroot",sqr);

	return 0;
}
