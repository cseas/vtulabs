import numpy as np
import math
import csv

def read_data(filename):
    """ read csv file and return header and data  """
    with open(filename, 'r') as csvfile:
        datareader = csv.reader(csvfile)
        metadata = next(datareader)
        traindata = []
        for row in datareader:
            traindata.append(row)            
    return (metadata, traindata)

class Node:
  def __init__(self, attribute):
    self.attribute = attribute
    self.children = []
    self.answer = ""
        
def subtables(data, col, delete):
    dict = {}
    # get unique values in the given col
    items = np.unique(data[:, col])
    
    # number of row = number of values 
    count = np.zeros((items.shape[0], 1))

  # calculate count of each unique value for the col
    for x in range(items.shape[0]):
        for y in range(data.shape[0]):
            if data[y, col] == items[x]:
                count[x] += 1
                
    for x in range(items.shape[0]):
      # dictionary to store rows corresponding to each unique value
        dict[items[x]] = np.empty((int(count[x]), data.shape[1]), dtype="S32")
         
        pos = 0
        for y in range(data.shape[0]):
            if data[y, col] == items[x]:
                dict[items[x]][pos] = data[y]
                pos += 1     
        
        if delete:
           dict[items[x]] = np.delete(dict[items[x]], col, 1)
    return items, dict    
        
        
def entropy(S):
    """ calculate the entropy """
    items = np.unique(S)
    # entropy is zero if all items are the same
    if items.size == 1:
        return 0
    
    counts = np.zeros((items.shape[0], 1))    
    for x in range(items.shape[0]):
        counts[x] = sum(S == items[x]) / (S.size)
        
    sums = 0
    for count in counts:
        sums += -1 * count * math.log(count, 2)
    return sums
    
def gain_ratio(data, col):
    items, dict = subtables(data, col, delete=False) 
    # item is the unique value and dict is the data corresponding to it
    total_size = data.shape[0]
    entropies = np.zeros((items.shape[0], 1))
      
    for x in range(items.shape[0]):
        ratio = dict[items[x]].shape[0]/(total_size)
        entropies[x] = ratio * entropy(dict[items[x]][:, -1])
             
    total_entropy = entropy(data[:, -1])
   
    for x in range(entropies.shape[0]):
        total_entropy -= entropies[x]
        
    return total_entropy


def create_node(data, metadata):
  # if there is only one label
  if (np.unique(data[:, -1])).shape[0] == 1:
    # if there is only yes or only no then return a node containing the value ""
    node = Node("")
    node.answer = np.unique(data[:, -1])
    return node
     
  # data.shape[1] - 1 returns the no of columns in the dataset, minus one to remove last column
  # size of gains = number of attributes
  # gains is one dim array (size = 4) to store the gain of each attribute
  gains = np.zeros((data.shape[1] - 1, 1))  
    
  # calculate gain ratio for each attribute
  for col in range(data.shape[1] - 1):
    gains[col] = gain_ratio(data, col)

  # we select the attribute with the highest information gain
  # argmax returns the index of the max value
  split = np.argmax(gains) 
  
  node = Node(metadata[split])    

  metadata = np.delete(metadata, split, 0)
  items, dict = subtables(data, split, delete=True)
    
  for x in range(items.shape[0]):
    # recursion
    child = create_node(dict[items[x]], metadata)
    # append pair of parent and child
    node.children.append((items[x], child))
    
  return node        
    

def empty(level):
  """ To generate empty space needed for shaping the tree"""
  s = ""
  for x in range(level):
    s += "   "
  return s


def print_tree(node, level):
    if node.answer != "":
        print(empty(level), node.answer.tobytes().decode("utf-8"))
        return
        
    print(empty(level), node.attribute)
    
    for value, n in node.children:
        print(empty(level + 1), value.tobytes().decode("utf-8"))
        print_tree(n, level + 2)
        
# metadata contains list of attributes
metadata, traindata = read_data("tennis.csv")
data = np.array(traindata) # to convert the traindata to numpy array 
# create tree
node = create_node(data, metadata)
print_tree(node, 0)
