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

    def delete_middle(self):
        """Deletes the middle node(s) from the doubly linked list."""
        if self.head is None:  # Empty list
            return

        slow = self.head
        fast = self.head

        # Use slow and fast pointers to find the middle
        while fast and fast.next:
            slow = slow.next  # Move one step
            fast = fast.next.next  # Move two steps

        # slow is now pointing to the middle node (or one of them if even length)

        if slow.prev:  # If it's not the first node
            slow.prev.next = slow.next
        else:  # It's the first node, update head
            self.head = slow.next

        if slow.next:  # If it's not the last node
            slow.next.prev = slow.prev

    def print_list(self):
        current = self.head
        while current:
            print(current.data, end=" <-> ")
            current = current.next
        print("None")


# Create a DoublyLinkedList
my_list = DoublyLinkedList()

# Add elements to the list
elements_to_add = [10, 20, 30, 40, 50]  # Odd length
# elements_to_add = [10, 20, 30, 40]  # Even length
for element in elements_to_add:
    my_list.append(element)

print("Original List:")
my_list.print_list()

# Delete the middle element(s)
my_list.delete_middle()

print("Modified List:")
my_list.print_list() 