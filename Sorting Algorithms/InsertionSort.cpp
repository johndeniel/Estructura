#include <iostream>
#include <vector>

// The insertionSort function implements the Insertion Sort algorithm to sort a vector in ascending order.
template <typename T>

void insertionSort(std::vector<T>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        T key = arr[i];
        int j = i - 1;

        // Shift elements of arr[0..i-1] that are greater than key to the right.
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    // Creating and using a sample insertion sort implementation.
    std::vector<int> myArray = {12, 11, 13, 5, 6};

    std::cout << "Unsorted Array: ";
    
    for (const int& num : myArray) {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    insertionSort(myArray);

    std::cout << "Sorted Array: ";

    for (const int& num : myArray) {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    return 0;
}