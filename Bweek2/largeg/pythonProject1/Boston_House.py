import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import StandardScaler
pd.set_option('display.max_columns', None)
filename = "D:/datasets/house_data.csv"
boston_data = pd.read_csv(filename)
print(boston_data)
print(boston_data.info())
print(boston_data.describe)
print(boston_data.shape)
print(boston_data.duplicated())
print(boston_data.duplicated().sum())#重复个数


sta1=(boston_data['CRIM']-boston_data['CRIM'].mean())/boston_data['CRIM'].std()
sta2=(boston_data['RM']-boston_data['RM'].mean())/boston_data['RM'].std()
sta3=(boston_data['LSTAT']-boston_data['LSTAT'].mean())/boston_data['LSTAT'].std()
boston_data.drop(boston_data.loc[sta1.abs()>3].index,inplace=True)
boston_data.drop(boston_data.loc[sta2.abs()>3].index,inplace=True)
boston_data.drop(boston_data.loc[sta3.abs()>3].index,inplace=True)
print(boston_data.shape)
#
for col in boston_data.columns[:-1]:
    plt.scatter(boston_data[col], boston_data['MEDV'])
    plt.xlabel(col)
    plt.ylabel('MEDV')
    plt.show()


X = boston_data['RM'].values.reshape(-1,1)
y = boston_data['MEDV'].values.reshape(-1,1)

X_mean = np.mean(X)#均值
y_mean = np.mean(y)#均值
numerator = 0
denominator = 0
for i in range(len(X)):
    numerator += (X[i] - X_mean) * (y[i] - y_mean)
    denominator += (X[i] - X_mean) ** 2

beta_1 = numerator / denominator#系数
beta_0 = y_mean - beta_1 * X_mean#截距
print('截距：beta_0:', beta_0)
print('系数：beta_1:', beta_1)
# 绘制拟合直线
x_range = np.arange(0,10,0.5)
y_range = beta_0 + beta_1 * x_range
plt.plot(x_range, y_range, color='red')
plt.scatter(X, y)
plt.xlabel('RM')
plt.ylabel('MEDV')
plt.show()
new_X = np.array([[10], [6], [3]])
predicted_y = beta_0 + beta_1 * new_X
print('Predicted MENV:', predicted_y)

