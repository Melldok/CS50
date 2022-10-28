# TODO

#For this exercise we copied the exact same logic we did on C but translated to Python

from cs50 import get_string

text = get_string("Text: ")

# Declaring all the variables we will need
letters = 0
words = 1
sentences = 0

# A loop to check the conditions
#As mentioned in the lecture, Python doesnt understand a string like an array of characters, so we use Pythons logic to loop through each character:
for c in text:

    if (c.isalpha()): # isalpha will check if the character is a letter, and if it is, it will sum 1 to letters

        letters += 1

    elif (c.isspace()): # isspace will chek if the character is a space, if it is, it will add one point to words, cause each word is separated by a space, but we will need to add one extra point to words at the end, cause the last word doesnt come with a space.

        words += 1

    elif (c == '.' or c == '?' or c == '!'): # I used ispunct at the beginning to add points if it's a punctuation mark, but given the problem, it shouuld only add points if one of these three options are met.

        sentences += 1

# Given the formula on the exercise, we calculate L and S and apply

L = letters / words * 100
S = sentences / words * 100

        # Data not working without adding the (float) mark, so we add it, so the pc treats the data as a floaat.
index = round(0.0588 * L - 0.296 * S - 15.8)

if(index < 1):

    print("Before Grade 1")

elif(index > 16):

    print("Grade 16+")

else:

    print(f"Grade {index}")




