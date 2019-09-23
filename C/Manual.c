#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

char string[SIZE];
char string1[SIZE];
long sum = 0;
double sumDec = 0;
int partChar = 0;

void upperLower(char string[]);
long convertStrtoInt(char string[]);
float convertStrtoFloat(char string[]);
void compareStr(char string1[], char string2[]);
void comparePartialStr(char string1[], char string2[], int partChar);
void randomize(void);

int main(void)
{
  puts("Enter text for upper and lower case conversion.");
  scanf("%100s", string); //only accepts 100 characters
  upperLower(string);

  for(int i = 0; i < 4; i++)
    {
      puts("Enter string of whole numbers.");
      scanf("%s", string);
      sum += convertStrtoInt(string);
    }
  printf("Sum: %ld\n", sum);

  for(int i = 0; i < 4; i++)
    {
      puts("Enter string of numbers with decimals.");
      scanf("%s", string);
      sumDec += convertStrtoFloat(string);
    }
  printf("Sum: %f\n", sumDec);

  puts("To compare two strings enter string 1 and string 2: ");
  scanf("%s %s", string, string1);
  compareStr(string, string1);

  puts("To partially compare two strings enter string 1 and string 2 \n and a number of the char to stop the comparision at: ");
  scanf("%s %s %d", string, string1, &partChar);
  comparePartialStr(string, string1, partChar);
  
  return(0);
  
}

void upperLower(char string[])
{
  char s[SIZE];
  printf("Your string: %s has been copied.\n", strcpy(s, string));
  for(int i = 0; i < SIZE; i++)
    {
      s[i] = toupper(s[i]);
    }
  printf("Your string: %s in uppercase.\n", s);

  for(int i = 0; i < SIZE; i++)
    {
      s[i] = tolower(s[i]);
    }
   printf("Your string: %s in lowercase.\n", s);

}

long convertStrtoInt(char string[])
{
  char *ptr;
  long number = strtol(string, &ptr, 0);
  return number;   
}
float convertStrtoFloat(char string[])
{
  char *ptr;
  float number = strtof(string, &ptr);
  return number; 
}
void compareStr(char string[], char string1[])
{
  int results = strcmp(string, string1);
  if(results < 0)
    printf("%s is more than %s\n", string, string1);
  else if (results > 0)
    printf("%s is less than %s\n", string, string1);
  else
    printf("%s is equal to %s\n" , string, string1);
}
void comparePartialStr(char string[], char string1[], int partChar)
{
  int results = strncmp(string, string1, partChar);

  if(results < 0)
    printf("%s is more than %s\n", string, string1);
  else if (results > 0)
    printf("%s is less than %s\n", string, string1);
  else
    printf("%s is equal to %s\n" , string, string1);
}
void randomize(void)
{
  char article[];
  char noun[];
  char verb[];
  char preposition[];
