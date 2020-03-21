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

const int N = 10010;

struct node {  
		int l, r, mx;
		node *left, *right;
		node(int ll, int rr) : 
			l(ll), r(rr), mx(-1), left(NULL), right(NULL) {}
}* root[N];
vector<int> chain[N];
vector<int> adj[N];


int sz[N], H[N], P[N], chainHd[N], pos[N],leadingEdge[N];

void update(node* p,int idx, int val){
	if(p->l == p->r) {
		p->mx = val;
		return;
	}        
	int mid = (p->l + p->r)>>1;
	update( (idx<=mid? p->left: p->right ), idx, val);
	p->mx = max(p->left->mx, p->right->mx);
}

int query(node* p,int ql, int qr) {
	if(qr < p->l or p->r < ql) return -1;
	if(ql <= p->l and p->r <= qr) return p->mx;
	return max(query(p->left,ql, qr), query(p->right,ql,qr));
}
		
node* build(int n,int l, int r) {
	node *p = new node(l, r);
	if(l < r) {
		int mid = (l + r)>>1;
		p->left = build(n,l, mid);
		p->right = build(n,mid+1, r);
	}
	p->mx= (l==r) ? leadingEdge[chain[n][l]] : 
					max(p->left->mx,p->right->mx);
	return p;
}

void dfs_build(int n, int p, int h) {   
	P[n] = p;
	H[n] = h;
	sz[n] = 1;
	for(int i=0; i<adj[n].size() ; i++) {
		int v=adj[n][i];
		if(v-p){
		 dfs_build(v, n, h+1);
		 sz[n] += sz[v];
		}
	}
}

void HLD(int n) {
	chain[n].pb(n);
	for(int i = 0; i < chain[n].size();i++){
		int v = chain[n][i];
		chainHd[v] = n;
		pos[v] = i;
		for( int k=0;k<adj[v].size();k++)
		{
			int j=adj[v][k];
			if(j!=P[v]) 
			 (sz[j]<<1) >= sz[v] ? chain[n].pb(j) : HLD(j);
		}
	}
	root[n] = build(n,0, chain[n].size() - 1);
}

int HLDquery(int u, int v) {
	
	int ans = -100;
	while(chainHd[u] != chainHd[v]) 
	{
		if(H[chainHd[u]] > H[chainHd[v]]) swap(u, v);
		ans = max(ans, query(root[chainHd[v]],0, pos[v]));
		
		v = P[chainHd[v]];
	}
	if(pos[u] > pos[v]) 
	swap(u, v);
	ans = max(ans,query(root[chainHd[u]],pos[u]+1, pos[v]));
	return ans;
}

int main() {
	int t,n,a,b,c,k,ti;char ss[10];
	vec< pair<pii,int> > edges;
	s(t);
	
	while (t--)
	{
		leadingEdge[1]=-1;
		s(n);
		
		for(int i=0; i<n-1; i++)
		{
			s(a);s(b);s(c);
			if(a>b) swap(a,b);
			adj[a].pb(b);
			adj[b].pb(a);
			edges.pb( { {a,b},c }) ;
		}
		
		dfs_build(1,1,0);
		for(int i=0; i<edges.size(); i++){
			if(H[edges[i].fi.fi]>H[edges[i].fi.se])
			swap(edges[i].fi.fi,edges[i].fi.se);
			leadingEdge[edges[i].fi.se]=edges[i].se;
		}
		HLD(1);
				
		while (1)
		{
			scanf("%s",ss);
			
			if(ss[0]=='D')
			break;
			
			else if(ss[0]=='C')
			{
				s(k);s(ti);
				update(root[ chainHd[(edges[k-1].fi).se] ] 
				,pos[(edges[k-1].fi).se] ,ti);
			}
			else
			{
			 	s(a);s(b);
			 	if(a==b) printf("0\n");
			 	else printf("%d\n",HLDquery(a,b));
			}
		}
		for(int i=0; i<=n; i++){
			adj[i].clear();
			chain[i].clear();
		}edges.clear();
	}
}
