'''
  Implementing FIND-S Algorithm
  Created by Abhijeet Singh
  www.absingh.com
'''
import csv

attributes = [
  ['Sunny', 'Rainy'],
  ['Warm', 'Cold'],
  ['Normal', 'High'],
  ['Strong', 'Weak'],
  ['Warm', 'Cool'],
  ['Same', 'Change']
]

print("\nMost general hypothesis: [?, ?, ?, ?, ?, ?]")
print("Most specific hypothesis: [0, 0, 0, 0, 0, 0]\n")

data = []

print("Given training dataset:")
with open("enjoysport.csv", 'r') as f:
  reader = csv.reader(f)
  
  # skip the header
  next(reader, None)
  
  for row in reader:
    data.append(row)
    print(row)


hypothesis = [0] * len(attributes)
for i in range(len(attributes)):
  hypothesis[i] = data[0][i]
print("\nInitial value of hypothesis:", hypothesis)

print("\nFind-S: Finding a Maximally Specific Hypothesis\n")

for i in range(len(data)):
  if data[i][-1] == "1":
    for j in range(len(attributes)):
      if data[i][j] != hypothesis[j]:
        hypothesis[j] = '?'

print("The final hypothesis is:\n", hypothesis)
