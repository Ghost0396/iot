class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def __str__(self):
        return f"Person(name={self.name}, age={self.age})"


# Creating an instance of Person
person = Person("Alice", 30)

# Using print function calls __str__ method
print(person)
