int euclid_gcd(int A,int B)
{
	if(A==0)
		return B;
	return euclid_gcd(B % A, A);	
}
