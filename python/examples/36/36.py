names = ["Alice", "Bob", "Catherine"]
ages = [25, 30, 28]

zipped = zip(names, ages)
print(list(zipped))  # Output: [('Alice', 25), ('Bob', 30), ('Catherine', 28)]

names = ["Alice", "Bob", "Catherine"]
ages = [25, 30, 28]
jobs = ["Engineer", "Doctor", "Artist"]

zipped = zip(names, ages, jobs)
print(list(zipped))  # Output: [('Alice', 25, 'Engineer'),
# ('Bob', 30, 'Doctor'), ('Catherine', 28, 'Artist')]

names = ["Alice", "Bob"]
ages = [25, 30, 28]

zipped = zip(names, ages)
print(list(zipped))  # Output: [('Alice', 25), ('Bob', 30)]
