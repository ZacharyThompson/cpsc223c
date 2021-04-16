#include <stdio.h> 
 
//If num is even add one, otherwise subtract one
int check(int num) 
{ 
    if (num % 2 == 0) //check if num is even
        num++;
    else
        num--;
    return num;
} 
 
//Ask user for a number, and add one if even or subtract one if odd
int main() { 
    int num = 0; 
    scanf("%d", &num); 
    printf("%d\n", check(num)); 
    return 0;
}
