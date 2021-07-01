# Exceptions in Python


```python
try:
    age = int(input("Enter anython but number:"))
except ValueError:
    print("You didn't enter a valid int")
else:
    print("No exceptions thrown.")
print("Execution continues...")
```

    You didn't enter a valid int
    Execution continues...
    


```python
try:
    age = int(input("Enter anython but number:"))
except ValueError as ex:
    print("You didn't enter a valid int")
    print(ex)
    print(type(ex))
else:
    print("No exceptions thrown.")
print("Execution continues...")
```

    You didn't enter a valid int
    invalid literal for int() with base 10: 'abc'
    <class 'ValueError'>
    Execution continues...
    


```python
try:
    age = int(input("Enter anython but number:"))
    div = 10/age
except ValueError:
    print("You didn't enter a valid int")
except ZeroDivisionError as ex:
    print("You didn't enter a valid int")
    print(ex)
else:
    print("No exceptions thrown.")
print("Execution continues...")

print()
# Avoid duplicate expt. message with..(x1,x2..)
try:
    age = int(input("Enter anython but number:"))
    div = 10/age
except (ValueError,ZeroDivisionError) as ex:
    print("You didn't enter a valid int")
    print(ex)
else:
    print("No exceptions thrown.")
print("Execution continues...")
```

    You didn't enter a valid int
    division by zero
    Execution continues...
    
    You didn't enter a valid int
    division by zero
    Execution continues...
    

## Releasing external resources with`Finally` and 'With`


```python
# try:
#     file = open("app.py")
#     file.close()
# except FileNotFoundError:
#     print("aaa")
#     file.close()
# else:
#      file.close()

# avoiding duplication with finally
try:
    f = open("app.py")
except FileNotFoundError:
    print("aaa")
else:
    print("No expt")
finally:
    f.close()
```

### `With` to automatically release external resources without `finally`


```python
try:
    with open("app.py") as file, open("another.txt") as an:
        print("File Opened...")

except FileNotFoundError as ex:
    print(ex)
else:
    print("No expt")
```

    [Errno 2] No such file or directory: 'app.py'
    


```python

```
