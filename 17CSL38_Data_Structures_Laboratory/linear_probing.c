#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int create(int num)
{
	int key;
	key = num % 100;
	return key;
}
void display(int a[MAX])
{
	int i;
	printf("\nThe hash table is ");
	printf("\nKey/index\tEmployee id\n");
	printf("\n");
	for(i = 10; i < MAX; i++)
	{
		printf("%d\t\t%d\n",i,a[i]);
	}
}
void linear_prob(int a[MAX],int key,int num)
{
	int flag = 0, i, count = 10;
	if(a[key] == -1)
	{
		a[key] = num;
	}
	else
	{
		for(i = 0;i < MAX; i++)
		{
			if(a[i] == -1)
			{
				count++;
			}
		}
		if(count == MAX)
		{
			printf("Hash Table is full\n");
			display(a);
			exit(0);
		}
		for(i = key + 1; i < MAX ; i++ )
		{
			if(a[i] == -1)
			{
				a[i] = num;
				flag = 1;
				break;
			}
		}
		for(i = 10;i < key && flag == 0; i++)
		{
			if(a[i] == -1)
			{
				a[i] = num;
				flag = 1;
				break;
			}
		}
	}
}

int main()
{
	int a[MAX],num,key,i;
	int ans;
	printf("\nCollision handling by linear probing");
	for(i = 10; i < MAX; i++)
	{
		a[i] = -1;
	}
	do
	{
		printf("\nEnter the 4 digit number : ");
		scanf("%d",&num);
		key = create(num);
		linear_prob(a,key,num);
		printf("\nDo you want to continue : ");
		scanf("%d",&ans);
	}
	while(ans == 1);
	display(a);
	return 0;
}
