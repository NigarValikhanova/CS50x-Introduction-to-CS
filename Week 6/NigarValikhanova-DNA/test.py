import csv

with open("large.csv") as file:
    reader = csv.DictReader(file)
    print(reader.fieldnames)
