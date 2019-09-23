//Varun Belani, 2/10/17, Lab 3, ATM program
#include <stdlib.h>
#include <stdio.h>


char input;
static int const pin = 3014; //pin would hopefully never change for an individual
int balance = 5000;
static int const pin_attempts = 3; //pin attempts should be 3 at all times unless specified
int amount_withdrawn_limit = 0;
int amount_deposited_limit = 0;
int transactions = 0;

//function prototypes used in atm program
void menu();
void process();
void show_balance();
void withdraw();
void deposit();
void quit();


int main(void)
{
  menu();
}
//menu function validates pin number of user in the database and displays the function options for atm.
void menu()
{

   unsigned int pinEntered;
   for (int i = 0; i < pin_attempts; i++)
     {
       puts("Enter pin: ");
       scanf("%4d" , &pinEntered);
       if(pinEntered != pin)
         {
           if(i == pin_attempts - 1)
             {
               puts("System exiting...");
               exit(0);
             }
           else
             {
               puts("Please enter the correct pin");
             }
         }
       else
         {
           puts("Successful pin entered!");
           i = 0; // just to reset the counter for attempts
           puts("");
           while(1) //makes atm wait for input, unfortunately menu shows up twice
             {
               puts("Enter 'b' for [b]alance");
               puts("Enter 'w' for cash [w]ithdrawal");
               puts("Enter 'd' for cash [d]eposition");
               puts("Enter 'q' for [q]uit");
               scanf("%1c", &input);
               process();
             }
         }
      
     }  

}
//processes the char input into what function the user wants to utilize
void process()
{
      switch(input)
    {
      case 'b':
      case 'B':
        show_balance();
        break;
      case 'w':
      case 'W':
        withdraw();
        break;
      case 'd':
      case 'D':
        deposit();
        break;
      case 'q':
      case 'Q':
        quit();
    }
      
         
}
//Simple function displaying balance.
void show_balance()
{
  printf("Your current balance is: $%d \n" , balance);
}
//A function that checks withdrawal amounts for each user. And does not allow withdrawal over a 1000.
void  withdraw()
{
  
static int const cashLimit = 1000; // is declaring a const locally a good idea?
  int user_withdrawal_amount = 0; //user input for withdrawal

       while(amount_withdrawn_limit < cashLimit)
        {
          puts("Enter the amount to withdraw in multiples of 20s. \n(i.e.; 20, 40, 60, 80, 100, up to 1000)\nEnter 0 to return to menu.");
  
          scanf("%4d", &user_withdrawal_amount); //only accepts up to thousands
          if(user_withdrawal_amount != 0)
            {
              
              if(user_withdrawal_amount > cashLimit && user_withdrawal_amount % 20 != 0)
                {
                  puts("Sorry withdrawal limit is $1000 only.");
                  break; //goes back to while loop
                }
              else
                {
                  
                  if(amount_withdrawn_limit > cashLimit)
                    {
                      puts("Sorry you cannot withdraw over $1000.");
                      break; // goes back to while loop
                    }
                  else
                    {
                  
                      balance = balance - user_withdrawal_amount;
                      show_balance();
                      puts("");
                      amount_withdrawn_limit += user_withdrawal_amount;
                      transactions++;
                    }
                }
            }
          else
            {
              menu();
            }
        }
       //recipt
      printf("Amount withdrawn: %d \nBalance left: %d \n", amount_withdrawn_limit, balance); 
      menu();
  
}
//function that deposits money up to 10000 a day and will not work if user tries to input over 10000.
void deposit()
{
  static int const cashLimit = 10000; //is declaring a const locally a good idea? Especially with same name as within withdrawal function.
  int user_deposit_amount = 0;
  if(amount_deposited_limit >= cashLimit)
    {
      puts("You have already deposited over 10000 for today. Please select another option.");
    }
  while(amount_deposited_limit < cashLimit)
    {
      puts("Enter the amount to deposit in 1s, 5s and 10s. \nWarning: No coins accepted \nEnter 0 to return to menu.");
      scanf("%5d", &user_deposit_amount);

      if(user_deposit_amount != 0)
        {
          if(user_deposit_amount <= cashLimit)
            {
              amount_deposited_limit += user_deposit_amount;
              if(amount_deposited_limit > cashLimit)
                {
                  puts("Sorry if you deposit this amount. You will go over 10000 for today.");
                  break; // go back to while loop to deposit another amount
                }
              balance += user_deposit_amount;
              show_balance();
              transactions++;
            }
          else
            {
              puts("Sorry you cannot deposit over $10000 for today");
              break; //goes back into while loop asking to enter another deposit amount
            }
        }
      else
        menu();
    }
  
}

void quit()
{
  printf("You had %d transactions.\nThank you for using this atm.\n" , transactions);
  exit(0);
}
               

