// Problem : http://www.spoj.com/problems/GONE/    
// NOTE: 'tight' tells you if the currently formed prefix matches exactly with 'ss'
// tight=0 means you can put any digit at idx position
// tight=1 means only [0,ss[idx]-'0'] digits can be allowed to stay within range   **/

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vec vector
#define pb push_back
#define s(x) scanf("%d",&x)
#define all(x)	x.begin(),x.end()
#define pii pair<int,int>
#define fi first
#define se second
#define mod 1000000007
#define SZ 200005
#define endl "\n"
#define trace(x) cerr << #x << ": " << x << endl
#define boost ios::sync_with_stdio(0);cin.tie(0)
 
int dp[12][2][100];
int primes[29] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109};
/////////////////////////////////////////////////
 
bool isPrime(int x) {
    for (int i = 0; i < 29; i++)
        if (primes[i] == x)
            return true;
    return false;
}
 
//count of all numbers in [0,ss] which have prime sum of digits
//dp[i][tight][sum]  =>  count of numbers formed by suffix[i..n-1] which add to 'sum'
//NOTE: prime is only checked at last, dp itself only holds count of numbers
 
int digit_dp(string ss) {
    int n = ss.size();
 
    //empty suffixes having sum=0
    dp[n][0][0] = 1;
    dp[n][1][0] = 1;
 
    for(int i = n-1; i >=0 ; i--) {
        for(int tight = 0; tight < 2 ; tight++) {
            for(int sum = 0; sum <100 ; sum++) {
                if(tight) {
                    for(int d = 0; d <= ss[i] - '0' ; d++) {
                        dp[i][1][sum] += (d == ss[i]-'0') ? dp[i+1][1][sum-d] : dp[i+1][0][sum-d];
                    }
                }
                else {
                    for(int d = 0; d < 10 ; d++) {
                        dp[i][0][sum] += dp[i+1][0][sum-d];
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 100; i++) {
        if(isPrime(i))
        ans += dp[0][1][i];
    }
    return ans;
}
 
void reset_dp() {
    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 100; k++) {
                dp[i][j][k] = 0;
            }
        }
    }
}
 
void purple()
{
    int a, b;
    cin >> a >> b;
    int countA = digit_dp(to_string(a - 1));
    reset_dp();
    int countB = digit_dp(to_string(b));
    reset_dp();
    cout << countB - countA << endl;
}
 
signed main() {
    boost;
    int t=1;
    cin>>t;
    while(t--) purple();
} 



















// /**			 RECURSIVE ----- DIGIT DYNAMIC PROGRAMMING 
// 			http://www.spoj.com/problems/GONE/    
// NOTE: 'tight' tells you if the currently formed prefix matches exactly with 'ss'
// tight=0 means you can put any digit at idx position
// tight=1 means only [0,ss[idx]-'0'] digits can be allowed to stay within range   **/

// #include<bits/stdc++.h>
// using namespace std;
// #define lli long long int
// #define vec vector
// #define pb push_back
// #define s(x) scanf("%d",&x)
// #define all(x)	x.begin(),x.end()
// #define pii pair<int,int>
// #define fi first
// #define se second
// #define SZ 100005
// int dp[12][2][100];
// int prms[29] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109};


// string ss;
// int size;

// bool isPrime(int x)
// {
// 	for(int i=0; i<29; i++)
// 	{
// 		if(prms[i]==x) return true;
// 	}return false;	
// }
 
// int digit_dp(int idx,int tight,int sum)
// {
// 	if(dp[idx][tight][sum]!=-1) return dp[idx][tight][sum];
	
// 	if(idx==size) return dp[idx][tight][sum]=isPrime(sum);	
	
	
// 	int ans=0;
// 	if (tight)
// 	{
// 		for(int i=0; i<=ss[idx]-'0'; i++)
// 		ans+=digit_dp(idx+1,i==ss[idx]-'0',sum+i);
// 	}
// 	else
// 	{
// 	   for(int i=0; i<10; i++)
// 	   ans+=digit_dp(idx+1,0,sum+i);  	
// 	}
// 	return dp[idx][tight][sum]=ans;	
// }


// int main()
// {
// 	int t;
// 	cin>>t;
// 	 string a,b;
	 
	 
// 	 while ( t--)
// 	 {
// 		 memset(dp,-1,sizeof(dp));		
// 		 cin>>a>>b;
		 
// 		 ss=a;
// 		 size=ss.size();
// 		 int ans1=digit_dp(0,1,0),tmp=0;
		 
// 		 for(int i=0; i<ss.size(); i++)
// 		 tmp+=ss[i]-'0';
		 		 
// 		 memset(dp,-1,sizeof(dp));	
			  
// 		 ss=b;
// 		 size=ss.size();
// 		 int ans2=digit_dp(0,1,0);
		 
// 		 int ans=ans2-ans1+isPrime(tmp);
// 		 cout<<ans<<endl;		
// 	 }
// }

