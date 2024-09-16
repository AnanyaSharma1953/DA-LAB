#define max 10
#include<stdlib.h>
#include<stdio.h>
typedef struct l
{
	int d;
	struct l *prev;
	struct l *next;
}q;
void enq(q**,q**);
void deq(q**);
void dis(q*);
int main()
{
	int ch;
	q *f=NULL,*r=NULL;
	do
	{
		printf("1:insert \n 2:delete\n 3:display \n \n 4:exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				enq(&f,&r);
				break;
			case 2:
				deq(&f);
				break;
			case 3:
				dis(f);
				break;
			case 4:
				exit(0);
			default:
				printf("invalid");		
		}
	}while(ch<=4);
}
void enq(q **f,q **r)
{
	q *p=NULL;
	p=(q*)malloc(sizeof(q));
	if(p!=NULL)
	{
		int x;
		scanf("%d",&x);
		p->d=x;
		if(*r==NULL&&*f==NULL)
		{
		*r=*f=p;
		p->prev=NULL;
	}
		else
		{
			(*r)->next=p;
			p->prev=*r;
			*r=p;
		}}
		(*r)->next=NULL;
}
void deq(q **f)
{
	q *p=NULL;
	p=(q*)malloc(sizeof(q));
	if(*f==NULL)
		printf("empty");
	else
	{
		p=*f;
		printf("%d",(*f)->d);
		*f=(*f)->next;
		if(*f==NULL)
			free(p);
		else
		{
			(*f)->prev=NULL;
			free(p);
		}
	}
}
void dis(q *f)
{
	if(f==NULL)
		printf("empty");
	else
	{
		while((f)!=NULL)
		{
			printf("%d ",(f)->d);
			f=f->next;
			}
		
	}
}
