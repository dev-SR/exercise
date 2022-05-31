# Custom Modules + Packages

**A python `package` is a collection of modules**. Modules that are related to each other are mainly put in the same package. When a module from an external package is required in a program, that package can be imported and its modules can be put to use.

**Any Python file, whose name is the module’s name property without the `.py` extension, is a `module`.**

A package is a directory of Python modules that contains an additional `__init__.py` file, which distinguishes a package from a directory that is supposed to contain multiple Python scripts. Packages can be nested to multiple depths if each corresponding directory contains its own `__init__.py` file.

## V1

```bash
root:
 |
 |__pkg1:
 |    \__mod1.py
 |    \__mod2.py
 |
 |__main.py
 |
```

### Creating a custom module

`mod1.py`:

```python
def fn1():
    print("pkg1.mod1.fn1()")
```

`mod2.py`:

```python
def fn2():
    print("pkg1.mod1.fn2()")
```

### Importing a custom module

`main.py`

```python

# from package.module import function
from pkg1.mod1 import fn1
from pkg1.mod2 import fn2

fn1()
fn2()

from pkg1 import mod1
mod1.fn1()
```

## V2:  `__init__.py`

The package folder contains a special file called `__init__.py`, which stores the package's content. It serves two purposes:

- The Python interpreter recognizes a folder as the package if it contains `__init__.py` file.
- `__init__.py` exposes specified resources from its modules to be imported.

```bash
root:
 |
 |__pkg2:
 |    \____init__.py
 |    \__mod1.py
 |    \__mod2.py
 |
 |__main.py
 |
```

same as V1

```python
from pkg2.mod1 import fn1
from pkg2.mod2 import fn2

fn1()
fn2()
```

The `__init__.py` file is normally kept empty. However, it can also be used to choose specific functions from modules in the package folder and make them available for import. Modify `__init__.py` as below:

`__init__.py`

```python
from .mod1 import fn1
from .mod2 import *
```

The specified functions can now be imported in the interpreter session or another executable script.

`main.py`

```python
from pkg2 import fn1, fn2

fn1()
fn2()
```

Note that functions `fn1()` and `fn2()` are imported from the package and not from their respective modules, as done earlier. The output of the above script is:

