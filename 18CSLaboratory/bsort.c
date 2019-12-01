#include<stdio.h>
int main()
{
	int i,a[10],t=0,j,n;
	printf("enter no. of elements\n");
	scanf("%d",&n);
	printf("enter the elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)
	{
	for(j=0;j<n-i-1;j++)
	{
		if(a[j]>a[j+1])
		{
			t= a[j];
			a[j] = a[j+1];
			a[j+1] = t;
		}
	}
}
printf("sorted elements are :\n");
for(i=0;i<n;i++)
	printf("%d\n",a[i]);
		return 0;
	}