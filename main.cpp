#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    Graph g(6);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 8);
    g.addEdge(3, 4, 3);
    g.addEdge(4, 5, 1);

    cout << "BFS distances from node 0:\n";
    auto bfsResult = g.bfs(0);
    for (int i = 0; i < bfsResult.size(); i++) {
        cout << "Node " << i << ": " << bfsResult[i] << endl;
    }

    cout << "\nDFS traversal from node 0:\n";
    auto dfsResult = g.dfs(0);
    for (int node : dfsResult) {
        cout << node << " ";
    }

    cout << "\n\nDijkstra shortest paths from node 0:\n";
    auto dijkstraResult = g.dijkstra(0);
    for (int i = 0; i < dijkstraResult.size(); i++) {
        cout << "Node " << i << ": " << dijkstraResult[i] << endl;
    }

    return 0;
}
