// Varun Belani, 2/3/17,Computer Systems and Low level Progamming
// Lab02, Paycheck.
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
  
  int employeeNumber;
  float hourlySalary; //could be for Ex. 7.50/hr 
  int weeklyTime;
  float overtime = 1.5 * hourlySalary;
  float netPay; // could be for Ex. 1220.67
  
 
  puts("Welcome to TEMPLE HUMAN RESOURCES"); //greeting

  //only pos. numbers and only up to 9 digits
  //employee number
  puts("Enter Employee Number: ");
  scanf("%d", &employeeNumber);
  if(employeeNumber <= 0)
    {
      puts("Not a valid number for employee. \n Please run the program again.");
      exit(0);
    }
  
  //only pos. numbers, can be float up to .2 precision
  //hourly salary
  puts("Enter Hourly Salary: "); 
  scanf("%f", &hourlySalary);
  

  if(hourlySalary <= 0) //this exits program if user enters a negative or 0
    { 
      puts("Not a valid number for Hourly Salary. \n Please run the program again.");
      exit(0);
    }
  //only pos. numbers, cannot be negative or 0
  //hours worked per week
  puts("Enter Weekly Time: "); 
  scanf("%d", &weeklyTime);

  if(weeklyTime <= 0) //this exits program if user enters a negative or 0
    { 
      puts("Not a valid number for Hourly Salary. \n Please run the program again.");
      exit(0);
    }

  if(weeklyTime > 40) //overtime condition
    {
      printf("Employee #: %d", employeeNumber);
      printf("Hourly Salary: $ %.2f", hourlySalary);
      printf("Weekly Time: %d", weeklyTime);
      unsigned int overtimeHours = weeklyTime - 40;
      netPay = 40 * hourlySalary + overtimeHours * overtime;
      printf("Net Pay: $ %.2f" , netPay);
    }
  else // not-overtime condition
    {
      printf("Employee #: %d", employeeNumber);
      printf("Hourly Salary: $  %.2f", hourlySalary);
      printf("Weekly Time: %d", weeklyTime);
      netPay = weeklyTime * hourlySalary;
      printf("Net Pay: $ %.2f", netPay);
    }
  
        
}

