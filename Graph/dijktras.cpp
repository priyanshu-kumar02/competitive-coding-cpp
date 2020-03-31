////////////////- src to dest  -//////////////////////////
//priority queue is faster than set

vec<pii> adj[10005];
int V,E;

int dijktra(int x,int y){
	vec<int> d(V+1,INT_MAX);
	d[x]=0;
	priority_queue<pii> cur;
	cur.push({0,x});
	
	while (!cur.empty())
	{	
	    int closest=cur.top().se;cur.pop();
	    if(closest==y) return d[y];
	    for(auto i: adj[closest])
			if(d[i.se]> d[closest]+i.fi)
			{
			 d[i.se]= d[closest]+ i.fi;
			 cur.push ({-d[i.se],i.se});
			}	
	}
	return -1;
}

////////////////////- src to all - ////////////////////////
int n=100005;
vector<int> dijktra(int x) {
	vec<int> d(n+1,INT_MAX);
        d[x]=0;
	priority_queue<pii> cur;
	cur.push({0,x});
	
	while (!cur.empty()) {	
		int closest=cur.top().se;cur.pop();
	    	for(auto i: adj[closest])
			if(d[i.se]> d[closest]+i.fi){
			 d[i.se]= d[closest]+ i.fi;
			 cur.push ({-d[i.se],i.se});
			}	
	}
	return d;
}

// amortised complexity of inner for = ElogV
//amortised complexity of erase operation in outer while= VlogV
//  => O( (E+V) logV) =>O(ElogV)
