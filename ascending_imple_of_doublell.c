void enq(q **f,q **r)
{
	q *p=NULL;
	p=(q*)malloc(sizeof(q));
	if(p!=NULL)
	{
		int x=0;
		scanf("%d",&x);
		p->d=x;
		p->next=NULL;
		if(*r==NULL&&*f==NULL)
		{
		p->prev=NULL;
		*f=*r=p;
		return ;
		}
		else if((p->d)<((*f)->d))
		{
			p->next=*f;
			(*f)->prev=p;
			*f=p;
			(*f)->prev=NULL;	
		}
		else
		{
		 q *m = *f;
       		 while (m->next != NULL && m->next->d < x) 
       		 {
           		 m = m->next;
        	}
        	p->next = m->next;
        	if (m->next != NULL) 
        	{
            	m->next->prev = p;
        	}
        	else 
        	{  
            *r = p; 
        }
        p->prev = m;
        m->next = p;
			
		}
	}
		
}
