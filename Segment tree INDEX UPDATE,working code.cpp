// SEGMENT TREE FOR RANGE SUM AND VALUE UPDATION(REPLACE)
//Ques- https://www.hackerearth.com/problem/algorithm/2-vs-3/
#include<bits/stdc++.h>
#define lli long long int
using namespace std;
 
lli tree[300005];
 
char ss[1000005];
lli p2[100006];
lli n,q,l,r,choice,idx;
 
 
void build(lli i,lli start,lli end)
{
	if(start==end)
	tree[i]=ss[start]-48; 
	
	else
	{
		lli mid=(start+end)/2;
		
		build(2*i+1,start,mid);
		build(2*i+2,mid+1,end);
		
		tree[i]=(tree[2*i+1]*p2[end-mid]+tree[2*i+2])%3;
 
	}
	
}

 
void update(lli i,lli idx,lli start,lli end) //i-> current working index in segtree
{	

	if(start==end)
	{
		if(tree[i]==0)
		tree[i]=1;
		return;
	}
	
	lli mid=(start+end)/2;
	if(idx<=mid)
	update(2*i+1,idx,start,mid);
	else
	update(2*i+2,idx,mid+1,end);
	
	tree[i]=(tree[2*i+1]*p2[end-mid]+tree[2*i+2])%3;
	
}
 

lli query(lli i,lli l,lli r,lli s,lli e) //splitting range as well
{
	
	if(l==s and r==e)
	return tree[i];
	
	lli mid=(s+e)/2;	
	
	if(r<=mid)		  return query(2*i+1,l,r,s,mid);
	else if(l>=mid+1) return query(2*i+2,l,r,mid+1,e);
	else
	
	return (query(2*i+1,l,mid,s,mid)*p2[r-mid]+query(2*i+2,mid+1,r,mid+1,e))%3;
}
 
int main()
{
//freopen("input.txt","r",stdin);
	p2[1]=2;p2[0]=1;
 for (lli i=2 ; i<100005 ; i++)
 p2[i]=(p2[i-1]*2)%3;
 
 scanf("%lld",&n);
 
 scanf("%s",ss);
 scanf("%lld",&q);
 
 build(0,0,n-1);
 
 while(q--)
 {
 scanf("%lld",&choice);
 
	 if(choice==0)
	 {
	 scanf("%lld %lld",&l,&r);
	 lli ans=query(0,l,r,0,n-1);
	 printf("%lld\n",ans);
	 }
	 
	 else
	 {
	 scanf("%lld",&idx);
	 update(0,idx,0,n-1);
	 }
 
 }
 
}
 
 
