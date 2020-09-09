// Problem: https://cses.fi/problemset/task/1139/
// Count distinct colors in subtree u

vector<int> adj[SZ];
int ans[SZ];
int col[SZ];
 
set<int> dfs(int u, int p) {
	set<int> large;
	large.insert(col[u]);
 
	for(int v: adj[u]) {
		if(v!=p) {
			set<int> small = dfs(v, u);
			if(small.size() > large.size()) swap(small, large);
			for(int color: small) {
				large.insert(color);
			}
		}
	}
	ans[u] = large.size();
	return large;
}
