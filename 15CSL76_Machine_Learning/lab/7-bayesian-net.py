# python3 -W ignore 7.py
import numpy as np
import pandas as pd
import csv
from pgmpy.estimators import MaximumLikelihoodEstimator
from pgmpy.models import BayesianModel
from pgmpy.inference import VariableElimination

# Read the attributes
lines = list(csv.reader(open("heart.csv", 'r')))
attributes = lines[0]

# Read Cleveland Heart disease data
heartDisease = pd.read_csv("heart.csv", names=attributes)
heartDisease = heartDisease.replace('?', np.nan)

# Display the data
print("Few dataset samples:")
print(heartDisease.head(3))

# Model Bayesian Network
model = BayesianModel([ ('age', 'trestbps'), ('sex', 'trestbps'), 
                        ('exang', 'trestbps'), ('trestbps', 'heartdisease'),
                        ('heartdisease', 'chol')])


print("\nLearning using Maximum Likelihood Estimator...")
model.fit(heartDisease, estimator=MaximumLikelihoodEstimator)

# Deducing with Bayesian Network
print("\nInferencing with Bayesian Network:")
HeartDisease_infer = VariableElimination(model)

print("\n1. Probability of HeartDisease given Age=20")
q = HeartDisease_infer.query(variables=["heartdisease"], evidence={'age': 20})
print(q['heartdisease'])
