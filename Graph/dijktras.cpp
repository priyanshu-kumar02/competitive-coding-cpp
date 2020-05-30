vec<pii> adj[SZ];
int previous[SZ];

vector<int> dijktra(int x) {
	vec<int> d(SZ, __LONG_LONG_MAX__);
	d[x] = 0LL;
	priority_queue< pii, vec<pii>, greater<pii> > pq;
	pq.push({0LL, x});
	vec<bool> seen(SZ); //reduces complexity whenever pq contains duplicate elements

	while (!pq.empty()) {	
		int u = pq.top().se;
		pq.pop();
		if(seen[u]) continue;
		seen[u] = true;

		for(pii i: adj[u]) {
			int v = i.se;
			int w = i.fi;
			if(d[v] > d[u] + w) {
				d[v] = d[u] + w;
				pq.push({d[v], v});
			}	
		}
	}	
	return d;
}

/* Dijktra on MATRIX 
https://www.hackerrank.com/contests/hack-the-interview-iv-apac/challenges/optimal-path-1/problem */
int di[] = {-1, 0, +1, 0};
int dj[] = {0, +1, 0, -1};

int dijktra(pii x) {
    map<pii, int> d;
    d[x] = 0;
    priority_queue< pipii, vec<pipii>, greater<pipii> > pq;
    pq.push({0, {0, 0}});
    
    while (!pq.empty()) {    
        pii closest = pq.top().se;
        int i = closest.fi;
        int j = closest.se;
        pq.pop();
        for(int k=0; k<4; k++) {
            int ii = i + di[k];
            int jj = j + dj[k];
            
            if(valid(ii,jj) and  (d.find({ii,jj})==d.end() ||  d[{ii,jj}] > max(d[{i,j}], cost(i,j,ii,jj)))) {
                d[{ii,jj}]  =  max(d[{i,j}], cost(i,j,ii,jj));
                pq.push({d[{ii,jj}], {ii,jj}});
            }   
        }
    }    
    return d[{n-1,m-1}];
}
