#include<stdio.h>
#include<stdlib.h>
int main()
{
	int low,high,mid,n,i,key,a[20];
	printf("enter the key:\n");
    scanf("%d",&key);
	printf("enter the no. of elemnts\n");
	scanf("%d",&n);
	printf("enter the  elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
}

low=0;
high=n-1;
mid=(low+high)/2;
while(low<=high)
{
if(a[mid]==key)
{
  printf("element found at position %d",mid+1);
  exit(0);
}
else if(a[mid]>key)
{
	high = mid - 1;
}
else
{
	low = mid+1;
}
mid=(low+high)/2;
}
printf("search is unsuccesful");

return 0;
}