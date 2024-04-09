class Dog:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def bark(self):
        return f"{self.name} says woof!"


joels_dog = Dog(name="Toby", age=12)
print(joels_dog.name)  # Accessing an attribute
print(joels_dog.bark())  # Calling a method

luis_dog = Dog(name="Manchas", age=5)
print(luis_dog.name)  # Accessing an attribute
print(luis_dog.bark())  # Calling a method
