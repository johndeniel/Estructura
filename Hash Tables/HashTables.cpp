#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

// HashTable class implements a basic hash table using separate chaining for collision resolution.
template <typename Key, typename Value> class HashTable {
    private:
        static const size_t TABLE_SIZE = 10; // Size of the hash table

    std::vector<std::list<std::pair<Key, Value>>> table; // Vector of linked lists

    // Simple hash function that calculates the sum of ASCII values of characters in the key.
    size_t hashFunction(const Key& key) const {
        size_t hash = 0;
        for (const auto& c : key) {
            hash += static_cast<size_t>(c);
        }
        return hash % TABLE_SIZE;
    }

    public:
        // Constructor initializes the hash table.
        HashTable() : table(TABLE_SIZE) {}

    // Inserts a key-value pair into the hash table.
    void insert(const Key& key, const Value& value) {
        size_t index = hashFunction(key);
        table[index].emplace_back(key, value);
    }

    // Finds the value associated with a given key in the hash table.
    // Returns true if the key is found, false otherwise.
    bool find(const Key& key, Value& value) const {
        size_t index = hashFunction(key);
        for (const auto& entry : table[index]) {
            if (entry.first == key) {
                value = entry.second;
                return true;
            }
        }
        return false;
    }
};

int main() {
    // Creating and using a sample hash table.
    HashTable<std::string, int> myHashTable;

    myHashTable.insert("apple", 5);
    myHashTable.insert("banana", 10);
    myHashTable.insert("cherry", 8);

    int value;

    if (myHashTable.find("banana", value)) {
        std::cout << "Value for key 'banana': " << value << std::endl;
    } else {
        std::cout << "Key 'banana' not found." << std::endl;
    }

    if (myHashTable.find("grape", value)) {
        std::cout << "Value for key 'grape': " << value << std::endl;
    } else {
        std::cout << "Key 'grape' not found." << std::endl;
    }

    return 0;
}
