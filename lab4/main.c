#include <stdio.h>

int main() {
	unsigned long n1 = 1, n2 = 1;
	int i;
	unsigned int elements;

	printf("Please enter the number of elements to be generated.\n");
	scanf("%d", &elements);

	printf("The first %d elements of the Fibonacci sequence are:\n", elements);

	printf("%ld ", n1);
	printf("%ld ", n2);

	for (i = 0; i < elements; i++) {
		unsigned long n3 = n1 + n2;
		printf("%ld ", n3);
		n1 = n2;
		n2 = n3;
	}
	putchar('\n');

	return 0;
}
