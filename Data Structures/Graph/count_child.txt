// O(V+E)   
//almost recursive DFS 
//children  include root
//assumption:connected graph ; apply to each vertex if disconnected
//let root be 1


vector<lli> graph[1000];
int cnt[100];

int dfs(int n,int p)
{
	if(graph[n].size()==1 and n!=1)//leaf condition
	{
	cnt[n]=1;
	return cnt[n];
	}
	
	int count=1;
	for (lli i=0 ; i<graph[n].size() ; i++)
	{
		int child=graph[n][i];
		if( child!=p )
		count+=dfs(child,n);
	}
	cnt[n]=count;
	return cnt[n];
	
}

//called as dfs(1,1)
