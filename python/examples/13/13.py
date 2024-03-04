"""
SPLIT
"""

text = "Hello World"
result = text.split()
print(result)  # Output: ['Hello', 'World']

text = "apple,banana,cherry"
result = text.split(',')
print(result)  # Output: ['apple', 'banana', 'cherry']

text = "one two three four"
result = text.split(' ', 2)
print(result)  # Output: ['one', 'two', 'three four']
