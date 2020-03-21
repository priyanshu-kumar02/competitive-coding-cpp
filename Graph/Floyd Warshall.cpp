#include<bits/stdc++.h>
#define lli long long int
#define pii pair<lli,lli>
#define mp(x,y) make_pair(x,y)
#define vec vector<lli,lli>
using namespace std;

lli V,E,weight,to;

//O(V^3) algorithm to find All Pair Shortest Paths(APSP),djiktra's better if no negative edges O( V*ElogV )
void floyd_warshall(vector< vector<pii> > &graph)
{
vector< vector<lli> > dist(V+1, vector<lli>(V+1,10e10) ); //VxV matrix that stores shortest paths b/w all possible pairs of vertices,initialised to INF

	for (lli i=0 ; i<V ; i++)
 	 for (lli j=0 ; j<V ; j++)
    	if(i==j)
	    dist[i][j]=0;

for (lli i=0 ; i<V ; i++)
{
	for (unsigned lli j=0 ; j<graph[i].size() ; j++)
	{
		weight=graph[i][j].first;
		to=graph[i][j].second;
		dist[i][to]=weight;
	}
	
}

for (lli k=0 ; k<V ; k++)
{
		for (lli i=0 ; i<V ; i++)
		{
			for (lli j=0 ; j<V ; j++)
			{
				if( dist[i][j] > dist[i][k]+dist[k][j] and (dist[i][k]!=10e10 and dist[k][j]!=10e10))
				dist[i][j]=dist[i][k]+dist[k][j];
			}
			
		}
		
}

		for (lli i=0 ; i<V ; i++)
		{
			for (lli j=0 ; j<V ; j++)
			cout<<dist[i][j]<<" ";
			cout<<endl;
		}
cout<<"ji";
}

//to check for negative cycles,check if any diag element is <0
int main()
{
V=5;
vector< vector<pii> > graph(5);
graph[ 0].push_back( mp(-1,2) );
graph[ 0].push_back( mp(4,1) );
graph[ 2].push_back( mp(3,1) );
graph[ 2].push_back( mp(2,3) );
graph[ 2].push_back( mp(2,4) );
graph[ 3].push_back( mp(5,1) );
graph[ 3].push_back( mp(1,2) );
graph[ 4].push_back( mp(-3,3) );

	

	floyd_warshall(graph);
	
}


