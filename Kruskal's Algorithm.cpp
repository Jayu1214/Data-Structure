#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int source, destination, weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class Graph {
public:
    Graph(int numVertices) : V(numVertices) {}

    void addEdge(int source, int destination, int weight) {
        Edge edge = {source, destination, weight};
        edges.push_back(edge);
    }

    vector<Edge> kruskalMST() {
        vector<Edge> minimumSpanningTree;
        sort(edges.begin(), edges.end());

        vector<int> parent(V, -1);

        for (const Edge& edge : edges) {
            int root1 = find(parent, edge.source);
            int root2 = find(parent, edge.destination);

            if (root1 != root2) {
                minimumSpanningTree.push_back(edge);
                unionSets(parent, root1, root2);
            }
        }

        return minimumSpanningTree;
    }

private:
    int V;
    vector<Edge> edges;

    int find(vector<int>& parent, int vertex) {
        if (parent[vertex] == -1)
            return vertex;
        return find(parent, parent[vertex]);
    }

    void unionSets(vector<int>& parent, int root1, int root2) {
        parent[root1] = root2;
    }
};

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    Graph graph(numVertices);

    for (int i = 0; i < numEdges; i++) {
        int source, destination, weight;
        cout << "Enter edge " << i + 1 << " (source, destination, weight): ";
        cin >> source >> destination >> weight;
        graph.addEdge(source, destination, weight);
    }

    vector<Edge> minimumSpanningTree = graph.kruskalMST();

    cout << "Minimum Spanning Tree:" << endl;
    for (const Edge& edge : minimumSpanningTree) {
        cout << edge.source << " - " << edge.destination << " : " << edge.weight << endl;
    }

    return 0;
}
