#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int value;
	struct node *next;
} node;

node *add_to_head(node *head, int value) {
	node *temp = head;
	head = (node *)malloc(sizeof(node));

	head->value = value;
	head->next = temp;
	return head;
}

node *create_list() {
	node *list = (node *)malloc(sizeof(node)); 
	list->next = NULL;
	return list;
}

void delete_list(node *head) {
	node *temp;
	while(head->next != NULL) {
		temp = head->next;
		free(head);
		head = temp;
	}
}

void print_list(node *list) {
	int i = 1;
	while(list != NULL) {
		printf("Node %d's Value is %d\n", i, list->value);
		list = list->next;
		i++;
	}
}

int main() {
	node *list1 = create_list();
	list1->value = 10;
	list1 = add_to_head(list1, 20);
	list1 = add_to_head(list1, 30);
	list1 = add_to_head(list1, 40);

	print_list(list1);
	delete_list(list1);

	return 0;
}
