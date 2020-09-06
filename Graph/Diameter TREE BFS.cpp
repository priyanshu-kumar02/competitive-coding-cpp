vec<int> adj[SZ];

pii bfs(int u) {
	vec<bool> visited(n+1, false);
	vec<int> d(n+1,0);
	d[u] = 0;
	queue<int> Q;
	Q.push(u);
	visited[u] = true;
	int front;
	
	while (!Q.empty()) {
		front = Q.front(); Q.pop();
		visited[front] = true;
		for (int v: adj[front]) {
			if (!visited[v]) {
				Q.push(v);
				d[v] = d[front]+1;
			}
		}
	}
	return { front, d[front]};
}

int diameter() {
	pii far = bfs(1);
	pii farthest = bfs(far.first);
	return farthest.se;
}
