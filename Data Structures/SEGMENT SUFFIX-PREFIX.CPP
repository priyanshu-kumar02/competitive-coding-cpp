/* Problem:http://www.spoj.com/problems/GSS3/
 * SEGMENT TREE STORING-> MAX PREFIX,MAX SUFFIX,SUM,MAX SUBARRAY SUM
*/
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define vec vector
#define pb push_back
#define s(x) scanf("%lld",&x)
#define pii pair<int,int>
#define PI 3.1415926535897932384626



struct node 
{
lli Lmax=0,Rmax=0,Submax=0,Sum=0;
};

lli arr[500005];
node tree[500005];

node create_leaf(lli val)
{
	node New;
	New.Lmax=New.Rmax=New.Submax=New.Sum=val;
	return New;
}

node create_node(node left,node rite)
{
		node New;
		New.Lmax=     max( left.Lmax, left.Sum+rite.Lmax );
		New.Rmax=     max( rite.Rmax, rite.Sum+left.Rmax );
		New.Submax=   max( left.Submax, max( rite.Submax, left.Rmax+rite.Lmax) );
		New.Sum=      left.Sum+rite.Sum;
		return New;
}

void build(lli i,lli s,lli e)
{
	if (s==e)
	{
		tree[i]=create_leaf(arr[s]);
		return;
	}
	lli mid=(s+e)>>1;
	build(2*i+1,s,mid);
	build(2*i+2,mid+1,e);
	
	tree[i]=create_node(tree[2*i+1],tree[2*i+2]);
}

node query(lli i,lli s,lli e,lli L,lli R)
{
		if (s>=L and e<=R)
		{
			return tree[i];
		}
		
		lli mid=(s+e)>>1;
		
		if (R<=mid)
		return query(2*i+1,s,mid,L,R);
		
		else if(L>=mid+1)
		return query(2*i+2,mid+1,e,L,R);
		
		else 
		{
			node left=query(2*i+1,s,mid,L,R);
			node rite=query(2*i+2,mid+1,e,L,R);
			node ans =create_node(left,rite);
			return ans;
		}
}

void update(int i,int s,int e,int x,int val)
{
	if (s==e and s==x)
	{
		tree[i]=create_leaf(val);
		return;
	}

	int mid=(s+e)>>1;

	if (x<=mid)
	update(2*i+1,s,mid,x,val);
	
	else
	update(2*i+2,mid+1,e,x,val);
	
	tree[i]=create_node(tree[2*i+1],tree[2*i+2]);		
} 
int main()
{
	//freopen("input.txt","r",stdin);
	
	lli n,q,l,r,type;
	s(n);
	for (lli i = 0; i < n; i++)
	{
		s(arr[i]);
	}
	s(q);
	build(0,0,n-1);
	
	while (q--)
	{
		s(type);
		s(l);s(r);
		
		
		if(type==1)
		{
		lli ans= query(0,0,n-1,l-1,r-1).Submax;
		printf("%lld\n",ans);
		}
		else
		{
			update(0,0,n-1,l-1,r);
		}
		
	}
}
