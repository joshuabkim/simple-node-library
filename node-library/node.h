#ifndef NODE_H_
#define NODE_H_

#include <stdlib.h>
#include <stdio.h>

/** node struct defintiion **/

typedef struct node {
	int data;
	struct node *next;
} node_t;

/** linked list functions **/
node_t* add(node_t *head, int data);
node_t* add_at(node_t *head, int data, int index);
void remove_node(node_t **head);
void print_list(node_t *head);
void free_list(node_t **head);

#endif // NODE_H_
