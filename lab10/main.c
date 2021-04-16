#include <stdio.h>
#define MAXLINE 1000 //max input line length
char pattern[] = "ould"; //term to search for

// getline get a line store it in s - return the size of the read line
int getline2(char s[], int lim)
{
  int c, i; //c is char , i is the counters
  for(i = 0; i < lim-1 && (c = getchar()) != '\n'; ++i)
  {
    s[i] = c;//write char to s
    //input - hello\n
    //s[] = hello\0
  }
  s[i] ='\0'; //append the null terminator
  return i;   //return the size
}

int strindex(char s[], char t[]) //s input, t term
{
  int matches = 0;
  int i, j, k;

  for(i = 0; s[i] != '\0'; i++) //search the array and keeps our place!
  {
    for(j = i, k = 0; t[k] !='\0' && s[j] == t[k]; j++ , k++)//j searches where we are starting with i in s, k searches t
    ; //search for a match!!!
    if( k > 0 && t[k] == '\0') //if we found a match
      matches++;
  }

  return matches;

}

int main()
{
  char line1[MAXLINE], line2[MAXLINE], line3[MAXLINE];
  int a, b, c;

  getline2(line1, MAXLINE);
  getline2(line2, MAXLINE);
  getline2(line3, MAXLINE);

  a = strindex(line1, pattern);
  b = strindex(line2, pattern);
  c = strindex(line3, pattern);

  // Print the line with the most occurences
  if (a > b && a > c)
    printf("%s\n", line1);
  else if (b > a && b > c)
    printf("%s\n", line2);
  else if (c > a && c > b)
    printf("%s\n", line3);
  else
    puts("More than one line has the max number of occurences."); //print message if occurences are equal

  return 0;
}
