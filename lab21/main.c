#include <stdlib.h>
#include <stdio.h>

int main() {
	int size, i, j;

	printf("Enter how many numbers you want summed: ");
	scanf("%d", &size);
	double *arr = (double *)malloc(sizeof(double)*size);

	for(i = 0; i < size; i++) {
		printf("Enter Number %d: ", i+1);
		scanf("%lf", &arr[i]);
	}

	double sum = 0;
	for(i = 0; i < size; i++) {
		sum += arr[i];
	}
	printf("Sum: %lf\n", sum);

	double newnum;
	int found;
	for(i = 0; i < 3; i++) {
		found = 0;
		printf("Enter a number: ");
		scanf("%lf", &newnum);
		for(j = 0; j < size; j++) {
			if (newnum == arr[j]) {
				puts("Number is already in array. It won't be added.");
				found = 1;
			}
		}
		if (!found) {
			puts("Number is not in array. It will be added.");
			size++;
			arr = (double *)realloc(arr, sizeof(double)*size);
			arr[size-1] = newnum;
		}
	}

	puts("Array Contents:");
	for(i = 0; i < size; i++) {
		printf("%lf\n", arr[i]);
	}

	free(arr);
	return 0;
}
