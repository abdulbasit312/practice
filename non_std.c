#include<stdio.h>
main()
{
	long i;
	FILE *fp;
	fp=fopen("test.dat","rb");
	for(int j=0;j<3;j++){
	printf("%ld",ftell(fp));
	printf("%c",fgetc(fp));
}
	fseek(fp,3L,SEEK_CUR);
printf("%ld",ftell(fp));
	printf("%c %li",fgetc(fp),ftell(fp));
}
