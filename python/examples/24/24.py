"""
Return on functions
"""

# Example 1


def add_numbers(a, b):
    return a + b


result = add_numbers(5, 3)
print(result)  # Outputs: 8

# Example 2


def calculator(a, b):
    add = a + b
    substract = a - b
    muliply = a * b
    divide = a / b
    return add, substract, muliply, divide


add, substract, muliply, divide = calculator(10, 5)
