import numpy as np
from sklearn.preprocessing import PolynomialFeatures
from sklearn.linear_model import LinearRegression
from sklearn.pipeline import Pipeline

data_x = []
data_y = []

num_feat, num_data = input().split()

for data in range(int(num_data)):
    raw_data = input().split()
    raw_data_x = []
    for feat in raw_data[:-1]:
        raw_data_x.append(float(feat))
    data_x.append(raw_data_x)
    data_y.append(float(raw_data[-1]))
    
data_x = np.array(data_x)
data_y = np.array(data_y)

model = Pipeline([('poly', PolynomialFeatures(degree=3)), ('linear', LinearRegression(fit_intercept=False))])
model.fit(data_x, data_y)
    
num_pred = int(input())

for pred in range(num_pred):
    pred_x = [float(x) for x in input().split()]
    pred_x = np.array([pred_x])
    pred_y = model.predict(pred_x)
    print(pred_y.tolist()[0])
