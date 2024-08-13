#include<stdio.h>
#define max 10
#include<stdlib.h>
int inser(int[],int,int);
int del(int[],int);
void show(int[],int);
void peek(int[],int);
int main()
{
	int t1=-1,t2=(max/2)-1;int ch;
	int m1=max/2;
	int m2=max;
	int arr[max];
	do
	{
		printf("1:insert in s1  \n 2:insertin s2\n 3:delin s1 \n 4:delin s2 \n 5:dis s1\n6: dis in s2 \n 7: peek in s1 \n 8: peek in s2 \n 		 9:exit\n");
		scanf("%d",&ch);
		
  	switch(ch)
  	{
  	
  		case 1:
  			t1=inser(arr,t1,m1);
  			break;
  		case 2:
  			t2=inser(arr,t2,m2);
  			break;
  		case 3:
  			t1=del(arr,t1);
  			break;
  		case 4:
  			t2=del(arr,t2);
  			break;
  		case 5:
  			show(arr,t1);
  			break;
  		case 6:
  		 	show(arr,t2);
  		 	break;
  		 case 7:
  		 	peek(arr,t1);
  		 	break;
  		 case 8:
  		 	peek(arr,t2);
  		 	break;
  		 case 9:
  		 	exit(0);
		default:
			printf("invalid");
  	}
  	}while(ch<=9);
  	return 0;
}
int inser(int a[],int top,int m)
{
	if(top==m-1)
		printf("overflow");
	else
	{
    	top++;
       printf("insert elements");
       scanf("%d",&a[top]);
       }
       
       return top;
}
int del(int a[],int top)
{
	if(top==-1)
		printf("underflow");
	else
	{
	
	printf("delelted ele is = %d",a[top]);top--;
}
	return top;
}
void peek(int stack[],int top)
{
   int x;
   if(top==-1)
   	printf("stack is empty");
   else
   {
   printf("%d",stack[top]);
}
}
void show(int stack[],int top)
{
	int i;
	if(top<=(max/2))
	{
	
	for(i=top;i>=0;i--)
		printf("%d ",stack[i]);
	}
	else
	
	{
	for(i=top;i>=(max/2);i--)
		printf("%d ",stack[i]);
	
	}
}
		
