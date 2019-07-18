#include<stdio.h> 
#define max 30
extern void enter()
{
	int no;
	FILE *fp;int c;
	char entry[max];	
	printf("The number of records you want to enter:");
	scanf("%d",&no);
        c=getchar();   //scanf doesnt take newline,so to accomodate that new line, we use this
		//otherwise the fgets reads the new line and stores it in file
	fp=fopen("test.dat","ab");
	for(int i=0;i<no;i++)
	{
		printf("Record no. %d :",(i+1));
		fgets(entry,max+1,stdin);
		fputs(entry,fp);
	}
	fclose(fp);
}

	
