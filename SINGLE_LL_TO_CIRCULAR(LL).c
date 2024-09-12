//ALL OTHER SAME AS QUEUE
void dis(q *f,q *r)
{
	if(f==NULL)
		printf("empty");
	else
	{
		while((f)!=r)
		{
			printf("%d ",(f)->d);
			f=f->next;
		}
		printf("%d  ",f->d);
		
	}
}
q* con(q *f)
{
	q *temp=f;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=f;
	return temp;
}
