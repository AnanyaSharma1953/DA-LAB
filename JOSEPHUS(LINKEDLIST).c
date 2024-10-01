
#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
	int d;
	struct list * next;
}s;
void inser(s**,s**);
void kill(s*,int);
//void disp(s*);
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
			/*case 2:
				disp(f);
				break;
				*/
			case 3:
				kill(f,2);
		}
	}while(ch<=3);	
}
//RECURSIVE
void kill(s* f, int k) {
    if (f->next == f) {
        printf("The survivor is person number %d\n", f->d);
        free(f); 
        return;
    } else {
        s* t = f;
        int y = 1;
        while (y < k-1) {
            y++;
            t = t->next;
        }
        s* to = t->next;
        t->next = to->next;
        printf("Person number %d is eliminated.\n", to->d);
        free(to);
        kill(t->next, k);
    }
}
/*NORMAL ITERATIVE
void kill(s* f, int k) 
{
    while (f->next != f) 
    {
        s* t = f;
        int y = 1;
        while (y < k-1) 
	{
            y++;
            t = t->next;
        }
        s* to = t->next;
        t->next = to->next;
        printf("Person number %d is eliminated.\n", to->d);
        free(to);
		f=t->next;
    }
    printf("The survivor is person number %d\n", f->d);
}
*/
void inser(s **f,s **r)
{
	s *p=NULL;
	p=(s*)malloc(sizeof(s));
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
