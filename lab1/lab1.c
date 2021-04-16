#include <stdio.h>
#define LOWER 0 //define our lower limit
#define UPPER 300 //define jur upper limit
#define STEPP 20 //define our step
//program that converts from Celsius to Fahrenheit
//0, 20, 40 ... 300
int main()
{
  float fahr, celsius;

  for(celsius = LOWER; celsius <= UPPER; celsius += STEPP)
  {
    //converting from celsius to fahrenheit
    fahr = celsius * (9.0/5.0) + 32;
    printf("%3.0f %6.5f\n", celsius, fahr); //%d assumes base 10
    //3.0f - print at least 3 characters wide with no decimal
    //6.1f - print at least 6 characters wide with 1 digit after the decimal
  }


  return 0;
}
