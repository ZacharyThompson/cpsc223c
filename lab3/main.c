#include <stdio.h>

int main() {
	int c, i;
	int char_count = 0;
	int nchar[10];

	for(i = 0; i < 10; i++) {
		nchar[i] = 0;
	}

	while((c = getchar()) != 'q') {
		if(c != ' ' && c != '\n' && c != '\t') // if c is not whitespace
			++char_count;
		else if (char_count > 0) { // prevent negative address
			++nchar[char_count-1];
			char_count = 0;
		}
	}

	int j;
	for (i = 0; i < 10; i++) {
		printf("%d:", (i+1));
		for (j = 0; j < nchar[i]; j++)
			printf("=");
		printf("\n");
	}

	return 0;
}
