#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
	int n;
	char *letter;
	printf("Enter the size of the char array");
	scanf("%d",&n);
	letter=(char*)malloc(n*sizeof(char));
	strcpy(letter,"HEllo there");
	printf("\n%s",letter);
	free(letter);
}