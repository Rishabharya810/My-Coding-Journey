# Complete Weather Forecasting Project
# ===================================

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import train_test_split, cross_val_score
from sklearn.preprocessing import StandardScaler, OneHotEncoder
from sklearn.compose import ColumnTransformer
from sklearn.pipeline import Pipeline
from sklearn.impute import SimpleImputer
from sklearn.ensemble import RandomForestRegressor, GradientBoostingRegressor
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, mean_absolute_error, r2_score
from sklearn.svm import SVR
from xgboost import XGBRegressor
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, LSTM, Dropout
from tensorflow.keras.callbacks import EarlyStopping
import warnings

# Suppress warnings
warnings.filterwarnings('ignore')

# Set random seeds for reproducibility
np.random.seed(42)
tf.random.set_seed(42)

# 1. Data Loading
# --------------
print("Loading data...")

# Load the dataset from local CSV file
df = pd.read_csv(r"C:\Users\RISHAB ARYA\Downloads\data\daily.csv")

# Rename columns for consistency
df.columns = ['datetime', 'temp']

# Convert 'temp' to numeric (in case it's string/object)
df['temp'] = pd.to_numeric(df['temp'], errors='coerce')

# Convert 'datetime' to datetime type
df['datetime'] = pd.to_datetime(df['datetime'], errors='coerce')

print("Dataset loaded successfully!")
print(f"Dataset shape: {df.shape}")

# 2. Exploratory Data Analysis
# ---------------------------
print("\n===== Exploratory Data Analysis =====")

# Basic information
print("\nBasic Information:")
print(df.info())

# Statistical summary
print("\nStatistical Summary:")
print(df.describe())

# Check for missing values
print("\nMissing Values:")
missing_values = df.isnull().sum()
print(missing_values[missing_values > 0])

# Plot histograms for numerical variables
plt.figure(figsize=(15, 10))
df.select_dtypes(include=[np.number]).hist(bins=20, figsize=(15, 10))
plt.tight_layout()
plt.savefig('numerical_histograms.png')
plt.close()

# Correlation analysis
plt.figure(figsize=(12, 10))
correlation = df.select_dtypes(include=[np.number]).corr()
sns.heatmap(correlation, annot=True, cmap='coolwarm', linewidths=0.5)
plt.title('Correlation Matrix')
plt.tight_layout()
plt.savefig('correlation_matrix.png')
plt.close()

# We'll assume 'temp' is our target variable for forecasting
# Let's analyze the temperature variable
plt.figure(figsize=(12, 6))
plt.plot(df['temp'].values)
plt.title('Temperature Values')
plt.xlabel('Index')
plt.ylabel('Temperature')
plt.savefig('temperature_series.png')
plt.close()

# 3. Data Preprocessing
# -------------------
print("\n===== Data Preprocessing =====")

# Handle missing values
print("Handling missing values...")
# Check column types to determine appropriate imputation strategy
numerical_cols = df.select_dtypes(include=[np.number]).columns.tolist()
categorical_cols = df.select_dtypes(include=['object']).columns.tolist()

# For this project, we'll predict temperature
target_col = 'temp'
if target_col in numerical_cols:
    numerical_cols.remove(target_col)

# 4. Feature Engineering
# --------------------
print("\n===== Feature Engineering =====")

# Create time-based features if date/time columns are available
if 'datetime' in df.columns:
    df['month'] = df['datetime'].dt.month
    df['day'] = df['datetime'].dt.day
    df['hour'] = df['datetime'].dt.hour
    df['dayofweek'] = df['datetime'].dt.dayofweek

    # Create lag features
    df['temp_lag1'] = df['temp'].shift(1)
    df['temp_lag2'] = df['temp'].shift(2)
    df['temp_lag3'] = df['temp'].shift(3)

    # Create rolling window features
    df['temp_rolling_mean_3'] = df['temp'].rolling(window=3).mean()
    df['temp_rolling_mean_6'] = df['temp'].rolling(window=6).mean()

    # Drop rows with NaN due to lag features
    df = df.dropna()

# Update column types after feature engineering
numerical_cols = df.select_dtypes(include=[np.number]).columns.tolist()
categorical_cols = df.select_dtypes(include=['object']).columns.tolist()
if target_col in numerical_cols:
    numerical_cols.remove(target_col)

# Define preprocessing for numerical columns
numerical_transformer = Pipeline(steps=[
    ('imputer', SimpleImputer(strategy='median')),
    ('scaler', StandardScaler())
])

