#include <iostream>
#include <vector>

// GnomeSort function implements the Gnome Sort algorithm on a vector.
// Gnome Sort is a simple sorting algorithm that works by repeatedly swapping adjacent elements if they are in the wrong order.
template <typename T>
void gnomeSort(std::vector<T>& array) {
    size_t i = 0;

    // Gnome Sort algorithm
    while (i < array.size()) {
        // If at the beginning or the current element is greater than or equal to the previous one, move to the next element.
        if (i == 0 || array[i] >= array[i - 1]) {
            ++i;
        } else {
            // If the current element is smaller than the previous one, swap them and move back to check again.
            std::swap(array[i], array[i - 1]);
            --i;
        }
    }
}

int main() {
    // Creating and using a sample vector for Gnome Sort.
    std::vector<int> myVector = {5, 2, 9, 1, 5, 6};

    // Displaying the original vector.
    std::cout << "Original vector: ";
    for (const auto& element : myVector) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Applying Gnome Sort to the vector.
    gnomeSort(myVector);

    // Displaying the sorted vector.
    std::cout << "Sorted vector: ";
    for (const auto& element : myVector) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
