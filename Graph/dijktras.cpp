vec<pii> adj[SZ];
int previous[SZ];

vector<int> dijktra(int x) {
	vec<int> d(SZ + 1, INT_MAX);
	d[x] = 0;
	priority_queue< pii, vec<pii>, greater<pii> > pq;
	pq.push({0, x});
	
	while (!pq.empty()) {	
		int closest = pq.top().se;
		pq.pop();
		for(auto v: adj[closest]) {
			int to = v.se;
			int weight = v.fi;
			if(d[to] > d[closest] + weight) {
				d[to] = d[closest] + weight;
				previous[to] = closest;
				pq.push({d[to], to});
			}	
		}
	}	
	return d;
}
