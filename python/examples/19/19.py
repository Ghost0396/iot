"""
LISTS METHODS
"""

# 1. append()
# Purpose: Adds an item to the end of the list.
# Syntax: list.append(item)

my_list = [1, 2, 3]
my_list.append(4)  # my_list is now [1, 2, 3, 4]

# 2. extend()
# Purpose: Adds all elements of an iterable to the end of the list.
# Syntax: list.extend(iterable)

my_list = [1, 2, 3]
my_list.extend([4, 5])  # my_list is now [1, 2, 3, 4, 5]

# 3. insert()
# Purpose: Inserts an item at a given position.
# Syntax: list.insert(index, item)

my_list = [1, 2, 4]
my_list.insert(2, 3)  # my_list is now [1, 2, 3, 4]

# 4. remove()
# Purpose: Removes the first item from the list whose value is equal to
# the specified value. Raises a ValueError if the item is not found.
# Syntax: list.remove(item)

my_list = [1, 2, 3, 2, 1]
my_list.remove(2)  # my_list is now [1, 3, 2, 1]

# 5. pop()
# Purpose: Removes the item at the given position in the list, and returns it.
# If no index is specified, pop() removes and returns the last item in the list
# Syntax: list.pop([index])

my_list = [1, 2, 3, 4]
popped_item = my_list.pop(2)  # popped_item is 3, my_list is now [1, 2, 4]

# 6. clear()
# Purpose: Removes all items from the list.
# Syntax: list.clear()

my_list = [1, 2, 3]
my_list.clear()  # my_list is now []

# 7. index()
# Purpose: Returns the index of the first item whose value is equal to
# the specified value. Raises a ValueError if the item is not found.
# Syntax: list.index(item, [start, [end]])

my_list = [1, 2, 3, 4, 3]
index = my_list.index(3)  # index is 2

# 8. count()
# Purpose: Returns the number of times the specified value appears in the list.
# Syntax: list.count(item)

my_list = [1, 2, 3, 2, 1, 2]
count = my_list.count(2)  # count is 3

# 9. sort()
# Purpose: Sorts the items of the list in place (the list is modified).
# Syntax: list.sort(key=None, reverse=False)

my_list = [3, 1, 4, 1, 5, 9, 2]
my_list.sort()  # my_list is now [1, 1, 2, 3, 4, 5, 9]
