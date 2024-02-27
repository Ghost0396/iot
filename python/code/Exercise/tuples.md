# Tuples

## Exercise 1: Tuple Creation and Access

    1. Create a tuple named colors containing at least 4 different color names as strings.
    
    2. Print the first and last color in the tuple.
    Create a new tuple mixed that combines colors with another tuple of your choice containing different types of data (e.g., numbers, strings).

Solution 1

python

colors = ("red", "green", "blue", "yellow")
print("First color:", colors[0])
print("Last color:", colors[-1])

mixed = colors + (1, 2, "circle")
print("Mixed tuple:", mixed)

Exercise 2: Tuples and Looping

    Given the tuple numbers = (10, 20, 30, 40, 50), write a loop that iterates through the tuple and prints each value.

Solution 2

python

numbers = (10, 20, 30, 40, 50)
for number in numbers:
    print(number)

Exercise 3: Tuple Unpacking

    Create a tuple person_info containing a name, age, and country.
    Unpack these values into variables name, age, and country respectively, and print them.

Solution 3

python

person_info = ("Alice", 30, "Canada")
name, age, country = person_info
print("Name:", name)
print("Age:", age)
print("Country:", country)

Exercise 4: Searching in Tuples

    Given a tuple items = ("apple", "banana", "cherry", "date"), write a program that checks if "banana" is in items.
    If "banana" is found, print its index in the tuple.

Solution 4

python

items = ("apple", "banana", "cherry", "date")
if "banana" in items:
    print("Index of 'banana':", items.index("banana"))

Exercise 5: Tuple Methods

    Create a tuple numbers with some repeated elements (e.g., 1, 2, 3, 2, 4, 4, 2).
    Use a tuple method to count how many times the number 2 appears in the tuple.
    Find the index of the first occurrence of the number 4.