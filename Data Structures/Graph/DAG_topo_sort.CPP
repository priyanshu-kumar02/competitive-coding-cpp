//1-based indexing
lli V,E,x,y,weight,to;

void dfs_finish_time(vector< vector<pii> > &graph,stack<lli> &Stack,lli v,vec &visited)
{
	
	visited[v]=1;
	for (unsigned lli i=0 ; i<graph[v].size() ; i++)
	{
		to=graph[v][i].second;
		if(!visited[ to ])
		dfs_finish_time(graph,Stack,to,visited);
	}

	Stack.push(v);
}

void topo_sort(vector< vector<pii> > &graph)//uses above function
{
	vec visited(V,0);
	stack<lli> Stack;
	
	for (lli i=1 ; i<=V ; i++)
	{
		if(!visited[i])
		dfs_finish_time(graph,Stack,i,visited);
	}
	
	while(!Stack.empty())
	{
	cout<<Stack.top()<<" ";
	Stack.pop();
	}

}


