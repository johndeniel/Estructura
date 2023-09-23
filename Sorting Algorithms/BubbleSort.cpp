#include <iostream>
#include <vector>

// Function to perform Bubble Sort on a vector of elements.
template <typename T> void bubbleSort(std::vector<T>& arr) {
    size_t n = arr.size(); // Get the size of the vector

    // Loop through the elements of the vector (n - 1) times.
    for (size_t i = 0; i < n - 1; ++i) {
        bool swapped = false; // Flag to track if any elements were swapped in this pass.

        // Inner loop to compare adjacent elements and swap if they are in the wrong order.
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]); // Swap the elements using the std::swap function.
                swapped = true; // Set the swapped flag to true.
            }
        }

        // If no two elements were swapped in the inner loop, the array is already sorted,
        // and we can exit the sorting process early.
        if (!swapped) {
            break;
        }
    }
}

int main() {
    std::vector<int> arr = {64, 25, 12, 22, 11};

    std::cout << "Original Array: ";

    for (const auto& num : arr) {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    bubbleSort(arr); // Call the Bubble Sort function to sort the array.

    std::cout << "Sorted Array: ";

    for (const auto& num : arr) {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    return 0;
}