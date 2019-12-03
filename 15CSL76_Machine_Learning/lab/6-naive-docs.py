import pandas as pd

msg = pd.read_csv("naivetrext1.csv", names=["message", "label"])

msg["labelnum"] = msg.label.map({"pos":1,"neg":0})
print("\nFirst few entries in dataset:\n", msg.head(3))
X = msg.message
y = msg.labelnum

# splitting the dataset into train and test data
from sklearn.model_selection import train_test_split
xtrain, xtest, ytrain, ytest = train_test_split(X, y)

# output of count vectoriser is a sparse matrix
from sklearn.feature_extraction.text import CountVectorizer
count_vect = CountVectorizer()

# create bag of words representation as sparse matrix
xtrain_dtm = count_vect.fit_transform(xtrain)
xtest_dtm = count_vect.transform(xtest)

# for viewing above in full matrix representation if needed
df = pd.DataFrame(xtrain_dtm.toarray(), columns=count_vect.get_feature_names())
print("\nXtrain:\n", df.head(3))

# Training Naive Bayes (NB) classifier on training data.
from sklearn.naive_bayes import MultinomialNB
clf = MultinomialNB().fit(xtrain_dtm, ytrain)
predicted = clf.predict(xtest_dtm)

# printing accuracy metrics
from sklearn import metrics
print("\nAccuracy metrics\n------------------")
print("Accuracy of the classifer is", metrics.accuracy_score(ytest, predicted))
print("Confusion matrix:")
print(metrics.confusion_matrix(ytest, predicted))
print("Recall and Precison:")
print(metrics.recall_score(ytest, predicted))
print(metrics.precision_score(ytest, predicted))

'''docs_new = ['I like this place', 'My boss is not my saviour']
X_new_counts = count_vect.transform(docs_new)
predictednew = clf.predict(X_new_counts)
for doc, category in zip(docs_new, predictednew):
print('%s->%s' % (doc, msg.labelnum[category]))'''
