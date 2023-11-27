#include <iostream>
#include <vector>
#include <algorithm>

// Function to perform insertion sort on a bucket
template <typename T>
void insertionSort(std::vector<T>& bucket) {
    std::size_t size = bucket.size();

    for (std::size_t i = 1; i < size; ++i) {
        T key = bucket[i];
        std::size_t j = i;

        // Move elements of the bucket that are greater than key to one position ahead
        while (j > 0 && bucket[j - 1] > key) {
            bucket[j] = bucket[j - 1];
            --j;
        }

        // Place the key at its correct position
        bucket[j] = key;
    }
}

// Function to perform bucket sort
template <typename T>
void bucketSort(std::vector<T>& arr) {
    // Determine the number of buckets (here, assuming all elements are in the range [0, 1))
    std::size_t numBuckets = arr.size();

    // Create empty buckets
    std::vector<std::vector<T>> buckets(numBuckets);

    // Distribute elements into buckets
    for (const auto& element : arr) {
        std::size_t bucketIndex = element * numBuckets;
        buckets[bucketIndex].push_back(element);
    }

    // Sort each bucket using insertion sort
    for (auto& bucket : buckets) {
        insertionSort(bucket);
    }

    // Concatenate the sorted buckets back into the original array
    std::size_t index = 0;
    for (const auto& bucket : buckets) {
        for (const auto& element : bucket) {
            arr[index++] = element;
        }
    }
}

int main() {
    // Creating and using a sample array for bucket sort.
    std::vector<double> arr = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23};

    // Displaying the original array
    std::cout << "Original array: ";
    for (const auto& element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Applying bucket sort
    bucketSort(arr);

    // Displaying the sorted array
    std::cout << "Sorted array: ";
    for (const auto& element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}