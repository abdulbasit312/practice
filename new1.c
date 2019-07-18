#include<stdio.h>
void main()
{
	int i,after_i,eof_flag;
	scanf("%d",&i);
	while((eof_flag=scanf("%d",&after_i))!=EOF)
	{
		if(i>after_i)
			break;
		else
			i=after_i;
	}
	if(eof_flag!=EOF)
	printf("The file is not sorted");
	else
	printf("The file is in ascending order");
}

