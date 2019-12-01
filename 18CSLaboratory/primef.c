#include<stdio.h>
int isprime(int n);
int main()
{
int n,i;
printf("enter a  no.\n");
scanf("%d",&n);
if(isprime(n))
printf("%d is a prime no.\n",n);
else
printf("%d ia not a prime no.\n",n);
return 0;
}
int isprime(int n)
{
	int i;
	for(i=2;i<n/2;i++)
	{
		if(n%i==0)
		return 0;
	}
	return 1;
}
