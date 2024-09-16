void dis(q *f,q *r)
{
    q *x=NULL,*y=NULL;
    x=f;int c=0;
    y=r;
    q *u=NULL;
    u=f;
    while(u!=NULL)
    {
        c++;
        u=u->next;
    }
    int m=c/2;
	if(f==NULL)
		printf("empty");
	else
	{
	    
		while(m!=0)
		{
		   m--;
			printf("%d ",x->d);
			x=x->next;
			printf("%d ",y->d);
			y=y->prev;
		}
	    if(c%2!=0)
	    printf("%d ",x->d);
	}
		
	
}
