# Modules

- Modules refer to a file containing Python code.
- Modules are used to break down large programs into small manageable and organized files (modular code).
- for e.g. : if a file `pretty.py` is called a module and its module name would be `pretty`.

## Different ways of importing modules

```python
#
import math
#
import math as m
m.factorial(5)
#
from math import factorial
factorial(5)
#
from math import *
```