#include<stdio.h>
#include<stdarg.h>
#include<limits.h>
main()
{
	int a,b,c,d,max(int,...),large;
	printf("Enter 1st number");
	scanf("%d",&a);
	printf("Enter 2nd number");
	scanf("%d",&b);
	printf("Enter 3rd number");
	scanf("%d",&c);
	printf("Enter 4th number");
	scanf("%d",&d);
	large=max(4,a,b,c,d);
	printf("\nThe largest number is %d.\n",large);

}

int max(int number,...)
{
	va_list ard_add;
	int i,next_int;
	int largest=INT_MIN;
	va_start(ard_add,number);
	for(i=0;i<number;i++)
	{
		if((next_int=va_arg(ard_add,int))>largest)
			largest= next_int;
	}
	return largest;
}
	
	

