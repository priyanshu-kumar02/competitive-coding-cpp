// SUFFIX ARRAY AND LCP (Longest Common Prefix)
// O(nlog^2(n))  <=SA_BUILD
// O(logn)       <=LCP 
// To get sorted order of suffixes with their index,use the last instance of array L[],L[i].p gives the index of suffix in ss[]
//NOTE:Giving a rank of -1 on line 31 to small strings ensures that small strings come b4 larger in sorted order
//Change "-1" to "-100" to make it work for alphanumeric strings

char ss[1005];
int P[20][1005];
int stp,cnt,N;

struct entry{
int nr[2];
int p;	//index of suffix in original string
} L[1005];

bool cmp(entry a,entry b)
{
return (a.nr[0]==b.nr[0]) ? (a.nr[1]<b.nr[1]) : (a.nr[0]<b.nr[0]);
}

void build_SA()
{
	for(int i=0; i<N; i++)
		P[0][i]=ss[i]-'a';
	
	for( (stp=1,cnt=1); (cnt>>1 <N); (stp++,cnt<<=1) )
	{
		for(int i=0; i<N; i++)
		{
			L[i].nr[0]= P[stp-1][i];
			L[i].nr[1]= i+cnt<N ? P[stp-1][i+cnt]: -1;
			L[i].p=i; 
		}
		sort(L,L+N,cmp);
		
		for(int i=0; i<N; i++)
			P[stp][L[i].p]= (i>0 and L[i].nr[0]==L[i-1].nr[0] and L[i].nr[1]==L[i-1].nr[1])? P[stp][L[i-1].p] : i;	
	}
}

int LCP(int x,int y)
{
	if (x==y) return N-x;
	
	int ans=0; 
	for(int k=stp-1; k>=0 and x<N and y<N; k--)
		if(P[k][x]==P[k][y])
		 x+=1<<k,y+=1<<k,ans+=1<<k;
	
	return ans;	
}


/*********************BELOW is complete code for spoj-SARRAY***************

#include<bits/stdc++.h>
using namespace std;
#define s(x) scanf("%d",&x)
string ss;
int P[20][100005];
int stp,cnt,N;
 
struct entry{
int nr[2];
int p;	//index of suffix in original string
} L[100005];
 
bool cmp(entry a,entry b)
{
return (a.nr[0]==b.nr[0]) ? (a.nr[1]<b.nr[1]) : (a.nr[0]<b.nr[0]);
}
 
void build_SA()
{
	for(int i=0; i<N; i++)
		P[0][i]=ss[i]-'a';
	
	for( (stp=1,cnt=1); (cnt>>1 <N); (stp++,cnt<<=1) )
	{
		for(int i=0; i<N; i++)
		{
			L[i].nr[0]= P[stp-1][i];
			L[i].nr[1]= i+cnt<N ? P[stp-1][i+cnt]: -100;
			L[i].p=i; 
		}
		sort(L,L+N,cmp);
		
		for(int i=0; i<N; i++)
			P[stp][L[i].p]=i;
	}
}
 
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
		cin>>ss;
		N=(ss).size();
		build_SA();
		for(int i=0; i<N; i++)
		{
			printf("%d\n",L[i].p);
			//cout<<ss.substr(L[i].p,N-L[i].p)<<endl;
		}
		
}



