//FACTORIAL and INVERSE FACTORIAL and nCr(i, j) <==> SZ<=1e5

ll f[SZ],c[SZ];
const ll mod = 998244353;

ll pow(ll x, ll y,ll m) {
    if( y == 0) return 1;
    ll half = pow(x, y/2, m);
    ll full = (half * half) % m;
    return y%2 ? (x * full) % m : full;
}

void initialise_facts() {
    f[0]=c[0]=1;	
    for (ll i = 1;i < SZ;++i) {
        f[i] = (f[i-1] * i) % mod;
        c[i] = pow(f[i], mod-2, mod);
    } 
}

ll nCr(ll n, ll k)  {
    ll ans = (1LL * f[n] * c[k]) % mod;
    return (1LL * ans * c[n - k]) % mod;
}


// FOR nCr where n<=1000
//see: Lucas therem, pdf in earth
// based on   nCr= (n-1)C(r-1)  +  (n-1)C(r)
//all elements of global array are preinitialised to zero



lli nCr[5009][5009];
void solvenCr()
{
	for(lli i= 1;i<=5000;i++)
	{
		nCr[i][1]=i;
	}
	for(lli i=2;i<=5000;i++)
	{
		for(lli j= 2;j<= i;j++)
		{
			nCr[i][j]=(nCr[i-1][j-1]+nCr[i-1][j]);
			
		}
	}
}


//nCr function with least overflow possible O(r)

lli nCr(lli n,lli r)
{
	
	if(r>n/2)
	r=n-r;
	lli ans=1;
	
	for (lli i = 1; i <=r ; i++)
	{
		ans=ans*(n-i+1)/i;   //ANS STAYS ALWAYS INTEGRAL
	}
	return ans;
}


