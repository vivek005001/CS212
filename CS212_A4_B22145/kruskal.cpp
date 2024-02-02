#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> rank, parent, size; 

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1); 

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUpair(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUpair(parent[node]);
    }

    void UnionbyRank(int u, int v) {
        int ulp_u = findUpair(u);
        int ulp_v = findUpair(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++; 
        }
    }

    void UnionbySize(int u, int v) {
        int ulp_u = findUpair(u);
        int ulp_v = findUpair(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class MST{
    public:
        vector<pair<int, vector<pair<int, int>>> > spanningTree(int V, int k, vector<vector<int>> adj[]) {
            vector<pair<int,pair<int,int>>> edges;
            vector<pair<int,vector<pair<int,int>>>> A;
            for(int i=0;i<V;i++){
                for(auto it: adj[i]){
                    int adjNode = it[0];
                    int wt = it[1];
                    int node = i;

                    edges.push_back({wt,{node,adjNode}});
                }
            }
            DisjointSet ds(V);
            sort(edges.begin(), edges.end());
            int mstWt = 0;
            int ans = V-1;
            vector<pair<int,pair<int,int>>> mst;
            vector<pair<int,int>> modified_road;
            for(auto it: edges){
                int wt = it.first;
                int u = it.second.first;
                int v = it.second.second;

                if(ds.findUpair(u) != ds.findUpair(v)){
                    ds.UnionbySize(u,v);
                    mst.push_back(it);

                    k-=it.first;

                    V--;
                    if(k>=V-1){
                        ans = V-1;
                    }
                    else{
                        modified_road.push_back({u, v});

                    }
                }
            }
            A.push_back({ans,modified_road});
            return A;
        }

};

int main()
{
    int V, E, k;
    cin >> V >> E >> k;

    vector<vector<int>> adj[V+1];

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    if (k < V - 1)
    {
        cout << -1 << endl;
        cout << "Answer Not possible" << endl;
        return 0;
    }
    MST ms;
    vector<pair<int,vector<pair<int,int>>>> result =  ms.spanningTree(V,k, adj);

    int ans = result[0].first;
    cout <<"No. of Super roads made = "<< ans << endl;
    cout << "Super Road is Made Between : ";

    vector<pair<int, int>> modified_road = result[0].second;

    for (auto i : modified_road)
    {
        cout << i.first << " - " << i.second << ", ";
    }
    cout << endl;
    
}


// 5 7 10
// 1 2 2
// 1 3 3
// 1 4 1
// 2 3 4
// 2 4 5
// 3 4 6
// 4 5 7


// 4 3 5
// 1 2 3
// 2 3 2
// 3 4 4

// 4 3 2 
// 1 2 3
// 2 3 2
// 3 4 4