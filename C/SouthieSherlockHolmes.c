#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *southieAccent(char *string);
int isVowel(char c);
    
int main(void)
{
  FILE *rPtr; //for reading/writing file
  FILE *wPtr;
  char *pch;
  const char s[2] = "\""; // representing each double quote on either end
  
  if((rPtr = fopen("sherlock.txt" , "r")) == NULL) 
    {
      puts("File to be read could not be opened.");
      puts("Exiting....");
      exit(0);
    }
  if((wPtr = fopen("southie-sherlock.txt" , "w")) == NULL)
    {
      puts("File to write could not be opened.");
      puts("Exiting...");
      exit(0);
    }
  else
    {
      fseek(rPtr, 0, SEEK_END);
      long pos = ftell(rPtr);
      fseek(rPtr, 0, SEEK_SET);
      
      char *bytes = malloc(pos);
      fread(bytes, pos, 1, rPtr);
      
      
      fgets(bytes, sizeof(bytes), rPtr);
      pch = strtok(bytes, s);
         
      while(pch != NULL)
        {
          pch = southieAccent(pch);
          fputs(pch, wPtr);
          pch = strtok(NULL, s);
        }

      free(bytes);
      
      fclose(rPtr);
      fclose(wPtr);
         
    }   
  return 0;
}
//this function compares chars in string
// if r is before a vowel then replace 'r' with 'h'
// but if a word ends in 'a' add an 'r' at the end
// leave it as 'r'
char *southieAccent(char *string)
{
  for(int i = 0; string[i] != '\0'; ++i)
    {
      if(string[i+1] == 'r' && isVowel(string[i]) == 1)
        {
          string[i+1] = 'h';
        }
      if(string[i-1] != ' ' && string[i] == 'a' && string[i+1] == ' ')
        {
          string[i+1] = 'r';
        }
    }

  //this commented section is under development
  /* const char str[8] = "wicked"; */
  /* const char str2[8] = "vehy"; //previous rule changes very to vehy   */

  /* for(int e = 0; string[e] != temp[e]; e++) */
  /* char *temp = strstr(string, str2); // temp holds first occurence of "very" AKA vehy */

  /* for(int f = 0; string[f] != temp[f]; f++) */
  /* string[i] = str[i]; */
      
  
  return string;
}
int isVowel(char c)
{
  switch(c)
    {
    case 'A':
    case 'a':
    case 'E':
    case 'e':
    case 'I':
    case 'i':
    case 'O':
    case 'o':
    case 'U':
    case 'u':
      return 1;
    default:
      return 0;
    }
}

          
          

