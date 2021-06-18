from datetime import datetime

user_input = input(
    "enter your goal with a deadline separated by colon [lear ML:29.04.2021]\n")

input_list = user_input.split(':')

goal = input_list[0]
deadline = input_list[1]

deadline_date = datetime.strptime(deadline, "%d.%m.%Y")
today_date = datetime.today()

time_till = deadline_date - today_date

hours_till = int(time_till.total_seconds()/60/60)

print(f"Dear User! Time remaining for your goal: {goal} is {hours_till} hours")


"""
IN: Lear ML:24.05.2021 
OUT: Dear User! Time remaining for your goal: Lear ML is 598 hours
"""
