#include <alloc.h>
#include <stdio.h>
#include <conio.h>
#define LIST struct list
LIST{
 int info;
 LIST* next;
 LIST* prev;
};

void add(LIST **i,
         LIST **start,
         LIST **last,
         int n);

void del(LIST **i,
         LIST **start,
         LIST **last,
         int *error);

void main()
{
 LIST *i=NULL;
 LIST *start=NULL;
 LIST *last=NULL;
 int error;

 clrscr();
 add(&i,&start,&last,12);
 add(&i,&start,&last,13);
 add(&i,&start,&last,14);
 add(&last,&start,&last,15);
 add(&start,&start,&last,16);
 del(&last,&start,&last,&error);
 del(&start,&start,&last,&error);
 i=i->prev;
 del(&i,&start,&last,&error);
 del(&i,&start,&last,&error);
 del(&i,&start,&last,&error);
 del(&i,&start,&last,&error);
}

void add(LIST **i,
         LIST **start,
         LIST **last,
         int n)
{
 LIST *new_node;
 new_node=(LIST*)malloc(sizeof(LIST));
 new_node->info=n;
 if (*start==NULL)
  {
	*start=new_node;
	*last=new_node;
	new_node->next=NULL;
	new_node->prev=NULL;
	*i=new_node;
  }
 if ((*i)->next!=NULL)
  {
	new_node->next=(*i)->next;
	(*i)->next->prev=new_node;
	new_node->prev=*i;
	(*i)->next=new_node;

  }
  else
	{
	 (*last)->next=new_node;
	 new_node->prev=*last;
	 new_node->next=NULL;
	 (*last)=new_node;
	 *i=new_node;
	}

}

void del(LIST **i,
         LIST **start,
         LIST **last,
         int *error)
{
 LIST *old_node=*i;
 if ((*start==NULL)||(*last==NULL)||(*i==NULL)) *error=1;
 else
  {
	if (*i==*start)
	 {
	  *i=(*i)->next;
	  *start=*i;
	  if (*i) (*i)->prev=NULL;
	 }
	else
	 if (*i==*last)
	  {
		(*i)=(*i)->prev;
		*last=*i;
		(*i)->next=NULL;
	  }
	 else
	  {
		(*i)->prev->next=(*i)->next;
		(*i)->next->prev=(*i)->prev;
		(*i)=(*i)->next;
	  }
	*error=0;
	free(old_node);
  }
}
