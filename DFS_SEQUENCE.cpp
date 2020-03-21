/* -Arranges graph in an array using dfs
 * -vertex i starts at start[i] in perm and ends at finish[i] in perm
   -subtree of each vertex i includes [ perm[start[i]],perm[finish[i]] ]
   -
   - */

	vector<long int> perm(400005);
	vector<lli> start(400005);
	vector<lli> finish(400005);
	vector< vector<lli> > graph(400005);
	lli timer=0;

	void dfs(lli node,lli parent)
	{
	timer++;
	start[node]=timer;
	perm[timer]=node;
		for (unsigned lli i=0 ; i<graph[node].size() ; i++)
		{	
			lli next=graph[node][i];
			if(next!=parent)
			dfs(next,node);
		}
	finish[node]=timer;
	}
	


	
	
	

	
