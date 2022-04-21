#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#define QUEUE struct queue
QUEUE
{  int info;
	QUEUE *next;
 };

extern void insert(QUEUE **q, int item);
extern int take_out(QUEUE **q, int *error);

void insert(QUEUE **q, int item)
{
	 QUEUE *current = *q;
	 QUEUE *previous = 0;
	 QUEUE *new_node;
 while ( current)
 {
	previous = current;
	current = current -> next;
  }
  new_node = ( QUEUE * ) malloc( sizeof( QUEUE) );
  new_node -> info = item;
  if (previous )
  {new_node -> next = previous -> next;
	previous -> next = new_node;
  }
  else
  {
	*q = new_node;
	(*q) -> next = 0;
  }
 }
 int take_out(QUEUE  **q, int *error )
 {
  int value = 0;
  QUEUE *old_header = *q;
  if (*q)
	{ value = old_header -> info;
		*q = (*q) -> next;
		free( old_header );
		*error = 0;
	 }
	else
		*error = 1;
  return value;
 }
void main()
{
 int error;
 QUEUE *q1=0, *q2=0;
 insert(&q1, 12);
 insert(&q1, 13);
 insert(&q1, 14);
 insert(&q2, take_out( &q1, &error ));
 insert(&q2, take_out( &q1, &error ));
 insert(&q2, take_out( &q1, &error ));
 printf("\nremove( &q2 ) = %d", take_out(&q2, &error));
 printf("\nremove( &q2 ) = %d", take_out(&q2, &error));
 printf("\nremove( &q2 ) = %d", take_out(&q2, &error));
 }


