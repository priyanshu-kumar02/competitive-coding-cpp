//DFS-based

int n; // vertices
vector<int> topo;
vec<int> adj[SZ];
int indexOf[SZ];

void dfs(int v) {
    vis[v] = true;
    for (int u : adj[v]) {
        if (!vis[u])
            dfs(u);
    }
    topo.push_back(v);
}

void topological_sort() {
    for (int i = 1; i <= n; ++i) {
        if (!vis[i])
            dfs(i);
    }
    reverse(all(topo));
}

bool isCyclic() {
	for(int i = 0; i < topo.size(); i++) 
	indexOf[topo[i]] = i;
	for(pii e: directed) {
		if(indexOf[e.fi] > indexOf[e.se])
		return true;
	}
	return false;
}




//BFS-based

/****   KAHN's ALGORITHM toposort using BFS.     ****/
// Problem: lexicographically smallest topological sort https://www.spoj.com/problems/TOPOSORT/
// detects cycle also (no toposort exists)

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

vec<int> adj[100005];
int in[100005]; //stores indegree of each vertex
vec<int> topo;
int vis_cnt = 0;
priority_queue <int, vector<int>, greater<int>> q; //min-heap

void bfs_topo()
{
	while (!q.empty()) {
		int u=q.top();
		q.pop();
		topo.pb(u);
        vis_cnt++;
		
		for(int v:adj[u]) {
			in[v]--;
			if(in[v]==0)
			q.push(v);
		} 
	}
}

int main()
{
	int n,m,u,v;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        cin >> u >> v;
        adj[u].pb(v);
		in[v]++;
	}

    for (int i = 1; i <= n; i++){
        if(in[i] == 0)
            q.push(i);
    }
    bfs_topo();
	if(vis_cnt < n) {
        cout << "Sandro fails.";
        return 0;
    }  
	for(int i=0; i<topo.size(); i++)
        cout << topo[i] << " ";
}
