#include <iostream>
#include <stdexcept>

// TreeNode class represents individual nodes in the binary search tree.
template <typename T> class TreeNode {
    public:
        T data;             // Data stored in the node
        TreeNode* left;     // Pointer to the left child node
        TreeNode* right;    // Pointer to the right child node

    TreeNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
};

// BinarySearchTree class implements a basic binary search tree.
template <typename T> class BinarySearchTree {
    private:
        TreeNode<T>* root;  // Pointer to the root node of the tree

    // Recursive function to insert a new value into the tree.
    TreeNode<T>* insertRecursive(TreeNode<T>* current, const T& value) {
        if (current == nullptr) {
            return new TreeNode<T>(value);
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

    // Recursive function to search for a value in the tree.
    bool searchRecursive(TreeNode<T>* current, const T& value) const {
        if (current == nullptr) {
            return false;
        }

        if (value == current->data) {
            return true;
        } else if (value < current->data) {
            return searchRecursive(current->left, value);
        } else {
            return searchRecursive(current->right, value);
        }
    }

    public:
        // Constructor initializes an empty binary search tree.
        BinarySearchTree() : root(nullptr) {}

    // Inserts a new value into the binary search tree.
    void insert(const T& value) {
        root = insertRecursive(root, value);
    }

    // Searches for a value in the binary search tree.
    bool search(const T& value) const {
        return searchRecursive(root, value);
    }
};

int main() {
    // Creating and using a sample binary search tree.
    BinarySearchTree<int> bst;

    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);

    std::cout << "Searching for 7: " << (bst.search(7) ? "Found" : "Not found") << std::endl;
    std::cout << "Searching for 12: " << (bst.search(12) ? "Found" : "Not found") << std::endl;

    return 0;
}
