class CircularQueue:
    def _init_(self, size):
        self.size = size
        self.queue = [None] * size
        self.front = -1
        self.rear = -1

    def is_full(self):
        return (self.rear + 1) % self.size == self.front

    def is_empty(self):
        return self.front == -1

    def enqueue(self, data):
        if self.is_full():
            print("Queue is full")
            return
        if self.is_empty():
            self.front = 0
            self.rear = 0
        else:
            self.rear = (self.rear + 1) % self.size
        self.queue[self.rear] = data
        print(f"Inserted {data} at position {self.rear}")

    def display(self):
        if self.is_empty():
            print("Queue is empty")
            return
        print("Queue elements are")
        i = self.front
        while True:
            print(self.queue[i], end=" ")
            if i == self.rear:
                break
            i = i+1
        print()

q = CircularQueue(5)  
q.enqueue(10)
q.enqueue(20)
q.enqueue(5)
q.enqueue(8)
q.display()