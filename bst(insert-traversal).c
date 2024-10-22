#include<stdio.h>
#include<stdlib.h>
#define max 10
typedef struct tree_type
{
	int d;
	struct tree_type *left;
	struct tree_type *right; 
}t;
void insert(t**,int);
void inorder(t*);
void preorder(t*);
void postorder(t*);
int main()
{
	t *root=NULL;
	int ch;
	do
	{
		printf("enter ch");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				int num;
				scanf("%d",&num);
				insert(&root,num);
				break;
			case 2:
				inorder(root);
				break;
			case 3:
				preorder(root);
				break;
			case 4:
				postorder(root);
				break;
		}
	}while(ch<=4);
}
void insert(t**root,int num)
{

if(*(root)==NULL)
{
	
	t *p=(t*)malloc(sizeof(t));
	p->left=NULL;
	p->right=NULL;
	p->d=num;
	*root=p;	
}
else
{
if(num<(*root)->d)
	insert(&(*root)->left,num);
else if(num==(*root)->d)
	printf("not possible");
else 
insert(&(*root)->right,num);
}
}
void inorder(t* root)
{
	if(root!=NULL)
	{
	inorder(root->left);
	printf("%d   ",root->d);
	inorder(root->right);
	}
	else
	printf("empty");
}
void preorder(t* root)
{
	if(root!=NULL)
	{
	
	printf("%d   ",root->d);
	preorder(root->left);
	preorder(root->right);
	}
}
void postorder(t* root)
{
	if(root!=NULL)
	{
	postorder(root->left);
	postorder(root->right);
	printf("%d   ",root->d);
	}
}
