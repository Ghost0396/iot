"""
Searching and Replacing
"""

# find() Searches the string for a specified value and returns the first
# position of where it was found, or -1 if not found.
text = "Hello, welcome to my world."
pos = text.find("welcome")
print(pos)  # Output: 7
pos = text.find("Python")
print(pos)  # Output: -1

# rfind() Similar to find(), but searches for the last occurrence
# of the substring.
text = "Hello, welcome to my world. welcome again!"
pos = text.rfind("welcome")
print(pos)  # Output: 25

# replace() Replaces a specified value with another value in the string.
text = "Hello, welcome to my world."
new_text = text.replace("welcome", "goodbye")
print(new_text)  # Output: Hello, goodbye to my world.

# Replacing with a count
new_text = text.replace("o", "O", 2)  # Only replace the first 2 occurrences
print(new_text)  # Output: HellO, welcOme to my world.

# count() Returns the number of times a specified value occurs in the string.
text = "Hello, welcome to my world. Welcome to Python."
count = text.count("welcome")
print(count)  # Output: 1

# Case insensitive count
count = text.lower().count("welcome")
print(count)  # Output: 2
