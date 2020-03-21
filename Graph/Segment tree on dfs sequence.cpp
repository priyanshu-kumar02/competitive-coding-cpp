/*problem:http://codeforces.com/problemset/problem/620/E
The New Year tree is an undirected tree with n vertices and root in the vertex 1.

You should process the queries of the two types:

-Change the colours of all vertices in the subtree of the vertex v to the colour c.
-Find the number of different colours in the subtree of the vertex v. */
 
	#include<stdio.h>
	#include<bits/stdc++.h>
	#include<vector>
	#define lli long long int
	#define vec vector<lli>
	using namespace std;

	vector<lli> tree(1<<20);
	vector<lli> lazy(1<<20,0);
	vector<int> color(400005);
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
	


	void check_lazy(lli i,lli ss,lli se)
	{
	if(lazy[i])
		{
		  tree[i]=1LL<<(lazy[i]);
		  if(ss!=se)  //not leaf
		  {
			  lazy[2*i+1]=lazy[i];
			  lazy[2*i+1+1]=lazy[i];
		  }
		  lazy[i]=0;
		}

	}
	

	void build(lli l , lli r , lli node){
	lazy[node]=0;
    if(l == r){
        tree[node] = (1LL << color[perm[l]] );
    }
    else{
        lli mid = (l + r) >> 1;
        build(l , mid , 2*node+1);
        build(mid + 1 , r , 2*node + 1+1);
        tree[node] = tree[2*node+1] | tree[2*node +1+ 1];
    }
}


	void update_lazy(lli i,lli qs,lli qe,lli val,lli ss,lli se) //i-> current working index in segtree
	{
		check_lazy(i,ss,se);
		
		if(qe<ss or qs>se or ss>se) return;
				
		if(ss>=qs and se<=qe)
		{
			tree[i]=1LL<<(val);
			if(ss!=se)
			{
			lazy[2*i+1]=val;
			lazy[2*i+1+1]=val;
			}return;
		}
		
		update_lazy(2*i+1,qs,qe,val,ss,(ss+se)/2);
		update_lazy(2*i+1+1,qs,qe,val,(ss+se)/2+1,se);
		tree[i]=tree[2*i+1] | tree[2*i+1+1];
		
	}

	//again 4 cases
	lli query(lli i,lli qs,lli qe,lli ss,lli se)
	{
		check_lazy(i,ss,se);
		
		if(qe<ss or qs>se or ss>se) return 0;
		
		if(ss>=qs and se<=qe) return tree[i];
		
		return query(2*i+1,qs,qe,ss,(ss+se)/2) | query(2*i+2,qs,qe,(ss+se)/2+1,se);
			
	}
lli count(lli mask)
{
lli cnt=0;
while (mask>0)
{
	if(mask&1)
	cnt++;
	mask=mask>>1;
}return cnt;



}
	int main()
	{
	
	lli n,m,x,y,v,c,type;

	scanf("%lld%lld",&n,&m);

		for (lli i=1 ; i<=n ; i++)
		scanf("%d",&color[i]);
		
		
		for (lli i=1 ; i<=n-1 ; i++)
		{
			scanf("%lld%lld",&x,&y);
			graph[x].push_back(y);
			graph[y].push_back(x);
			
		}
		dfs(1,0);
		for (lli i=1 ; i<=n ; i++)
		{
			update_lazy(0,start[i],start[i],color[i],1,n);
		}
		
		
			
		while(m--)
		{
			scanf("%lld",&type);
			if(type==1)
			{
			scanf("%lld%lld",&v,&c);
			update_lazy(0,start[v],finish[v],c,1,n);
			}
						else
			{
			scanf("%lld",&v);
			lli mask=query(0,start[v],finish[v],1,n);
			printf("%lld\n",count(mask));
			}
		}
	
	}