# Define preprocessing for categorical columns
categorical_transformer = Pipeline(steps=[
    ('imputer', SimpleImputer(strategy='constant', fill_value='missing')),
    ('onehot', OneHotEncoder(handle_unknown='ignore'))
])

# Combine preprocessing steps
preprocessor = ColumnTransformer(
    transformers=[
        ('num', numerical_transformer, numerical_cols),
        ('cat', categorical_transformer, categorical_cols)
    ])

# Prepare features (X) and target (y)
X = df.drop(columns=[target_col, 'datetime'])  # Drop only target and datetime, keep engineered features
y = df[target_col]

# Split data into train and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

print(f"Training set size: {X_train.shape}")
print(f"Test set size: {X_test.shape}")

# 5. Model Training and Evaluation
# ------------------------------
print("\n===== Model Training and Evaluation =====")

# Function to evaluate models
def evaluate_model(model, X_test, y_test, model_name):
    y_pred = model.predict(X_test)
    mse = mean_squared_error(y_test, y_pred)
    mae = mean_absolute_error(y_test, y_pred)
    rmse = np.sqrt(mse)
    r2 = r2_score(y_test, y_pred)
    
    print(f"\n{model_name} Performance:")
    print(f"Mean Squared Error: {mse:.4f}")
    print(f"Root Mean Squared Error: {rmse:.4f}")
    print(f"Mean Absolute Error: {mae:.4f}")
    print(f"R² Score: {r2:.4f}")
    
    # Plot actual vs predicted
    plt.figure(figsize=(10, 6))
    plt.scatter(y_test, y_pred, alpha=0.5)
    plt.plot([y_test.min(), y_test.max()], [y_test.min(), y_test.max()], 'r--')
    plt.xlabel('Actual')
    plt.ylabel('Predicted')
    plt.title(f'{model_name}: Actual vs Predicted')
    plt.savefig(f'{model_name.replace(" ", "_").lower()}_predictions.png')
    plt.close()
    
    return {'model': model_name, 'mse': mse, 'rmse': rmse, 'mae': mae, 'r2': r2}

# List to store model performance
model_performances = []

# 5.1 Linear Regression
print("\nTraining Linear Regression model...")
lr_pipeline = Pipeline(steps=[
    ('preprocessor', preprocessor),
    ('regressor', LinearRegression())
])
lr_pipeline.fit(X_train, y_train)
model_performances.append(evaluate_model(lr_pipeline, X_test, y_test, "Linear Regression"))

# 5.2 Random Forest
print("\nTraining Random Forest model...")
rf_pipeline = Pipeline(steps=[
    ('preprocessor', preprocessor),
    ('regressor', RandomForestRegressor(n_estimators=100, random_state=42))
])
rf_pipeline.fit(X_train, y_train)
model_performances.append(evaluate_model(rf_pipeline, X_test, y_test, "Random Forest"))

# 5.3 Gradient Boosting
print("\nTraining Gradient Boosting model...")
gb_pipeline = Pipeline(steps=[
    ('preprocessor', preprocessor),
    ('regressor', GradientBoostingRegressor(n_estimators=100, random_state=42))
])
gb_pipeline.fit(X_train, y_train)
model_performances.append(evaluate_model(gb_pipeline, X_test, y_test, "Gradient Boosting"))

# 5.4 XGBoost
print("\nTraining XGBoost model...")
xgb_pipeline = Pipeline(steps=[
    ('preprocessor', preprocessor),
    ('regressor', XGBRegressor(n_estimators=100, random_state=42))
])
xgb_pipeline.fit(X_train, y_train)
model_performances.append(evaluate_model(xgb_pipeline, X_test, y_test, "XGBoost"))

# 5.5 Support Vector Regression
print("\nTraining SVR model...")
svr_pipeline = Pipeline(steps=[
    ('preprocessor', preprocessor),
    ('regressor', SVR(kernel='rbf'))
])
svr_pipeline.fit(X_train, y_train)
model_performances.append(evaluate_model(svr_pipeline, X_test, y_test, "SVR"))

# 5.6 Neural Network
print("\nPreparing data for Neural Network...")
# Process the data
preprocessed_X_train = preprocessor.fit_transform(X_train)
preprocessed_X_test = preprocessor.transform(X_test)

# Create Neural Network for regression
print("Training Neural Network model...")
model = Sequential([
    Dense(64, activation='relu', input_shape=(preprocessed_X_train.shape[1],)),
    Dropout(0.2),
    Dense(32, activation='relu'),
    Dropout(0.2),
    Dense(16, activation='relu'),
    Dense(1)
])

model.compile(optimizer='adam', loss='mse', metrics=['mae'])
early_stopping = EarlyStopping(monitor='val_loss', patience=10, restore_best_weights=True)

