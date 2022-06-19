from sibling_pkg.sibling_mod import fromSibling
from .child_pkg.child_mod import fromChild
from sibling_pkg.sibling_child_pkg.sibling_child_mod import fromChildOfSibling


def fn1():
    print("pkg1.mod1.fn1()")
    fromChild()
    fromSibling()
    fromChildOfSibling()
