# Flow Control

- [Flow Control](#flow-control)
  - [Truthy and Falsy Values](#truthy-and-falsy-values)
    - [Falsy Values](#falsy-values)
      - [Sequences and Collections:](#sequences-and-collections)
      - [Numbers](#numbers)
      - [Constants](#constants)
    - [Truthy Values](#truthy-values)
      - [Truthy values include:](#truthy-values-include)
  - [Comparison](#comparison)
    - [Chained Comparison](#chained-comparison)
    - [! -> not](#---not)
- [FOR](#for)
    - [Continue](#continue)
    - [break](#break)
- [WHILE](#while)
    - [Guessing Game](#guessing-game)
    - [Hi Lo Game](#hi-lo-game)


```python
"""
cd .\Py\02flow_controll\
jupyter nbconvert --to markdown py_controlflow.ipynb --output README.md
"""
```

## Truthy and Falsy Values



> - Values that evaluate to False are considered Falsy.
> - Values that evaluate to True are considered Truthy.

### Falsy Values


#### Sequences and Collections:



- Empty lists []
- Empty tuples ()
- Empty dictionaries {}
- Empty sets set()
= Empty strings ""
- Empty ranges range(0)



#### Numbers



- Zero of any numeric type.
- Integer: 0
- Float: 0.0
- Complex: 0j



#### Constants



- None
- False



### Truthy Values



> By default, an object is considered true.



#### Truthy values include:



- Non-empty sequences or collections (lists, tuples, strings, dictionaries, sets).
- Numeric values that are not zero.
- True

## Comparison

### Chained Comparison


```python
age = int(input("How old are you?"))
# if age >= 16 and age <= 65;
if 16 <= age <=65:
    print("Have a good day at work")
else:
    print("Enjoy your free time")
```

    Enjoy your free time


### ! -> not


```python
day = "Firday"
temperature = 30
raining = False
if day == "Saturday" and temperature > 27 or not raining:
    print("Go swimming")
else:
    print("Learn Python")
```

    Go swimming



```python
name = input("Please enter your name: ")
if name:
    print(f"Hello, {name}")
else:
    print("Are you the man with no name?")
```

    Are you the man with no name?


# FOR


```python
number = "9,233;372:036 854,775;807"
separators = ""
for char in number:
    if not char.isnumeric():
        separators = separators + char

print(separators)
values = "".join(char if char not in separators else " " for char in number);
values
```

    ,;: ,;





    '9 233 372 036 854 775 807'



### Continue


```python
shopping_list = ['milk','pasta','eggs','rice','bread']
for item in shopping_list:
    if item == 'rice':
        continue # skip if rice
    print("Buying List: " + item)
```

    Buying List: milk
    Buying List: pasta
    Buying List: eggs
    Buying List: bread


### break


```python
shopping_list = ['milk','pasta','eggs','rice','bread']
item_to_found = "rice"
found_at = None

for index in range(len(shopping_list)):
    if shopping_list[index] == item_to_found:
        found_at = index
        break # stop if rice

if found_at is not None:
    print(f"Item found at postiton {found_at}")
else:
    print(f"{item_to_found} not found")
```

    Item found at postiton 3


# WHILE


```python
while 1:
	stop = input("Press 'q' to quit: ")
	if stop == 'q':
		break
```


```python
available = ["north","south","east","west"]
chosen = ""
while chosen not in available:
    chosen = input("Please chooose a direction: ")
    if chosen.casefold() == 'quit':
        print("Game Over")
        break

if not chosen:
    print(f"You have choosen {chosen}")
```

### Guessing Game


```python
from random import randint
answer = randint(1,10)
print(answer)
print(f"Please guess number between 1 and {answer}")

guess = 1000
while guess != answer:
    guess = int(input())
    if guess ==0:
        break
    if guess == answer:
        print("Well done, you guessed it")
    else:
        if guess < answer:
            print("Please guess higher")
        else:
            print("Please guess lower")
```

    8
    Please guess number between 1 and 8
    Please guess higher
    Please guess higher
    Please guess higher
    Please guess higher
    Well done, you guessed it


### Hi Lo Game


```python
low =1
high =1000

print(f"Please think of a number between {low} and {high}")

guesses = 1
guess=1000
while True:
    print(f"\t Guessing in the range of {low} and {high}")
    guess = low + (high -low) // 2
    high_low = input (f"My guess is {}.")
```
