#include <stdio.h> 
 
//This program asks users for numbers and finds the sum and average of those numbers
int main() { 
 
   const int maxInput = 100; //Max amount of numbers that can be inputted
   int i; 
   double number, average, sum = 0.0; 
 
   //Ask user for numbers until counter == maxInput 
   for (i = 1; i <= maxInput; ++i) {
      printf("%d. Enter a number: ", i); 
      scanf("%lf", &number); 
 
 
      if (number < 0.0) { //If user inputs a negative number exit the loop
         break;
      } 
      sum += number; //Add inputted number to sum
   }
   average = sum / (i - 1); //Calculate average
   printf("Sum = %.2f\n", sum); 
   printf("Average = %.2f", average); 
 
   return 0;
}
