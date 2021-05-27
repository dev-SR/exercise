def days_to_units(num_of_days, conversion_unit):
    """
    Convert Days to Seconds
    """
    if conversion_unit == 'hours':
        return f"{num_of_days} days are {num_of_days * 24} hours"
    elif conversion_unit == 'minutes':
        return f"{num_of_days} days are {num_of_days * 24*60} minutes"
    else:
        return "unsupported unit"


def validate_and_execute():
    try:
        user_input_number = int(days_and_unit_dictionary['days'])
        if user_input_number > 0:
            calculated_value = days_to_units(
                user_input_number, days_and_unit_dictionary['unit'])
            print(calculated_value)
        elif user_input_number == 0:
            print("you entered a 0, please enter a valid positive number")
        else:
            print("You've entered a negative number")
    except ValueError:
        print("your input is not a number. Don't ruin my program")


user_input = ""
while user_input != "exit":
    user_input = input("\nEnter in days:unit form ex:[10:minutes]\n")
    days_and_units = user_input.split(":")
    days_and_unit_dictionary = {
        "days": days_and_units[0], "unit": days_and_units[1]}
    print(days_and_unit_dictionary)
    validate_and_execute()
