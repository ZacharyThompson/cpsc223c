/*
Define the macro lowest that returns the smallest number
Define the macro line that returns y with the formula y = mx+b
 -Test your macro with the following: call line(m + 1, x + 1, b)
Define the macro swap(t,x,y) that interchanges two arguments of type t. (Block structure will help.)
*/

#include <stdio.h>

#define dprint(expr) printf(#expr " = %d\n", expr)
#define cprint(expr) printf(#expr " = %c\n", expr)

#define lowest(A,B) ((A) < (B) ? (A) : (B))
#define line(m,x,b) (m)*(x)+(b)
#define swap(t,x,y) \
{\
	t temp = x;\
	x = y;\
	y = temp;\
}

int main() {
	puts("Lowest:");
	int a = 25, b =19, low;
	dprint(a);
	dprint(b);
	low = lowest(a,b);
	dprint(low);

	puts("Line:");
	int M = 2, X = 5, B = 10;
	dprint(M);
	dprint(X);
	dprint(B);
	int y = line(M,X,B);
	dprint(y);

	puts("Swap int:");
	int var1 = 56, var2 = 123;
	dprint(var1);
	dprint(var2);
	swap(int, var1, var2);
	dprint(var1);
	dprint(var2);

	puts("Swap char:");
	char c1 = 'X', c2 = 'F';
	cprint(c1);
	cprint(c2);
	swap(char, c1, c2);
	cprint(c1);
	cprint(c2);

	return 0;
}
