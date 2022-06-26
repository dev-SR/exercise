# Custom Modules + Packages

- [Custom Modules + Packages](#custom-modules--packages)
  - [V1](#v1)
    - [Creating a custom module](#creating-a-custom-module)
    - [Importing a custom module](#importing-a-custom-module)
  - [V2:  `__init__.py`](#v2--__init__py)
  - [V3: 🌟🌟importing from child/sibling/sibling's child 📁packages📁](#v3-importing-from-childsiblingsiblings-child-packages)
    - [using `__init__.py`](#using-__init__py)

**A python 📁 `package` 📁 is a collection of modules**. Modules that are related to each other are mainly put in the same package. When a module from an external package is required in a program, that package can be imported and its modules can be put to use.

**Any Python file, whose name is the module’s name property without the `.py` extension, is a 📄 `module`📄**

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

Output:

```bash
pkg1.mod1.fn1()
pkg1.mod2.fn2()
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

Output:

```bash
pkg2.mod1.fn1()
pkg2.mod2.fn2()
```

Note that functions `fn1()` and `fn2()` are imported from the package and not from their respective modules, as done earlier. The output of the above script is:

## V3: 🌟🌟importing from child/sibling/sibling's child 📁packages📁

```bash
root:
 |
 |__pkg1:
 |    \____init__.py
 |    \__mod1.py
 |    \__child_pkg:
 |          \____init__.py
 |          \__child_mod.py
 |
 |__sibling_pkg:
 |    \____init__.py
 |    \__sibling_mod.py
 |    \__sibling_child_pkg:
 |          \____init__.py
 |          \__sibling_child_mod.py
 |
 |__main.py
 |
```

`pk1.child_pkg.child_mod.py`

```python
def fromChild():
	print("pk1.child_pkg.child_mod.fromChild()")
```

`pk2.sibling_pkg.sibling_mod.py`

```python
def fromSibling():
    print("sibling_pkg.sibling_mod.fromSibling()")
```

`pk2.sibling_pkg.sibling_child_pkg.sibling_child_mod.py`

```python
def fromChildOfSibling():
    print('sibling_pkg.sibling_child_pkg.sibling_child_mod.fromChildOfSibling()')

```

Importing from sibling modules and child packages:

`pk1.mod1.py`

```python
from .child_pkg.child_mod import fromChild
from sibling_pkg.sibling_mod import fromSibling
from sibling_pkg.sibling_child_pkg.sibling_child_mod import fromChildOfSibling


def fn1():
    print("pkg1.mod1.fn1()")
    fromChild()
    fromSibling()
    fromChildOfSibling()

```

`main.py`

```python
from pkg1.mod1 import fn1
fn1()
```

Running `main.py` :

```bash
pkg1.mod1.fn1()
pk1.child_pkg.child_mod.fromChild()
sibling_pkg.sibling_mod.fromSibling()
sibling_pkg.sibling_child_pkg.sibling_child_mod.fromChildOfSibling()
```

Must run the `main.py` to work properly.

### using `__init__.py`

`pk1.child_pkg.__init__.py`

```python
from .child_mod import *
```

`pk1.__init__.py`

```python
from .mod1 import *
```

`pk2.sibling_pkg.__init__.py`

```python
from .sibling_mod import *
from .sibling_child_pkg.sibling_child_mod import *
```

`pk2.sibling_pkg.sibling_child_pkg.__init__.py`

```python
from .sibling_child_mod import *
```
`pk1.mod1.py`

```python
from .child_pkg import fromChild
from sibling_pkg import fromSibling
from sibling_pkg.sibling_child_pkg import fromChildOfSibling

def fn1():
    print("pkg1.mod1.fn1()")
    fromChild()
    fromSibling()
    fromChildOfSibling()

```

`main.py`

```python
from pkg1 import fn1
fn1()
```

output:

```bash
pkg1.mod1.fn1()
pk1.child_pkg.child_mod.fromChild()
sibling_pkg.sibling_mod.fromSibling()
sibling_pkg.sibling_child_pkg.sibling_child_mod.fromChildOfSibling()
```

Additional: Importing everything in `main.py`


```python
from pkg1 import fromChild, fromSibling, fromChildOfSibling
def fn1():
    print("main()")
    fromChild()
    fromSibling()
    fromChildOfSibling()
fn1()
```

now: `pk1.__init__.py`

```python
from .child_pkg import *
from sibling_pkg import *
from sibling_pkg.sibling_child_pkg import *
```

output:

```python
main()
pk1.child_pkg.child_mod.fromChild()
sibling_pkg.sibling_mod.fromSibling()
sibling_pkg.sibling_child_pkg.sibling_child_mod.fromChildOfSibling()
```
