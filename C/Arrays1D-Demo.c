#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

//Varun Belani 2/21/17 Lab 04
//Demonstration of a 1 dimensional array through functions

int demoArray[0]; //declared here for demo purposes
int low = 0;
int elem_highest = 0;
int elem_lowest = 0;
int reverse_low = 0;
int reverse_high = 0;
int high = 0;
int n = 0;
char choice;
int seq1 = 0;
int seq2 = 0;

void process(void);
void menu(void);
void fillArray(int low, int high, int n);
int findWithRange(int low, int high);
void reverseArray(int low, int high);
void findSequence(int seq1, int seq2);

int main()
{
  menu(); 
}
void menu()
{
 
  puts("Enter size of array. ");
  scanf("%3d", &n);
  puts("Enter lowest value in your array.");
  scanf("%3d", &low);
  puts("Enter highest value in your array.");
  scanf("%3d", &high);
  fillArray(low, high, n);
     
  while(1)
    {
      puts("What would you like to do with this array?");
      puts("Find [L]argest value within range?");
      puts("     [R]everse the whole array?");
      puts("Rever[S]e specific range within array?");
      puts("     [F]ind Tom and Jerry?");
      scanf("%1c", &choice);
      process();
    }
}
void process()
{
  switch(choice)
    {
    case 'l':
    case 'L':
      puts("Enter starting range element to find largest value.");
      scanf("%3d", &elem_lowest);
      puts("Enter ending range element to find largest value.");
      scanf("%3d", &elem_highest);
      puts("The highest element in the range:");
      printf("%3d \n", findWithRange(elem_lowest, elem_highest));
      break;
    case 'r':
    case 'R':
      puts("Reversing whole array...");
      reverseArray(0, n); 
      break;
    case 's':
    case 'S':
       puts("Enter starting element for reversal of array.");
       scanf("%3d", &reverse_low);
       puts("Enter ending element for reversal of array.");
       scanf("%3d", &reverse_high);
       puts("Reversing range in array....");
       reverseArray(reverse_low, reverse_high);
       break;
    case 'f':
    case 'F':
      puts("Enter first value to find sequence.");
      scanf("%4d", &seq1);
      puts("Enter second value to find sequence.");
      scanf("%4d", &seq2);
      puts("Finding sequence...");
      findSequence(seq1, seq2);
      break;
    }
}
  
//this function fills an array with random integers and asks for number of elements
void fillArray(int low, int high, int n)
{ 
  for (int i = 0; i < n; i++) 
    {
      // this line of code is here is to avoid the off by one error between range = (high - low) 
      demoArray[i] = rand() % (high - low + 1) + low; 
      printf("Element: %d\t%d \n", i , demoArray[i]);
    }
}
//finds highest value between low (starting) element and high (ending) element
int findWithRange(int low_search, int high_search)
{
  int l = low_search; //lower range element
  int h = high_search;//higher range element
  int largest = 0;
 
  for(int i = l; i < h; i++)
    {
      if(demoArray[i] > largest)
        {
          largest = demoArray[i];
        }
      else if(demoArray[i+1] > largest)
        {
          largest = demoArray[i+1];
        }
      else
        ;
     
    }
  return largest;
}

void reverseArray(int lower_range, int higher_range)
{
  int l = lower_range;
  int h = higher_range;
  int temp = 0;

  while( l < h+1 ) // +1 for off by one error
    {
      temp = demoArray[l];
      demoArray[l] = demoArray[h];
      demoArray[h] = temp;
      l++;
      h--;
    }
  
  l = lower_range;
  h = higher_range + 1; //+1 for off by one error

  for(; l < h; l++)
    {
      printf("Element: %d\t%d \n", l , demoArray[l]);
    }     
}
void findSequence(int first_val, int second_val)
{
  int element = 0;
  for(int i = 0; i < n; i++)
    {
      
      if(demoArray[i] == first_val)
        {
          element = i;
          break;
        }
      else if(demoArray[i] == second_val)
        {
          element = i;
          break;
        }
      else
        element = -1;
    }
  
  if(element == -1)
    {
      puts("sequence not found");
    }
  else
    printf("sequence found at index: %1d\n\n", element);
 
}
