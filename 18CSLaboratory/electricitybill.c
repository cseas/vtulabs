#include<stdio.h>
int main()
{
int mc=100;
float u,totalamount;
char name[10];
printf("Enter the name\n");
scanf("%s",name);
printf("enter the units\n");
scanf("%f",&u);
if(u<=200)
	totalamount = 100 + 0.8*u;
else if(u>200&&u<=300)
	totalamount = 100 + 0.8*200 + 0.9*(u-200);
else if(u>300)	
	totalamount = 100 + 0.8*200 + 0.9*100 + 1*(u-300);
if (totalamount>400)
	totalamount = totalamount + totalamount*(0.15);
printf("total amount is %f",totalamount);
return 0;
}
