#include <iostream>
#include <vector>

// PancakeSort class implements the Pancake Sort algorithm for sorting elements.
class PancakeSort {
private:
    // Flips the elements in the given range (from index 0 to endIdx).
    void flip(std::vector<int>& arr, int endIdx) {
        int start = 0;
        while (start < endIdx) {
            std::swap(arr[start], arr[endIdx]);
            start++;
            endIdx--;
        }
    }

    // Finds the index of the maximum element in the given range (from index 0 to endIdx).
    int findMaxIndex(const std::vector<int>& arr, int endIdx) const {
        int maxIdx = 0;
        for (int i = 1; i <= endIdx; ++i) {
            if (arr[i] > arr[maxIdx]) {
                maxIdx = i;
            }
        }
        return maxIdx;
    }

public:
    // Sorts the elements using the Pancake Sort algorithm.
    void pancakeSort(std::vector<int>& arr) {
        int n = arr.size();
        for (int currSize = n; currSize > 1; --currSize) {
            // Find the index of the maximum element in the remaining unsorted part.
            int maxIdx = findMaxIndex(arr, currSize - 1);

            // Move the maximum element to the beginning of the unsorted part.
            if (maxIdx != currSize - 1) {
                flip(arr, maxIdx);
                flip(arr, currSize - 1);
            }
        }
    }
};

int main() {
    // Creating and using a sample Pancake Sort.
    PancakeSort pancakeSort;

    std::vector<int> arr = {4, 2, 8, 1, 6, 3, 7, 5};
    std::cout << "Original array: ";
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    pancakeSort.pancakeSort(arr);

    std::cout << "Sorted array: ";
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}