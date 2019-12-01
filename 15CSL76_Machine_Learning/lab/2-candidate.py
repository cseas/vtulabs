import csv

print("The Given Training Data Set:\n")
data = []
with open('enjoysport2.csv', 'r') as csvFile:
    reader = csv.reader(csvFile)
    for row in reader:
        data.append (row)
        print(row)
    
num_attributes = len(data[0]) - 1

print("\nThe initial value of hypothesis:")
G = ['?'] * num_attributes
S = ['0'] * num_attributes
print ("The most general hypothesis G0:", G)
print ("The most specific hypothesis S0:", S)

# initialise specific hypothesis
for j in range(num_attributes):
       S[j] = data[0][j];

# Comparing with Remaining Training Examples of Given Data Set
print("\nCandidate Elimination Algorithm: Hypothesis Version Space Computation\n")
# temp serves as general hypothesis
temp = []

for i in range(len(data)):
    print("-----------------------------------------------------------------")
    # positive sample, work on specific hypothesis
    if data[i][-1] == 'Yes':
        for j in range(num_attributes):
            if data[i][j] != S[j]:						
                S[j] = '?'                                                             	
                           
        # delete any general hypothesis not consistent with S
        for j in range(num_attributes):			
            for k in range(len(temp)):	                                 
                if temp[k][j] != '?' and temp[k][j] != S[j]:	               
                    del temp[k]
        
        print("For training example no. {0}, the hypothesis is S{0}:".format(i+1), S)
        if len(temp) == 0:
            print("For training example no. {0}, the hypothesis is G{0}:".format(i+1), G)
        else:    
            print("For training example no. {0}, the hypothesis is G{0}:".format(i+1), temp)
    
    # negative sample, work on general hypothesis
    if data[i][-1] == 'No':
        for j in range(num_attributes):
          if S[j] != data[i][j] and S[j] != '?':
            G[j] = S[j]
            temp.append(G)
            # reset G
            G = ['?'] * num_attributes
                 
        print("For training example no. {0}, the hypothesis is S{0}:".format(i+1), S)
        print("For training example no. {0}, the hypothesis is G{0}:".format(i+1), temp)
        