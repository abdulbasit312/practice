#include<stdio.h>
#define IBM
#ifndef IBM
#define IBM printf("This is an Ibm computer")
#else
#define VAX printf("this is a vax computer") 
#endif
void main()
{
IBM;	
}
