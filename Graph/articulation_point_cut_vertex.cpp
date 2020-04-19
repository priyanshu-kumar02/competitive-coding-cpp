//Problem: https://www.spoj.com/problems/SUBMERGE/
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define vec vector
#define pb push_back
#define s(x) scanf("%d",&x)
#define all(x)	x.begin(),x.end()
#define pii pair<int,int>
#define fi first
#define se second
#define SZ 100005
#define boost ios::sync_with_stdio(0);cin.tie(0)
 
vec<int> adj[SZ];
int t = 0;  //time-stamp
bool vis[SZ],AP[SZ];
int parent[SZ],low[SZ],disc[SZ];

void init() {
  for(int i =0; i<SZ; i++){
   vis[i] = AP[i] = false;  // Initializing AP and vis array as false
   parent[i] = -1;          // Initializing parent of each vertex to -1
   adj[i].clear();          // clearing the adjacency list.
   disc[i] = low[i] = 0;
  }
  t = 0;                    // initializing tim to 0
}
 
void dfs(int u)             //dfs(u) sets the minimum time-stamp for u that u can reach above
{
  vis[u] = true;
  low[u] = disc[u] = ++t;
  int child=0;
 
  for(int v: adj[u])
  {
	   if(vis[v] == false)
	   {
			child++;
			parent[v] = u;
			dfs(v);
			low[u]=min(low[u], low[v]);
			  
			if(parent[u] != -1 and low[v] >= disc[u])
			AP[u] = true;
			if(parent[u] == -1 and child > 1)   //root
			AP[u] = true;
	   }
	   else if(v!=parent[u])
       low[u]=min(low[u], disc[v]);
  }
}


int main()
{
	int n, m , u ,v;
	s(n); s(m);
	while (!(n==0 and m==0))
	{
		init();
		for(int i=0; i<m; i++) {
			s(u);s(v);
			adj[u].pb(v);
			adj[v].pb(u);
		}
		dfs(1);
		int ans = 0;
		for(int i=1; i<=n; i++)
		    ans += AP[i] ? 1 : 0;
		printf("%d\n", ans);
		s(n); s(m);
	}
}
