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
	int size, i;
	puts("How many numbers are in the list?");
	scanf("%d", &size);
	
	node *list1 = create_list();
	int val;
	for(i = 0; i < size; i++) {
		puts("Enter a num");
		scanf("%d", &val);
		if (i == 0)
			list1->value = val;
		else
			list1 = add_to_head(list1, val);
	}

	print_list(list1);
	delete_list(list1);

	return 0;
}
