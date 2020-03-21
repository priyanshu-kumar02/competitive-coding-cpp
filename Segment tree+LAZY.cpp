// SEGMENT TREE FOR RANGE SUM AND VALUE UPDATION(add)
/*You are given an array of N elements, which are initially all 0. After that you will be given C commands. They are -

* 0 p q v - you have to add v to all numbers in the range of p to q (inclusive), where p and q are two indexes of the array.

* 1 p q - output a line containing a single integer which is the sum of all the array elements between p and q (inclusive)*/

#include<bits/stdc++.h>
#define lli long long int
#define vec vector<lli>
using namespace std;

vec tree(400010,0);
vec arr(100005,0);
vec lazy(400010,0);

/* 4 cases for lazy updation of range
1.Working node is lazy marked.  //just this is extra from normal segtree
2.Completeley inside.
3.Completely outside.
4.Partial.
*/ 
void update_lazy(lli i,lli qs,lli qe,lli val,lli ss,lli se) //i-> current working index in segtree
{
	if(lazy[i])
	{
	  tree[i]+=(se-ss+1)*lazy[i];
	  if(ss!=se)  //not leaf
	  {
		  lazy[2*i+1]+=lazy[i];
          lazy[2*i+2]+=lazy[i];
	  }
	  lazy[i]=0;
	}
	
	if(qe<ss or qs>se or ss>se) return;
	
	if(ss>=qs and se<=qe)
	{
		tree[i]+=(se-ss+1)*val;
		if(ss!=se)
		{
		lazy[2*i+1]+=val;
		lazy[2*i+2]+=val;
		}return;
	}
	
	update_lazy(2*i+1,qs,qe,val,ss,(ss+se)/2);
	update_lazy(2*i+2,qs,qe,val,(ss+se)/2+1,se);
	tree[i]=tree[2*i+1]+tree[2*i+2];
	
}

//again 4 cases
lli sum_lazy(lli i,lli qs,lli qe,lli ss,lli se)
{
	if(lazy[i])
	{
	  tree[i]+=(se-ss+1)*lazy[i];
		  if(ss!=se)  //not leaf
		  {
			  lazy[2*i+1]+=lazy[i];
			  lazy[2*i+2]+=lazy[i];
		  }
	  lazy[i]=0;
	}
	
	if(qe<ss or qs>se or ss>se) return 0;
	
	if(ss>=qs and se<=qe) return tree[i];
	
	return sum_lazy(2*i+1,qs,qe,ss,(ss+se)/2)
	       +sum_lazy(2*i+2,qs,qe,(ss+se)/2+1,se);
		
}
int main()
{
lli t,n,c,type,q,p,v;
ios::sync_with_stdio(0);
cin>>t;

	while (t--)
	{
		cin>>n>>c;
		
		while (c--)
		{
			cin>>type;
			
			if(type==0)
			{
			cin>>p>>q>>v;
			update_lazy(0,p,q,v,1,n);
			}
			else
			{
			cin>>p>>q;
			cout<<sum_lazy(0,p,q,1,n)<<endl;
			}
		}
		arr.clear();lazy.clear();tree.clear();
		arr.resize(100005,0);
		lazy.resize(400010,0);
		tree.resize(400010,0);
	}
	
}
