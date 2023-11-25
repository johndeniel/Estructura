#include <iostream>
#include <vector>

template <typename T>
class HeapSort {
private:
    std::vector<T> array;

    void heapify(int size, int rootIndex) {
        int largest = rootIndex;
        int leftChild = 2 * rootIndex + 1;
        int rightChild = 2 * rootIndex + 2;

        // Compare with left child
        if (leftChild < size && array[leftChild] > array[largest]) {
            largest = leftChild;
        }

        // Compare with right child
        if (rightChild < size && array[rightChild] > array[largest]) {
            largest = rightChild;
        }

        // If the largest is not the root, swap and continue heapifying
        if (largest != rootIndex) {
            std::swap(array[rootIndex], array[largest]);
            heapify(size, largest);
        }
    }

    void buildHeap() {
        int size = array.size();

        // Start from the last non-leaf node and heapify each node in reverse order
        for (int i = size / 2 - 1; i >= 0; --i) {
            heapify(size, i);
        }
    }

public:
    HeapSort(const std::vector<T>& inputArray) : array(inputArray) {}

    void sort() {
        int size = array.size();

        // Build max heap
        buildHeap();

        // Extract elements from the heap one by one
        for (int i = size - 1; i > 0; --i) {
            std::swap(array[0], array[i]); // Move current root to the end
            heapify(i, 0); // Heapify the reduced heap
        }
    }

    const std::vector<T>& getSortedArray() const {
        return array;
    }
};

int main() {
    std::vector<int> unsortedArray = {12, 11, 13, 5, 6, 7};
    HeapSort<int> heapSort(unsortedArray);

    std::cout << "Original array: ";
    for (int val : unsortedArray) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    heapSort.sort();

    std::cout << "Sorted array: ";
    for (int val : heapSort.getSortedArray()) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
