#include<stdio.h>
#define TRUE 1
#define FALSE 0
#define PAGE_LENGTH 52
main()
{
	int printpages(void);
	while(printpages())
		;
}
int printpages()
{
	int line_no;
	int c;
	static int page_no=1;	
	int echo_line(void);
	if((c=getchar())==EOF)	
		return(FALSE);
	ungetc(c,stdin);	
	printf("\nPage no. : %d\n\n", page_no++);
	for(line_no=0;line_no<PAGE_LENGTH;line_no++)
	{
		if(echo_line()==EOF)
		{	
			putchar('\f');
			return(FALSE);
		}
	}
		putchar('\f');
		return (TRUE);	
}	
	

int echo_line()
{
	int c;
	while((c=getchar())!=EOF && c!='\n')
		putchar(c);
	if(c=='\n')
		putchar('\n');
	return (c);
}
