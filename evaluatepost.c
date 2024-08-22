#include<stdio.h>
#include<stdlib.h>
#define max 100
void push(int[],int,int*);
int pop(int[],int*);
int po(int,int);
int main()
{
	int i=0,pos=0,top=-1;
	int stack[max];
	char ch;
  	char postfix[max];	
  	printf("enterarray");
  	scanf("%s",postfix);
  	while(postfix[i]!='\0')
  	{
  		ch=postfix[i++];
  		if(ch=='^'||ch=='*'||ch=='/'||ch=='%'||ch=='+'||ch=='-')
  		{
            		int x=pop(stack,&top);
            		int x1=pop(stack,&top);
            		int res=0;
            		switch(ch)
            		{
            			case '+':
            				res=x1+x;
            				break;
            			case '-':
            				res=x1-x;
            				break;
            			case '*':
            				res=x1*x;
            				break;
            			case '/':
            				res=x1/x;
            				break;
            			case '^':
            				res=po(x1,x);
            				break;
            		}
            		push(stack,res, &top);
        	}
        	else
        	{
        		int m=0;
        		printf("enter value of %c",ch);
        		scanf("%d",&m);
        		push(stack,m,&top);
        	}	
        	
    	}
  	printf("%d", stack[top]);
	return 0;
}
void push(int stack[],int ch,int *top)
{
	
    	(*top)++;
        stack[*top]=ch;
       
}
int pop(int a[],int *top)
{ char c;
	
	c=a[*top];
	(*top)--;
	int y=c-'0';
	
	
	return c;
}
int po(int a,int b)
{
	int r=1;
	while(b>=1)
	{r=r*a;
	b--;
	}
	return r;
}
