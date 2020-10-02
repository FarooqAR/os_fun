#ifndef MY_Q_H
#define MY_Q_H

struct node {
	int val;
	struct node *next;
};


// enqueue'd at tail
void enqueue (struct node ** headaddr, int val );
// dequeue'd from head
int dequeue (struct  node **headaddr);

void print (struct node * head);
#endif
