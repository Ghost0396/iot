# Functions args and kargs

## Exercise 1: Greet Function

Problem: Write a function greet that accepts a name and returns a greeting message.

    Input: greet("Alice")
    Expected Output: "Hello, Alice!"

## Exercise 2: Sum of List

Problem: Create a function sum_list that takes a list of numbers as a positional argument and returns the sum of those numbers.

    Input: sum_list([1, 2, 3, 4])
    Expected Output: 10

## Exercise 3: Full Name

Problem: Define a function full_name that takes first and last names as keyword arguments and returns the full name.

    Input: full_name(first_name="John", last_name="Doe")
    Expected Output: "John Doe"

## Exercise 4: Power Function

Problem: Implement a function power that takes a base and an exponent. If the exponent is not provided, it should default to 2.

    Input: power(3, 3)
    Expected Output: 27
    Input: power(4)
    Expected Output: 16

## Exercise 5: Dynamic Greeting

Problem: Write a function dynamic_greeting that accepts any number of names (*args) and returns a greeting message for each name.

    Input: dynamic_greeting("Alice", "Bob", "Charlie")
    Expected Output: ["Hello, Alice!", "Hello, Bob!", "Hello, Charlie!"]

## Exercise 6: Pizza Toppings

Problem: Create a function pizza_order that takes a mandatory size argument and any number of toppings (*args) to be added to the pizza. Return a description of the pizza order.

    Input: pizza_order("Large", "Pepperoni", "Mushrooms")
    Expected Output: "Large pizza with Pepperoni, Mushrooms"

## Exercise 7: User Registration

Problem: Define a function register_user that accepts mandatory email and password parameters, and any number of additional user details as keyword arguments (**kwargs). Return the user's details as a dictionary.

    Input: register_user(email="john.doe@example.com", password="1234", first_name="John", last_name="Doe")
    Expected Output: {'email': 'john.doe@example.com', 'password': '1234', 'first_name': 'John', 'last_name': 'Doe'}