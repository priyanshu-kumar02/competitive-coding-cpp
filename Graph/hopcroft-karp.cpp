/** source:http://zobayer.blogspot.in/2010/05/maximum-matching.html **/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vec vector
#define pb push_back
#define s(x) scanf("%d",&x)
#define all(x)	x.begin(),x.end()
#define pii pair<int,int>
#define fi first
#define se second
#define SZ 100005
#define boost ios::sync_with_stdio(0);
#define max(a,b,c,d) max(max(a,b),max(c,d))
 
#define MAX 100001
#define NIL 0
#define INF (1<<28)
 
vector< int > adj[MAX];
int n, m, match[MAX], dist[MAX];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = includes edges from left side to rite side
// 1-based indexing
 
bool bfs() {
    int i, u, v, len;
    queue< int > Q;
    for(i=1; i<=n; i++) {
        if(match[i]==NIL) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(dist[u]<dist[NIL]) {
            len = adj[u].size();
            for(i=0; i<len; i++) {
                v = adj[u][i];
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}
 
bool dfs(int u) {
    int i, v, len;
    if(u!=NIL) {
			len = adj[u].size();
			for(i=0; i<len; i++){
				v = adj[u][i];
				if(dist[match[v]]==dist[u]+1) {
					if(dfs(match[v])) {
						match[v] = u;
						match[u] = v;
						return true;
					 }
				 }
			 }
        dist[u] = INF;
        return false;
     }
    return true;
}
 
int hopcroft_karp() {
    int matching = 0, i;
    // match[] is assumed NIL for all vertex in G
    while(bfs())
        for(i=1; i<=n; i++)
            if(match[i]==NIL && dfs(i))
                matching++;
    return matching;
}
int main()
{
	int p,u,v;
	cin>>n>>m>>p;
	for(int i=0; i<p; i++){
		cin>>u>>v;
		adj[u].pb(v+n);
	}
	cout<<hopcroft_karp();
}
