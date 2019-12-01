#include<stdio.h>
int main()
{
	int n,rev = 0,t,rem;
	printf("enter a number\n ");
	scanf("%d",&n);
	t =n;
	while(n!=0){
		rem = n%10 ;
	    rev = rev*10 + rem;
	    n = n/10;
	}
	printf("reverse number is %d\n",rev);
	    if(t==rev)
	    	printf("number is palindrome\n");
	    else 
	    	printf("number is not palindrome\n");
	    return 0;

}