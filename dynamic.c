#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*

cd C:\Users\kvsha\Documents\Code\C\Dynamic Linked List
gcc -g -Wall -Wextra dynamic.c -o linklist
linklist

*/

#include "functions.h"


int main(void) {
	

	printf("welcome to dynamic linked list!\nEnter any char to exit.\n\n");

	node myNode;
	node* root = &myNode;

	int mySize = 0;
	int* size = &mySize;

	int input;
	char term;

	while (true) {
		printMenu();
		if (scanf("%i%c", &input, &term) != 2 || term != '\n') break;

		if (input == 0) { // print list
			printList(root, size);
		}

		else if (input == 1) { // add index
			int value, index;

			printf("Enter an instruction [index value]: ");
			scanf("%i %i", &index, &value);

			addValue(root, size, value, index);
		}

		else if (input == 2) { // remove index
			int index;

			printf("Enter an index to remove from LL: ");
			scanf("%i", &index);

			removeIndex(root, size, index);
		}

		else {
			printf("Command out of range! (0->2)\n");
		}
	}


	return 0;

}