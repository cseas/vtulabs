#include<stdio.h>
#include<math.h>
#define pi 3.142
int main()
{
int n,i;
float deg,x,term,sum;
printf("enter the value of n\n");
scanf("%d",&n);
printf("enter the degree\n");
scanf("%f",&deg);
x=(deg*pi)/180;
printf("rad= %f\n",x);
term=x;
sum=term;
for(i=3;i<=n;i=i+2)
{
term=(-term*x*x)/(i*(i-1));
sum=sum+term;
}
printf("using user defined function");
printf("sin(%f)=%f\n",deg,sum);
printf("using library function\n");
printf("sin(%f)=%f\n",deg,sin(x));
return 0;
}