history = model.fit(
    preprocessed_X_train, y_train,
    epochs=100,
    batch_size=32,
    validation_split=0.2,
    callbacks=[early_stopping],
    verbose=0
)

# Plot training history
plt.figure(figsize=(12, 6))
plt.subplot(1, 2, 1)
plt.plot(history.history['loss'], label='Training Loss')
plt.plot(history.history['val_loss'], label='Validation Loss')
plt.title('Loss')
plt.xlabel('Epoch')
plt.ylabel('Mean Squared Error')
plt.legend()

plt.subplot(1, 2, 2)
plt.plot(history.history['mae'], label='Training MAE')
plt.plot(history.history['val_mae'], label='Validation MAE')
plt.title('Mean Absolute Error')
plt.xlabel('Epoch')
plt.ylabel('MAE')
plt.legend()

plt.tight_layout()
plt.savefig('nn_training_history.png')
plt.close()

# Evaluate Neural Network
y_pred_nn = model.predict(preprocessed_X_test).flatten()
mse_nn = mean_squared_error(y_test, y_pred_nn)
mae_nn = mean_absolute_error(y_test, y_pred_nn)
rmse_nn = np.sqrt(mse_nn)
r2_nn = r2_score(y_test, y_pred_nn)

print("\nNeural Network Performance:")
print(f"Mean Squared Error: {mse_nn:.4f}")
print(f"Root Mean Squared Error: {rmse_nn:.4f}")
print(f"Mean Absolute Error: {mae_nn:.4f}")
print(f"R² Score: {r2_nn:.4f}")

# Plot actual vs predicted for NN
plt.figure(figsize=(10, 6))
plt.scatter(y_test, y_pred_nn, alpha=0.5)
plt.plot([y_test.min(), y_test.max()], [y_test.min(), y_test.max()], 'r--')
plt.xlabel('Actual')
plt.ylabel('Predicted')
plt.title('Neural Network: Actual vs Predicted')
plt.savefig('neural_network_predictions.png')
plt.close()

model_performances.append({'model': 'Neural Network', 'mse': mse_nn, 'rmse': rmse_nn, 'mae': mae_nn, 'r2': r2_nn})

# 5.7 Time Series Forecasting with LSTM (if we have time-based data)
if 'datetime' in df.columns:
    print("\nPreparing data for LSTM model...")
    
    # Prepare time series data in sequences
    def create_sequences(data, seq_length):
        xs, ys = [], []
        for i in range(len(data) - seq_length):
            x = data.iloc[i:(i + seq_length)].values
            y = data.iloc[i + seq_length]
            xs.append(x)
            ys.append(y)
        return np.array(xs), np.array(ys)
    
    # Use only temperature data for this example
    temp_data = df[['temp']].copy()
    
    # Normalize the data
    scaler = StandardScaler()
    temp_scaled = scaler.fit_transform(temp_data)
    temp_data_scaled = pd.DataFrame(temp_scaled, columns=['temp'])
    
    # Create sequences for LSTM
    seq_length = 10
    X_seq, y_seq = create_sequences(temp_data_scaled, seq_length)
    
    # Split into train and test sets
    train_size = int(len(X_seq) * 0.8)
    X_train_seq, X_test_seq = X_seq[:train_size], X_seq[train_size:]
    y_train_seq, y_test_seq = y_seq[:train_size], y_seq[train_size:]
    
    # Build LSTM model
    lstm_model = Sequential([
        LSTM(50, return_sequences=True, input_shape=(seq_length, 1)),
        Dropout(0.2),
        LSTM(50),
        Dropout(0.2),
        Dense(1)
    ])
    
    lstm_model.compile(optimizer='adam', loss='mse', metrics=['mae'])
    
    # Train LSTM model
    print("Training LSTM model...")
    lstm_history = lstm_model.fit(
        X_train_seq, y_train_seq,
        epochs=50,
        batch_size=32,
        validation_split=0.2,
        callbacks=[EarlyStopping(monitor='val_loss', patience=10, restore_best_weights=True)],
        verbose=0
    )
    
    # Plot LSTM training history
    plt.figure(figsize=(12, 6))
    plt.subplot(1, 2, 1)
    plt.plot(lstm_history.history['loss'], label='Training Loss')
    plt.plot(lstm_history.history['val_loss'], label='Validation Loss')
    plt.title('LSTM Loss')
    plt.xlabel('Epoch')
    plt.ylabel('Mean Squared Error')
    plt.legend()
    
    plt.subplot(1, 2, 2)
    plt.plot(lstm_history.history['mae'], label='Training MAE')
    plt.plot(lstm_history.history['val_mae'], label='Validation MAE')
    plt.title('LSTM Mean Absolute Error')
    plt.xlabel('Epoch')
    plt.ylabel('MAE')
    plt.legend()
    
    plt.tight_layout()
    plt.savefig('lstm_training_history.png')
    plt.close()
    
    # Evaluate LSTM model
    y_pred_lstm = lstm_model.predict(X_test_seq).flatten()
    y_test_seq_flat = y_test_seq.flatten()
    
    # Inverse transform to get original scale
    y_pred_lstm_rescaled = scaler.inverse_transform(y_pred_lstm.reshape(-1, 1)).flatten()
    y_test_seq_rescaled = scaler.inverse_transform(y_test_seq_flat.reshape(-1, 1)).flatten()
    
    mse_lstm = mean_squared_error(y_test_seq_rescaled, y_pred_lstm_rescaled)
    mae_lstm = mean_absolute_error(y_test_seq_rescaled, y_pred_lstm_rescaled)
    rmse_lstm = np.sqrt(mse_lstm)
    r2_lstm = r2_score(y_test_seq_rescaled, y_pred_lstm_rescaled)
    
    print("\nLSTM Model Performance:")
    print(f"Mean Squared Error: {mse_lstm:.4f}")
    print(f"Root Mean Squared Error: {rmse_lstm:.4f}")
    print(f"Mean Absolute Error: {mae_lstm:.4f}")
    print(f"R² Score: {r2_lstm:.4f}")
    
    # Plot LSTM predictions
    plt.figure(figsize=(12, 6))
    plt.plot(y_test_seq_rescaled, label='Actual')
    plt.plot(y_pred_lstm_rescaled, label='Predicted')
    plt.title('LSTM: Temperature Forecasting')
    plt.xlabel('Time Steps')
    plt.ylabel('Temperature')
    plt.legend()
    plt.savefig('lstm_forecasting.png')
    plt.close()
    
    # Add LSTM performance to the list
    model_performances.append({
        'model': 'LSTM', 
        'mse': mse_lstm, 
        'rmse': rmse_lstm, 
        'mae': mae_lstm, 
        'r2': r2_lstm
    })

