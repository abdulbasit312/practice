#include<stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct student
{
	char name[30];
	int roll;
	struct student* next;
}stu;
main()
{
	stu* start,*createlist(),*displaylist(stu*),*find_nth(stu*,int),*delete_at_nth(stu*,int),*add_at_nth(stu*,stu*,int);
	stu* ele,*t;
	stu temp;
	int ans,a,c;
	do{
		printf("\n1.enter elements in list");
		printf("\n2.print elements in list");
		printf("\n3.Find the nth element");
		printf("\n4.add element in between");
		printf("\n5.delete element from list");
		printf("\n0.Exit");
		printf("\nEnter your choice :");
		scanf("%d",&ans);
		switch(ans)
		{
			case 1:
				start=createlist();
				break;
			case 2:
				if(displaylist(start)==NULL)
					printf("\nEmpty list");
				break;
			case 3:
				printf("Enter element number to find :\n");
				scanf("%d",&a);
				if((ele=find_nth(start,a))==NULL)
					printf("\nElement not present");
				else
				{
				printf("\nThe name of the student is : %s",ele->name);
				printf("\nThe roll no of the student is: %d",ele->roll);
				}
				break;
			case 4:
				printf("Enter place to add :\n");
				scanf("%d",&a);
				c=getchar();
				printf("\nThe name of the student is : ");
				gets(temp.name);
				printf("\nThe roll no of the student is: ");
				scanf("%d",&temp.roll);
				if((t=add_at_nth(&temp,start,a))==NULL)
					printf("\nNot possible");
				else
					start=t;
				break;
			case 5:
				printf("Enter place to delete :\n");
				scanf("%d",&a);
				if((t=delete_at_nth(start,a))==NULL)
					printf("\nNot deleted");
				else
				{
					start=t;
					printf("\nDeleted");
				}
				break;
		}
	}while(ans!=0);
}
stu* createlist()
{
	int c;
	static stu *new;
	static stu* current;
	int res;
	static int run=0;
	if(run==0)
	{	run++;	
		new=current=(stu*)malloc(sizeof(stu));
	c=getchar();
	printf("\nEnter name of 1st student : ");
	gets(current->name);
	printf("\nEnter Roll of 1st student :");
	scanf("%d",&(current->roll));
	printf("\ndo you wish to enter more elements?\n1/Yes\n2.No :");
	scanf("%d",&res);
	}
	else
		res=1;
	while(res==1)
	{
		current->next=(stu*)malloc(sizeof(stu));
		current=current->next;
		c=getchar();
		printf("\nEnter name of %d student : ",(run+1));
		gets(current->name);
		printf("\nEnter Roll of %d student :",(run+1));
		scanf("%d",&(current->roll));
		run++;
		printf("\ndo you wish to enter more elements?\n1/Yes\n2.No :");
		scanf("%d",&res);
	}
	current->next=NULL;
	return(new);
}
stu* displaylist(stu* start)
{
	int i=0;
	if(start==NULL)
		return (NULL);
	while((start)!=NULL)
	{
		printf("\n\nName of student %d is : %s",++i,start->name);
		printf("\nRoll of student %d is : %d",i,start->roll);
		start=start->next;
	}
	return(1);
}
stu* find_nth(stu* start,int n)
{
	int i;
	if(n<1)
		return NULL;
	for(i=1;i<=n-1 && start!=NULL;i++)
	{
		start=start->next;
	}
	return (start);			//if it returns null it means element is not there in list	
}
// add and delete left
stu* add_at_nth(stu* add,stu* start, int n)
{
	stu* prev;
	if(n==1)
	{
		add->next=start;
		return add;
	}
	prev=find_nth(start,n-1);
	if(prev==NULL)
		return NULL;
	add->next=prev->next;
	prev->next=add;
	return start;
}
stu* delete_at_nth(stu* start, int n)
{
	stu* delete,*pred;
	if(n==1)
	{
		delete=start;
		start=start->next;
		free(delete);
		return (start);
	}
	pred=find_nth(start,n-1);
	if(pred->next==NULL)
		return NULL;
	delete=pred->next;
	pred->next=delete->next;
	free(delete);
	return(start); 
}