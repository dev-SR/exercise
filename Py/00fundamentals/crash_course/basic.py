from base import days_to_units
# ! fails with text,decimal


def validate_and_execute():
    user_input_number = int(user_input)
    if user_input_number > 0:
        calculated_value = days_to_units(user_input_number)
        print(calculated_value)
    elif user_input_number == 0:
        print("you entered a 0, please enter a valid positive number")
    else:
        print("You've entered a negative number")


# ?test 1:
user_input = ""
while user_input != "exit":
    user_input = input(
        "Hey, enter a number of days and I will convert it ot hours\n")
    validate_and_execute()
