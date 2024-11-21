int total(t *root)
{
    if (root == NULL) 
    {
        return 0;
    }
    return 1 + total(root->left) + total(root->right);
}
int max(t* root)
{
	if(root->right==NULL)
	{
		return (root->d);
	}
	max(root->right);
}
//non-recursive to find max ele
/*
int maxt(t * root)
{
	if(root==NULL)
	return 0;
	else
	{
		while((root->right)!=NULL)
		{
			root=root->right;
		}
		return (root->d);
	}
}
*/
int min(t* root)
{
	if(root->left==NULL)
	return (root->d);
	min (root->left);
}
void count_leaf(t *root,int *c)
{
	if(root==NULL)
	{
	return;
	}
	else
	{
		if(root->right==NULL&&root->left==NULL)
		{
			*c=(*c)+1;
		}
		count_leaf(root->left,c);
		count_leaf(root->right,c);
	}
}
void count_single(t *root,int *ct)
{
	if(root==NULL)
	{
	return;
	}
	else
	{
		if((root->right!=NULL&&root->left==NULL)||(root->right==NULL&&root->left!=NULL))
		{
			*ct=(*ct)+1;
		}
		count_single(root->left,ct);
		count_single(root->right,ct);
	}
}
