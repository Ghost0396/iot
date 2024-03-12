import os
import csv

filepath = 'python/examples/26/example.csv'
if os.path.exists(filepath):
    with open(filepath, 'r') as file:
        reader = csv.reader(file)
        for row in reader:
            print(row)
            name, age, city = row
            print('Name: {}, Age: {}, City: {}'.format(name, age, city))
else:
    print(f"The file {filepath} does not exist.")

# print(os.listdir(path='.'))
# print(os.getcwd())
