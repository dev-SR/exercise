# Modules

**Any text file with the `.py` extension containing Python code is basically a module.** Different Python objects such as functions, classes, variables, constants, etc., defined in one module can be made available to an interpreter session or another Python script by using the import statement. Functions defined in built-in modules need to be imported before use. On similar lines, a custom module may have one or more user-defined Python objects in it. These objects can be imported in the interpreter session or another script.


- Modules refer to a file containing Python code.
- Modules are used to break down large programs into small manageable and organized files (modular code).
- for e.g. : if a file `pretty.py` is called a module and its module name would be `pretty`.

## Different ways of importing modules

```python
# import <module>
import math
# import <module> as <alias>
import math as m
m.factorial(5)
# syntax for importing specific functions from a module
# from <module> import <function>, <variable>, <class>
from math import factorial, pi
factorial(5)
#
from math import *
```