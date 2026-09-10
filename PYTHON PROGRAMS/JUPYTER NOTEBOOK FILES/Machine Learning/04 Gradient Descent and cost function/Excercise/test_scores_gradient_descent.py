import os
from concurrent.futures import ThreadPoolExecutor, as_completed

import numpy as np
import pandas as pd
import math


# ---------------------------------------------------
# Gradient Descent (stable + precise + overflow safe)
# ---------------------------------------------------
def gradient_descent(x, y, learning_rate, max_iterations=1_000_000):
    m = 0.0
    b = 0.0
    n = len(x)
    prev_cost = float("inf")

    for i in range(max_iterations):
        y_pred = m * x + b
        error = y - y_pred

        # Cost
        cost = (1/n) * np.sum(error ** 2)

        # Stop when cost stops improving
        if math.isclose(cost, prev_cost, rel_tol=1e-20):
            break

        # Gradients
        md = -(2/n) * np.sum(x * error)
        bd = -(2/n) * np.sum(error)

        # Update
        m_new = m - learning_rate * md
        b_new = b - learning_rate * bd

        # Overflow protection
        if not np.isfinite(m_new) or not np.isfinite(b_new):
            return float("inf"), float("inf"), float("inf")

        m, b = m_new, b_new
        prev_cost = cost

    return m, b, cost


def _run_gradient_descent_process(x, y, learning_rate, iterations):
    m, b, cost = gradient_descent(x, y, learning_rate, iterations)
    return learning_rate, iterations, m, b, cost


def _run_candidate_batch(evaluator, candidates, max_workers):
    if not candidates:
        return []

    results = []
    with ThreadPoolExecutor(max_workers=max_workers) as executor:
        futures = {executor.submit(evaluator, candidate): candidate for candidate in candidates}
        for future in as_completed(futures):
            candidate = futures[future]
            try:
                resolved, cost = future.result()
            except Exception:
                resolved, cost = candidate, float("inf")
            results.append((resolved, cost))

    return results


# ---------------------------------------------------
# Tune Learning Rate (increase until cost stops improving)
# ---------------------------------------------------
def tune_learning_rate(x, y, start_lr, lr_step, fixed_iterations, max_workers=None):
    max_workers = max_workers or os.cpu_count() or 1
    batch_size = max(1, max_workers * 4)
    tolerance = 1e-12
    min_step = lr_step * 1e-6
    best_lr = start_lr
    best_cost = float("inf")
    step = lr_step
    center = best_lr
    max_rounds = 12
    round_index = 0

    def evaluate_lr(lr):
        _, _, _, _, cost = _run_gradient_descent_process(x, y, lr, fixed_iterations)
        return lr, cost

    while step >= min_step and round_index < max_rounds:
        round_index += 1
        span = (batch_size // 2) * step
        start = max(step, center - span)
        candidates = [start + i * step for i in range(batch_size)]
        results = _run_candidate_batch(evaluate_lr, candidates, max_workers)
        results.sort(key=lambda entry: entry[0])

        local_best_cost = float("inf")
        local_best_lr = None
        local_best_idx = None

        for idx, (lr, cost) in enumerate(results):
            print(f"Trying learning_rate={lr:.6f}, cost={cost:.10f}")
            if not np.isfinite(cost):
                continue
            if cost < local_best_cost:
                local_best_cost = cost
                local_best_lr = lr
                local_best_idx = idx

        if local_best_lr is None or not np.isfinite(local_best_cost):
            print("All learning-rate candidates failed to deliver a finite cost. Stopping search.")
            break

        if local_best_cost >= best_cost - tolerance:
            print(f"No learning rate improved the cost beyond tolerance; stopping at {best_lr:.6f}")
            break

        best_cost = local_best_cost
        best_lr = local_best_lr

        if local_best_idx is None:
            break

        if local_best_idx >= len(results) - 1:
            center = best_lr + step
        else:
            step = max(step / 2, min_step)
            center = best_lr

    return best_lr, best_cost


# ---------------------------------------------------
# Tune Iterations (increase until cost stops improving)
# ---------------------------------------------------
def tune_iterations(x, y, learning_rate, start_iterations, iter_step, max_workers=None):
    max_workers = max_workers or os.cpu_count() or 1
    batch_size = max(1, max_workers * 4)
    tolerance = 1e-12
    best_iterations = start_iterations
    best_cost = float("inf")
    step = iter_step
    min_step = 1
    center = best_iterations
    max_rounds = 12
    round_index = 0

    def evaluate_iterations(iters):
        _, _, _, _, cost = _run_gradient_descent_process(x, y, learning_rate, iters)
        return iters, cost

    while step >= min_step and round_index < max_rounds:
        round_index += 1
        span = (batch_size // 2) * step
        start = max(1, center - span)
        candidates = [start + i * step for i in range(batch_size)]
        results = _run_candidate_batch(evaluate_iterations, candidates, max_workers)
        results.sort(key=lambda entry: entry[0])

        local_best_cost = float("inf")
        local_best_iters = None
        local_best_idx = None

        for idx, (iters, cost) in enumerate(results):
            print(f"Trying iterations={iters}, cost={cost:.10f}")
            if not np.isfinite(cost):
                continue
            if cost < local_best_cost:
                local_best_cost = cost
                local_best_iters = iters
                local_best_idx = idx

        if local_best_iters is None or not np.isfinite(local_best_cost):
            print("All iteration candidates failed to deliver a finite cost. Stopping search.")
            break

        if local_best_cost >= best_cost - tolerance:
            print(f"No iteration count improved the cost beyond tolerance; stopping at {best_iterations}")
            break

        best_cost = local_best_cost
        best_iterations = local_best_iters

        if local_best_idx is None:
            break

        if local_best_idx >= len(results) - 1:
            center = best_iterations + step
        else:
            step = max(step // 2, min_step)
            center = best_iterations

    return best_iterations, best_cost


# ---------------------------------------------------
# MAIN SCRIPT
# ---------------------------------------------------
if __name__ == "__main__":

    # Load CSV
    df = pd.read_csv("test_scores.csv")
    x = df["math"].values.astype(float)
    y = df["cs"].values.astype(float)

    # Step 1: Tune learning rate
    best_lr, _ = tune_learning_rate(
        x, y,
        start_lr=0.0001,
        lr_step=0.0001,
        fixed_iterations=500
    )

    # Step 2: Tune iterations
    best_iters, _ = tune_iterations(
        x, y,
        learning_rate=best_lr,
        start_iterations=200,
        iter_step=200
    )

    # Step 3: Final gradient descent
    m, b, cost = gradient_descent(x, y, best_lr, best_iters)

    print("\nFinal selected values:")
    print("learning_rate =", best_lr)
    print("iterations    =", best_iters)
    print("m             =", m)
    print("b             =", b)
    print("final cost    =", cost)

    # Step 4: Compare with sklearn
    from sklearn.linear_model import LinearRegression
    model = LinearRegression()
    model.fit(df[['math']], df['cs'])

    print("\nSklearn Results:")
    print("m =", model.coef_[0])
    print("b =", model.intercept_)
