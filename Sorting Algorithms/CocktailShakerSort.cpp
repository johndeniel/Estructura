#include <iostream>
#include <vector>

// CocktailShakerSort function implements the Cocktail Shaker Sort algorithm.
template <typename T>
void CocktailShakerSort(std::vector<T>& array) {
    bool swapped = true; // Flag to check if any swaps were made

    size_t start = 0;
    size_t end = array.size() - 1;

    while (swapped) {
        // Reset the swapped flag on entering the loop,
        // because it might be true from a previous
        // swap, which we want to reset.
        swapped = false;

        // Perform a bubble sort from left to right
        for (size_t i = start; i < end; ++i) {
            if (array[i] > array[i + 1]) {
                std::swap(array[i], array[i + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped by inner loop,
        // the array is sorted, and the process can be terminated.
        if (!swapped)
            break;

        // Decrease the end index, as the last element
        // is already in its rightful spot.
        end--;

        // Reset the swapped flag.
        swapped = false;

        // Perform a bubble sort from right to left
        for (size_t i = end - 1; i >= start; --i) {
            if (array[i] > array[i + 1]) {
                std::swap(array[i], array[i + 1]);
                swapped = true;
            }
        }

        // Increase the start index, as the first element
        // is already in its rightful spot.
        start++;
    }
}

int main() {
    // Creating and using a sample array for Cocktail Shaker Sort.
    std::vector<int> myArray = {4, 2, 7, 1, 9, 5, 3};

    std::cout << "Original array:";
    for (const auto& element : myArray) {
        std::cout << " " << element;
    }
    std::cout << std::endl;

    // Applying Cocktail Shaker Sort to the array.
    CocktailShakerSort(myArray);

    std::cout << "Sorted array:";
    for (const auto& element : myArray) {
        std::cout << " " << element;
    }
    std::cout << std::endl;

    return 0;
}