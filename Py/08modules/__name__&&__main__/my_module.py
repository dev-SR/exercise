def greeting(name):
    return "Hello, "+name


print("I'm inside a module my_module.py and __name__ = ", __name__)

if __name__ == '__main__':
    print("I'm very confidential code...")
