# TODO


# Using the same validation as we used in hello.py
while True:
    try:
        # Validating input
        height = int(input("Height: "))
        if height > 0 and height <= 8:
            # Tried to apply the exact loops as done in mario.c but got confusing, so after several trys, the logic remains the same, but since there is concatenation in python we will use it.
            j = height - 1 #Declaring a J loop as variable, it will determinate the number of blank spaces needed, so, opposite thatn the user input each time, it will lower every time
            for i in range(1, height+1):
               print((" " * j)+("#" * i)) # Using concatenation to print everytning on the same line every time
               # Making our variables shrink, because on every line we need one less space to print and one lower number to multiply I by. Because we are not printing height each line, but i.
               height -= 1
               j -= 1
            break
        else:
            # error if user doesnt provide the right int
            print("Invalid input, int between 1 and 8 needed")

    except ValueError:
        # Error if user doesnt provide an int
        print("Invalid input, int between 1 and 8 needed")
    continue


