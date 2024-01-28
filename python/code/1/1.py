"""
The print() function in Python is one of the most fundamental and frequently used functions. It's used to output data to the standard output device, which is usually your screen.
Here's a breakdown of how print() works and its features:
Basic Usage

    Syntax: print(object(s), sep=' ', end='\n', file=sys.stdout, flush=False)
    Purpose: To display the specified message or data to the screen.

Parameters

    object(s): This can be any number of objects, separated by commas. print() converts each object to a string and writes it to the standard output.
    sep=' ': This is the separator between the objects if you print more than one. By default, it's a space. You can set it to any string.
    end='\n': This specifies what to print at the end. Default is the newline character (\n), which means each print() statement adds a new line at the end.
    file=sys.stdout: This defines the output stream. The default is the system's standard output (usually the screen). You can redirect the output to a file or another device.
    flush=False: When set to True, the stream is forcibly flushed. In most cases, you won't need to use this parameter.
"""

print("Hello World")
