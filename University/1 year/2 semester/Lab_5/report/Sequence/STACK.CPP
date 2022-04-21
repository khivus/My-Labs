#include <alloc.h>
#include <stdio.h>
#define STACK struct stack
STACK
{
  int info;
  STACK *next;
};
 void push (STACK **s, int item);
 int pop (STACK **s, int *error);
 int peek (STACK *s, int *error);

 void push (STACK **s, int item)
 {
  STACK *new_item;
	 new_item = (STACK*) malloc(sizeof(STACK));
	 new_item ->info=item;
	 new_item ->next=*s;
	 *s =new_item;
 }
 int pop (STACK **s, int *error)
 {
 STACK *old_item = *s;
 int old_info = 0;
 if(*s)
 {old_info =old_item ->info;
 *s =(*s)->next;
 free(old_item);
 *error=0;
 }
 else
 *error=1;
 return (old_info);
 }
 int peek (STACK **s, int *error)
 {
 if(*s)
 {*error=0;
 return(*s)->info;
 }
 else
 {
	*error =1;
	return 0;
 }
 }
void main()
{
  STACK *s1, *s2;
  int error;
  push( &s1, 12);
  printf("\npeek( s1 ) =%d", peek( &s1, &error ));
  push( &s1, 13);
  printf("\npeek( s1 ) =%d", peek( &s1, &error ));
  push( &s1, 14);
  printf("\npeek( s1 ) =%d", peek( &s1, &error ));
     push( &s2, pop( &s1, &error));
     push( &s2, pop( &s1, &error));
     push( &s2, pop( &s1, &error));
  printf("\npop( &s2 ) =%d", pop( &s2, &error ));
  printf("\npop( &s2 ) =%d", pop( &s2, &error ));
  printf("\npop( &s2 ) =%d", pop( &s2, &error ));
}



