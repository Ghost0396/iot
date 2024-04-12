# Inheritance
## Exercise 1: Basic Inheritance

### Objective: 
Create a simple class hierarchy that demonstrates basic inheritance.

### Description:

- Define a base class named Vehicle with attributes make and model, and a method display_info() that prints the make and model of the vehicle.
- Define two subclasses, Car and Motorcycle, that inherit from Vehicle. Add an attribute number_of_wheels to each subclass (4 for Car, 2 for Motorcycle), and override the display_info() method to include the number of wheels.
- Instantiate an object of each subclass and call their display_info() method.

### Expected Output: 
When you run your program, it should display the make, model, and number of wheels for each vehicle.

## Exercise 2: Method Overriding and super()

### Objective: 
Practice using the super() function to call methods from a parent class.

### Description:

- Create a base class named Person with an __init__ method that takes name and age as parameters and initializes them.
- Create a subclass named Employee that inherits from Person. The Employee class should have its own __init__ method that also takes employee_id as a parameter, in addition to the name and age.
- In the Employee class's __init__ method, use super() to call the parent class's __init__ method for name and age, and then initialize employee_id.
- Instantiate an Employee object with all three pieces of information and verify that it stores all information correctly.

### Expected Output: 
When inspecting the Employee object, you should see the name, age, and employee ID correctly assigned.

## Exercise 6: Using Special Methods in Inheritance

### Objective: 
Explore the use of special methods in a class hierarchy.

### Description:

- Create a base class Book with an __init__ method for title and author, and implement the __str__ method to return a formatted string containing the title and author.
- Create a subclass EBook that inherits from Book and adds an attribute for file_format. Override the __str__ method to include the file format in the string representation.
- Instantiate a Book and an EBook, and print both to see their string representations.

### Expected Outcome
Understands how special methods like __str__ are inherited and overridden in subclass.