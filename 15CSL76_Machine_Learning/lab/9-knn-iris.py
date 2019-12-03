from sklearn.datasets import load_iris
from sklearn.neighbors import KNeighborsClassifier
import numpy as np
from sklearn.model_selection import train_test_split

iris = load_iris()
print("Iris Target Names:\n", iris.target_names)
 
X_train, X_test, y_train, y_test = train_test_split(
    iris.data, iris.target)
 
kn = KNeighborsClassifier(n_neighbors=1)
kn.fit(X_train, y_train)

y_pred = kn.predict(X_test)

print("\nFirst few predictions:\nActual\t\t\tPredicted")
target_names = iris.target_names
for i in range(10):
    print(target_names[y_test[i]], "\t\t", target_names[y_pred[i]])

from sklearn import metrics
print("\nAccuracy:", metrics.accuracy_score(y_test, y_pred))
