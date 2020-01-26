## Programmer: Varun Belani
## "I did not help anyone with this project and I did not receive help from anyone."
## Description: The Sleepy Hill Hotel program computes and prints a hotel bill for each hotel guest.
## INPUT: Clerk Info and Guest info 
## OUTPUT: printing of billing statement 

## Because of the garbage in garbage out concept I take in the input IN THE MAIN FUNCTION, 
## validate it, and then run its calculations through a seperate function. I seperate this project into
## 2 functions (not including main) for usability and organization for the future.

## Slightly advanced input validation in this program so it is longer.
def room(roomType, stayTime):
    dr = 150.00 # Double room
    sr = 100.00 # Single room
    pr = 75.00 # Parlor room
    
    if roomType == 'p':
        return pr * stayTime 
    if roomType == 's':
        return sr * stayTime
    if roomType == 'd':
        return dr * stayTime
# DRINKS COST CALCULATOR
def drinksCalc(drinks):
    if drinks > 1:
        return (drinks - 1) * 1.75
    else: 
        return 0

def total(room, drinks, bonusCard):
    BONUSCARD = 0.1 # 10 %
    if bonusCard == 'y' or bonusCard == 'Y':
        roomTotal = room - (BONUSCARD * room) + drinks
    else:
        roomTotal = room + drinks
    return roomTotal

def clerk():
    clerkName = input("Enter clerk's name: ")
    if not clerkName.isalpha():
        print("Please only use alphabets for name.")
        clerk()
    else:
        print("\nWelcome",clerkName,"to the Sleepy Hill Hotel Billing System. You are to use\n"
          "this program to print the hotel bill for a customer who is checking out of \n"
          "their hotel room. Please let the management know if you have any problems \n"
          "with our systems.\n")

