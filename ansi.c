#include<stdio.h>
void main()
{
	char c;
	int value;
	int i;
	while(scanf(" %c",&c)!=EOF){
	do{
		printf("%c",c);
		scanf("%c",&c);
	}while(c!='\n');
	printf("\n");
	scanf("%d",&value);
	for(i=1;i<=value;i++) 
	{
		printf("*");
	}
	printf("\n");
	}
}

