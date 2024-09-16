#define max 10
#include<stdlib.h>
#include<stdio.h>
typedef struct l
{
	int d;
	struct l *prev;
	struct l *next;
}q;
q* enq(q*);
q* deq(q*);
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
				r=enq(r);
				if(f==NULL)
				f=r;
				break;
			case 2:
				f=deq(f);
				if(f==NULL)
				r=NULL;
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
q* enq(q *r)
{
	q *p=NULL;
	p=(q*)malloc(sizeof(q));
	if(p!=NULL)
	{
		int x;
		scanf("%d",&x);
		p->d=x;
		if(r==NULL)
		{
		r=p;
		p->prev=NULL;
	}
		else
		{
			(r)->next=p;
			p->prev=r;
			r=p;
		}}
		(r)->next=NULL;
		return r;
}
q* deq(q *f)
{
	q *p=NULL;
	p=(q*)malloc(sizeof(q));
	if(f==NULL)
		printf("empty");
	else
	{
		p=f;
		printf("%d",(f)->d);
		f=f->next;
		if(f==NULL)
			free(p);
		else
		{
			f->prev=NULL;
			free(p);
		}
	}
	return f;
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
