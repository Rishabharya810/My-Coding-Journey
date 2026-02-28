# Weather Forecasting Project - Fixed Version
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_squared_error, mean_absolute_error, r2_score
import warnings

# Suppress warnings
warnings.filterwarnings('ignore')
np.random.seed(42)

# 1. Data Loading
print("Loading data...")
df = pd.read_csv(r"C:\Users\RISHAB ARYA\Downloads\data\daily.csv")
df.columns = ['datetime', 'temp']
df['temp'] = pd.to_numeric(df['temp'], errors='coerce')
df['datetime'] = pd.to_datetime(df['datetime'], errors='coerce')
df = df.dropna()
print(f"Dataset shape: {df.shape}")

# 2. Feature Engineering
print("\n===== Feature Engineering =====")
df['year'] = df['datetime'].dt.year
df['month'] = df['datetime'].dt.month
df['dayofyear'] = df['datetime'].dt.dayofyear
df['temp_lag1'] = df['temp'].shift(1)
df['temp_lag7'] = df['temp'].shift(7)
df['temp_rolling_mean7'] = df['temp'].rolling(7).mean()
df = df.dropna()

# 3. Prepare Data
X = df.drop(columns=['temp', 'datetime'])
y = df['temp']
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, shuffle=False)

scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)

# 4. Model Training
print("\n===== Model Training =====")
model = RandomForestRegressor(n_estimators=100)
model.fit(X_train_scaled, y_train)

# 5. Evaluation
y_pred = model.predict(X_test_scaled)
mse = mean_squared_error(y_test, y_pred)
rmse = np.sqrt(mse)
mae = mean_absolute_error(y_test, y_pred)
r2 = r2_score(y_test, y_pred)

print("\nModel Performance:")
print(f"RMSE: {rmse:.4f}")
print(f"MAE: {mae:.4f}")
print(f"R²: {r2:.4f}")

# 6. Feature Importance (Fixed)
print("\n===== Feature Importance =====")
importances = model.feature_importances_
features = X.columns

importance_df = pd.DataFrame({'Feature': features, 'Importance': importances})
importance_df = importance_df.sort_values('Importance', ascending=False)
print(importance_df)

plt.figure(figsize=(10, 6))
sns.barplot(x='Importance', y='Feature', data=importance_df)
plt.title('Feature Importance')
plt.tight_layout()
plt.savefig('feature_importance.png')
plt.close()

# 7. Plot Predictions
plt.figure(figsize=(12, 6))
plt.plot(y_test.values, label='Actual')
plt.plot(y_pred, label='Predicted')
plt.title('Temperature Predictions')
plt.legend()
plt.savefig('predictions.png')
plt.close()

print("\n===== Project Complete =====")