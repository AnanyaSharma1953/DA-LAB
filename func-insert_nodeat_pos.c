void in(q **lo)
{
	int x=0,y=0;
	q *p=NULL;
	printf("enter pos ");
	scanf("%d",&x);
	printf("enter val");
	scanf("%d",&y);
	int c=0;
	q *i=*lo;
	p=(q*)malloc(sizeof(q));
	while((c)!=(x-1))
	{
		c++;
		i=i->next;
	}
	p->d=y;
	q *j=i->next;
	i->next=p;
	p->prev=i;
	p->next=j;
	j->prev=p;
}
