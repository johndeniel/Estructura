#include <iostream>
#include <vector>

// LinearSearch class implements a basic linear search algorithm.
template <typename T>
class LinearSearch {
public:
    // Searches for a target element in the given vector using linear search.
    // Returns the index of the target if found, otherwise returns -1.
    static int search(const std::vector<T>& array, const T& target) {
        for (size_t i = 0; i < array.size(); ++i) {
            if (array[i] == target) {
                return static_cast<int>(i);
            }
        }
        return -1; // Target not found
    }
};

int main() {
    // Creating and using a sample linear search.
    std::vector<int> myArray = {4, 2, 7, 1, 9, 5};
    int target = 7;

    // Performing linear search on the array.
    int result = LinearSearch<int>::search(myArray, target);

    // Displaying the result of the linear search.
    if (result != -1) {
        std::cout << "Element " << target << " found at index " << result << std::endl;
    } else {
        std::cout << "Element " << target << " not found in the array." << std::endl;
    }

    return 0;
}