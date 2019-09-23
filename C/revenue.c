// Varun Belani, 2/9/17,Computer Systems and Low level Progamming
// Lab02, Revenue.
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
  float price; //item price (could have float)
  int quantity;
  float cost; // price * quantity 
  float discount_rate; //0%, 10%, 15% and 25% discount rate to full prices
  float discounted_cost; // amount of money saved = (cost - (cost * discount_rate))
  puts("Welcome to Temple store \nEnter item price: ");
  scanf("%f", &price);

  if(price <= 0)
    {
      puts("Only inputs above 0 allowed. Run the program again");
      exit(0);
    }

  puts("Enter quantity: ");
  scanf("%d", &quantity);

  if(quantity <= 0)
    {
      puts("Only inputs above 0 allowed. Run the program again");
      exit(0);
    }
  
  printf("The item price is: $%.2f \n", price);
  printf("The order is: %d item(s) \n", quantity);
  cost = price * quantity;
  printf("The cost is: $%.2f \n", cost);

  if(quantity > 1 && quantity < 49)
    {
       discount_rate = 0.0;
       printf("The discount is: %.2f percent \n", discount_rate*100); // discount rate decimal to percent
       discounted_cost = cost * discount_rate; //calculation of discounted cost
       printf("The discounted amount is: $%.2f \n", discounted_cost);
       printf("The total is: $%.2f \n", cost- discounted_cost); //cost - discounted cost is total cost after discounts.
    }
  if(quantity >= 50 && quantity <= 99)
    {
       discount_rate = .10;
       printf("The discount is: %.2f percent \n", discount_rate*100);
       discounted_cost = cost * discount_rate;
       printf("The discounted amount is: $%.2f \n", discounted_cost);
       printf("The total is: $%.2f \n", cost - discounted_cost);
    }
  if(quantity >= 100 && quantity <= 149)
    {
      discount_rate = .15;
      printf("The discount is: %.2f percent \n", discount_rate*100);
      discounted_cost = cost * discount_rate;
      printf("The discount amount is: $%.2f \n", discounted_cost);
      printf("The total is: $%.2f \n", cost - discounted_cost);
    }
  if(quantity >= 150)
    {
      discount_rate = .25;
      printf("The discount is: %.2f percent \n", discount_rate*100);
      discounted_cost = cost * discount_rate;
      printf("The discount amount is: $%.2f \n", discounted_cost);
      printf("The total is: $%.2f \n", cost - discounted_cost);
    }
  puts("Thank you for using Temple store");
}
