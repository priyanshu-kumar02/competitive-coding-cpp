lli euclid_gcd(lli A,lli B)
{
	if(A==0)
	return B;
	
	else
	return euclid_gcd(B%A,A);	
}
