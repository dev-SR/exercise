from basic import days_to_units

# !Validating text , though don't works with decimal and negative numbers
# ! isdigit don't process a negative number


def validate_and_execute2():
    if user_input.isdigit():
        user_input_number = int(user_input)
        if user_input_number > 0:
            calculated_value = days_to_units(user_input_number)
            print(calculated_value)
        elif user_input_number == 0:
            print("you entered a 0, please enter a valid positive number")
    else:  # if not a number
        print("your input is not a number. Don't ruin my program")


# ?test 2:
user_input = ""
while user_input != "exit":
    user_input = input("Hey, enter a number of days and I will convert it ot hours\n")
    validate_and_execute2()


# # !Handelling with try catch
def validate_and_execute3():
    try:
        user_input_number = int(user_input)
        if user_input_number > 0:
            calculated_value = days_to_units(user_input_number)
            print(calculated_value)
        elif user_input_number == 0:
            print("you entered a 0, please enter a valid positive number\n")
        else:
            print("You've entered a negative number\n")
    except ValueError:
        print("your input is not a number. Don't ruin my program\n")


user_input = ""
while user_input != "exit":
    user_input = input("Enter a number:\n")
    validate_and_execute3()
