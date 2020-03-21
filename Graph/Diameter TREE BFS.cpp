#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define vec vector
#define pb push_back
#define s(x) scanf("%d",&x)
#define pii pair<int,int>
#define PI 3.1415926535897932384626
 
vec<int> graph[10005];
pii bfs(int n)
{
	vec<int> visited(10005,0);
	vec<int> dist(10005,0);
	dist[n]=0;
	
	queue<int> Q;
	Q.push(n);
	visited[n]=1;
	int x;
	
	while (!Q.empty())
	{
		x=Q.front();
		Q.pop();
		visited[x]=1;
		
		for (int i:graph[x])
		{
			if (!visited[i])
			{
				Q.push(i);
				dist[i]=dist[x]+1;
			}
			
		}
		
	}
	//cout<<x<<","<<dist[x]<<endl;
	return {x,dist[x]};
}
 
int main()
{
	//freopen("input.txt","r",stdin);
	int v,x,y;
	cin>>v;
	for (int i = 0; i < v-1; i++)
	{
		cin>>x>>y;
		graph[x].pb(y);
		graph[y].pb(x);
	}
	pii far=bfs(1);
	pii farthest=bfs(far.first);
	cout<<farthest.second;
 
 
}
 