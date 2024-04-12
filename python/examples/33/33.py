class Animal:
    def __init__(self, name, sound):
        self.name = name
        self.sound = sound

    def make_sound(self):
        print(f"The {self.name} goes '{self.sound}'.")


class Bird(Animal):
    def __init__(self, name, sound, can_fly):
        super().__init__(name, sound)
        self.can_fly = can_fly

    def display_flying_ability(self):
        if self.can_fly:
            print(f"The {self.name} can fly.")
        else:
            print(f"The {self.name} cannot fly.")


class Mammal(Animal):
    def __init__(self, name, sound, habitat):
        super().__init__(name, sound)
        self.habitat = habitat

    def display_habitat(self):
        print(f"The {self.name} lives in {self.habitat}.")


parrot = Bird("Parrot", "squawk", True)
parrot.make_sound()  # Inherited from Animal
parrot.display_flying_ability()  # Defined in Bird

elephant = Mammal("Elephant", "trumpet", "the savannah")
elephant.make_sound()  # Inherited from Animal
elephant.display_habitat()  # Defined in Mammal
