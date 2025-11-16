import matplotlib
import csv

bubble_sort = insertion_sort = selection_sort = []

with open("benchmarks.csv") as file:
    csv_file = csv.reader(file, ",")
    for row in csv_file:
        print(row)