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
t* del(t*,int);
t* mint(t*);
int main()
{
	t *root=NULL;
	int ch;
	do
	{
        int num=0,n=0;
		printf("enter ch");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				scanf("%d",&num);
				insert(&root,num);
				break;
			case 2:
				inorder(root);
				break;
			case 3:
            scanf("%d",&n);
				root=del(root,n);
                printf("root is %d",root->d);
				break;
		}
	}while(ch<=4);
}
t* del(t* root,int key)
{
    if(root==NULL)
    {
        return root;
    }
    else if(key<(root->d))
    root->left=del(root->left,key);
    else if(key>(root->d))
    root->right=del(root->right,key);
    else
    {
        if(root->left==NULL)
        {
            t* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            t* temp=root->left;
            free(root);
            return temp;
        }
        t* temp=mint(root->right);
        root->d=temp->d;
        root->right=del(root->right,temp->d);
    }
    return root;
}
t* mint(t* node)
{
    t* curr=node;
    while(curr!=NULL && curr->left!=NULL)
    curr=curr->left;
return curr;
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
}
