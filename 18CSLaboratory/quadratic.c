#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{

	float a,b,c,d,r1,r2;
	printf("enter the coefficients\n");
	scanf("%f %f %f",&a,&b,&c);
	d = (b*b) - (4*a*c);
	if(d>0)
	{
		printf("roots are real and distinct\n");
		r1 = (-b + sqrt (d))/2*a;
		r2 = (-b - sqrt (d))/2*a;

	}
	else if(d ==0)
		{
			printf("roots are equal\n");
			r1 = r2 = -b/2*a;
            }
            else 
            {
            	
            	r1 = -b/2*a;
            	r2 = sqrt(fabs(d))/2*a;
            	printf("roots are imaginary %f+i%f and %f-i%f",r1,r2,r1,r2);
            	exit (0);

 }
                printf("roots are %f and %f",r1,r2); 
                return 0;
 }