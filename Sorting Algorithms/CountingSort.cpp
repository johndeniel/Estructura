#include <iostream>
#include <vector>
#include <algorithm>

// CountingSort class implements the Counting Sort algorithm.
class CountingSort {
public:
    // Sorts the input vector using Counting Sort.
    static void sort(std::vector<int>& arr) {
        if (arr.empty()) {
            return; // Nothing to sort
        }

        // Find the maximum element in the array
        int maxElement = *std::max_element(arr.begin(), arr.end());

        // Create a count array to store the count of each element
        std::vector<int> count(maxElement + 1, 0);

        // Count the occurrences of each element
        for (int element : arr) {
            count[element]++;
        }

        // Update the count array to store the cumulative count
        for (size_t i = 1; i < count.size(); ++i) {
            count[i] += count[i - 1];
        }

        // Create a temporary array to store the sorted result
        std::vector<int> result(arr.size());
        for (int i = arr.size() - 1; i >= 0; --i) {
            result[count[arr[i]] - 1] = arr[i];
            count[arr[i]]--;
        }

        // Copy the sorted result back to the original array
        std::copy(result.begin(), result.end(), arr.begin());
    }
};

int main() {
    // Creating and using a sample array for Counting Sort.
    std::vector<int> arr = {4, 2, 1, 3, 4, 2, 1, 3, 5, 4};
    
    std::cout << "Original array: ";
    for (int element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Applying Counting Sort to the array
    CountingSort::sort(arr);

    std::cout << "Sorted array: ";
    for (int element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
