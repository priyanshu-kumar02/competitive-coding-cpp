//FINDS LCA USING SQRT DECOMPOSITION...LOOK IN MATERIAL FOR EXPLANATION, O(sqrt(height)) for LCA(x,y)
//Problem:http://www.spoj.com/problems/LCA/

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define vec vector
#define pb push_back

vec<int> graph[1005];
int  P[1005],L[1005],MP[1005];  //P=parent,L=level,GP=megaparent (means the link with upper section)
int max_L=-1;
int root=-1;

//calculates (parent,level) arrays
void calc(int n) 				 
{
	if(n==1)
	L[n]=0,P[n]=-1;
	
	else
	L[n] = L[P[n]]+1;
	
	max_L= max( L[n],max_L);  
	
	for (int i:graph[n])
	{
		if(i!=P[n])
		{
		 P[i]=n;
		 calc(i);
	    }
	}
}

//calculates MegaParent of all nodes
void calc_MP(int n)
{
	if(L[n]<root)
	MP[n]=1;
	
	else
	{
		if(L[n]%root==0)
		 MP[n]=P[n];
		else
		 MP[n]=MP[P[n]];
	}
	
	for(int i:graph[n])
	if(i!=P[n])
	calc_MP(i);
}

int LCA(int x,int y)
{
	while (MP[x]!=MP[y])
	{
		if(L[x]>L[y])
		x=MP[x];
		else
		y=MP[y];
	}
	
	while(x!=y)
	{
		if(L[x]>L[y])
		x=P[x];
		else
		y=P[y];
	}
	return x;
	
}
int main()
{
	
	//freopen("input.txt","r",stdin);
	int t,n,m,q,x,y;
	cin>>t;
	
	for( int C=1; C<=t; C++)
	{
		cin>>n;
		max_L=-1;
		
		for (int i = 1; i <=n ; i++)
		{
			cin>>m;
			while (m--)
			{
				cin>>x;
				graph[i].pb(x);
				graph[x].pb(i);
			}
			
		}
		calc(1);
		root=(int)sqrt(max_L+1);
		calc_MP(1);
		
		cin>>q;
		cout<<"Case "<<C<<":\n";
		
		while (q--)
		{
			cin>>x>>y;
			cout<<LCA(x,y)<<endl;
		}
		
		memset(P,0,sizeof(int)*1005);
		memset(L,0,sizeof(int)*1005);
		memset(MP,0,sizeof(int)*1005);
		for (int i = 1; i <=n ; i++)
		graph[i].clear();
		max_L=-1;		
	}
	
	
}
