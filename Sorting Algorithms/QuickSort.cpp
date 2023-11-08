#include <iostream>
#include <vector>

// Partition the array into two parts and return the pivot index.
template <typename T>
int partition(std::vector<T>& arr, int low, int high) {
    T pivot = arr[high];  // Choose the last element as the pivot.
    int i = low - 1;      // Index of the smaller element.

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);  // Swap elements at i and j.
        }
    }

    std::swap(arr[i + 1], arr[high]);  // Swap pivot with the element at (i + 1).
    return i + 1;  // Return the pivot index.
}

// Recursive function to sort an array using Quick Sort.
template <typename T>
void quickSort(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        // Recursively sort elements before and after the pivot.
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    std::vector<int> data = {12, 4, 5, 6, 7, 3, 1, 15, 2, 14};

    std::cout << "Original Array: ";
    for (const auto& element : data) {
        std::cout << element << " ";
    }

    quickSort(data, 0, data.size() - 1);

    std::cout << "\nSorted Array: ";
    for (const auto& element : data) {
        std::cout << element << " ";
    }

    return 0;
}