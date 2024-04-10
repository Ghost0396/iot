# Methods
## Exercise 1: Implement a Circle Class

### Objective: 
Create a Circle class that models a circle with a radius. The class should have:

- An __init__ method that initializes the circle's radius, with a default value of 1 if no radius is provided.
- An instance method area that calculates and returns the area of the circle.
- An instance method perimeter that calculates and returns the perimeter of the circle.

Use the formulae:

    Area = π * radius^2
    Perimeter = 2 * π * radius

Code:
```
class Circle:
    # Your code here

# Example usage
circle = Circle(5)
print(circle.area())  # Should print the area of the circle
print(circle.perimeter())  # Should print the perimeter of the circle
```

## Exercise 2: Create a Student Class

### Objective: 
Design a Student class that represents a student with the following characteristics:

- An __init__ method that initializes the student's name and an empty list of grades.
- An instance method add_grade that takes a grade and adds it to the list of grades.
- An instance method calculate_average that calculates and returns the average of the grades.

```
class Student:
    # Your code here

# Example usage
student = Student("John Doe")
student.add_grade(88)
student.add_grade(92)
student.add_grade(79)
print(student.calculate_average())  # Should print the average grade
```

## Exercise 3: Build a BankAccount Class

### Objective: 
Implement a BankAccount class to model a simple bank account, with the following details:

- An __init__ method that initializes the account holder's name and starting balance (default to 0 if not provided).
- An instance method deposit that takes an amount and adds it to the account balance. Ensure the deposit amount is positive; otherwise, print a message.
- An instance method withdraw that takes an amount and subtracts it from the account balance if sufficient funds are available. If the amount is negative or the balance is insufficient, print a message.

```
class BankAccount:
    # Your code here

# Example usage
account = BankAccount("Jane Doe", 1000)
account.deposit(500)
account.withdraw(200)
account.withdraw(1500)  # Should warn about insufficient funds
```