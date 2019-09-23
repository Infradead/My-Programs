## Programmer: Varun Belani
## Pay program corrected in Lab 1
## Date: 9/6/2019

# This program calculates the user's gross pay

# display prompts and get input
hours = float(input("How many hours did you work? "))
rate = float(input("How much do you get paid per hour? "))
# Could lead to error if input to rate is not checked
# what if a negative number is entered?

# calculations
if(hours <= 40):
    pay = hours * rate;
else:
    pay = (hours - 40) * (1.5 * rate) + 40 * rate

# display results
# This is a formatted print statement .2f means floating point with a
# accuracy of 2 decimals, with a sep variable for a extra space.
print("You earned $", format(pay, ".2f"), sep="")