# 6. Model Comparison
# -----------------
print("\n===== Model Comparison =====")

# Create a DataFrame for model comparison
comparison_df = pd.DataFrame(model_performances)
print(comparison_df)

# Plot model comparison
plt.figure(figsize=(14, 10))

# RMSE comparison
plt.subplot(2, 2, 1)
sns.barplot(x='model', y='rmse', data=comparison_df)
plt.title('RMSE Comparison')
plt.xticks(rotation=45)
plt.tight_layout()

# MAE comparison
plt.subplot(2, 2, 2)
sns.barplot(x='model', y='mae', data=comparison_df)
plt.title('MAE Comparison')
plt.xticks(rotation=45)
plt.tight_layout()

# R2 comparison
plt.subplot(2, 2, 3)
sns.barplot(x='model', y='r2', data=comparison_df)
plt.title('R² Comparison')
plt.xticks(rotation=45)
plt.tight_layout()

# MSE comparison
plt.subplot(2, 2, 4)
sns.barplot(x='model', y='mse', data=comparison_df)
plt.title('MSE Comparison')
plt.xticks(rotation=45)
plt.tight_layout()

plt.savefig('model_comparison.png')
plt.close()

# 7. Feature Importance Analysis
# ----------------------------
print("\n===== Feature Importance Analysis =====")

# Get feature names after preprocessing
feature_names = []
if hasattr(preprocessor, 'transformers_'):
    for name, trans, cols in preprocessor.transformers_:
        if name == 'cat' and hasattr(trans.named_steps['onehot'], 'get_feature_names_out'):
            cat_features = trans.named_steps['onehot'].get_feature_names_out(cols)
            feature_names.extend(cat_features)
        else:
            feature_names.extend(cols)

# Get feature importance from Random Forest
if hasattr(rf_pipeline.named_steps['regressor'], 'feature_importances_'):
    importances = rf_pipeline.named_steps['regressor'].feature_importances_
    
    # Create feature importance DataFrame
    if len(feature_names) == len(importances):
        feature_importance_df = pd.DataFrame({
            'Feature': feature_names,
            'Importance': importances
        }).sort_values(by='Importance', ascending=False)
        
        print("\nFeature Importance (Random Forest):")
        print(feature_importance_df.head(10))
        
        # Plot feature importance
        plt.figure(figsize=(12, 6))
        sns.barplot(x='Importance', y='Feature', data=feature_importance_df.head(15))
        plt.title('Feature Importance')
        plt.tight_layout()
        plt.savefig('feature_importance.png')
        plt.close()

