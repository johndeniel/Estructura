#include <iostream>
#include <vector>

// Function to perform bitonic merge
void bitonicMerge(std::vector<int>& arr, int low, int count, bool dir) {
    // Base case: if there is only one element in the sequence, it is already sorted
    if (count > 1) {
        int k = count / 2;

        // Compare and swap elements based on the direction (ascending or descending)
        for (int i = low; i < low + k; ++i)
            if ((arr[i] > arr[i + k]) == dir)
                std::swap(arr[i], arr[i + k]);

        // Recursively merge the two halves
        bitonicMerge(arr, low, k, dir);
        bitonicMerge(arr, low + k, k, dir);
    }
}

// Function to recursively sort a bitonic sequence in ascending or descending order
void bitonicSort(std::vector<int>& arr, int low, int count, bool dir) {
    // Base case: if there is more than one element in the sequence
    if (count > 1) {
        int k = count / 2;

        // Sort the first half in ascending order
        bitonicSort(arr, low, k, true);

        // Sort the second half in descending order
        bitonicSort(arr, low + k, k, false);

        // Merge the sorted halves
        bitonicMerge(arr, low, count, dir);
    }
}

// Function to initialize bitonic sort
void bitonicSort(std::vector<int>& arr) {
    int n = arr.size();

    // Ensure the input size is a power of 2
    if ((n & (n - 1)) != 0) {
        std::cerr << "Error: Input size must be a power of 2." << std::endl;
        return;
    }

    // Sort the entire array in ascending order
    bitonicSort(arr, 0, n, true);
}

int main() {
    // Example usage of Bitonic Sort
    std::vector<int> arr = {3, 7, 4, 8, 6, 2, 1, 5};

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    // Perform Bitonic Sort
    bitonicSort(arr);

    std::cout << "\nSorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}