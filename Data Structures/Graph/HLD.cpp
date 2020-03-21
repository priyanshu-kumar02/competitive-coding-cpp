/*********  HLD Implementation for    ************************************/
/******** https://www.hackerrank.com/challenges/heavy-light-white-falcon**/

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
#define SZ 100005 //1e5

const int N = 50010;
struct node {  
		int l, r, mx;
		node *left, *right;
		node(int ll, int rr) : 
			l(ll), r(rr), mx(0), left(NULL), right(NULL) {}
};

/******** SEGTREE-ON EACH CHAIN ******/
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
	if(qr < p->l or p->r < ql) return 0;
	if(ql <= p->l and p->r <= qr) return p->mx;
	return max(query(p->left,ql, qr), query(p->right,ql,qr));
}
		
node* build(int l, int r) {
	node *p = new node(l, r);
	if(l < r) {
		int mid = (l + r)>>1;
		p->left = build(l, mid);
		p->right = build(mid+1, r);
	}
	return p;
}
/**********************************************/

/********* SETUP SUBSIZE,PARENT,HEIGHT ********/
vector<int> adj[N];
int n, q;

node* 	root[N];/**holds root of segtree of each chain**/
vector<int> chain[N];
int sz[N], H[N], P[N], chainIdx[N], pos[N];


void dfs_build(int n, int p, int h) {
	P[n] = p;
	H[n] = h;
	sz[n] = 1;
	for(int i : adj[n]) {
		if(i-p){
		 dfs_build(i, n, h+1);
		 sz[n] += sz[i];
		}
	}
}
/**********************************************/

/************ HLD,HLD-QUERY***********************/
void HLD(int n) {
	chain[n].pb(n);
	for(int i = 0; i < chain[n].size();i++){
		int v = chain[n][i];
		chainIdx[v] = n;
		pos[v] = i;
		for(int j : adj[v])
			if(j-P[v]) 
			 2*sz[j] >= sz[v] ? chain[n].pb(j) : HLD(j);
	}
	root[n] = build(0, chain[n].size() - 1);
}

int query(int u, int v) {
	
	int ans = 0;
	while(chainIdx[u] != chainIdx[v]) 
	{
		if(H[chainIdx[u]] > H[chainIdx[v]]) swap(u, v);
		ans = max(ans, query(root[chainIdx[v]],0, pos[v]));
		v = P[chainIdx[v]];
	}
	
	if(pos[u] > pos[v]) 
	swap(u, v);
	
	ans = max(ans,query(root[chainIdx[u]],pos[u], pos[v]));
	return ans;
}
/******************************************************/

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> q;
	for(int i = 0;i < n-1;i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs_build(0, 0, 0);
	HLD(0);
	
	for(int i = 0;i < q;i++) {
		int type;
		cin >> type;
		if(type == 1) {
			int u, x;
			cin >> u >> x;
			update(root[chainIdx[u]],pos[u], x);
		}else {
			int u, v;
			cin >> u >> v;
			cout << query(u, v) << "\n";
		}
	}
}
