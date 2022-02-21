# Code by Varun Belani

# There is Fuzzbang, but its only for python 3
# SO i made my own alphanumeric generator
# which is a part of the fuzzer functionality
import random
import string
# bounds on length of alphanumeric strings
# Application min pass length was 6
# when bruteforcing passes AVOID the chars: @#%/:\
# Alphabets in uppercase allow for increased attack vector for bruteforcing
# But injecting @#%/:\ anywhere else may be useful

MIN_LEN = 6
MAX_LEN = 12
# string module has some really awesome functions!!!
# https://stackoverflow.com/questions/16060899/alphabet-range-in-python
lowercase_alpha = list(string.ascii_lowercase)
uppercase_alpha = list(string.ascii_uppercase)
special_chars = list(string.punctuation)

special_chars.remove('@') 
special_chars.remove('#') 
special_chars.remove('%') 
special_chars.remove('/') 
special_chars.remove(':')
# list only recognizes '\' this way.
# chr() is convert ascii code 92 to ascii char '\'
special_chars.remove(chr(92))
# List must be iterated backwards, as the del function move all following elements back one place to fill the gap

#for i in range(len(special_chars), -1):
 #   if special_chars == '@' or '#' or '%' or '/' or ':' or '\':
  #      del special_chars[i]

# Simple but non-elegant way of deleting through parsing
# List must work its way backwards because removing pushes all values to front

#        if special_chars[i] == '@':
#            special_chars.remove(i)
#        if special_chars[i] == '#':
#            special_chars.remove(i) 
#        if special_chars[i] == '%':
#            special_chars.remove(i) 
#        if special_chars[i] == '/':
#            special_chars.remove(i) 
#        if special_chars[i] == ':':
#            special_chars.remove(i) 
# \ is escape char so must use ASCII code
#        if special_chars[i] == "\x92":
#            special_chars.remove(i) 

def rand_gen():
    fuzz_string = ""
    # random.choice only takes lists
    # Generate a loop to create fuzzed input
    for i in range(random.randrange(MIN_LEN, MAX_LEN)): 
        lAlpha = random.choice(lowercase_alpha)
        uAlpha = random.choice(uppercase_alpha)
        sChar = random.choice(special_chars)
        # Pick randomly between 3 variables
        fuzz_string += random.choice([lAlpha, uAlpha, sChar])
    # Also seems interesting https://stackoverflow.com/questions/32288236/how-do-i-randomly-select-a-variable-from-a-list-and-then-modify-it-in-python
    return fuzz_string

