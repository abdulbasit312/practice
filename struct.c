#include<stdio.h>
main()
{
	typedef enum tag{first,second,third} TAG;
	TAG record1,record2;
	record1=second;
	record2=first;
	printf("record1 %d",record1);
	printf("\nrecord2 %d",record2);
}

