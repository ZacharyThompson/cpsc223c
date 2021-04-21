#include <stdio.h>

/* atoi: convert s to integer */
int atoi(char s[]) {
	int i, n;
	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0'); //ascii code offset
	return n;
}

// check if string is a number
int isnumber(char s[]) {
	int i;
	for(i = 0; s[i] != '\0'; i++) {
		if (s[i] < '0' || s[i] > '9')
			return 0;
	}
	return 1;
}

// return result of given operation
int op(int operand1, int operator, int operand2) {
	switch (operator) {
		case '+':
			return operand1 + operand2;
		case '-':
			return operand1 - operand2;
	}
	return 0;
}

int main(int argc, char *argv[]) {
	int answer, operand, operator;
	int i;

	if (argc < 2) {
		puts("ERROR: provide arguments");
		return 1;
	}

	// check if first thing is a number
	if (!isnumber(argv[1])) {
		puts("ERROR: missing operand");
		return 1;
	}
	answer = atoi(argv[1]); // answer is initially set to the first number

	for(i = 2; i < argc; i++) {
		// if index is odd
		if (i % 2 == 1) {
			// check if argument is a number
			if (!isnumber(argv[i])){
				puts("ERROR: missing operand");
				return 1;
			}
			operand = atoi(argv[i]);
			answer = op(answer, operator, operand); // new answer = old answer +/- operand
		} else {
			// check if argument is an operator and is correct size
			if (argv[i][0] != '+' && argv[i][0] != '-' || argv[i][1] != '\0' ){
				puts("ERROR: missing operator");
				return 1;
			}
			operator = argv[i][0];
		}
	}

	// check if there is a number at the end. i will be odd if it is not true.
	if(i%2 == 1) {
		puts("ERROR: missing operand");
		return 1;
	}

	printf("%d\n", answer);

	return 0;
}
