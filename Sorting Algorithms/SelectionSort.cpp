#include <iostream>
#include <vector>

// Selection sort algorithm for sorting an array in ascending order.
template <typename T>

void selectionSort(std::vector<T>& arr) {
    size_t n = arr.size();

    for (size_t i = 0; i < n - 1; ++i) {
        size_t minIndex = i;

        // Find the index of the minimum element in the unsorted part of the array
        for (size_t j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the element at index i
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {

    // Creating and using a sample selection sort algorithm.
    std::vector<int> arr = {64, 25, 12, 22, 11};

    std::cout << "Original array: ";

    for (const auto& element : arr) {
        std::cout << element << " ";
    }

    selectionSort(arr);

    std::cout << "\nSorted array: ";
    
    for (const auto& element : arr) {
        std::cout << element << " ";
    }

    return 0;
}