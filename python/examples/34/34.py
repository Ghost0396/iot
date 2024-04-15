try:
    # Code that might throw an exception
    result = 10 / 0
except ZeroDivisionError:
    # Code that runs if there is a ZeroDivisionError
    print("You can't divide by zero!")


# -------------------------------------------------------#

try:
    # Code that might throw an exception
    result = 10 / 2
except ZeroDivisionError:
    # Code that runs if there is a ZeroDivisionError
    print("You can't divide by zero!")
except TypeError:
    # Code that runs if there is a TypeError
    print("Type error occurred")
else:
    # Code that runs if there is no exception
    print("Division successful, result is", result)


# -------------------------------------------------------#


try:
    result = 10 / 2
except ZeroDivisionError:
    print("You can't divide by zero!")
else:
    print("Division successful, result is", result)
finally:
    print("Executing finally block")


# -------------------------------------------------------#


try:
    # Trying to access a non-existent key in a dictionary
    d = {"key": "value"}
    print(d["nonexistent_key"])
except KeyError as e:
    print(f"KeyError: {str(e)}")
