# Modules

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