import copy
import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
from sklearn.mixture import GaussianMixture
from sklearn.cluster import KMeans

# Importing the dataset
data = pd.read_csv("ex.csv")
print("Input Data and Shape:")
print(data.head(3))
print("Shape:", data.shape)

# Getting the values and plotting it
f1 = data['V1'].values
f2 = data['V2'].values
X = np.array(list(zip(f1, f2)))
print('Graph for whole dataset')
plt.scatter(f1, f2, c='black', s=50)
plt.show()

##########################################
kmeans = KMeans(2, random_state=0)
labels = kmeans.fit(X).predict(X)
centroids = kmeans.cluster_centers_
print("Labels KMeans:", labels)

print('Graph using Kmeans Algorithm')
# plot all points, color the labels
plt.scatter(X[:, 0], X[:, 1], c=labels, s=50)
# mark centroids
plt.scatter(centroids[:, 0], centroids[:, 1], marker='*', s=200, c='black')
plt.show()


# gmm demo
gmm = GaussianMixture(n_components=2)
labels = gmm.fit(X).predict(X)
print("\nLabels EM:", labels)
print('Graph using EM Algorithm')
plt.scatter(X[:, 0], X[:, 1], c=labels, s=40)
plt.show()
