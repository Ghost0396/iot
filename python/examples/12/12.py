"""
Formatting
"""

# .format() Method
name = "John"
age = 30
print("My name is {} and I am {} years old.".format(name, age))
# With positional arguments
print("My name is {0} and I am {1} years old.".format(name, age))
# With keyword arguments
print("My name is {n} and I am {a} years old.".format(n=name, a=age))

# F-strings (Formatted String Literals)
name = "John"
age = 30
print(f"My name is {name} and I am {age} years old.")
# With expressions
print(f"{name} is {age + 5} years old in five years.")
