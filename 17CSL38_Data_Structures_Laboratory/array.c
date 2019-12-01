#include<stdio.h>
#include<stdlib.h>
int n;
int read(int a[20],int n)
{
    int i;
    printf("Enter the elements \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    return 0;
}
void display(int a[20],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}
void insert(int a[20], int pos)
{
    int ele,i;
    pos = pos-1;
    printf("Enter the element to be inserted : ");
    scanf("%d",&ele);
    for(i=n;i>=pos;i--)
    {
        a[i] = a[i - 1];
    }
    a[pos] = ele;
    n=n+1;
}
void delete(int a[20],int pos)
{
    int i;
    printf("Deleted element is %d ", a[pos - 1]);
    for(i=pos-1;i<n;i++)
    {
        a[i] = a[i+1];
    }
    n--;
}
int main()
{
    int ch,a[20],pos,item;
    while(1)
    {
        printf("\n1.Create an array\n2.display\n3.insert\n4.delete\n5.exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the number of elements : ");
                    scanf("%d",&n);
                    read(a,n);
                    break;
            case 2:display(a,n);
                    break;
            case 3:printf("Enter the position to be inserted : ");
                    scanf("%d",&pos);
                    insert(a,pos);
                    break;
            case 4:printf("Enter the position to be deleted : ");
                    scanf("%d",&item);
                    delete(a,pos);
                    break;
            case 5:exit(0);
            default: printf("Enter the correct value");
        }
    }
}

//Output
/*
1.Create an array
2.display
3.insert
4.delete
5.exit
Enter your choice : 1
Enter the number of elements : 6
Enter the elements
1
2
3
4
5
6

1.Create an array
2.display
3.insert
4.delete
5.exit
Enter your choice : 2
1
2
3
4
5
6

1.Create an array
2.display
3.insert
4.delete
5.exit
Enter your choice : 3
Enter the position to be inserted : 2
Enter the element to be inserted : 9

1.Create an array
2.display
3.insert
4.delete
5.exit
Enter your choice : 2
1
9
2
3
4
5
6

1.Create an array
2.display
3.insert
4.delete
5.exit
Enter your choice : 4
Enter the position to be deleted : 2
Deleted element is 9
1.Create an array
2.display
3.insert
4.delete
5.exit
Enter your choice : 2
1
2
3
4
5
6

1.Create an array
2.display
3.insert
4.delete
5.exit
Enter your choice : 5

*/