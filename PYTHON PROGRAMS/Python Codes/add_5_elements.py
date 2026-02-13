class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node
            new_node.prev = current

    def print_list(self):
        current = self.head
        while current:
            print(current.data, end=" <-> ")
            current = current.next
        print("None")


# Create a DoublyLinkedList
my_list = DoublyLinkedList()

# Add 5 elements to the list
elements_to_add = [10, 20, 30, 40, 50]
for element in elements_to_add:
    my_list.append(element)

# Print the resulting list
my_list.print_list()  # Output: 10 <-> 20 <-> 30 <-> 40 <-> 50 <-> None