import math
## Varun Belani 9/20/19
## Takes first/last names and returns full name and initials
## Calculates F to C temperature
## Calculates Volume



# identifier inititalizations
number = 2	        # number of scores
score1 = 100;		# first test score
score2 = 95;	        # second test score
BOILING_IN_F = 212;     # freezing temperature


# Find an arithmetic average
average = (score1 + score2) / number
output = str(score1) + " and " + str(score2) + " have an average of " + str(average)
print(output)

# Convert Fahrenheit temperatures to Celsius
fToC = 5/9 * (BOILING_IN_F - 32)
output = str(BOILING_IN_F) + " in Fahrenheit is " + str(fToC) + " in Celsius."
print(output)
print()	# to leave a blank line

# ADD LINES FOR TASK #3 HERE
# prompt and store the user's first name, with input validation str()
fName = str(input("Please enter your first name: "))
lName = str(input("Please enter your last name: "))
# prompt and store the user's last name
# concatenate the user's first and last names
fullName = (fName+" "+lName)
# print out the user's full name
print(fullName)
print()		# to leave a blank line

# ADD LINES FOR TASK #4 HERE
# get the first character from the user's first name
firstInitial = fName[0]
lastInitial = lName[0]
initials = (firstInitial+lastInitial)
print(initials)
# get the first character from the user's last name
# print out the user's first initial and last initial with no space between them
print()		    # to leave a blank line

# ADD LINES FOR TASK #5 HERE
# prompt and store the user input for a diameter of a sphere
diameter = float(input("Input diameter: "))
# calculate the radius
radius = float(diameter / 2)
# calculate the volume
volume = 4 * (math.pi * radius ** 3) / 3.0
# print out the volume
print(format(volume, ".3f"), sep="")
