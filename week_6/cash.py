# TODO

# Copied the exercise done in C and "translating" it to Python. First try was without main function, didnt work.

from cs50 import get_float

#Making sure the user writes a number bigger than 0
while True:

    # Using float number as requested, so we can use dollars for the prompt
    dollars = get_float("Change owed: ")
    if dollars > 0:
        break

def main():


        # Rounding the dollars so we can use the same logic as in C
        cents = round(dollars*100)

        # Calculate the number of quarters to give the customer
        quarters = calculate_quarters(cents)
        cents = cents - quarters * 25

        # Calculate the number of dimes to give the customer
        dimes = calculate_dimes(cents)
        cents = cents - dimes * 10

        # Calculate the number of nickels to give the customer
        nickels = calculate_nickels(cents)
        cents = cents - nickels * 5

        # Calculate the number of pennies to give the customer
        pennies = calculate_pennies(cents)
        cents = cents - pennies * 1

        # Sum coins
        coins = quarters + dimes + nickels + pennies

        # Print total number of coins to give the customer
        print(f"{coins}")



def calculate_quarters(cents):

    quarters = 0
    while (cents >= 25):

        cents = cents - 25
        quarters += 1

    return quarters


def calculate_dimes(cents):

    dimes = 0
    while (cents >= 10):

        cents = cents - 10
        dimes += 1

    return dimes


def calculate_nickels(cents):

    nickels = 0
    while (cents >= 5):

        cents = cents - 5
        nickels += 1

    return nickels


def calculate_pennies(cents):

    pennies = 0
    while (cents >= 1):

        cents = cents - 1
        pennies += 1

    return pennies


if __name__ == "__main__":
    main()