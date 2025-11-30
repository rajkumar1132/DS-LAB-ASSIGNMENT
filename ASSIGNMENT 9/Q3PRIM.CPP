//Minimum Spanning Tree (Kruskal and Prim)
// PRIM

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int primMST(int V, vector<vector<pair<int,int>>>& adj) {
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    key[0] = 0;
    pq.push({0, 0});

    int totalWeight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        totalWeight += key[u];

        for (auto [v, w] : adj[u]) {
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                pq.push({w, v});
            }
        }
    }

    return totalWeight;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V = 5;
    vector<vector<pair<int,int>>> adj(V);

    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected graph
    };

    addEdge(0, 1, 2);
    addEdge(0, 3, 6);
    addEdge(1, 2, 3);
    addEdge(1, 3, 8);
    addEdge(1, 4, 5);
    addEdge(2, 4, 7);
    addEdge(3, 4, 9);

    cout << "Total weight of Prim MST: " << primMST(V, adj) << "\n";

    return 0;
}
