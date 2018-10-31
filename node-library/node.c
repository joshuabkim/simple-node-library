#include "node.h"

/**
 * The add function inserts a new data node at the
 * front of the linked list. It takes in two parameters:
 * a pointer to a node_t struct, which points to the head
 * and an int for the new data attribute tbat will be 
 * added before the head reference. 
 */ 
node_t* add(node_t *head, int data) {
	
	node_t *tmp = (node_t *)malloc(sizeof(node_t));
	if(tmp == NULL) {
		exit(0);
	}
	
	tmp->data = data;
	tmp->next = head;
	head = tmp;
	return head;
} 

/**
 * The add_at() function inserts a new data node at the 
 * specified index. It takes in three parameters: a pointer 
 * to a node_t struct, which refers to the head, an int for 
 * the new data attribute, and another int for the specified
 * index. Indexes are 0 based and if the given index is out
 * of bounds, the function will print a message via stderr. 
 */
node_t* add_at(node_t *head, int data, int index) {

	if(index < 0) {
		exit(0);
	}

	if(head == NULL) {
		head = (node_t *)malloc(sizeof(node_t));
		head->data = data;
		return head;
	} else {
		int i;
		node_t *curr = head, *prev = NULL;
		for(i=0; i<index; i++) {
			if(curr == NULL) {
				exit(0);
			}
			prev = curr;
			curr = curr->next;
		}

		if(prev == NULL) {
			node_t *newhead = (node_t *)malloc(sizeof(node_t));
			newhead->data = data; 
			newhead->next = curr;
			return newhead;
		} else {
			node_t *newnode = (node_t *)malloc(sizeof(node_t));
			newnode->data = data;
			newnode->next = curr;
			prev->next = newnode;
			return head;
		}
		
	}
}

/**
 * The remove_node() function deletes the head of a given
 * linked list. It takes in one parameter: a double pointer 
 * to the head of the linked list.
 */
void remove_node(node_t **head) {

	if(*head != NULL) {
		node_t *tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}	
} 

/**
 * The print_list() function traverses the linked list and
 * prints each data point. It takes in one parameter: a node_t 
 * pointer, which refers to the head of the list. If the list 
 * is empty, a message is printed via stderr.
 */
void print_list(node_t *head) {

	if(head == NULL) {
		fprintf(stderr, "error: head is NULL\n");
		exit(0);
	}
	
	node_t *tmp;
	for(tmp = head; tmp != NULL; tmp = tmp->next) {
		printf("%i -> ", tmp->data);
	}
	printf("null\n");
}

/**
 * The free_list() function deallocates every data node in a given
 * list. It takes in one parameter: a node_t double pointer, which
 * is a pointer to the pointer to the head. If the reference is empty,
 * a message is printed via stderr. 
 */ 
void free_list(node_t **head) {

	if(*head == NULL) {
		fprintf(stderr, "error: head is NULL\n");
		exit(0);
	}

	node_t *tmp;
	while(*head != NULL) {
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}
