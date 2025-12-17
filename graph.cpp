#include "graph.h"
#include <stack>
#include <climits>

// Constructor
Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

// Add edge (undirected graph)
void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

// BFS
vector<int> Graph::bfs(int src) {
    vector<int> dist(V, -1);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto &neigh : adj[node]) {
            int next = neigh.first;
            if (dist[next] == -1) {
                dist[next] = dist[node] + 1;
                q.push(next);
            }
        }
    }
    return dist;
}

// DFS (iterative)
vector<int> Graph::dfs(int src) {
    vector<int> visited(V, 0);
    stack<int> st;
    vector<int> order;

    st.push(src);

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            visited[node] = 1;
            order.push_back(node);

            for (auto &neigh : adj[node]) {
                int next = neigh.first;
                if (!visited[next]) {
                    st.push(next);
                }
            }
        }
    }
    return order;
}

// Dijkstra
vector<int> Graph::dijkstra(int src) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d > dist[node]) continue;

        for (auto &neigh : adj[node]) {
            int next = neigh.first;
            int weight = neigh.second;

            if (dist[node] + weight < dist[next]) {
                dist[next] = dist[node] + weight;
                pq.push({dist[next], next});
            }
        }
    }
    return dist;
}
