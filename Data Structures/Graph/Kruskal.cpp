// O(ElogV)  ,sorting of edges complexity dominates  ,E<=V^2
// KRUSKAL Minimum Spanning Trees ,assuming edge-weight<10e10
//Note: Notice why we don't use marked[V] for cycle detection as we use in prim's
//we could sort the edges as well using 'pair<lli, <pair<lli,lli> > edges'  but dat takes n^2 at worst...pr_queue takes n*log(n) always

#include<bits/stdc++.h>
#define lli long long int
#define mp make_pair
#define s(x) scanf("%lld",&x)
using namespace std;
 
 
vector<lli> dsu;
vector<lli> size;
lli V,E;
 
 
void initialise()
{
	for (lli i=0 ; i<=V ; i++)
	{
		dsu[i]=i;
		size[i]=1;
	}
	
} 

lli root(lli i)
{
	while (i!=dsu[i])
	{
		dsu[i]=dsu[dsu[i]];
		i=dsu[i];
	}
	return i;
}
 
 
void unite(lli x,lli y)
{
 
	lli root_x=root(x);
	lli root_y=root(y);
	
	if(root_x!=root_y)
	{
		if(size[root_x]<size[root_y])
		{
			dsu[root_x]=root_y;
			size[root_y]+=size[root_x];
		}
		else
		{
			dsu[root_y]=root_x;
			size[root_x]+=size[root_y];
		}
	}
 
}
 
lli kruskal( set<  pair< lli,pair<lli,lli> >  > edges)
{
	
	lli cost=0,added=0;
	
	for ( added=0 ; added!=V-1 ; ) 
	{
		lli weight=(*edges.begin()).first;
		
		lli src   =(*edges.begin()).second.first;
		lli dst   =(*edges.begin()).second.second;
		edges.erase(*edges.begin());
		
		if(root(src) != root(dst) ) //detect cycle
		{
			unite(src,dst);
			cost+=weight;
			added++;
		}	
		
	}
	
	return cost;	
}
 
 
int main()
{

lli t,src;
s(t);
 
  while(t--)
  {
		lli x,y,weight;
		s(V);s(E);
 
		set< pair< lli ,pair<lli,lli> >  > edges;
		dsu.resize(V+1);size.resize(V+1);
		initialise();
		
			for (lli i=1 ; i<=E ; i++)
			{
				s(x);s(y);s(weight);
				edges.insert( {weight, {x,y}} );
			}
			cin>>src;
		printf("%lld\n",kruskal(edges));
  }
}
