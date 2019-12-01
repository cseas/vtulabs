#include<stdio.h>
#include<stdlib.h>
#define MAX 5
char CQ[MAX],f = -1,r = -1;
int CQfull()
{
  if((f==r+1)||((f==0) && (r == MAX - 1)))
  {
    return 1;
  }
  return 0;
}
int CQempty()
{
  if(f == -1)
  {
    return 1;
  }
  return 0;
}
void CQinsert(char ele)
{
  if(CQfull())
  {
    printf("\nOverflow");
  }
  else
  {
    if(f == -1)
    {
      f = 0;
    }
    r = ( r + 1 ) % MAX;
    CQ[r] = ele;
  }
}
char CQdelete()
{
  char ele;
  if(CQempty())
  {
    printf("\nUnderflow");
    return -1;
  }
  else
  {
    ele = CQ[f];
    if( f == r )
    {
      f = -1;
      r = -1;
    }
    else
    {
      f = ( f + 1 ) % MAX;
      return ele;
    }
  }
}
display()
{
  int i;
  if(CQempty())
  {
    printf("\nEmpty Queue");
  }
  else
  {
    printf("front[%d] --> ",f);
    for(i = f;i != r; i = (i + 1) % MAX)
    {
      printf("%c - ",CQ[i]);
    }
    printf("%c",CQ[i]);
    printf(" <-- [%d]Rear",r);
  }
}
int main()
{
  int ch;
  char ele;
  while(1)
  {
    printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("\nEnter the element to be inserted : ");
             scanf("%s",&ele);
             CQinsert(ele);
             break;
      case 2:ele = CQdelete();
              if(ele != -1)
              {
                printf("\nDeleted element is %c", ele);
              }
              break;
      case 3:printf("\nThe circular queue is \n");
             display();
             break;
      case 4:exit(0);
    }
  }
  return 0;
}
