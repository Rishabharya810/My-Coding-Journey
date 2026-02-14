class Queue:
    def __init__(self):
        self.queue = []
        self.front = -1
        self.rear = -1

    def _isempty_(self):
        return self.front == -1
    
    def enqueue(self, data):
        if self._isempty_():
            self.front = 0
        self.rear += 1
        self.queue.append(data)
        print(f"Inserted {data} at position {self.rear}")

    def dequeue(self):
        if self._isempty_():
            print("Queue is empty!")
            return
        data = self.queue[self.front]
        if self.front == self.rear:
            self.front = -1
            self.rear = -1
        else:
            self.front += 1
        print(f"Removed {data} from position {self.front - 1}")

    def display(self):
        if self._isempty_():
            print("Queue is empty!")
            return
        print("Queue elements are:")
        for i in range(self.front, self.rear + 1):
            print(self.queue[i], end=" ")
        print()

q = Queue()
q.enqueue(10)
q.enqueue(20)
q.display()
