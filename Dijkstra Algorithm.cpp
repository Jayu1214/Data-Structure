#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

const int INF = INT_MAX;  // Represents infinity in this implementation.

class Graph {
public:
    Graph(int numVertices) : V(numVertices) {
        adj.resize(V);
    }

    void addEdge(int source, int destination, int weight) {
        adj[source].push_back(make_pair(destination, weight));
    }

    void dijkstra(int startVertex) {
        vector<int> distance(V, INF);
        set<pair<int, int>> minDistances;  // Use a set to keep track of minimum distances.

        distance[startVertex] = 0;
        minDistances.insert({0, startVertex});

        while (!minDistances.empty()) {
            pair<int, int> current = *minDistances.begin();
            minDistances.erase(minDistances.begin());

            int u = current.second;

            for (const pair<int, int>& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (distance[u] != INF && distance[u] + weight < distance[v]) {
                    minDistances.erase({distance[v], v});
                    distance[v] = distance[u] + weight;
                    minDistances.insert({distance[v], v});
                }
            }
        }

        // Print the shortest distances from the start vertex to all other vertices.
        cout << "Shortest distances from vertex " << startVertex << " to all other vertices:\n";
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": ";
            if (distance[i] == INF) {
                cout << "Infinity";
            } else {
                cout << distance[i];
            }
            cout << endl;
        }
    }

private:
    int V;
    vector<vector<pair<int, int>> > adj;
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

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    graph.dijkstra(startVertex);

    return 0;
}
