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
int min(t* root)
{
	if(root->left==NULL)
	return (root->d);
	min (root->left);
}
