#include <bits/stdc++.h>
#include <set>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int,int>>> adj, int S) {
    set<pair<int, int>> st;
    vector<int> dist(V, 1e9);
    vector<int> parent(V, -1);

    st.insert({0, S});
    dist[S] = 0;

    while (!st.empty()) {
        auto it = *(st.begin());
        int node = it.second;
        int current_dist = it.first;
        st.erase(st.begin());

        for (auto edge : adj[node]) {
            int adjNode = edge.first;
            int edgeWeight = edge.second;
            if (parent[adjNode] == node) { 
                cout  << "Negative Cycle : "<< -1 << endl;
                return vector<int>();
            }

            if (current_dist + edgeWeight < dist[adjNode]) {
                if (dist[adjNode] != 1e9) {
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = current_dist + edgeWeight;
                st.insert({dist[adjNode], adjNode});
                parent[adjNode] = node; 
            }


        }
    }
    return dist;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> shortestDistances = dijkstra(V, adj, 0);

    if (shortestDistances.empty()) {
        return 0;
    }

    for (int i = 0; i < V; i++) {
        cout << "Shortest distance from " << "0" << " to " << i << " is: " << shortestDistances[i] << endl;
    }

    return 0;
}
