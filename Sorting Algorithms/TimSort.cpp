#include <iostream>
#include <vector>
#include <algorithm>

// Constants
const int MIN_MERGE = 32; // Minimum size for a segment before applying insertion sort

// TimSort class implements a simplified version of the Tim Sort algorithm.
template <typename T>
class TimSort {
private:
    // Helper function for insertion sort within a specified range.
    static void insertionSort(std::vector<T>& arr, int left, int right) {
        for (int i = left + 1; i <= right; ++i) {
            T key = arr[i];
            int j = i - 1;

            // Shift elements greater than the key to the right
            while (j >= left && arr[j] > key) {
                arr[j + 1] = arr[j];
                --j;
            }

            arr[j + 1] = key; // Place the key in its correct position
        }
    }

    // Helper function for merging two sorted segments.
    static void merge(std::vector<T>& arr, int l, int m, int r) {
        int len1 = m - l + 1, len2 = r - m;
        std::vector<T> left(len1), right(len2);

        // Copy data to temporary arrays
        for (int i = 0; i < len1; ++i)
            left[i] = arr[l + i];
        for (int i = 0; i < len2; ++i)
            right[i] = arr[m + 1 + i];

        int i = 0, j = 0, k = l;

        // Merge the two arrays
        while (i < len1 && j < len2) {
            if (left[i] <= right[j])
                arr[k++] = left[i++];
            else
                arr[k++] = right[j++];
        }

        // Copy the remaining elements of left, if any
        while (i < len1)
            arr[k++] = left[i++];

        // Copy the remaining elements of right, if any
        while (j < len2)
            arr[k++] = right[j++];
    }

public:
    // Main sorting function implementing the Tim Sort algorithm.
    static void timSort(std::vector<T>& arr) {
        int n = arr.size();

        // Apply insertion sort on small segments
        for (int i = 0; i < n; i += MIN_MERGE)
            insertionSort(arr, i, std::min((i + MIN_MERGE - 1), (n - 1)));

        // Merge segments in a bottom-up manner
        for (int size = MIN_MERGE; size < n; size = 2 * size) {
            for (int left = 0; left < n; left += 2 * size) {
                int mid = left + size - 1;
                int right = std::min((left + 2 * size - 1), (n - 1));

                if (mid < right)
                    merge(arr, left, mid, right);
            }
        }
    }
};

int main() {
    // Example usage of the TimSort algorithm
    std::vector<int> data = {5, 2, 9, 1, 5, 6};

    std::cout << "Original array: ";
    for (const auto& element : data) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Apply Tim Sort to the array
    TimSort<int>::timSort(data);

    std::cout << "Sorted array: ";
    for (const auto& element : data) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}