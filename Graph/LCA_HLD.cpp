vec<int> adj[1001];
int P[1001],SZ[1001],H[1001];

int t,N,m,x,q,u,v;

void dfs(int n,int h)
{
	H[n]=h;
	SZ[n]=1;
	
	for (int i: adj[n])
	{
		if (i!=P[n])
		{
			P[i]=n;
			dfs(i,h+1);
			SZ[n]+=SZ[i];
		}
	}	
}

vec<int> chain[1001];
int chainHead[1001];   

void HLD(int n)
{
	chain[n].pb(n);
	
	for(int i=0; i<chain[n].size(); i++)
	{
		int v=chain[n][i];
		chainHead[v]=n;
		for ( int j:adj[v] )
		{
	      if(j!=P[v])
	 	  (SZ[j]*2 >= SZ[v]) ? chain[n].pb(j) : HLD(j);
		}	
	}	
}

int LCA(int u,int v)
{
	while (chainHead[u] != chainHead[v])
	{ 
		if ( H[ chainHead[u] ]  >  H[ chainHead[v] ] )
		swap(u,v);
		v=P[chainHead[v]];		
	}
	return H[u] < H[v] ? u : v;	
}
