#include<stdio.h>
#include<math.h>
int bintodec(int n);
int sum=0,i =0;
int main()
{
	int n,dec;
	printf("enter the binary form:\n");
	scanf("%d",&n);
	dec=bintodec(n);
	printf("decimal form : %d\n",dec);
	return 0;
}
int bintodec(int num)
{
	sum = sum+(num%10)*pow(2,i);
	if(num==1)
return sum;
else
{
i++; 
return(bintodec(num/10));
	}

}

