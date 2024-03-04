"""
dictionaries
"""

my_dict = {'name': 'John', 'age': 30, 'city': 'New York'}

print(my_dict['name'])  # Outputs: John

# Adding or Updating Elements
# You can add a new key-value pair or update the value of an existing key.
my_dict['email'] = 'john@example.com'  # Adds a new key-value pair
my_dict['age'] = 31  # Updates the value of an existing key

# Removing Elements
# You can remove key-value pairs using del, the pop() method, or the popitem().
del my_dict['city']  # Removes the key 'city' and its value
age = my_dict.pop('age')  # Removes the key 'age' and returns its value
item = my_dict.popitem()  # Removes and returns the last inserted key-value

# .get(key[, default])
# Returns the value for a key if it exists in the dictionary.
# If the key is not found, it returns None or a specified default value.
my_dict = {'a': 1, 'b': 2}
print(my_dict.get('a'))  # Output: 1
print(my_dict.get('c'))  # Output: None
print(my_dict.get('c', 'Not Found'))  # Output: 'Not Found'

# .keys()
# Returns a view object containing the dictionary's keys.
my_dict = {'a': 1, 'b': 2}
print(list(my_dict.keys()))  # Output: ['a', 'b']

# .values()
# Returns a view object containing the dictionary's values.
my_dict = {'a': 1, 'b': 2}
print(list(my_dict.values()))  # Output: [1, 2]

# .items()
# Returns a view object containing tuples of (key, value) pairs.
my_dict = {'a': 1, 'b': 2}
print(list(my_dict.items()))  # Output: [('a', 1), ('b', 2)]
