import numpy as np


def run_gradient_descent(x, y, learning_rate, iterations):
    m_curr = 0.0
    b_curr = 0.0
    n = len(x)

    for _ in range(iterations):
        y_predicted = m_curr * x + b_curr
        error = y - y_predicted
        md = -(2 / n) * np.sum(x * error)  # derivative w.r.t m
        bd = -(2 / n) * np.sum(error)       # derivative w.r.t b
        m_curr = m_curr - learning_rate * md
        b_curr = b_curr - learning_rate * bd

    final_pred = m_curr * x + b_curr
    final_cost = (1 / n) * np.sum((y - final_pred) ** 2)
    return m_curr, b_curr, final_cost


def tune_learning_rate(x, y, start_lr, lr_step, max_lr, fixed_iterations):
    current_lr = start_lr
    best_lr = start_lr
    best_cost = float("inf")

    while current_lr <= max_lr:
        _, _, cost = run_gradient_descent(x, y, current_lr, fixed_iterations)
        print(
            f"Trying learning_rate={current_lr:.5f}, "
            f"iterations={fixed_iterations}, cost={cost:.10f}"
        )

        if not np.isfinite(cost) or cost >= best_cost:
            print(
                f"Cost increased at learning_rate={current_lr:.5f}. "
                f"Reverting to learning_rate={best_lr:.5f}."
            )
            break

        best_cost = cost
        best_lr = current_lr
        current_lr += lr_step

    return best_lr, best_cost


def tune_iterations(x, y, learning_rate, start_iterations, iter_step, max_iterations):
    current_iterations = start_iterations
    best_iterations = start_iterations
    best_cost = float("inf")

    while current_iterations <= max_iterations:
        _, _, cost = run_gradient_descent(x, y, learning_rate, current_iterations)
        print(
            f"Trying iterations={current_iterations}, "
            f"learning_rate={learning_rate:.5f}, cost={cost:.10f}"
        )

        if not np.isfinite(cost) or cost >= best_cost:
            print(
                f"Cost increased at iterations={current_iterations}. "
                f"Reverting to iterations={best_iterations}."
            )
            break

        best_cost = cost
        best_iterations = current_iterations
        current_iterations += iter_step

    return best_iterations, best_cost


x = np.array([1, 2, 3, 4, 5], dtype=float)
y = np.array([5, 7, 9, 11, 13], dtype=float)

# Step 1: tune learning rate first (iterations fixed)
initial_learning_rate = 0.01
learning_rate_step = 0.01
max_learning_rate = 1.00
fixed_iterations_for_lr_tuning = 200

best_learning_rate, _ = tune_learning_rate(
    x,
    y,
    initial_learning_rate,
    learning_rate_step,
    max_learning_rate,
    fixed_iterations_for_lr_tuning,
)

# Step 2: tune iterations second (learning rate fixed)
initial_iterations = 100
iterations_step = 100
max_iterations = 5000

best_iterations, _ = tune_iterations(
    x,
    y,
    best_learning_rate,
    initial_iterations,
    iterations_step,
    max_iterations,
)

m, b, cost = run_gradient_descent(x, y, best_learning_rate, best_iterations)

print("\nFinal selected values")
print(f"learning_rate = {best_learning_rate}")
print(f"iterations    = {best_iterations}")
print(f"m             = {m}")
print(f"b             = {b}")
print(f"final cost    = {cost}")
