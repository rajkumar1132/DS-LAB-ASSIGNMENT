// Minimum Spanning Tree (Kruskal and Prim)
// KRUSKAL
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y])
            parent[x] = y;
        else if (rank[x] > rank[y])
            parent[y] = x;
        else {
            parent[y] = x;
            rank[x]++;
        }
    }
};

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(V);
    int mst_weight = 0;

    cout << "Edges in Kruskal MST:\n";
    for (auto& e : edges) {
        if (dsu.find(e.u) != dsu.find(e.v)) {
            cout << e.u << " - " << e.v << " (Weight: " << e.w << ")\n";
            mst_weight += e.w;
            dsu.unite(e.u, e.v);
        }
    }
    return mst_weight;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V = 4;
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };

    int weight = kruskalMST(V, edges);
    cout << "Total weight of Kruskal MST: " << weight << "\n";

    return 0;
}