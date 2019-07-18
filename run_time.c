#include<stdlib.h>
#include<stdio.h>
#include<string.h>
main()
{
	char *ptr;
	ptr= (char*)calloc(3,20*sizeof(char));
	*((ptr+2)[0])='a';
	*((ptr+2)[1])='b'
	printf("%c",*((ptr+2)[1]));
	free(ptr);

}
