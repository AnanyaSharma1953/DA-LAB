#define max 10
#include<stdlib.h>
#include<stdio.h>
typedef struct l
{
	int d;
	struct l *next;
}q;
void enq(q**,q**);
void deq(q**,q**);
void dis(q*,q*);
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
				deq(&f,&r);
				break;
			case 3:
				dis(f,r);
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
		if(*f==NULL&&*r==NULL)
			*f=*r=p;
		else
		{
			(*r)->next=p;
			*r=p;
		}
		(*r)->next=(*f);
	}
	
}
void deq(q **f,q **r)
{
	q *p=NULL;
	if(*f==NULL&&*r==NULL)
		printf("empty");
	else
	{
		p=*f;
		printf("%d",(*f)->d);
		if(*f==*r)
			*f=*r=NULL;
		else
		{
			*f=(*f)->next;
		(*r)->next=*f;
			free(p);
		}
	}
}
void dis(q *f,q *r)
{
	if(f==NULL)
		printf("empty");
	else
	{
		while((f)!=(r))
		{
			printf("%d ",(f)->d);
			f=f->next;
			}
			printf("%d  ",f->d);
		
	}
}

