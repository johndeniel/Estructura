#include <iostream>
#include <vector>

// Function to perform Cycle Sort on an array
template <typename T>
void cycleSort(std::vector<T>& arr) {
    const size_t n = arr.size();

    // Traverse the array to place each element at its correct position
    for (size_t start = 0; start < n - 1; ++start) {
        T item = arr[start];
        size_t pos = start;

        // Find the correct position for the current element
        for (size_t i = start + 1; i < n; ++i) {
            if (arr[i] < item) {
                ++pos;
            }
        }

        // If the current element is already in the correct position, skip
        if (pos == start) {
            continue;
        }

        // Move the current element to its correct position
        while (item == arr[pos]) {
            ++pos;
        }
        std::swap(item, arr[pos]);

        // Rotate the cycle
        while (pos != start) {
            pos = start;
            for (size_t i = start + 1; i < n; ++i) {
                if (arr[i] < item) {
                    ++pos;
                }
            }
            while (item == arr[pos]) {
                ++pos;
            }
            std::swap(item, arr[pos]);
        }
    }
}

int main() {
    // Sample usage of Cycle Sort
    std::vector<int> arr = {5, 2, 1, 3, 4};
    
    std::cout << "Original Array: ";
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    cycleSort(arr);

    std::cout << "Sorted Array: ";
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}