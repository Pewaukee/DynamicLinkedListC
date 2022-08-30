#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdlib.h>
#include <stdio.h>

#include "node.h"

//define the method definition
void printMenu();
void printList(node* root, int* size);
void addValue(node* root, int* size, int value, int index);
void removeIndex(node* root, int* size, int index);

//create the functions bodies
void printMenu() {
	printf("0: print linked list\n");
	printf("1: insert value\n");
	printf("2: remove index\n");
}

void printList(node* root, int* size) {
	if (*size == 0) {printf("empty list\n"); return;}
	node* cur_node = root->next; // there is a dummy node at the start
	for (int i = 0; i < *size; ++i) {
		printf("%i->", cur_node->value);
		cur_node = cur_node->next;
	}
	printf("\n");
}

void addValue(node* root, int* size, int value, int index) {
	if (index < 0 || index >= *size + 1) {
		printf("Invalid index value to insert\n");
		return;
	}

	int i = 0;
	node* cur = root;

	while (i < index) {
		cur = cur->next;
		i++;
	}

	// insert new node
	node* newNode = malloc(sizeof(node));
	newNode->value = value;
	newNode->next = cur->next;
	cur->next = newNode;

	*size = *size + 1; // *size++; doesn't work, changes the value of the address or something
}

void removeIndex(node* root, int* size, int index) {
	if (index < 0 || index >= *size) {
		printf("Invalid index to remove\n");
		return;
	}

	node* prev = root; // due to dummy node
	node* cur = root->next; // due to dummy node

	int i = 0;
	while (i < index) {
		prev = cur;
		cur = cur->next;
		i++;
	}

	// delete the index using prev
	prev->next = cur->next;

	*size = *size - 1;
}

#endif