"""
Parameters
"""

"""
1. Positional Parameters

These are the simplest form of parameters.
Each argument you pass into the function aligns with a parameter in the
order they are defined.
"""


def multiply(x, y):
    return x * y


# Call the function with positional arguments
result = multiply(2, 3)  # x=2, y=3
print(result)  # Output: 6

"""
2. Default Parameters

Parameters can have default values.
If the argument is not provided when the function is called,
the parameter uses the default value.
"""


def greet(name, message="Hello"):
    return f"{message}, {name}!"


# Call the function without providing 'message'
print(greet("Alice"))  # Output: Hello, Alice!

# Call the function, overriding the default value of 'message'
print(greet("Bob", "Goodbye"))  # Output: Goodbye, Bob!

"""
3. Keyword (Named) Parameters

You can explicitly name the arguments when calling the function,
which allows you to skip certain optional arguments or provide
them out of order.
"""


def register_user(first_name, last_name, age, country="Unknown"):
    return f"{first_name} {last_name}, Age: {age}, Country: {country}"


# Using keyword arguments to specify values out of order
print(register_user(age=30, last_name="Smith", first_name="John"))

"""
4. Variable Length Positional Parameters (*args)

When you don't know the exact number of positional
arguments that will be passed, use *args.
It collects extra arguments into a tuple.
"""


def sum_numbers(*args):
    return sum(args)


# Passing a varying number of arguments
print(sum_numbers(1, 2, 3))  # Output: 6
print(sum_numbers(1, 2, 3, 4, 5))  # Output: 15

"""
5. Variable Length Keyword Parameters (**kwargs)

For an unknown number of keyword arguments,
**kwargs collects them into a dictionary.
This is useful for handling named arguments dynamically.
"""


def user_profile(**kwargs):
    profile = ""
    for key, value in kwargs.items():
        profile += f"{key}: {value}\n"
    return profile


# Creating a user profile with varying data
print(user_profile(name="Alice", age=25, profession="Engineer"))
