"""
Logical Operators
"""

# and: Returns True if both statements are true.
print((5 > 3) and (10 > 5))  # Output: True, because both conditions are true
print((5 > 3) and (5 > 10))  # Output: False, because the second condition is false # noqa: E501

# or: Returns True if at least one of the statements is true.
print((5 > 3) or (5 > 10))  # Output: True, because the first condition is true
print((5 < 3) or (5 > 10))  # Output: False, because both conditions are false

# not: Reverse the logical state of its operand. If a condition is true, the not operator will make it false, and vice versa. # noqa: E501
print(not (5 > 3))  # Output: False, because 5 > 3 is true, so not true is false # noqa: E501
print(not (5 < 3))  # Output: True, because 5 < 3 is false, so not false is true # noqa: E501
