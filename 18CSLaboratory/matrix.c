#include<stdio.h>
int main(){
	int i,j,k,m,n,p,q,a[10][10],b[10][10],c[10][10];
	printf("enter the size of first array\n");
	scanf("%d%d",&m,&n);
	printf("enter the size of second array\n");
	scanf("%d%d",&p,&q);
	printf("enter the first array\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
		printf("enter the second array\n");
		for(i=0;i<p;i++)
		{
			for(j=0;j<q;j++)
				scanf("%d",&b[i][j]);
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<q;j++)
           {
             c[i][j]=0;
             for(k=0;k<n;k++)
             	c[i][j]+=a[i][k]*b[k][j];
         }
       }
           printf("multiplied matrix is :\n");
           for(i=0;i<m;i++)
           {

           	for(j=0;j<q;j++)
           		printf(" %d",c[i][j]);
           	printf("\n");
           }
           return 0;
           }
