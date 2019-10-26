# Name: Varun Belani
# Date: 10/18/19
# Purpose: Generates numbers from 1 - 6 inclusive and does it 6000 times
#          The program keeps track of how many times each digit is entered
#          The tracked numbers between 1-6 are printed with how many times each were picked.
#          The loop is ended by user with a 'y' char.

import random

doAgain = True

num1 = 0
num2 = 0
num3 = 0
num4 = 0
num5 = 0
num6 = 0

print("Welcome. This program will generate random numbers between 1 and 6, 6000 times.")
print("The program keeps track of how many of each digit are generated")


while(doAgain):
    for x in range (1, 6000):    
        number = random.randint(1,6)        
        if number == 1:
            num1 += 1
        elif number == 2:       
            num2 += 1
        elif number == 3:
            num3 += 1   
        elif number == 4:
            num4 += 1
        elif number == 5:
            num5 += 1
        elif number == 6:
            num6 += 1
       
    print("Number of ones: ",num1)
    print("Number of twos: ",num2)
    print("Number of threes: ",num3)
    print("Number of fours: ",num4)
    print("Number of fives: ",num5)     
    print("Number of sixes: ",num6)
   
    
    num1 = 0
    num2 = 0
    num3 = 0
    num4 = 0
    num5 = 0
    num6 = 0

    usrInput = input("Type 'Y' to play again and any other key to quit: ")

    if usrInput == 'y' or usrInput == 'Y':
        doAgain = True
    else:
        doAgain = False
        
print("Program terminated.")    