# 8. Confusion Matrix for Classification Task (if applicable)
# ---------------------------------------------------------
print("\n===== Classification Metrics =====")
print("Note: This is a regression task, so confusion matrix isn't applicable.")
print("However, we can create error distribution analysis.")

# Plot error distributions
for i, perf in enumerate(model_performances):
    model_name = perf['model']
    
    if model_name == 'Linear Regression':
        y_pred = lr_pipeline.predict(X_test)
    elif model_name == 'Random Forest':
        y_pred = rf_pipeline.predict(X_test)
    elif model_name == 'Gradient Boosting':
        y_pred = gb_pipeline.predict(X_test)
    elif model_name == 'XGBoost':
        y_pred = xgb_pipeline.predict(X_test)
    elif model_name == 'SVR':
        y_pred = svr_pipeline.predict(X_test)
    elif model_name == 'Neural Network':
        y_pred = model.predict(preprocessed_X_test).flatten()
    elif model_name == 'LSTM':
        continue  # Skip LSTM since it has different data structure
    
    # Calculate errors
    errors = y_test - y_pred
    
    # Plot error distribution
    plt.figure(figsize=(10, 6))
    sns.histplot(errors, kde=True)
    plt.title(f'Error Distribution - {model_name}')
    plt.xlabel('Prediction Error')
    plt.ylabel('Frequency')
    plt.axvline(x=0, color='r', linestyle='--')
    plt.savefig(f'error_distribution_{model_name.replace(" ", "_").lower()}.png')
    plt.close()

# 9. Forecasting Future Values (if time-series data is available)
# ------------------------------------------------------------
if 'datetime' in df.columns:
    print("\n===== Forecasting Future Values =====")
    
    # For demonstration, let's forecast the next 7 values using our best model
    # Find the best model based on RMSE
    best_model_info = min(model_performances, key=lambda x: x['rmse'])
    best_model_name = best_model_info['model']
    print(f"Best model for forecasting: {best_model_name} (RMSE: {best_model_info['rmse']:.4f})")
    
    if best_model_name == 'LSTM':
        # Use the last sequence from our data to predict the next value
        last_sequence = X_seq[-1]
        
        # Generate predictions for next 7 time steps
        forecasted_values = []
        current_sequence = last_sequence.copy()
        
        for _ in range(7):
            # Reshape for prediction
            pred_seq = current_sequence.reshape(1, seq_length, 1)
            # Get prediction
            next_pred = lstm_model.predict(pred_seq)[0][0]
            forecasted_values.append(next_pred)
            # Update sequence (remove first element, add new prediction)
            current_sequence = np.append(current_sequence[1:], [[next_pred]], axis=0)
        
        # Scale back to original values
        forecasted_values = scaler.inverse_transform(np.array(forecasted_values).reshape(-1, 1)).flatten()
        
        # Create dates for forecasting (assuming daily data)
        last_date = pd.to_datetime(df['datetime'].iloc[-1])
        forecast_dates = [last_date + pd.Timedelta(days=i+1) for i in range(7)]
        
        # Plot forecasted values
        plt.figure(figsize=(12, 6))
        # Plot last 30 actual values
        actual_dates = pd.to_datetime(df['datetime'].iloc[-30:])
        actual_values = df['temp'].iloc[-30:].values
        plt.plot(actual_dates, actual_values, label='Historical Data')
        
        # Plot forecasted values
        plt.plot(forecast_dates, forecasted_values, label='Forecast', color='red')
        plt.title('Temperature Forecast (7 Days)')
        plt.xlabel('Date')
        plt.ylabel('Temperature')
        plt.legend()
        plt.xticks(rotation=45)
        plt.tight_layout()
        plt.savefig('temperature_forecast.png')
        plt.close()
        
        # Display forecasted values
        forecast_df = pd.DataFrame({
            'Date': forecast_dates,
            'Forecasted Temperature': forecasted_values
        })
        print("\nForecasted Temperature Values:")
        print(forecast_df)

# 10. Summary and Conclusion
# -----------------------
print("\n===== Summary and Conclusion =====")

# Find the best model
best_model = comparison_df.loc[comparison_df['rmse'].idxmin()]
print(f"\nBest performing model: {best_model['model']} with RMSE of {best_model['rmse']:.4f}")

# Print comprehensive summary
print("\nModel Performance Summary:")
print(comparison_df.sort_values(by='rmse'))

print("\nWeather Forecasting Project Complete!")