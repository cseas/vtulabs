#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int strlength(char s1[]);
void strcomp(char s1[],char s2[]);
void strconcat(char s1[],char s2[]);
int main()
{
	char s1[20],s2[20];
	int s;
	printf(" 1 for string length \n 2 for string comparison \n 3 for string concatination \n ");
	scanf("%d",&s);
	switch(s)
	{
	  case 1: printf("enter a string:");
	          scanf("%s",s1);
              printf("string length is : %d\n",strlength(s1));
              break;
      case 2: printf("enter two strings:");
              scanf("%s %s",s1,s2);
              strcomp(s1,s2);
              break;
      case 3: printf("enter two strings:");
              scanf("%s %s",s1,s2); 
              strconcat(s1,s2);
     default:
     break;               
	}         

    return 0;
}
int strlength(char s1[])
{
	 int i,c=0;
	 for(i=0;s1[i]!='\0';i++)
	 {
        c++;
	 }
	 return c;
}
void strcomp(char s1[],char s2[])
{
	int l1,l2,i;
	l1=strlength(s1);
	l2=strlength(s2);
	if(l1!=l2)
	{
		 printf("strings are diff.");
	}
	else
	{
         for(i=0;i<l1;i++)
         	{
         		if(s1[i]!=s2[i])
         		{
         		 printf("strings are diff");
         		 exit(0);
         	    }} 
         		 printf("string are same");
}}
void strconcat(char s1[],char s2[])
{
	char s3[50];
	int i,k=0;
	for(i=0;s1[i]!='\0';i++)
		{
	     s3[i]=s1[i];
	     k=k+1;
	    }
	for(i=0;s2[i]!='\0';i++)
		{
		 s3[k]=s2[i];
		 k=k+1;
		}
		s3[k]='\0';
	printf("the concatinated string is:%s",s3);
}