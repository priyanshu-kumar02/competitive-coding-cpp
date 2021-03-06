lli V,E,i,weight,to,large=10000000000;
lli p; unsigned lli q;

lli ford_bellman(vector< vector<pii> > &graph,lli src ,lli trg)
{

vector<lli> dist(V+1,large);
dist[src]=0;

	for ( i=1 ; i<=V-1 ; i++) //max path length is V-1
	{
		for( p=0 ; p<V ;p++)
		{
			for ( q=0 ; q<graph[p].size() ; q++)
			{
				weight=graph[p][q].first;
				to	  =graph[p][q].second;
				
				if( dist[p]!=large and dist [to] > dist[p]+weight )
				dist[to]=dist[p]+weight;  //to keep an track of path ,keep an array parent_of[] everytime you updare here 
							  //parent_of[to]=p
			}
			
		}
	}
	
return dist[trg];

}

// O(VE) ; all edges traversed V-1 times
/* to detect nesgative edge cycle,add one more iteration  thru all edges and check if any distance is reduced (add following code to ford_bellman() )
 * 		for( p=0 ; p<V ;p++)
		{
			for ( q=0 ; q<graph[p].size() ; q++)
			{
				weight=graph[p][q].first;
				to	  =graph[p][q].second;
				
				if( dist[p]!=large and dist [to] > dist[p]+weight )
				return -1;
			}
			
		}
		* */

