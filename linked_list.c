#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node
{
	int value;    // int variable
	node* next;   // pointer variable for storing address of the next node 
};

void print(node* header);
void add(node* header, int position, int x);
void delete(node* header, int position);
node* access(node* header, int position);
int main(void)
{
	// initialize list : [5,2,10]
	node* header = (node*)malloc(sizeof(node)*4);
	header->value = 3; header->next = (header + 1);   // header->value : list size
	(header + 1)->value = 5; (header + 1)->next = (header + 2);
	(header + 2)->value = 2; (header + 2)->next = (header + 3);
	(header + 3)->value = 10;
	printf("Initialize a list:\n"); print(header);

	int element; int k;

	// adding an element at the kth position
	element = 4; k = 2;
	add(header, k, element);
	printf("\nAdd an element at the 2nd position:\n"); print(header);
	
	// deleting an element at the kth position
	k = 3;
	delete(header, k);
	printf("\nDelete an element at the 3rd position:\n"); print(header);
	
	// access an element at the kth position
	element = 7; k = 2;
	access(header, k)->value = element;
	printf("\nAccess an element at the 2nd position:\n"); print(header);

	free(header);
	return 0;
}

void print(node* header)
{
	node* dummy = (node*)malloc(sizeof(node));
	dummy->next = header;

	printf("[");
	for (int i = 0; i < (header->value) - 1; i++) {
		dummy->next = dummy->next->next;
		printf("%d, ", dummy->next->value);
	}
	dummy->next = dummy->next->next;
	printf("%d]\n", dummy->next->value);

	free(dummy);
}

void add(node* header, int position, int x)   // add x at the designated position 
{
	node* new_nod = (node*)malloc(sizeof(node));
	new_nod->value = x; new_nod->next = header;

	node* dummy = (node*)malloc(sizeof(node));
	dummy->next = header;

	for (int i = 0; i < position; i++) {
		new_nod->next = new_nod->next->next;
	}

	for (int i = 0; i < position - 1; i++) {
		dummy->next = dummy->next->next;
	}
	dummy->next->next = new_nod;

	header->value++;
	free(dummy);
}

void delete(node* header, int position)   // delete element of designated position
{
	node* dummy = (node*)malloc(sizeof(node));
	dummy->next = header;

	for (int i = 0; i < position - 1; i++) {
		dummy->next = dummy->next->next;
	}

	if (position != header->value)
		dummy->next->next = dummy->next->next->next;
	else
		dummy->next->next = NULL;   // in case of deleting the last element

	header->value--;
	free(dummy);
}

node* access(node* header, int position)   // return element of designated position
{
	node* dummy = (node*)malloc(sizeof(node));
	dummy->next = header;

	for (int i = 0; i < position; i++) {
		dummy->next = dummy->next->next;
	}

	return dummy->next;
}