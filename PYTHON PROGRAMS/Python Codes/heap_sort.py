def heapify(arr, n, i):
    """
    Heapifies a subtree rooted at index i.

    Args:
        arr: The array representing the heap.
        n: The size of the heap.
        i: The index of the root of the subtree to heapify.
    """
    largest = i  # Initialize largest as root
    left = 2 * i + 1  # Left child
    right = 2 * i + 2  # Right child

    # See if left child of root exists and is greater than root
    if left < n and arr[largest] < arr[left]:
        largest = left

    # See if right child of root exists and is greater than root
    if right < n and arr[largest] < arr[right]:
        largest = right

    # Change root, if needed
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # Swap

        # Heapify the affected sub-tree
        heapify(arr, n, largest)


def heap_sort(arr):
    """
    Sorts an array using heap sort algorithm.

    Args:
        arr: The array to be sorted.
    """
    n = len(arr)

    # Build a maxheap.
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # One by one extract elements
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # Swap
        heapify(arr, i, 0)


# Example usage:
arr = [12, 11, 13, 5, 6, 7]
heap_sort(arr)
print("Sorted array is", arr)  # Output: Sorted array is [5, 6, 7, 11, 12, 13]