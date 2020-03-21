Q.Given a sequence of n positive integers we need to count consecutive sub-sequences whose sum is divisible by k.

Constraints : N is up to 10^6 and each element up to 10^9 and K is up to 100



#include<stdio.h>
#include<iostream>
#define lli long long int
using namespace std;

int main()
{
	
	lli n,k;
	
	scanf("%lld %lld",&n,&k);
	lli arr[n];
	lli mod_count[k];
	
	
	
	for(lli i=0;i<k;i++)
	mod_count[i]=0;
	
	
	lli sum=0;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&arr[i]);
		sum=(sum+arr[i])%k;
		mod_count[sum]++;
	}
	
	lli ans=0;
	for(int i=0;i<k;i++)
	{
 	ans=ans+(mod_count[i]*(mod_count[i]-1)/2);
 	}
 	
 	cout<<ans+mod_count[0];
	
	
}