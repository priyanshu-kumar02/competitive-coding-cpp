// MATRIX CHAIN MULTIPLICATION ALGORITHM (dP) O(n^3)
//http://www.spoj.com/problems/MIXTURES/

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
 
int main()
{
	//freopen("input.txt","r",stdin);
	int n;
	
	while (s(n)!=EOF)
	{
		int arr[n+1];
		int sum[n+1];
		sum[0]=0;
		
		for(int i=1; i<=n; i++)
		{
			s(arr[i]);
			sum[i]=sum[i-1]+arr[i];
		}
		int dp[n+1][n+1];
		for(int i=1; i<=n; i++)
		{
			dp[i][i]=0;
			for(int j=1; j<=n; j++)
			{
				if(i!=j)
				dp[i][j]=1000000000;
			}
		}
		
		for(int l=2; l<=n; l++)
		{
			for(int i=1; i<=n-l+1; i++)
			{
				int j=i+l-1;
				for(int spt=i; spt<=j-1; spt++)
				 dp[i][j]=min(dp[i][j], dp[i][spt]+dp[spt+1][j]+((sum[spt]-sum[i-1])%100)*((sum[j]-sum[spt])%100)  );				
			}
		}
		printf("%d\n",dp[1][n]);		
	}
	
 
 
 
}
