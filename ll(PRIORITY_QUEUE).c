#define max 10
#include<stdlib.h>
#include<stdio.h>
typedef struct l
{
	int d;
	int ptr;
	struct l *next;
}q;
void enq(q**,q**);
void deq(q**,q**);
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
				deq(&f,&r);
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
		scanf("%d",&p->ptr);
		p->d=x;
		if(*f==NULL&&*r==NULL)
			*f=*r=p;
		else
		{
			(*r)->next=p;
			*r=p;
		}
		(*r)->next=NULL;
	}
	
}
void deq(q **f, q **r) {
    q *p = NULL;
    if (*f == NULL) {
        printf("empty\n");
        return;
    }

    // Step 1: Find the maximum ptr value in the queue
    p = *f;
    int m = p->ptr;
    q *maxNode = p; // Start by assuming the front has the max value
    while (p != NULL) {
        if (p->ptr > m) {
            m = p->ptr;
            maxNode = p; // Update maxNode when a larger value is found
        }
        p = p->next;
    }

    // Step 2: Handle case when max node is at the front of the queue
    if ((*f)->ptr == m) {
        q *temp = *f;
        *f = (*f)->next;
        if (*f == NULL) {
            *r = NULL; // If front becomes NULL, the rear should also be NULL
        }
        printf("%d \n", temp->d);
        free(temp);
    }
    // Step 3: Handle case when max node is at the rear of the queue
    else if ((*r)->ptr == m) {
        p = *f;
        while (p->next != *r) {
            p = p->next;
        }
        printf("%d \n", (*r)->d);
        free(*r);
        p->next = NULL;
        *r = p;
    }
    // Step 4: Handle case when max node is somewhere in the middle
    else {
        p = *f;
        while (p->next != NULL && p->next != maxNode) {
            p = p->next;
        }
        if (p->next == maxNode) {
            q *temp = maxNode;
            p->next = maxNode->next;
            printf("%d \n", temp->d);
            free(temp);
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
