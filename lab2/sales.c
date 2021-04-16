#include <stdio.h>

int main() {
	float day1, day2, day3;
	printf("Enter the sales for day 1: ");
	scanf("%f", &day1);
	printf("Enter the sales for day 2: ");
	scanf("%f", &day2);
	printf("Enter the sales for day 3: ");
	scanf("%f", &day3);

	float total = day1 + day2 + day3;

	printf("Sales Amounts\n------------------\n");
	printf("Day 1:%10.2f\n", day1);
	printf("Day 2:%10.2f\n", day2);
	printf("Day 3:%10.2f\n", day3);
	printf("Total:%10.2f\n", total);

	return 0;
}
