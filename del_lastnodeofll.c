void deq(q **f)
{
	q *p=NULL;
	p=(q*)malloc(sizeof(q));
	q *o=NULL;
	o=*f;
	while((o->next->next)!=NULL)
	{
		(o)=(o)->next;
	}
	p=o->next;
	o->next=NULL;
		printf("%d  ",p->d);
	free(p);
}
