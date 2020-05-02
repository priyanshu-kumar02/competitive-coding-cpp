int n; // number of vertices
vector<vector<int>> adj; // adjacency list of graph
vector<bool> vis(SZ, false);
vector<int> topo;

void dfs(int v) {
    vis[v] = true;
    for (int u : adj[v]) {
        if (!vis[u])
            dfs(u);
    }
    topo.push_back(v);
}

void topological_sort() {
    for (int i = 0; i < n; ++i) {
        if (!vis[i])
            dfs(i);
    }
    reverse(all(topo));
}
