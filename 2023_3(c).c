void del(l** p,l**r)
{
	if(*p==NULL)
        printf("empty");
    else{
        l *pp=*p;
        l *ll=NULL;
        while(pp!=NULL && pp->next!=NULL)
        {
            ll=pp;
            if(pp->d==pp->next->d)
            {
                pp->next=pp->next->next;
            }
            
                pp=pp->next;
            
        }
        *r=ll;
    }
}
