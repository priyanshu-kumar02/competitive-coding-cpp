// FFT-O(nlogn) to multiply 2 polynomials
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define vec vector
#define pb push_back
#define s(x) scanf("%lld",&x)
#define all(x)	x.begin(),x.end()
#define pii pair<int,int>
#define fi first
#define se second
#define SZ 100005 //1e5

const double PI = 4*atan(1);
typedef complex<double> base;
vector<base> omega;
lli FFT_N,mod=100003;

void init_fft(lli n)
{
  FFT_N  = n;
  omega.resize(n);
  double angle = 2 * PI / n;
  for(lli i = 0; i < n; i++)
    omega[i] = base( cos(i * angle), sin(i * angle));
}

void fft (vector<base> & a)
{
  lli n = (lli) a.size();
  if (n == 1)  return;
  lli half = n >> 1;
  vector<base> even (half),  odd (half);
  for (lli i=0, j=0; i<n; i+=2, ++j)
    {
      even[j] = a[i];
      odd[j] = a[i+1];
    }
  fft (even), fft (odd);
  for (lli i=0, fact = FFT_N/n; i < half; ++i)
    {
      base twiddle =  odd[i] * omega[i * fact] ;
      a[i] =  even[i] + twiddle;
      a[i+half] = even[i] - twiddle;
    }
}
void multiply (const vector<lli> & a, const vector<lli> & b, vector<lli> & res)
{
  vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
  lli n = 1;
  while (n < 2*max (a.size(), b.size()))  n <<= 1;
  fa.resize (n),  fb.resize (n);

  init_fft(n);
  fft (fa),  fft (fb);
  for (size_t i=0; i<n; ++i)
    fa[i] = conj( fa[i] * fb[i]);
  fft (fa);
  res.resize (n);
  for (size_t i=0; i<n; ++i)
    {
      res[i] = (lli) (fa[i].real() / n + 0.5);
      res[i]%=mod;
    }
}

 
vec<lli> form_subset_polynomial(vec<lli> &A_i )
{
	vec<vec<lli>> calc[20];
	vec<lli> tmp;
	
	for(auto x:A_i){
		tmp.clear();
		tmp.pb(1),tmp.pb(x);
		calc[0].pb(tmp);
	}
	
  int p=0,l=A_i.size();  
  vec<lli> res;
  
  while(l>1)
    {
      p++;
      for(lli i=0;i<l/2;i++)
        {
          calc[p].pb(res);
          multiply(calc[p-1][2*i],calc[p-1][2*i+1],calc[p][i]);
        }
      if(l%2)
        calc[p].pb(calc[p-1][l-1]);
      l=calc[p].size();
    }
    return calc[p][0];	//returns final polynomial with coeff of x^n at calc[p][0][0] and so on..
}

int  main()
{	
	/*
	vector<lli> a,b,res;
	a.PB(1);a.PB(3);a.PB(1);
	b.PB(2);b.PB(1);b.PB(5);
	multiply(a,b,res);
	for(int i=0; i<res.size(); i++)
	{
		cout<<res[i]<<" ";
	}
	// RUN ABOVE CODE TO SEE HOW IT WORKS
	*/
	
	lli n,k,x;
	cin>>n;
	vec<lli> value_vector;
	for(lli i=0; i<n; i++)
	{
		s(x);
		value_vector.pb(x);
	}
	vec<lli> RESULT=form_subset_polynomial(value_vector);
	
	int q;
	cin>>q;
	
	while (q--)
	{
		cin>>k;
		cout<<RESULT[k]<<endl;
	}
}
