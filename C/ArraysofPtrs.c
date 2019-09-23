//Varun Belani, 3/2/17, Lab 05, Project 2: 2D Arrays of Pointers to Functions
// Function prototypes were not created by me.
// Fig. 6.22: fig06_22.c
#include <stdio.h>
#include <stdlib.h>
#define STUDENTS 3
#define EXAMS 4

// function prototypes
void minimum(const int grades[STUDENTS][EXAMS], size_t pupils, size_t tests);
void maximum(const int grades[STUDENTS][EXAMS], size_t pupils, size_t tests);
void average(const int grades[STUDENTS][EXAMS], size_t pupils, size_t tests);
void printArray(const int grades[STUDENTS][EXAMS], size_t pupils, size_t tests);
void menu(void); //displays options

//declaring pointer array
void (*processGrades[4]) (const int grades[STUDENTS][EXAMS]
                          , size_t pupils, size_t tests); 

// function main begins program execution
int main(void)
{
   // initialize student grades for three students (rows)
   int studentGrades[STUDENTS][EXAMS] =  
      { { 77, 68, 86, 73 },
        { 96, 87, 89, 78 },
        { 70, 90, 86, 81 } };
   // default choice to avoid errors in different systems
   int choice = 0;

   //assign addresses of functions to pointer array
   processGrades[0] = printArray;
   processGrades[1] = minimum;
   processGrades[2] = maximum;
   processGrades[3] = average;

   puts("Enter a choice:");
   menu();
   scanf("%1d", &choice);     
   //  while(choice > 0 && choice <= 4)
   //  {
   //      menu();
         switch(choice)
           {
           case 0:
             // output array studentGrades
             puts("The array is:");
             ((*processGrades[choice]) (studentGrades, STUDENTS, EXAMS));
             break;
           case 1:
             // determine smallest and largest grade values
             ((*processGrades[choice]) (studentGrades, STUDENTS, EXAMS));
             break;
           case 2:        
             ((*processGrades[choice]) (studentGrades, STUDENTS, EXAMS));
             break;
           case 3:
             puts("Average on all tests for each student: ");
             // calculate average grade for each student
             ((*processGrades[choice]) (studentGrades, STUDENTS, EXAMS)); 
             break;
           case 4:
             puts("Ending program...");
             exit(0);
           }
     
             // }
      
}
//Simple display
void menu()
{
  puts("0 Print the array of grades");
  puts("1 Find the minimum grade");
  puts("2 Find the maximum grade");
  puts("3 Print the average on all tests for each student");
  puts("4 End Program");
}

  // Find the minimum grade
void minimum(const int grades[STUDENTS][EXAMS], size_t pupils, size_t tests)
{
   int lowGrade = 100; // initialize to highest possible grade

   // loop through rows of grades
   for (size_t i = 0; i < pupils; ++i)
     {
      // loop through columns of grades
       for (size_t j = 0; j < tests; ++j)
         {
           if (grades[i][j] < lowGrade)
             {
               lowGrade = grades[i][j];
             } 
         } 
     } 

   printf("Minimum grade: %d\n", lowGrade); // show minimum grade 
} 

// Find the maximum grade
void maximum(const int grades[STUDENTS][EXAMS],
             size_t pupils, size_t tests)
{
   int highGrade = 0; // initialize to lowest possible grade

   // loop through rows of grades
   for (size_t i = 0; i < pupils; ++i)
     {

      // loop through columns of grades
      for (size_t j = 0; j < tests; ++j)
        {

         if (grades[i][j] > highGrade)
           {
             highGrade = grades[i][j];
           } 
        } 
     } 

   printf("Maximum grade: %d\n", highGrade);
} 

// Determine the average grade for a particular student
void average(const int grades[STUDENTS][EXAMS],
             size_t pupils, size_t tests)      
{                                                         
   int total[STUDENTS]; // test grade for each student                
                                                          
   // total all grades for all students
   for(size_t i = 0; i < pupils; ++i)
     {
       for (size_t j = 0; j < tests; ++j)
         {
           total[i] += grades[i][j];                          
         }
     }

   for(int i = 0; i < STUDENTS; i++)
     printf("Student: %d\t%.2f\n" , i+1 , (double) total[i] / tests); // average
} 

// Print the array
void printArray(const int grades[STUDENTS][EXAMS],
                size_t pupils, size_t tests)
{
   // output column heads
   printf("%s", "                 [0]  [1]  [2]  [3]");

   // output grades in tabular format
   for (size_t i = 0; i < pupils; ++i)
     {

      // output label for row
      printf("\nstudentGrades[%lu] ", i);

      // output grades for one student
      for (size_t j = 0; j < tests; ++j) 
         printf("%-5d", grades[i][j]);

      
     }
   puts(""); //empty line after printing array
} 
