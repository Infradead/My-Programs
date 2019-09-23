//Varun Belani, 3/30/17, CIS 2107-04, Lab 08: "TeleWordGenerator"
//From my understanding, given a seven digit number,write to a file every possible seven letter word corresponding to that number. I'm presuming that the word can be unintelligible.
#include <stdio.h>
#include <stdlib.h>
#define POSSIBILITIES 2187

char randomChar(int number); 

int main(void)
{
  FILE *fPtr;

  if ((fPtr = fopen("seven-letter-words.txt", "w")) == NULL)
    {
      puts("File could not be opened");
    }
   else
    {
      puts("Enter the seven digit phone number. Only use digits 2-9.");

      char phone[8]; // 7 digit phone number
      char word[8]; // name referring to 7 digit number
      int number = 0;
 
      scanf("%7s", phone);
      fprintf(fPtr, "%s \n", phone);
      for(int f = 0; f < POSSIBILITIES; f++)
        {
          for(int i = 0; i < 7; i++)
            {
              int x = phone[i] - '0'; //converting char digit to int
              word[i] = randomChar(x); 
            }
          fprintf(fPtr, "%s \n", word);
        }
      fclose(fPtr);
    }  
}
// given one integer creates one random character depending on that number
char randomChar(int number)
{
  char randomLetter;
  switch(number)
    {
    case 2:
      randomLetter = "ABC"[random () % 3];
      break;
    case 3:
      randomLetter = "DEF"[random () % 3];
      break;
    case 4:
      randomLetter = "GHI"[random () % 3];
      break;
    case 5:
      randomLetter = "JKL"[random () % 3];
      break;
    case 6:
      randomLetter = "MNO"[random () % 3];
      break;
    case 7:
      randomLetter = "PQRS"[random () % 4];
      break;
    case 8:
      randomLetter = "TUV"[random () % 3];
      break;
    case 9:
      randomLetter = "WXYZ"[random () % 4];
      break;
    } 
  return randomLetter;
}

