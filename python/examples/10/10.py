"""
Checking Content
"""

# isdigit() Checks if all characters in the string are digits.
num = "12345"
print(num.isdigit())  # Output: True
num = "12345a"
print(num.isdigit())  # Output: False

# isalpha() Checks if all characters in the string are alphabetic.
word = "Hello"
print(word.isalpha())  # Output: True
word = "Hello123"
print(word.isalpha())  # Output: False

# isalnum() Checks if all characters in the string are alphanumeric
# (either alphabets or numbers).
text = "Hello123"
print(text.isalnum())  # Output: True
text = "Hello 123"
print(text.isalnum())  # Output: False

# isspace() Checks if all characters in the string are whitespace characters.
space = "   "
print(space.isspace())  # Output: True
space = " a "
print(space.isspace())  # Output: False

# startswith() Determines if the string starts with a specified substring.
text = "Python programming"
print(text.startswith("Python"))  # Output: True
print(text.startswith("python"))  # Output: False  # Case sensitive

# endswith() Determines if the string ends with a specified substring.
text = "Python programming"
print(text.endswith("programming"))  # Output: True
print(text.endswith("Programming"))  # Output: False  # Case sensitive
