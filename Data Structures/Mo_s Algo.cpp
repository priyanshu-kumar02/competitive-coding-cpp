//Mo's algo O( (n+q)root(n) )
//Prob: Count distinct elements in range [L,R]

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define vec vector
#define pb push_back
#define s(x) scanf("%d",&x)
#define pii pair<int,int>
#define fi first
#define se second
#define PI 3.1415926535897932384626
 
int SQRT,ans=0;
int arr[30004];
int freq[1000002];
int query_ans[200005];
 
struct node{
	int L,R,i;
	}query[200005];
 
bool cmp(node a,node b)
{
	if (a.L/SQRT != b.L/SQRT)
	return a.L < b.L;
	return a.R < b.R;
}
 
void add(int pos)
{
	freq[arr[pos]]++;
	if(freq[arr[pos]]==1)
	ans++;
}
void remove(int pos)
{
	freq[arr[pos]]--;
	if(freq[arr[pos]]==0)
	ans--;
}
 
 
int main()
{
	//freopen("input.txt","r",stdin);
	int n,q;
	s(n);
	SQRT=floor(sqrt(n));
	for(int i=0; i<n; i++)
	{
		s(arr[i]);
	}
	s(q);
	
	for(int i=0; i<q; i++)
	{
		s(query[i].L); query[i].L--;
		s(query[i].R); query[i].R--;
		query[i].i=i;
	}
	sort(query,query+q,cmp);
	int currentL=0,currentR=0,L,R;
	add(0);
	
	for(int i=0; i<q; i++){
		L=query[i].L;
		R=query[i].R;
		
		while(currentL < L) 
		remove(currentL++);
		
		while(currentL > L) 
		add(--currentL);
		
		while(currentR < R) 
		add(++currentR);
		
		while(currentR > R) 
		remove(currentR--);
				
		query_ans[query[i].i]=ans;
	}
	for(int i=0; i<q; i++)
	printf("%d\n",query_ans[i]);
	
}
 
