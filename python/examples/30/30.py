class Car:
    def __init__(self, make, model, fuel_level=100):
        self.make = make
        self.model = model
        self.fuel_level = fuel_level

    def drive(self):
        if self.fuel_level > 0:
            print(f"The {self.make} {self.model} is now driving.")
            self.fuel_level -= 10  # Decrease fuel level by 10 units
        else:
            print("Cannot drive. The car is out of fuel!")

    def refuel(self, amount):
        if amount <= 0:
            print("Refuel amount must be positive.")
        else:
            self.fuel_level += amount
            if self.fuel_level > 100:
                self.fuel_level = 100
            print(f"The car has been refueled. Fuel level: {self.fuel_level}")

    def display_fuel_level(self):
        print(f"Fuel level: {self.fuel_level}")


# Creating an instance of the Car class
my_car = Car("Toyota", "Corolla")

# Display initial fuel level
my_car.display_fuel_level()  # Expected: Fuel level: 100

# Let's drive the car
my_car.drive()  # Decreases fuel level by 10
my_car.display_fuel_level()  # Expected: Fuel level: 90

# Drive until fuel is depleted to demonstrate the check
for _ in range(9):
    my_car.drive()

# Attempt to drive without fuel
my_car.drive()  # Expected: Cannot drive. The car is out of fuel!

# Refueling the car
my_car.refuel(50)  # Adds 50 to the fuel level
my_car.display_fuel_level()
