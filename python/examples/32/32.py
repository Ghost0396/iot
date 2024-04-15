# Base class
class Animal:
    def __init__(self, name):
        self.name = name

    def speak(self):
        raise NotImplementedError("Subclasses must implement abstract method")


# Derived class 1
class Dog(Animal):
    def speak(self):
        return f"{self.name} says Woof!"


# Derived class 2
class Cat(Animal):
    def speak(self):
        return f"{self.name} says Meow!"


# Creating instances of the derived classes
dog = Dog("Buddy")
cat = Cat("manchas")

# Each instance uses the inherited structure but performs its unique action
print(dog.speak())
print(cat.speak())
