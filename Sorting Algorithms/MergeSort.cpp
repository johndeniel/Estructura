#include <iostream>
#include <vector>

// Merge two subarrays into a single sorted array
template <typename T>
void merge(std::vector<T>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays to hold the data
    std::vector<T> leftArray(n1);
    std::vector<T> rightArray(n2);

    for (int i = 0; i < n1; i++) {
        leftArray[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++) {
        rightArray[j] = arr[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;

    // Merge the two subarrays back into the original array
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

// Recursive function to perform merge sort on the array
template <typename T>
void mergeSort(std::vector<T>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int arrSize = arr.size();
    mergeSort(arr, 0, arrSize - 1);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}