import csv

data = [
    ["Name", "Age", "City"],
    ["John Doe", "30", "New York"],
    ["Jane Smith", "25", "Los Angeles"]
]

with open('python/examples/27/example.csv', mode='w', newline='') as file:
    writer = csv.writer(file)
    writer.writerows(data)

print("CSV file has been written successfully.")
