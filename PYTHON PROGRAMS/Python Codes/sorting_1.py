def bubble_sort(array): 
    length = len(array) 
    for pass_num in range(length): 
        for idx in range(0, length - pass_num - 1): 
            if array[idx] > array[idx + 1]: 
                array[idx], array[idx + 1] = array[idx + 1], array[idx] 
    return array

def selection_sort(array): 
    length = len(array) 
    for outer_idx in range(length): 
        min_index = outer_idx 
        for inner_idx in range(outer_idx + 1, length): 
            if array[inner_idx] < array[min_index]: 
                min_index = inner_idx 
        array[outer_idx], array[min_index] = array[min_index], array[outer_idx] 
    return array

def insertion_sort(array): 
    for current_idx in range(1, len(array)): 
        key = array[current_idx] 
        prev_idx = current_idx - 1 
        while prev_idx >= 0 and key < array[prev_idx]: 
            array[prev_idx + 1] = array[prev_idx] 
            prev_idx -= 1 
        array[prev_idx + 1] = key 
    return array

def merge_sort(array): 
    if len(array) > 1: 
        mid = len(array) // 2 
        left_half = array[:mid] 
        right_half = array[mid:] 

        merge_sort(left_half) 
        merge_sort(right_half) 

        left_idx = right_idx = main_idx = 0 

        while left_idx < len(left_half) and right_idx < len(right_half): 
            if left_half[left_idx] < right_half[right_idx]: 
                array[main_idx] = left_half[left_idx] 
                left_idx += 1 
            else: 
                array[main_idx] = right_half[right_idx] 
                right_idx += 1 
            main_idx += 1 

        while left_idx < len(left_half): 
            array[main_idx] = left_half[left_idx] 
            left_idx += 1 
            main_idx += 1 

        while right_idx < len(right_half): 
            array[main_idx] = right_half[right_idx] 
            right_idx += 1 
            main_idx += 1 
    return array

def quick_sort(array): 
    if len(array) <= 1: 
        return array 
    pivot = array[len(array) // 2] 
    left_partition = [x for x in array if x < pivot] 
    middle_partition = [x for x in array if x == pivot] 
    right_partition = [x for x in array if x > pivot] 
    return quick_sort(left_partition) + middle_partition + quick_sort(right_partition)

def python_sort(array): 
    return sorted(array)

def main(): 
    sample_array = [64, 34, 25, 12, 22, 11, 90] 
    print("Original Array:", sample_array) 

    print("\nBubble Sort:", bubble_sort(sample_array.copy())) 
    print("Selection Sort:", selection_sort(sample_array.copy())) 
    print("Insertion Sort:", insertion_sort(sample_array.copy())) 
    print("Merge Sort:", merge_sort(sample_array.copy())) 
    print("Quick Sort:", quick_sort(sample_array.copy())) 
    print("Python Built-in Sort:", python_sort(sample_array.copy()))

if __name__ == "__main__": 
    main()
