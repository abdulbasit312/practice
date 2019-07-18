#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct linkedlist{
	char name[20];
	struct linkedlist* next;
}LINKED;
main()
{
	LINKED *start, *add;
	int d,c;
	LINKED *linked(),*add_element_at_nth(LINKED*,LINKED*,int),*delete_nth_node(LINKED*,int);
	void print(LINKED*);
	start=linked();
	print(start);
	c=getchar();
	printf("\nEnter the record to add");
	gets(add->name);
	printf("\nadd at position?");
	scanf("%d",&d);
	start=add_element_at_nth(start,add,d);
	print(start);
	printf("\nwhich number record to delete?");
	scanf("%d",&d);
	start=delete_nth_node(start,d);
	print(start);
}
LINKED *linked()
{
	LINKED *first, *current;
	int ch,i=1,c;
	first=current= (LINKED*)malloc(sizeof(LINKED));
	printf("Enter the name of 1st student:");
	gets(current->name);
	printf("\nDo you wish to enter more names?\n Yes-1\n No-0\t");
	scanf("%d",&ch);
	while(ch)
	{
		if((current->next=(LINKED*)malloc(sizeof(LINKED)))==NULL)
		{
			printf("\n not enough space");
			return(first);
		}
		current=current->next;
		printf("Enter the name of student %d:",i++);c=getchar();
		gets(current->name);
		printf("\nDo you wish to enter more names?\n Yes-1\n No-0\t");
		scanf("%d",&ch);
	}
	current->next=NULL;
	return(first);
}
void print(LINKED *ptr)
{
	while(ptr!=NULL)
	{
		printf("\n%s",ptr->name);
		ptr=ptr->next;
	}
	printf("\nEnd of Output");
}
LINKED* find_nth_element(int n, LINKED* list)
{
	if(n<1)
		return(NULL);
	while(--n && list!=NULL)
	{
		list=list->next;
	}
	return(list);
}
LINKED *add_element_at_nth(LINKED *list,LINKED *ele, int n)
{
	LINKED* find_nth_element(int n,LINKED*);
	if(n==1)
	{
		ele->next=list;
		return(ele);
	}
	LINKED *pred;
	pred=find_nth_element(n-1,list);
	if(pred==NULL)
		return(NULL);
	ele->next=pred->next;
	pred->next=ele;
	return(list);
}
LINKED *delete_nth_node(LINKED* list,int n)
{
	LINKED *pred,*old,*find_nth_element(int n,LINKED*);
	if(n==1)
	{
		if(list==NULL)
			return(NULL);	
		old=list;
		list=list->next;
	}
	else{
		pred=find_nth_element(n-1,list);
		old=pred->next;
		pred->next=old->next;
	}
	free(old);
	return(list);
}