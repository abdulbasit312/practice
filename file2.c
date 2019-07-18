#include<stdio.h> 
#define max 30
extern void display()
{
	int i;
	char arr[max];
	printf("\nThe records in file are");
	FILE *fp;
	fp=fopen("test.dat","rb");
	while(fgets(arr,max+1,fp)!=NULL)
	{
		printf("%s",arr);
	}
	printf("EOF reached");
	fclose(fp);
}

