#include <stdio.h>

char street[40], city[40], state[2];
int house_num, zip;

int main() {
	while (1) {
		printf("Enter your street: ");
		scanf("%39[^\n]s", street);
		while((getchar()) != '\n');

		printf("Enter your house or apartment number: ");
		scanf("%d", &house_num);
		while((getchar()) != '\n');

		printf("Enter your city: ");
		scanf("%39[^\n]s", city);
		while((getchar()) != '\n');

		printf("Enter your zipcode: ");
		scanf("%d", &zip);
		while((getchar()) != '\n');

		printf("Enter your state: ");
		scanf("%39[^\n]s", state);
		while((getchar()) != '\n');

		printf("%d %s, %s, %s %d\n", house_num, street, city, state, zip);

		printf("Would you like to enter another address? Enter y or n: \n");
		char cont = getchar();
		while((getchar()) != '\n');
		if (cont == 'n'){
			break;
		}
	}
	return 0;
}
