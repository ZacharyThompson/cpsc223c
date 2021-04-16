 
#include <stdio.h> 
 
int main() 
{ 
	int h = 500, count = 0; 

	printf("All the numbers from %i to zero\n", h); 
	puts("not divisible by 2, 3, 5 or 7:\n"); 
 
	do { 
		if ( (h % 2 != 0) && (h % 3 != 0) && (h % 5 != 0) && (h % 7 != 0) ) {
			printf("%5i", h); 
			count++; 
			if (count % 10 == 0)  /* print 10 per line */ 
				putchar('\n'); 
		}
	} while (h--); 
	putchar('\n');
	return 0;
}
