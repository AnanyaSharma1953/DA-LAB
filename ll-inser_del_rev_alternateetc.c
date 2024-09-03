#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
	int d;
	struct list *next;	
}l;
l* insert_last(l*);
l* insert_first(l*);
l* insert_sec(l*);
l* del_first(l*);
l* del_sec(l*);
l* del_last(l*);
void disp_rev(l*);
l* del_secondlast(l*);
void disp_alternate(l*);
void dis(l*);
main()
{
	l *f=NULL,*pt=NULL;
	int c=0;
	do{
	printf("enter 1: insert at last \n 2;insert at first node \n 3:display\n 4:insert after first node \n 5: del first node \n 6: del second node \n 7: del last\n 8:reverse \n 9:del second last \n 10:alternate display \n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			f=insert_last(f);
			if(pt==NULL)
			pt=f;
			break;
		case 2:
			pt=insert_first(pt);
			break;
		case 3:
			dis(pt);
			break;
		case 4:
			pt=insert_sec(pt);
			break;
		case 5:
			pt=del_first(pt);
			break;
		case 6:
			pt=del_sec(pt);
			break;
		case 7:
			f=del_last(pt);
			break;
		case 8:
			disp_rev(pt);
			break;
		case 9:
			f=del_secondlast(pt);
			break;
		case 10:
			disp_alternate(pt);
			break;
	}
	
	}while(c<=10);
	
}
l* insert_last(l *pt)
{
	l *p=NULL;
	int ch;
	p=(l*)malloc(sizeof(l));
	if(p!=NULL)
	{
	int x;
	printf("enter val");
	scanf("%d",&x);
	p->d=x;
	if(pt==NULL)
	{
		pt=p;
	}
	else
	{
	   pt->next=p;
	   pt=p;
	}
	}
	pt->next=NULL;
	return pt;
}
l* insert_first(l *ptr)
{
	l *p=NULL;
	int x;
	p=(l*)malloc(sizeof(l));
	if(p!=NULL)
	{
	   scanf("%d",&x);
	   p->d=x;
	   p->next=ptr;
	   ptr=p;
	}
	  return ptr;
}
void dis(l *p)
{
	while(p!=NULL)
	{
		printf("%d  ",p->d);
		p=p->next;
	}
}
l* insert_sec(l *p)
{
	l *ptr=NULL,*p1=NULL;
	p1=p;
	p1=p1->next;
	int x;
	ptr=(l*)malloc(sizeof(l));
	if(ptr!=NULL)
	{
	   scanf("%d",&x);
	   ptr->d=x;
	   }
	   ptr->next=p->next;
	   p->next=ptr;
	  return p;
	
}
l* del_first(l * pt)
{
	l *p=NULL;
	p=pt;
	pt=pt->next;
	free(p);
	return pt;
}
l* del_sec(l* p)
{
	l* pt=p->next;
	p->next=p->next->next;
	free(pt);
	return p;
}
l* del_last(l* p)
{
	l *f=NULL;
	f=p;
	while(f->next->next!=NULL)
		f=f->next;
	f->next=NULL;
	return f;
}
void disp_rev(l* p)
{
	if(p==NULL)
		return ;
	else
	{
		disp_rev(p->next);
		printf("%d  ",p->d);
	}		
}
l* del_secondlast(l* p)
{
	l *f=NULL;
	f=p;
	while(f->next->next->next!=NULL)
		f=f->next;
	f->next=f->next->next;
	return f;
}
void disp_alternate(l* p)
{
	l *temp=p;
    int count = 0; // Counter to track node position
    while (temp != NULL)
    {
        if(count % 2 == 1) 
        { 
            printf("%d  ", temp->d);
        }
        count++;
        temp = temp->next;
    }
}
l* inser_ataparticular(l* p)
{
	int x,c=0,v=0;
	printf("\n enter x\n");
	scanf("%d",&x);
	l *f1=p,*f2=p;
	while(f1->d!=x)
	{
		c++;
		f1=f1->next;	
	}
	while(c!=1)
		f2=f2->next;
	f1=f1->next;
	printf("enter 1: before 2:after \n");
	scanf("%d",&v);
	if(v==1)
	{
		
	}
}
