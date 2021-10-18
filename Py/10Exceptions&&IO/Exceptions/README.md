- [Exceptions in Python](#exceptions-in-python)
  - [Try - Except](#try---except)
  - [Releasing external resources with`Finally` and `With`](#releasing-external-resources-withfinally-and-with)
    - [Finally](#finally)
    - [`With` to automatically release external resources without `finally`](#with-to-automatically-release-external-resources-without-finally)
  - [Raising Exception](#raising-exception)

# Exceptions in Python

- Whenever these error occur, Python creates an exception object
- As a programmer, our task is to handle these exceptions appropriately


```python
"Hello" + 1
```


    ---------------------------------------------------------------------------

    TypeError                                 Traceback (most recent call last)

    <ipython-input-2-48a28808618d> in <module>
    ----> 1 "Hello" + 1


    TypeError: can only concatenate str (not "int") to str



```python
print(str(dir(__builtins__))[0:200],".....")
```

    ['ArithmeticError', 'AssertionError', 'AttributeError', 'BaseException', 'BlockingIOError', 'BrokenPipeError', 'BufferError', 'BytesWarning', 'ChildProcessError', 'ConnectionAbortedError', 'Connection .....


## Try - Except

- whenever an exception occur, it makes our program crash if not handled properly.
- To avoid this issue, we use Try block. The suspected line that can throw any error, we put inside try block.
- Except Block will help to receive the program flow if any line inside try-block throws an error.


```python
l = [2, 0, 'Hello', None]

for el in l:
	print("Current el: ", el)
	res = 5/int(el)
	print("Result: ", res)
```

    Current el:  2
    Result:  2.5
    Current el:  0



    ---------------------------------------------------------------------------

    ZeroDivisionError                         Traceback (most recent call last)

    <ipython-input-9-3788d6a3482d> in <module>
          3 for el in l:
          4                 print("Current el: ", el)
    ----> 5                 res = 5/int(el)
          6                 print("Result: ", res)


    ZeroDivisionError: division by zero



```python
l = [2,0,'Hello',None]

for el in l:
	try:
		print("Current el: ",el)
		res = 5/int(el)
		print("Result: ",res)
	except:
		pass
```

    Current el:  2
    Result:  2.5
    Current el:  0
    Current el:  Hello
    Current el:  None



```python
for el in l:
	try:
		print("Current el: ", el)
		res = 5/int(el)
		print("Result: ", res)
	except Exception as e:
		print("Error caused: ",e)
		print(sys.exc_info()[0])
	print("-"*50)

print("\nThere are 100 more lines.")
```

    Current el:  2
    Result:  2.5
    --------------------------------------------------
    Current el:  0
    Error caused:  division by zero
    <class 'ZeroDivisionError'>
    --------------------------------------------------
    Current el:  Hello
    Error caused:  invalid literal for int() with base 10: 'Hello'
    <class 'ValueError'>
    --------------------------------------------------
    Current el:  None
    Error caused:  int() argument must be a string, a bytes-like object or a number, not 'NoneType'
    <class 'TypeError'>
    --------------------------------------------------

    There are 100 more lines.



```python
for el in l:
	try:
		print("Current el: ", el)
		res = 5/int(el)
		print("Result: ", res)
	except ValueError as ve:
		print("ValueError caused: ", ve)
	except ZeroDivisionError as ze:
		print("Don't divide by zero: ", ze)
	except Exception as e:
		print("Error caused: ", e)
		print(sys.exc_info()[0])
	print("-"*50)

print("\nThere are 100 more lines.")

```

    Current el:  2
    Result:  2.5
    --------------------------------------------------
    Current el:  0
    Don't divide by zero:  division by zero
    --------------------------------------------------
    Current el:  Hello
    ValueError caused:  invalid literal for int() with base 10: 'Hello'
    --------------------------------------------------
    Current el:  None
    Error caused:  int() argument must be a string, a bytes-like object or a number, not 'NoneType'
    <class 'TypeError'>
    --------------------------------------------------

    There are 100 more lines.



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


## Releasing external resources with`Finally` and `With`

### Finally

- finally block is executed everytime, no matter error occurred or not.
- this can be used to release the allocated resources.
- e.g. closing a file, or closing a db connection


```python
try:
	ans = 5/0
	print(ans)
except Exception as e:
    print("Error occurred :",e)
finally:
    print("I will always execute")

```

    Error occurred : division by zero
    I will always execute



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


## Raising Exception

- programmers can create new exceptions whenever code doesn't work in a usual way.
- raise keyword is used to raise an Exception


```python
raise Exception("Error")
```


    ---------------------------------------------------------------------------

    Exception                                 Traceback (most recent call last)

    <ipython-input-16-2ebba92f5f3b> in <module>
    ----> 1 raise Exception("Error")


    Exception: Error



```python
try:
	name = input("Enter your name :")

	print("Hello ",name)
	if len(name) < 4:
		raise ValueError("Name cannot be less than 4 characters")

except Exception as e:
	print("Error occurred :",e)
	print(sys.exc_info()[0])
```

    Hello  abc
    Error occurred : Name cannot be less than 4 characters
    <class 'ValueError'>

