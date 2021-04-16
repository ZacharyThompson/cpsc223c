#include <stdio.h>

//ascii 0(45) 1(46) 2 3 4 5 6 7 8 9  
//array[45-'0'] = array[0]

//looking inside standard library functions

//atoi convert s to int 
int atoi(char s[])
{
  int i, n;
  n = 0;
  for(i = 0; s[i] >= '0' && s[i] <= '9'; ++i) //235582\n\0
  {
    n =10 * n + (s[i] - '0'); //46(1) - 45 
  }

  //2
  //23
  //2355
}

//abcedf...zABCDEF..Z
//convert char to lower case
int lower(int c)
{
  if(c >= 'A' && c <= 'Z')
  return c + 'a' - 'A';  
  else
  return c;  
}

//strcat append one string to another
//string t, string s  ts
//the string must be big enough to hold the append value
void strcat2(char s[], char t[])
{
  int i, j;
  i = j = 0;
  //s timmy\0  t jimmy\0
  while(s[i] != '\0') //note s must be big enough to hold s+t
  i++;

//s timmyjimmy\0
  while((s[i++] = t[j++]) != '\0')
  ;//setting an empty loop  
}


/*  c provided getline
getline(&buffer, &size, stdin)

we will make our own getline to funciton like the c++
getline(string(char arr[]), int maxline)
*/

// timmy\n  && !out of bounds 
void getline2(char s[], int lim)
{
  int c, i;

  for(i = 0; i < lim - 1  && (c = getchar()) != '\n'; ++i)
  {
    s[i] = c;
  }
  s[i] = '\0';//append null to the end of the array
  
}

//lab write strcopy2
//p1 take string contents of one array and copy them to another string
//using your functions - write a program to read 3 lines of input, and print the longest line


void strcopy2(char s[], char t[], int lim) {
	int i;
	for (i = 0; i < lim - 1 && t[i] != '\0'; i++) {
		s[i] = t[i];
	}
	s[i] = '\0';
}

int string_length(char s[]) {
	int i;
	int size = 0;
	for (i = 0; s[i] != '\0'; i++)
		size++;
	return size;
}

int main() {
	char str1[50], str2[50], str3[50];

	printf("Enter 3 Strings:\n");
	getline2(str1, 50);
	getline2(str2, 50);
	getline2(str3, 50);

	int a,b,c;
	a = string_length(str1);
	b = string_length(str2);
	c = string_length(str3);

	if (a > b && a > c)
		printf("Longest: %s\n", &str1);
	else if (b > a && b > c)
		printf("Longest: %s\n", &str2);
	else if (c > a && c > b)
		printf("Longest: %s\n", &str3);
	else
		printf("Some of the strings have equal length.\n");

	
	return 0;
}
