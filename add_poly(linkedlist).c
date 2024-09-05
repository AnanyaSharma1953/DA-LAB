#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
	int ex;
	int c;
	struct list *next;	
}l;
l* insert_last(l*);
void dis(l*);
l* add(l*,l*);
main()
{
	l *f1=NULL,*p1=NULL,*a=NULL;
	int c=0;
	l* f2=NULL,*p2=NULL;
	do{
	printf("enter 1: insert at last \n 2;insert at first node \n 3:display\n \n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			f1=insert_last(f1);
			if(p1==NULL)
			p1=f1;
			break;
		case 2:
			f2=insert_last(f2);
			if(p2==NULL)
			p2=f2;
			break;
		case 3:
			dis(p1);
			break;
		case 4:
			dis(p2);
			break;
		case 5:
			a=add(p1,p2);
			break;
case 6:
	dis(a);
break;
}
	}while(c<=6);
}
l* insert_last(l *pt)
{
	l *p=NULL;
	p=(l*)malloc(sizeof(l));
	if(p!=NULL)
	{
	int x,e;
	printf("enter val");
	scanf("%d%d",&x,&e);
	p->c=x;
p->ex=e;
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
void dis(l *p)
{
	while(p!=NULL)
	{
		printf("%dx^%d  ",p->c,p->ex);
		p=p->next;
	}
}
l* add(l *f1, l *f2) {
    l *result = NULL, *tail = NULL;

    while (f1 != NULL || f2 != NULL) {
        l *new_node = (l*)malloc(sizeof(l));
        if (new_node == NULL) {
            printf("Memory allocation failed.\n");
            return NULL;
        }

        new_node->next = NULL;

        if (f1 == NULL) {
      
            new_node->c = f2->c;
            new_node->ex = f2->ex;
            f2 = f2->next;
        } else if (f2 == NULL) {
           
            new_node->c = f1->c;
            new_node->ex = f1->ex;
            f1 = f1->next;
        } else if (f1->ex == f2->ex) {
         
            new_node->c = f1->c + f2->c;
            new_node->ex = f1->ex;
            f1 = f1->next;
            f2 = f2->next;
        } else if (f1->ex > f2->ex) {
            
            new_node->c = f1->c;
            new_node->ex = f1->ex;
            f1 = f1->next;
        } else {
        
            new_node->c = f2->c;
            new_node->ex = f2->ex;
            f2 = f2->next;
        }

        if (result == NULL) {
            result = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    return result;
}
