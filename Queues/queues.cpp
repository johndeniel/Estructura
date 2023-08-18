#include <iostream>

// Node class represents individual elements in the queue.
template <typename T> class Node {
    public:
        T data;           // Data stored in the node
        Node* next;       // Pointer to the next node in the queue

        Node(const T& value) : data(value), next(nullptr) {}
    };

// Queue class implements a basic queue data structure using linked list.
template <typename T> class Queue {
    private:
        Node<T>* frontNode; // Pointer to the front node in the queue
        Node<T>* rearNode;  // Pointer to the rear node in the queue
        size_t queueSize;   // Current size of the queue

    public:
        // Constructor initializes an empty queue.
        Queue() : frontNode(nullptr), rearNode(nullptr), queueSize(0) {}

    // Destructor deallocates memory used by the queue.
    ~Queue() {
        clear();
    }

    // Enqueues a new element at the rear of the queue.
    void enqueue(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            frontNode = newNode;
            rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        queueSize++;
    }

    // Dequeues and returns the front element from the queue.
    T dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }

        T dequeuedValue = frontNode->data;
        Node<T>* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        queueSize--;

        return dequeuedValue;
    }

    // Returns the front element of the queue without removing it.
    T front() const {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        return frontNode->data;
    }

    // Checks if the queue is empty.
    bool isEmpty() const {
        return frontNode == nullptr;
    }

    // Returns the number of elements in the queue.
    size_t size() const {
        return queueSize;
    }

    // Clears the queue by deallocating all nodes.
    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    // Creating and using a sample queue.
    Queue<int> myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    std::cout << "Front element: " << myQueue.front() << std::endl;

    myQueue.dequeue();

    std::cout << "Queue size after dequeue: " << myQueue.size() << std::endl;

    while (!myQueue.isEmpty()) {
        std::cout << myQueue.dequeue() << " ";
    }

    return 0;
}   