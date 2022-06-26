from .child_pkg import fromChild
from sibling_pkg import fromSibling
from sibling_pkg.sibling_child_pkg import fromChildOfSibling


def fn1():
    print("pkg1.mod1.fn1()")
    fromChild()
    fromSibling()
    fromChildOfSibling()
