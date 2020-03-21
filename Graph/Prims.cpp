// O( ( (V+E)logV )
// PRIMS ALGORITH, EFFICIENT IF TOO MANY EDGES
//1-based indexing
//adj[x][i] denotes pair <weight,dest>

vec<pii> adj[1002];
 
lli prims(){
	vec<lli> visited(1002,0);
	lli done=1,to,wt,cost=0;
	visited[1]=1;
	set<pii> S;
	for(auto it:adj[1]) S.insert(it);
	
	while (done!=n){
		wt=(*S.begin()).fi,to=(*S.begin()).se;
		S.erase({wt,to});
		if(visited[to]) continue;
		visited[to]=1;
		done++,cost+=wt;
		for(auto it:adj[to])
		if(!visited[it.se]) S.insert(it);		
	}
	return cost;	
}
