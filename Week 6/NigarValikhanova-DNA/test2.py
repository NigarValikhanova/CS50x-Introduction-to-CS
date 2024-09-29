import csv

rows = []
with open("large.csv") as file:
    reader = csv.DictReader(file)
    for row in reader:
        rows.append(row)


for row in rows:
    print(row)
