#include <stdio.h>

/* atoi: convert s to integer */
int atoi(char s[]) {
	int i, n;
	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0'); //ascii code offset
	return n;
}

int main(int argc, char *argv[]) {
	int operand, operator;
	int answer = 0;
	int i;

	for(i = 1; i < argc; i++) {
		if (i%2 == 1)
			operand = atoi(argv[i]);
		else
			operator = argv[i][0];
	}
	printf("%d\n", answer);


	return 0;
}
