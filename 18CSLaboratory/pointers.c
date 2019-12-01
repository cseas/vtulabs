#include<stdio.h>
#include<math.h>
int main()
{
	float a[10],*ptr,mean,sum=0,var,sumstd=0,std;
	int n,i;
	printf("enter the number of elements \n");
	scanf("%d",&n);
	printf("enter the array elements \n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&a[i]);
	}
	ptr=a;
	for(i=0;i<n;i++)
	{
		sum=sum+(*ptr);
		ptr++;
	}
	mean=sum/n;
	ptr=a;
	for(i=0;i<n;i++)
	{
		sumstd=sumstd+pow((*ptr-mean),2);
		ptr++;
	}
	var=sumstd/n;
	std=sqrt(var);
	
	printf("mean=%f \n",mean);
	printf("variance=%f \n",var);
	printf("standard deviation=%f\n",std);
	return 0;
}
