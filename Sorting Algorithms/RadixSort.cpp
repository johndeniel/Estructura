#include <iostream>
#include <vector>

// Function to find the maximum value in the array.
int findMax(const std::vector<int>& arr) {
    int max = arr[0];
    for (int i : arr) {
        if (i > max) {
            max = i;
        }
    }
    return max;
}

// Function to perform counting sort on the specified digit.
void countingSort(std::vector<int>& arr, int exp) {
    const int radix = 10; // Base 10 for decimal digits
    const int n = arr.size();

    std::vector<int> output(n, 0);
    std::vector<int> count(radix, 0);

    // Count occurrences of each digit at the specified place value.
    for (int i = 0; i < n; ++i) {
        count[(arr[i] / exp) % radix]++;
    }

    // Adjust the count array to store actual positions of the digits.
    for (int i = 1; i < radix; ++i) {
        count[i] += count[i - 1];
    }

    // Build the output array by placing elements in their sorted order.
    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % radix] - 1] = arr[i];
        count[(arr[i] / exp) % radix]--;
    }

    // Copy the sorted elements back to the original array.
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

// Radix Sort implementation.
void radixSort(std::vector<int>& arr) {
    // Find the maximum number to determine the number of digits.
    int max = findMax(arr);

    // Perform counting sort for every digit place value.
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    // Example usage of Radix Sort.
    std::vector<int> numbers = {170, 45, 75, 90, 802, 24, 2, 66};

    std::cout << "Original array: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }

    radixSort(numbers);

    std::cout << "\nSorted array: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }

    return 0;
}