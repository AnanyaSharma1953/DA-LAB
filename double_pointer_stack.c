#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
	int d;
	struct list *next;
}s;
#define max 10
void inser(s**);
void del(s**);
void show(s*);
int main()
{
	s *top=NULL;
  	int ch=0;
  	do
  	{
  	
  	printf("1:insert");
  	printf("2:delete");
  	scanf("%d",&ch);
  	switch(ch)
  	{
  	
  		case 1:
  			inser(&top);
  			break;
  		case 2:
  			del(&top);
  			break;
  		case 3:
  			show(top);
  			break;
  		case 4:
  			exit(0);
		default:
			printf("invalid");
  	}
  	}while(ch<=4);
  	return 0;
}
void inser(s **top)
{
	int x;
	s *p=NULL;
	p=(s*)malloc(sizeof(s));
	if(p!=NULL)
	{
       scanf("%d",&x);
       p->d=x;
       p->next=*top;
       *top=p;
       }
       
       return;
}
void del(s **top)
{
	s *p=NULL;
	if(*top!=NULL)
	{
		printf("%d",(*top)->d);
		p=*top;
		*top=(*top)->next;
		free(p);
	}
	else
	printf("empty");
}
void show(s *tp)
{
		if(tp==NULL)
			printf("empty");
		else
		{
		while(tp!=NULL)
		{
		printf("%d  ",tp->d);
		tp=tp->next;
		}
		}
}
