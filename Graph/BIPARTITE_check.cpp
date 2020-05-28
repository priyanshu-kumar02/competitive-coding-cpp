vec<int> adj[SZ];
int color[SZ]; //{1,2}
bool isBipartite = true;

void dfs(int u, bool parity) {
	color[u] = parity ? 2 : 1;
	for(int v: adj[u]) {
		if(!color[v]) {
			dfs(v, !parity);
		}
		else if(color[v] == color[u]){
			isBipartite = false;
			return;
		}
	}
}