def main():
    clerk()
    validation = True
    guestTotal = 0.00
    guestName = input("Guest name: ")
        # Checks if name has only letters. 
    print("")
    while validation:
        if guestName.isalpha():
            validation = False
        else:
            print("Please only use alphabets and spaces for the guest name.\n")
            guestName = input("Guest name: ")
    
    print("")
    # Value or this "switch" must be resert to default otherwise the rest of the
    # while loops wont validate input.
    validation = True
        
    roomType = input("******Room Type********\n"
                         "'P' or 'p' for Parlor\n"
                         "'S' or 's' for Single\n"
                         "'D' or 'd' for Double\n"
                     "***********************\n"
                     "==> ")
    while validation:    
        if roomType.lower() == 'p' or roomType.lower() == 's' or roomType.lower() == 'd':
            roomType = roomType.lower()
            validation = False
        else:
            print("Please only enter upper or lower case version of:\n"
            "'p', 's' or 'd' for room type.\n")
            roomType = input("******Room Type********\n"
                         "'P' or 'p' for Parlor\n"
                         "'S' or 's' for Single\n"
                         "'D' or 'd' for Double\n"
                         "***********************\n"
                         "==> ")
    print("") 
    validation = True 

    while validation:
        stayTime = input("Nights stayed at hotel? Minimum must be 1 night: ")
        print("")
        if stayTime.isdigit():    # Instead of making these two if statements 1 line its better security practice to see
            if int(stayTime) >= 1:     # if the value IS a digit first and then see if its greater than one. 
                stayTime = int(stayTime) # Manipulative chars can be put in which is why we have 2 if statements (good security programming).
                validation = False  
            else:
                print("Night(s) stayed at hotel must be atleast 1 or above.")
    print("")
    validation = True
    
    # I Could validate input here by saying drinks = int(input...) but if a character is entered then there is an error.
    drinks = input("Note: If no drink taken please enter 0, and put $0.00 as their charge.\n"
                       "Otherwise, the maximum number of drinks is 25.\n"
                       "Number of drinks taken from refrigerator: ")
    while validation:
        if drinks.isdigit():
            if int(drinks) >= 0 and int(drinks) <= 25:
                drinks = int(drinks)
                validation = False
            else:
                print("")
                print("Number entered must be between 0 and 25.")
                drinks = input("Number of drinks taken from refrigerator: ")
        else:
            print("")
            drinks = input("Please enter a NUMBER for the drinks. 0 and 25 Inclusive: ")
            
    print("")   
    validation = True  
      
    bonusCard = input("If customer has a bonus card then enter 'y' or 'Y' \n otherwise any other alphabet for NO: ")
    while validation:
        if bonusCard.isalpha():
            if bonusCard == 'Y' or bonusCard == 'y':
                validation = False
            else:
                validation = False
        else:
            print("Only alphabets are allowed for input.")
            print("")
            bonusCard = input("If customer has a bonus card then enter 'y' or 'Y' \n otherwise any other alphabet for NO: ")
            
    print("")        
    roomCost = room(roomType, stayTime)
    drinksCost = drinksCalc(drinks)
    totalCost = total(roomCost, drinksCost, bonusCard)
    
    
    print("*" * 50)
    print("            Sleepy Hill Hotel Bill       ")
    print("*" * 50)
    print("Customer name:", guestName)
    if roomType == 'p':
        print("Type of Room: Parlor")
        print("Cost of room per night: $75.00")
    elif roomType == 's':
        print("Type of Room: Single")
        print("Cost of room per night: $100.00")
    else:
        print("Type of Room: Double")
        print("Cost of room per night: $150.00")
    
    print("Length of Stay:",stayTime)
    if bonusCard == 'y' or bonusCard == 'Y':
        print("Has Bonus Card: Yes")
        print("Total room cost (before discount): $", roomCost, sep='')
        print("Total room cost (after discount): $", roomCost - (roomCost * .10), sep='')
    else:
        print("Has Bonus Card: No")
        print("Total room cost (No discount b/c of no bonus card): $", roomCost, sep='')
    print("")
    print("Number of drinks (including free drink):",drinks)
    print("Cost of drinks: $", drinksCost, sep='')
    print("")
    print("Final Cost: $",totalCost, sep='')
    print("")
    print("*" * 50)
    print("             Come Back Soon!            ")
    print("*" * 50)
  
  
  ### Some code found on STACK OVERFLOW
  ### https://stackoverflow.com/questions/36571560/directing-print-output-to-a-txt-file-in-python-3
   
    receipt = open("receipt.txt", 'w')
   
    print("*" * 50, file=receipt)
    print("            Sleepy Hill Hotel Bill       ", file=receipt)
    print("*" * 50, file=receipt)
    print("Customer name:", guestName, file=receipt)
  
    if roomType == 'p':
        print("Type of Room: Parlor", file=receipt)
        print("Cost of room per night: $75.00", file=receipt)
    elif roomType == 's':
        print("Type of Room: Single" , file=receipt)
        print("Cost of room per night: $100.00", file=receipt)
    else:
        print("Type of Room: Double", file=receipt)
        print("Cost of room per night: $150.00", file=receipt)
    
    print("Length of Stay:",stayTime, file=receipt)
   
    if bonusCard == 'y' or bonusCard == 'Y':
        print("Has Bonus Card: Yes", file=receipt)
        print("Total room cost (before discount): $", roomCost, sep='', file=receipt)
        print("Total room cost (after discount): $", roomCost - (roomCost * .10), sep='', file=receipt)
    else:
        print("Has Bonus Card: No", file=receipt)
        print("Total room cost (No discount b/c of no bonus card): $", roomCost, sep='', file=receipt)
   
    print("", file=receipt)
    print("Number of drinks (including free drink):",drinks, file=receipt)
    print("Cost of drinks: $", drinksCost, sep='', file=receipt)
    print("", file=receipt)
    print("Final Cost: $",totalCost, sep='', file=receipt)
    print("", file=receipt)
    print("*" * 50, file=receipt)
    print("             Come Back Soon!            ", file=receipt)
    print("*" * 50, file=receipt)

    print("Receipt written to file. Ready to Print!")   
    
main()