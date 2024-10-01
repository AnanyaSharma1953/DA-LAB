#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
	int d;
	struct list * next;
}s;
void inser(s**,s**);
void disp(s*);
int main()
{
	int ch;
	s *f=NULL,*r=NULL;
	do
	{
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				inser(&f,&r);
				break;
			case 2:
				disp(f);
		}
	}while(ch<=2);	
}//
void inser(s **f,s **r)
{
	s *p=NULL;
	p=(s*)malloc(sizeof(s));
	printf("enter element");
	scanf("%d",&p->d);
	p->next=NULL;
	if(*f==NULL&&*r==NULL)
	{
		*f=*r=p;
	}
	else if((p->d)>(*r)->d)
	{
		(*r)->next=p;
		*r=p;
	}
	else if((p->d)<(*f)->d)
	{
		p->next=*f;
		*f=p;
	}
	else
	{
		s *ff=*f;
		while(ff->next->d<p->d)
		{
			ff=ff->next;
		}
		p->next=ff->next;
		ff->next=p;
	}
}
void disp(s *f)
{
	while(f!=NULL)
	{
		printf("%d->",f->d);
		f=f->next;
	}
}
