#include <alloc.h>
#include <stdio.h>
#include <conio.h>
#define LIST struct list
LIST{
 int info;
 LIST* next;
};

void add(LIST **i,
         LIST **start,
         int n);

void del(LIST **i,
         LIST **start,
         int *error);

void main()
{
 LIST *i=NULL;
 LIST *start=NULL;
 int error;

 clrscr();
 add(&i,&start,12);
 add(&i,&start,13);
 add(&i,&start,14);
 add(&i,&start,15);
 del(&i,&start,&error);
 i=i->next;
 add(&i,&start,16);
 del(&i,&start,&error);
 add(&i,&start,17);
 i=i->next;
 del(&i,&start,&error);
 i=i->next;
 del(&i,&start,&error);
 del(&i,&start,&error);
 del(&i,&start,&error);
}

void add(LIST **i,
         LIST **start,
         int n)
{
 LIST *new_node;
 new_node=(LIST*)malloc(sizeof(LIST));
 new_node->info=n;
 if (!*start)
  {
	*start=new_node;
	new_node->next=*start;
  }
 else
  {
	new_node->next=(*i)->next;
	(*i)->next=new_node;
  }
  *i=new_node;
}

void del(LIST **i,
         LIST **start,
         int *error)
{
 LIST *previous=*start;
 if (*start==NULL)
 {
  *error=1;
 }
 else
  if ((*start)->next==*start)
    {
   free(*start);
   *start= NULL;
   *i=*start;
   *error=0;
    }
    else
   {
    while (previous->next!=*i) previous=previous->next;
    previous->next=(*i)->next;
    free(*i);
    if (*start==*i) *start=previous;
    *i=previous;
    *error=0;
   }
}
