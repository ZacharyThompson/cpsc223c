#include <stdio.h> 
 
int check(int num) 
{ 
    if (num % 2 == 0) 
        goto A; 
    else 
        goto B; 
 
A: 
    num += 2; 
B: 
    num -= 1; 
    goto C; 
C: 
    return num; 
} 
 
int main() { 
    int num = 0; 
    scanf("%d", &num); 
    printf("%d\n", check(num)); 
}
