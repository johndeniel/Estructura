#include <iostream>

// Node class represents individual elements in the linked list.
template <typename T> class Node {
    public:
        T data;           // Data stored in the node
        Node* next;       // Pointer to the next node in the list

        Node(const T& value) : data(value), next(nullptr) {}
    };

// LinkedList class implements a singly linked list data structure.
template <typename T> class LinkedList {
    private:
        Node<T>* head;    // Pointer to the first node in the list

    public:
        // Constructor initializes an empty linked list.
        LinkedList() : head(nullptr) {}

        // Destructor deallocates memory used by the linked list.
        ~LinkedList() {
            clear();
        }

    // Add a new element at the front of the linked list.
    void pushFront(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    // Remove the first element from the linked list.
    void popFront() {
        if (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Check if the linked list is empty.
    bool isEmpty() const {
        return head == nullptr;
    }

    // Clear the linked list by deallocating all nodes.
    void clear() {
        while (!isEmpty()) {
            popFront();
        }
    }

    // Display the contents of the linked list.
    void display() const {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    // Creating and using a sample linked list.
    LinkedList<int> myList;

    myList.pushFront(3);
    myList.pushFront(2);
    myList.pushFront(1);

    std::cout << "List content: ";
    myList.display();

    myList.popFront();

    std::cout << "List content after popFront: ";
    myList.display();

    myList.clear();

    return 0;
}