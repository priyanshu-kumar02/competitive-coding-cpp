vec<int> adj[1001];
int P[1001],SZ[1001],H[1001];

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
