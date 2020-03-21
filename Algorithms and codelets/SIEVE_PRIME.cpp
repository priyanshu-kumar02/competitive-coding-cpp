// SEIVE CHECKING IF i is prime or not
vec<lli> isPrime(100009,1);	
void sieve(lli n,vec<lli> &isPrime){	
	isPrime[0]=isPrime[1]=0;	
	
	for(lli i=2;i*i<=n;i++){
		if(isPrime[i])
		   for(lli j=i*i;j<=n;j+=i)
		   isPrime[j]=0;
	}
}

///////SIEVE WITH SP[i]=minimum prime that divides i

vector<lli> sp(100009,0);
lli MAX=100009;

void Sieve()
{
	for (int i = 2; i < MAX; i += 2)	sp[i] = 2; //even numbers have smallest prime factor 2
	for (lli i = 3; i < MAX; i += 2)
	{
	     if (!sp[i])
	     {
	      sp[i] = i;			//if sp is zero then its a prime itself so mark sp of all its multples as i
			
	      for (lli j = i; (j*i) < MAX; j += 2) //multiples are marked from i*i,i*(i+2),i*(i+4).. so that all odd multiples of i are marked
	      if (!sp[j*i]) sp[j*i] = i;
			
	     }
	}
}


//this method can be used to check primes as 'if(sp[i]==i)->i is prime'
//for factorising use
		lli freq[100005]; //stores power of each prime in prime factorisation of x
		while(x>1)
		{
		 int min_p=sp[x];
		 
			 while(x%min_p==0 and x>1)
			 {
			  x=x/min_p;
			  freq[min_p]++;
			 }
		}
