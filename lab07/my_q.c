#include <stdio.h>
#include <stdlib.h>
#include "my_q.h"

// enqueue'd at tail
void enqueue (struct node ** headaddr, int val ) {
	if (headaddr==NULL){
		fprintf(stderr, "NULL ptr passed\n"); exit(1);
	}


	struct node * n = malloc(sizeof(struct node));
	if (n==NULL){
		fprintf(stderr, "memory allocation failed\n"); exit(1);
	}
	n->val = val;
	n->next = NULL;


	if( *headaddr==NULL){ // empty list
		*headaddr = n;
	}
	else {
		// get to tail
		struct node *tmp = *headaddr;
		while (tmp->next != NULL)
			tmp = tmp->next;

		tmp->next = n;
	}
}
		
	
// dequeue'd from head
int dequeue (struct  node **headaddr) {
	
	if (headaddr==NULL){
		fprintf(stderr, "NULL ptr passed\n"); exit(1);
	}

	if (*headaddr==NULL) { // list is empty
		return -1;
	}
	else {
		struct node *n = *headaddr;
		*headaddr = (*headaddr)->next;
		int val = n->val;
		free(n);
		return val;
	}
}


void print (struct node * head) {
	if (head==NULL)
		fprintf(stdout, "empty queue\n");

	else {
		while (head!=NULL){
			fprintf(stdout, "%d,", head->val);
			head = head->next;
		}
		fprintf(stdout, "\n");
	}
}
