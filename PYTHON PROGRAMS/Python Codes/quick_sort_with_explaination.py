def quick_sort_inplace(arr, low, high):
    """Sorts a list in-place using Quick Sort (last element as pivot), printing after each partition."""
    if low < high:
        partition_index = partition(arr, low, high)
        print(f"Array after partition: {arr}")
        quick_sort_inplace(arr, low, partition_index - 1)
        quick_sort_inplace(arr, partition_index + 1, high)


def partition(arr, low, high):
    """Partitions the list around the last element (pivot) and returns its final index."""
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]  # Swap

    arr[i + 1], arr[high] = arr[high], arr[i + 1] # Swap pivot to its correct position
    return i + 1


# Example Usage:
my_list = [10, 7, 8, 9, 1, 5]  
n = len(my_list)
quick_sort_inplace(my_list, 0, n - 1)
print(f"Final sorted list: {my_list}")
