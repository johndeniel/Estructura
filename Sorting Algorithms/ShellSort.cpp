#include <iostream>
#include <vector>

// Function to perform Shell Sort on a vector of elements
template <typename T>
void shellSort(std::vector<T>& array) {
    int n = array.size();

    // Start with a large gap and reduce it until the gap is 1
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Perform insertion sort on elements gapped by 'gap'
        for (int i = gap; i < n; ++i) {
            T temp = array[i];
            int j;

            // Shift elements of the sorted sequence until the correct position is found
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }

            // Place the current element at its correct position
            array[j] = temp;
        }
    }
}

int main() {
    // Example usage of Shell Sort on an integer vector

    // Creating an array
    std::vector<int> myArray = {12, 34, 54, 2, 3};

    // Displaying the original array
    std::cout << "Original Array: ";
    for (const auto& element : myArray) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Applying Shell Sort
    shellSort(myArray);

    // Displaying the sorted array
    std::cout << "Sorted Array: ";
    for (const auto& element : myArray) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}