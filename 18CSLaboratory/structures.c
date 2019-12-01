#include<stdio.h>
#include<math.h>

struct student
{
	int usn;
	char name[10];
	int  marks[4];
};
int main()
{
	struct student s[10];
	int sum,average=50,avg[10],n,i,j;
	printf("enter the number of students \n");
	scanf("%d",&n);
	printf("enter the details of students\n");
	for(i=0;i<n;i++)
	{
		sum=0;
		printf("enter usn\n");
		scanf("%d",&s[i].usn);
		printf("enter name\n");
		scanf("%s",&s[i].name);
		printf("enter the marks\n");
		for(j=0;j<4;j++)
		{
			scanf("%d",&s[i].marks[j]);
			sum=sum+s[i].marks[j];
		}
		avg[i]=sum/4;
	}
	printf("avg=%d\n",average);
	printf("the students above average marks are:\n");
	printf("usn\t name\n");
	for(i=0;i<n;i++)
	if(avg[i]>=average)
	printf("\n %d\t %s ",s[i].usn,s[i].name);
	printf("the students below average marks are:\n");
	printf("usn\t name\n");
	for(i=0;i<n;i++)
	if(avg[i]<average)
	printf("\n %d\t %s",s[i].usn,s[i].name);
return 0;
}
