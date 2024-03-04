"""
Type conversion functions
"""

# int() Converts a value to an integer.
int(3.5)       # Converts float to integer (output: 3)
int("10")      # Converts string to integer (output: 10)
int(True)      # Converts boolean to integer (output: 1)

# float() Converts a value to a floating-point number.
float(1)       # Converts integer to float (output: 1.0)
float("2.5")   # Converts string to float (output: 2.5)
float(False)   # Converts boolean to float (output: 0.0)

# str() Converts a value to a string.
str(20)        # Converts integer to string (output: "20")
str(3.14)      # Converts float to string (output: "3.14")
str(True)      # Converts boolean to string (output: "True")

# bool() Converts a value to a boolean.
bool(0)        # Converts integer to boolean (output: False)
bool(1)        # Non-zero values are converted to True (output: True)
bool("")       # Empty string is converted to False (output: False)
