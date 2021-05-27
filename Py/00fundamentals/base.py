units = 24 * 60 * 60
name_of_units = "hours"

print("*" * 50)


def days_to_units(num_of_days):
    """
    Convert Days to Seconds
    """
    return f"{num_of_days} days are {num_of_days * units} {name_of_units}"
