//Varun Belani, 2/24/17, Lab 05, Project 1: 2D Arrays Processing without pointers

#include <stdlib.h>
#include <stdio.h>
//#include <stdbool.h>

int cols = 0; 
int rows = 0;

void displayOutputs(int data[]);
void isSquare(void);
int colSum(int data[]);
int rowSum(int data[], int row);
int max(int data[]);

int main()
{
  puts("How many columns?");
  scanf("%2d", &cols);
  puts("How many rows?");
  scanf("%2d", &rows);

  int demoArray[rows][cols];
  int totalElem = rows * cols;

  int data[totalElem];

  for(int i = 0; i < rows; i++)
    {    
      for(int j = 0; j < cols; j++)
        {
          printf("enter [%d][%d]", i , j);
          scanf("%5d", &demoArray [i][j]);               
        }
    }
  int x = 0;
  //code for making column data
  for(int i = 0; i < rows; i++)
    {
      for(int j = 0; j < cols; j++)
        {
          data[x] = demoArray[i][j];
          x++;
        }
    }

  for(int i = 0; i < x; i++)
    {
      printf("%d\n", data[i]);
    }

  for(int i = 0; i < rows; i++)
    printf("Sum of row %d = %d\n", i+1, rowSum(data, i));

  int col_sum = colSum(data);
  /* for(int j = 0; j < cols; j++) */
  /*   { */
  /*     printf("%d", colData[j]); */
  /*   } */
  
  
  /* puts("Enter the row you want the sum of."); */
  /* scanf("%2d", &row_x); */
  /* printf("Sum: %d\n", rowSum(row_x)); */

  /* puts("Enter the column you want the sum of."); */
  /* scanf("%2d", &col_x); */
  /* printf("Sum: %d\n", colSum(col_x)); */

  /* puts("Displaying outputs of 2D array."); */
  /* displayOutputs(); */
    
}

void isSquare(void)
{
  if(cols == rows)
    {
      puts("This is a square array.");
    }
  else
    {
      puts("This is not a square array.");
    }
}
          

//finds sum of row in array by traversing only that specific row but adding up all the column values.
int rowSum(int data[], int row)
{
  int sum = 0;
  for(int i = row; i < ; i++)
    {
      sum += data[i];
    }
  return sum;
}
//finds sum of column in array by traversing only that specific column but adding up all the row values.
int colSum(int data[])
{
  int sum = 0;

  
  return sum;
}
int max(int data[])
{
  return 0;

}  
void displayOutputs(int data[])
{

}

