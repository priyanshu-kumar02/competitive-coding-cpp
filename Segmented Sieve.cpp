//problem- SPOJ-PRIME1
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define vec vector
#define pb push_back
#define s(x) scanf("%d",&x)
#define pii pair<int,int>

vec<bool> isPrime(32010,true);              //IF RANGE OF SEGMENT IS [l,r], THIS 32010 IS ROOT(r)

void make_sieve()
{
	for (int i = 4; i <=32000 ; i+=2)
		isPrime[i]=false;
	
	
	isPrime[1]=false;
	
	for (int i = 3; i*i <=32000 ; i++)
	{
		if (isPrime[i])
		{
			for (int j =i*i; j <=32000 ; j=j+i)
			isPrime[j]=false;
		}
	}	
}

void solve_segment(int m,int n)
{
		map<int,int> mp;
		 mp[1]=1;
		
		int root=sqrt(n)+10;
		for (int i = 2; i <= root; i++)
		{
			if(isPrime[i])
			{
				int tmp=m/i;
				int crawl=i*tmp;										//makes crawl reach begining of segment
				
				while (crawl<=n)
				{
					if(crawl!=i)
					mp[crawl]=1;
					crawl+=i;
				}
			}	
		}
		for (int i = m; i <=n ; i++)
		{
			if(mp[i]==0)												//if still uninitialised
			printf("%d\n",i);
		}
		cout<<endl;
}



int main()
{
	make_sieve();
	
	int t,n,m;
	s(t);
	
	while (t--)
	{
		s(m);s(n);
		solve_segment(m,n);
	}
	
}
