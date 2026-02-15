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

    def delete_last_n(self, n):
        """Deletes the last 'n' elements from the doubly linked list."""
        if self.head is None:  # Empty list
            return

        if n <= 0:  # Invalid input
            return

        # Traverse to the end of the list
        current = self.head
        while current.next:
            current = current.next

        # Delete the last 'n' nodes
        for _ in range(n):
            if current.prev:  # If not the first node
                current.prev.next = None
                current = current.prev  # Move to the new last node
            else:  # List becomes empty
                self.head = None
                return

    def print_list(self):
        current = self.head
        while current:
            print(current.data, end=" <-> ")
            current = current.next
        print("None")


# Create a DoublyLinkedList
my_list = DoublyLinkedList()

# Add elements to the list
elements_to_add = [10, 20, 30, 40, 50]
for element in elements_to_add:
    my_list.append(element)

print("Original List:")
my_list.print_list()

# Delete the last 2 elements
my_list.delete_last_n(2)

print("Modified List:")
my_list.print_list() 