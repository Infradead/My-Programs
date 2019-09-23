# Programmer: Varun Belani
# This program calculates the total price which includes sales tax

# identifier initialization

#    TAX_RATE = 0.055;
#  ^ unexpected indent
TAX_RATE = 0.055;
#   Could also be written taxRate?
#   But possibly a constant should be written in caps?

# display prompts to get input
# item = inpt("Item price: $"))
#          ^ incorrect variable name
#          ^ variable undeclared
item = input("Item description:     ")
price = float(input("Item price:   $"))
print() # new line

# calculations
#tax = price + TAX_RATE        < Incorrect order
#total = price * tax           < Incorrect order
tax = price * TAX_RATE          # Correct order
total = price  + tax

# display results
# print(itm + "    $", price, sep="")
#        ^ incorrect variable name; variable doesn't exist
# Also with the above statement you cannot concatenate (+) a number with
# a string literal, must replace with ,
print(item,"     $", price, sep="") 
print("Tax    $", tax, sep="")
print("Total      $", total, sep="");
