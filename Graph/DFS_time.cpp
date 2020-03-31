vec<int> adj[SZ];
int T;
int L[SZ], P[SZ], tin[SZ], tout[SZ];
/////////////////////////////////////////////////
 
void dfs(int u, int p, int l) {
    tin[u] = T++;
    P[u] = p;
    L[u] = l;
    for (int v : adj[u]) 
        if (v - p)
        dfs(v, u, l + 1);
    tout[u] = T++;
}
