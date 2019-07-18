#include<stdio.h>
main()
{
	int a,i;
	for(i=0;i<5;i++)
	{
		printf("%d time of  run.\n",i);
		if(i==3)
			goto a;
	}
	a:printf("\n we are out of loop");
} 
