/*WAC (MENU DRIVCEN) TOCREATE A SINGLE LIKEDLIST BY INSERTING NODES AT THE RIGHT HAND SIDE,THEN WRITE ANOTHER FUNCTION TO SORT THE LIKED LIST IN ASCENDING ORDER,PERFORM REVERSE OPEARTION ON LINKEDLIST.*/
#include <stdio.h>
#include<stdlib.h>
typedef struct linked_list
{
	int data;
	struct linked_list *next;
}ll;
void push(ll**,ll**);
void sort(ll**,ll**);
void rev(ll*);
int main()
{
	int ch;
	ll* f=NULL,* r=NULL;
	do{
	printf("1.CREATE\n2.SORT\n3.REVERSE");
	printf("ENTER YOUR CHOICE");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			push(&f,&r);
			break;
		case 2:
			sort(&f,&r);
			break;
		case 3:
			rev(f);
			break;
	}}while(ch=3);
}
void push(ll**f,ll**r)
{
	ll*p=NULL;
	int x;
	printf("ENTER DATA");
	scanf("%d",&x);
	p=(ll*)malloc(sizeof(ll));
	p->data=x;
	if (p!=NULL)
	{
		if(*r==NULL)
		{
			(*f=*r=p);
			(*r)->next=NULL;}
		else
		{
			(*r)->next=p;
			(*r)=p;
			(*r)->next=NULL;
		}
	}
}
void sort(ll**f,ll**r)
{
	ll *p=NULL,*k=NULL;
	k=*f;
	p=*f;
	int n=0;
	while(p!=NULL)
	{
		n++;
		p=p->next;
	}
	int a[n];
	p=*f;
	int i=0;
	while(p!=NULL)
	{
	a[i]=p->data;
	i++;
	p=p->next;
	}
	for(i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
		if(a[j]>a[j+1])
		{
			int t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
		}
	}
	}
	for(int j=0;j<n;j++)
	{
		(*f)->data=a[j];
		(*f)=(*f)->next;
	}
	*f=k;
			while(k!=NULL)
			{
				printf("%d ->",k->data);
				k=k->next;
			}
			
}
void rev(ll*f)
{
	if(f==NULL)
		return;
	else
	{
		rev((f)->next);
		printf("%d -> ",(f)->data);
	}
}	
