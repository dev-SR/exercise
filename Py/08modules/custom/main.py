from pkg1 import fromChild, fromSibling, fromChildOfSibling


def fn1():
    print("main()")
    fromChild()
    fromSibling()
    fromChildOfSibling()


fn1()
