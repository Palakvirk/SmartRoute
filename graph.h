#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <utility>
#include <queue>

using namespace std;

class Graph {
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    vector<int> bfs(int src);
    vector<int> dfs(int src);
    vector<int> dijkstra(int src);
};

#endif
