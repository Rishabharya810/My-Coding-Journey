class Node:
    """
    Represents a node in a doubly linked list.
    """

    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


class DoublyLinkedList:
    """
    Represents a doubly linked list.
    """

    def __init__(self):
        self.head = None

    def append(self, data):
        """
        Appends a new node with the given data to the end of the list.
        """
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node
            new_node.prev = current

    def prepend(self, data):
        """
        Prepends a new node with the given data to the beginning of the list.
        """
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node

    def delete(self, data):
        """
        Deletes the first node with the given data from the list.
        """
        current = self.head
        while current:
            if current.data == data:
                if current.prev:
                    current.prev.next = current.next
                else:
                    self.head = current.next
                if current.next:
                    current.next.prev = current.prev
                return  # Node deleted, exit the loop
            current = current.next

    def print_list(self):
        """
        Prints the data of each node in the list.
        """
        current = self.head
        while current:
            print(current.data, end=" <-> ")
            current = current.next
        print("None")


# Example usage:
my_list = DoublyLinkedList()
my_list.append(1)
my_list.append(2)
my_list.append(3)
my_list.prepend(0)
my_list.print_list()  # Output: 0 <-> 1 <-> 2 <-> 3 <-> None

my_list.delete(2)
my_list.print_list()  # Output: 0 <-> 1 <-> 3 <-> None