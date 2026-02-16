def tower_of_hanoi(n, source, destination, auxiliary):
  """Solves the Tower of Hanoi puzzle recursively.

  Args:
    n: The number of disks.
    source: The source peg (string).
    destination: The destination peg (string).
    auxiliary: The auxiliary peg (string).
  """
  if n == 1:
    print(f"Move disk 1 from {source} to {destination}")
  else:
    tower_of_hanoi(n - 1, source, auxiliary, destination)
    print(f"Move disk {n} from {source} to {destination}")
    tower_of_hanoi(n - 1, auxiliary, destination, source)


# Get the number of disks from the user
num_disks = int(input("Enter the number of disks: "))

# Solve the Tower of Hanoi puzzle
tower_of_hanoi(num_disks, "A", "C", "B")  # A, B, C are the peg names