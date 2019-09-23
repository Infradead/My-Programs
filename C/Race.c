//Varun Belani, 3/7/17, CIS 2107, Lab 06: "Race",
// Problem statement: Design and implement functions
// to process pointers using random move generation
// on every second of the clock.
// my results seem skewed...the hare always wins

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 70 
int tPosition = 1; //tortoise position
int hPosition = 1; //hare position

struct tortoise
{
  int crPosition;
  //rules
  int fastPlod;
  int slip;
  int slowPlod;
};

struct hare
{
  int crPosition;

  //rules
  int sleep;
  int bigHop;
  int bigSlip;
  int smallHop;
  int smallSlip;
};

void processRace(void);

struct tortoise t1;
struct hare h1;

int main()
{
  puts("ON YOUR MARK, GET SET");
  processRace();
}

void processRace(void)
{
  sleep(2);
  int i = 0;
  char tortoise = 'T';
  char hare = 'H';
  char *collision = "OUCH";
  puts("BANG               !!!!");
  puts("AND THEY'RE OFF    !!!!");
 
  for(int i = 0; i < MAX; i++)
    {
      
      // random number from 1 to 20
      int f = rand() % 20 + 1;
      sleep(2);
      if(f >= 1 && f <= 5) // 50 % chance of fast plod
        {
          t1.fastPlod = 3;
          tPosition += t1.fastPlod;
         
        }
      else if(f >= 6 && f <= 7)
        {
          t1.slip = -6;
          if(tPosition > 6)
            {
              tPosition += t1.slip;
            }
          else
            tPosition = 1;
        }
      else if(f >= 8 && f <= 10)
        {
          t1.slowPlod = 1;
          tPosition += t1.slowPlod;
        }
      else if(f >= 11 && f <= 12)
        {
          hPosition += 0;
        }
      else if(f >= 13 && f <= 14)
        {
          h1.bigHop = 9;
          hPosition += h1.bigHop;
        }
      else if(f == 15)
        {
          h1.bigSlip = -12;
          hPosition += h1.bigSlip;
        }
      else if(f >= 16 && f <= 18)
        {
          h1.smallHop = 1;
          hPosition += h1.smallHop;
        }
      else if(f >= 19 && f <= 20)
        {
          h1.smallSlip = -2;
          hPosition += h1.smallSlip;
        }

      if(tPosition == hPosition)
      printf("%*s\n", tPosition, collision);

      if(tPosition == MAX)
        {
          puts("TORTOISE WINS!!! YAY!!!");
          break;
        }
      else if(hPosition == MAX)
        {
          puts("Hare wins. Yuch.");
          break;
        }
      else if (hPosition == tPosition)
        {
          puts("Its a tie.");
        }
      printf("%*c\n", tPosition, tortoise);
      printf("%*c\n", hPosition, hare);

    }
  
}
