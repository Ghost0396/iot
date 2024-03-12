import csv

new_data = ["Alice Johnson", "28", "Seattle"]

with open('python/examples/27/example.csv', mode='a', newline='') as file:
    writer = csv.writer(file)
    writer.writerow(new_data)

print("New data has been appended to the CSV file.")
