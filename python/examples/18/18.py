"""
SLICING
"""

# sequence[start:stop:step]

# Basic Slicing
my_string = "Hello, World!"
print(my_string[1:5])  # Output: 'ello'

# Omitting the Start and Stop
print(my_string[:5])  # Output: 'Hello'
print(my_string[7:])  # Output: 'World!'

# Negative Indices
print(my_string[-6:-1])  # Output: 'World'

# Using Step
print(my_string[::2])  # Output: 'Hlo ol!'

# Reversing a String
print(my_string[::-1])  # Output: '!dlroW ,olleH'
