#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

// BogoSort class implements the Bogo Sort algorithm.
template <typename T>
class BogoSort {
private:
    // Helper function to check if the vector is sorted.
    bool isSorted(const std::vector<T>& array) const {
        return std::is_sorted(array.begin(), array.end());
    }

    // Helper function to shuffle the vector randomly.
    void shuffle(std::vector<T>& array) {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(array.begin(), array.end(), g);
    }

public:
    // Sorts the input vector using the Bogo Sort algorithm.
    void sort(std::vector<T>& array) {
        while (!isSorted(array)) {
            shuffle(array);
        }
    }
};

int main() {
    // Creating and using a sample Bogo Sort instance.
    BogoSort<int> bogoSort;

    std::vector<int> myArray = {5, 2, 8, 9, 1};
    
    std::cout << "Original Array: ";
    for (const auto& element : myArray) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Sorting the array using Bogo Sort.
    bogoSort.sort(myArray);

    std::cout << "Sorted Array: ";
    for (const auto& element : myArray) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
