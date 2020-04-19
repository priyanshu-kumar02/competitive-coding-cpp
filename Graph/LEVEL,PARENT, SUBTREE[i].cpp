vec<int> adj[SZ];
int P[SZ],S[SZ],L[SZ];

void dfs(int u,int l)
{
	L[u] = l;
	S[u] = 1;
	
	for (int v: adj[u]) {
		if (v != P[u]) {
			P[v] = u;
			dfs(v,l+1);
			S[u] += S[v];
		}
	}	
}

//called as: dfs(1, 0)
