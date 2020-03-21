/****************   RABIN-MILLER PRIMALITY TEST  ******************/
/** 
 * Lets take p-1=s*2^d
 * Then for any 'a' in [2,n-1]
 * a^(p-1)=1   (mod p)   by fermet
 * (a^s-1)(a^s+1)(a^2s+1)(a^4s+1)(a^8s+1).....(a^(p-1)+1)=0   (mod p)
 * 
 * Now for p to be prime either one of all above factors shud be 0.
 * REASON: If none of the factors is 0 but still a^p-1=1 (mod p),then p can't be
 *  prime. Though it will pass fermet test!!! .Thats why rabin>fermet.
 * 
 * Conclusion: We just need to check if {a^s%p==1 or -1} OR {a^is==-1 for some i}
 *  			to pass Rabin-Miller. else return false
 * */


#include<bits/stdc++.h>
using namespace std;
#define ulli unsigned long long int
#define vec vector
#define pb push_back
#define s(x) scanf("%d",&x)
#define all(x)	x.begin(),x.end()
#define pii pair<int,int>
#define fi first
#define se second
#define SZ 100005 //1e5

//returns (a*b)%m  when a*b>lli_MAX
ulli MM(ulli a,ulli b,ulli m) {
	if(b==0) return 0;
	ulli tmp=MM((2*a)%m,b/2,m);
	return b&1 ? (a+tmp)%m : tmp;		
}

ulli power(ulli x,ulli y,ulli m)
{
	if(y==0) return 1;
	ulli tmp=power(x,y/2,m);
	ulli tmp2=MM(tmp,tmp,m);
	return y&1 ? MM(x, tmp2, m): tmp2;
}

//p-1= s*2^d
bool miller_rabin(ulli p, int it){
	if(p==2) return true;
	if(p<2 or !p&1) return false;
	
	ulli s = p-1;
	while(!(s&1)) s >>= 1;
	
	while(it--){
		ulli a = rand()%(p-1)+1,tmp = s;
		ulli mod = power(a,tmp,p);
		
		if(mod==1 or mod==p-1) continue;
		
		while(tmp!=p-1 and mod!=p-1){
			mod = MM(mod,mod,p);
			tmp <<= 1;
		}
		
		if(mod!=p-1) return false;
	}
	return true;
}

int main()
{
	ulli n;
	int t;
	scanf("%d",&t);
	
	while (t--){
		scanf("%llu",&n);
		bool Rabin_passed= miller_rabin(n,1);
		printf( Rabin_passed==1 ? "YES\n" : "NO\n" );
	}
}

