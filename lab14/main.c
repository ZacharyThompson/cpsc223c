#include <stdio.h>

#define DEBUG 0

int main() {
	double base, height, area;

#if DEBUG
	base = 2;
	height = 3;
#else
	puts("Area of a triangle.");

	puts("Enter base of triangle:");
	scanf("%lf", &base);
	while(getchar() != '\n');

	puts("Enter height of triangle:");
	scanf("%lf", &height);
	while(getchar() != '\n');
#endif

	area = 0.5 * base * height;
	printf("Area: %lf\n", area);

	return 0;
}
