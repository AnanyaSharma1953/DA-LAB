void enq(l **f,l **r)
{
	l *p=NULL;
    p=(l*)malloc(sizeof(l));
    printf("enter element");
    scanf("%d",&p->d);
    p->next=NULL;
    p->prev=NULL;
    if(*f==NULL&&*r==NULL)
    {
        *f=*r=p;
    }
    else if((*r)->d<p->d)
    {
        p->prev=*r;
        (*r)->next=p;
        *r=p;
    }
    else if(p->d<(*f)->d)
    {
        (*f)->prev=p;
        p->next=*f;
        *f=p;
    }
    else
    {
        l *pp=NULL;
        pp=*f;
        while(pp->next->d<p->d)
        {
           pp=pp->next;
        }
        p->prev=pp;
        pp->next->prev=p;
        p->next=pp->next;
        pp->next=p;
    }
}
