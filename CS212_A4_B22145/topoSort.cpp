#include <bits/stdc++.h>
#include <queue>
using namespace std;

class TopoSort
{
public:
    vector<int> topoSort(int V, vector<vector<int>> adj)
    
    {
        int indegree[V+1] = {0};
        for (int i = 0; i < V+1; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V+1; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        if (q.empty())
        {
            cout << -1 << endl;
            cout << "They can't complete the HomeWork as all are dependent on one another";
        }
        vector<int> topo;
        vector<bool> visited(V + 1, 0);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            visited[node] = 1;
            topo.push_back(node);

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (!visited[it] && indegree[it] == 0)
                    q.push(it);
            }
        }
        return topo;
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N+1);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }
    TopoSort topo;
    vector<int> ans = topo.topoSort(N,adj);
    if(ans.size() != N + 1){
        cout<<-1<<endl;
        cout<<"They can't complete HW as all are dependent on one another";        
    }
    else {
        cout<<1<<endl;
        cout<<"They can complete HW";   
    }
    
    return 0;
}