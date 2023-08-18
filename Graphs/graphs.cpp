#include <iostream>
#include <unordered_map>
#include <unordered_set>

// Graph class implements a basic undirected graph using an adjacency list representation.
template <typename T> class Graph {
    private:
        std::unordered_map<T, std::unordered_set<T>> adjacencyList; // Adjacency list for vertices and their neighbors

    public:
        // Adds a vertex to the graph.
        void addVertex(const T& vertex) {
            if (adjacencyList.find(vertex) == adjacencyList.end()) {
                adjacencyList[vertex] = std::unordered_set<T>();
            }
        }

    // Adds an edge between two vertices in the graph.
    void addEdge(const T& vertex1, const T& vertex2) {
        adjacencyList[vertex1].insert(vertex2);
        adjacencyList[vertex2].insert(vertex1); // Undirected graph, so adding in both directions
    }

    // Displays the graph's adjacency list.
    void display() const {
        for (const auto& entry : adjacencyList) {
            std::cout << entry.first << " -> ";
            for (const auto& neighbor : entry.second) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // Creating and using a sample undirected graph.
    Graph<std::string> myGraph;

    myGraph.addVertex("A");
    myGraph.addVertex("B");
    myGraph.addVertex("C");
    myGraph.addVertex("D");

    myGraph.addEdge("A", "B");
    myGraph.addEdge("B", "C");
    myGraph.addEdge("C", "D");
    myGraph.addEdge("D", "A");

    // Displaying the adjacency list of the graph.
    myGraph.display();

    return 0;
}
