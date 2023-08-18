#include <iostream>

// Node class represents individual elements in the stack.
template <typename T> class Node {
    public:
        T data;           // Data stored in the node
        Node* next;       // Pointer to the next node in the stack

        Node(const T& value) : data(value), next(nullptr) {}
    };

// Stack class implements a basic stack data structure using linked list.
template <typename T> class Stack {
    private:
        Node<T>* topNode; // Pointer to the top node in the stack
        size_t stackSize; // Current size of the stack

    public:
        // Constructor initializes an empty stack.
        Stack() : topNode(nullptr), stackSize(0) {}

    // Destructor deallocates memory used by the stack.
    ~Stack() {
        clear();
    }

    // Pushes a new element onto the stack.
    void push(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = topNode;
        topNode = newNode;
        stackSize++;
    }

    // Removes and returns the top element from the stack.
    T pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty");
        }

        T poppedValue = topNode->data;
        Node<T>* temp = topNode;
        topNode = topNode->next;
        delete temp;
        stackSize--;

        return poppedValue;
    }

    // Returns the top element of the stack without removing it.
    T top() const {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty");
        }
        return topNode->data;
    }

    // Checks if the stack is empty.
    bool isEmpty() const {
        return topNode == nullptr;
    }

    // Returns the number of elements in the stack.
    size_t size() const {
        return stackSize;
    }

    // Clears the stack by deallocating all nodes.
    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    // Creating and using a sample stack.
    Stack<int> myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    std::cout << "Top element: " << myStack.top() << std::endl;

    myStack.pop();

    std::cout << "Stack size after pop: " << myStack.size() << std::endl;

    while (!myStack.isEmpty()) {
        std::cout << myStack.pop() << " ";
    }

    return 0;
}