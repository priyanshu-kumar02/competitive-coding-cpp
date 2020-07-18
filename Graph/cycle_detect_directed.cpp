vec<int> adj[SZ];
vec<bool> vis(SZ, false);
vec<bool> instack(SZ, false);

void dfs_cyc(int u) {
	instack[u] = true;
	vis[u] = true;

	for (int v : adj[u]) {
		if (!vis[v])
			dfs_cyc(v);
		else if (instack[v]) {
			cycle = true;
			return;
		}
	}
	instack[u] = false;
}
