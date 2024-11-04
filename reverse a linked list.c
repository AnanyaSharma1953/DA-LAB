void reverse(l **f,l** r)
{
	l *f1=NULL,*r1=NULL,*p=NULL;
	p=*f;
	f1=*f;
	r1=*f;
	int n=0;
	while(p!=NULL)
	{
		n++;
		p=p->next;
	}
	p=*f;
	int n1=n/2;
	while(n1!=0)
	{
			r1=*f;
		n1--;
		int x=1;
		while(x!=n)
		{
			r1=r1->next;
			x++;
		}
		n--;
		int y=p->d;
		p->d=r1->d;
		r1->d=y;
		p=p->next;
	}
}
