from base import days_to_units


def validate_and_execute_list():
    try:
        user_input_number = int(item)
        if user_input_number > 0:
            calculated_value = days_to_units(user_input_number)
            print(calculated_value)
        elif user_input_number == 0:
            print("you entered a 0, please enter a valid positive number")
        else:
            print("You've entered a negative number")
    except ValueError:
        print("your input is not a number. Don't ruin my program")


user_input = ""
while user_input != "exit":
    user_input = input("Enter list with space separeated:\n")
    print(user_input.split())
    for item in user_input.split():
        validate_and_execute_list()

user_input = ""
while user_input != "exit":
    user_input = input("\nEnter list with comma separeated:\n")
    print(user_input.split(', '))
    for item in user_input.split(', '):
        validate_and_execute_list()

user_input = ""
while user_input != "exit":
    user_input = input("\nEnter list with: Duplicates filtered :\n")
    list_of_days = set(user_input.split())
    print(list_of_days)
    for item in list_of_days:
        validate_and_execute_list()
