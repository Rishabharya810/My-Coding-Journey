print("Hello, my name is Rishab Arya.")

x = 1 + 2 * 3 - 8 / 4
print(x)

'''''
name = input("What is your name? ")
print("Hello,", name , "!") 
print("Hello," + name + "!") 

'''''

list1 = [1, 2, 3] 
list2 = list1  # list2 now references the same object as list1.

print(list1 is list2)  # Output: True (they refer to the same object)

list2.append(4)
print(list1)  # Output: [1, 2, 3, 4] (list1 is also modified)

def modify_list(my_list):
    my_list.append(4) 

my_list = [1, 2, 3]
modify_list(my_list)
print(my_list)

class Point:  
    def __init__(self, x, y):
        self.x = x
        self.y = y


p = Point(10, 20)
print(p.x)
print(p.y)


class MyUnion:
    def __init__(self, value, type):
        self.value = value
        self.type = type  # To keep track of the data type stored

u = MyUnion(10, 'int')
print(u.value)  

u.value = "Hello"  # Overwriting with a different type
u.type = 'str'
print(u.value)


class Node:
    # ... (Node class remains the same) ...

class SinglyLinkedList:
    # ... (Previous methods remain the same) ...

    def search(self, target):
        """
        Searches for a node with the given target data.

        Args:
            target: The data to search for.

        Returns:
            A tuple (found, index):
                - found: True if the target is found, False otherwise.
                - index: The index of the target node if found, -1 otherwise.
        """

        current = self.head
        index = 0
        while current:
            if current.data == target:
                return True, index
            current = current.next
            index += 1 

        return False, -1  # Target not found 

# Example Usage
my_list = SinglyLinkedList()
my_list.append(10)
my_list.append(20)
my_list.append(30)

found, index = my_list.search(20)
if found:
    print(f"Target found at index: {index}")
else:
    print("Target not found in the list.")