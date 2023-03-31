from sklearn.preprocessing import StandardScaler
from sklearn.feature_selection import SelectKBest, f_regression
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error
import matplotlib.pyplot as plt

filename = "D:/datasets/house_data.csv"
d = pd.read_csv(filename)
x = d.values[:, :-1]  # 获取除最后一列外的数据
y = d.values[:, -1]  # 获取最后一列数据
stand = StandardScaler()
stand_x = stand.fit_transform(x)
best = SelectKBest(f_regression, k=3)
best_index = best.fit_transform(stand_x, y)
print(best_index)
best_features = d.columns[:-1][best.get_support()]
print(best_features)
x_train, x_test, y_train, y_test = train_test_split(x_best, y, test_size=0.2)

# 创建线性回归模型
Ir = LinearRegression()
Ir.fit(x_train, y_train)  # 拟合数据，训练模型

y_test_predict = Ir.predict(x_test)  # 测试集预测结果
y_train_predict = Ir.predict(x_train)  # 训练集预测结果

error_1 = mean_squared_error(y_train, y_train_predict)
error_2 = mean_squared_error(y_test, y_test_predict)

print("训练误差:", error_1, "测试误差:", error_2)

plt.plot(y_test_predict, "r-", label="predict value")
plt.plot(y_test, "b-", label="true value")
plt.legend()
plt.show()