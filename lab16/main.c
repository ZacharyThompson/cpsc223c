#include <stdio.h>
double rectprism(double l, double w, double h) {
	return (l*w*h);
}

double pyramid(double l, double w, double h) {
	return (l*w*h*(1.0/3.0));
}

double ellipsoid(double l, double w, double h) {
	return (l*w*h*(4.0/3.0)*3.14);
}

int main() {
	double length, width, height;

	// declare funtion pointer array
	double (*func_ptr_arr[])(double, double, double) = {rectprism, pyramid, ellipsoid};

	puts("Enter Length: ");
	scanf("%lf", &length);

	puts("Enter Width: ");
	scanf("%lf", &width);

	puts("Enter Height: ");
	scanf("%lf", &height);

	int input;
	double result;

	// Keep asking user for input until they want to quit
	while (1) {
		puts("Select volume to calculate: ");
		puts("1 - Volume of a Rectangular Prism.");
		puts("2 - Volume of a Pyramid.");
		puts("3 - Volume of an Ellipsoid.");
		puts("q - Quit.");

		while((getchar()) != '\n'); // clear input buffer
		input = getchar();

		// Check if they want to quit or if input is invalid
		if(input == 'q') {
			break;
		} else if(input < '1' || input > '3') {
			puts("Error: Invalid Input");
			continue;
		}

		input = input - '0'; // convert input into a regular integer, not ascii

		result = (*func_ptr_arr[input-1])(length, width, height);
		printf("Volume = %lf\n\n", result);
	}

	return 0;
}
