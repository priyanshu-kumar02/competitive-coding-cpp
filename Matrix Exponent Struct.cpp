#include<bits/stdc++.h>
using namespace std;
#define lli long long int

const int sz=2;
const int mod=1e9+7;

struct matrix{
	int M[sz][sz];
	matrix() { memset(M,0,sizeof(M)); }
	
	matrix operator * (matrix B)
	{
		matrix C;
		for(int i=0; i<sz; i++)
		for(int j=0; j<sz; j++)
		for(int k=0; k<sz; k++)
		 C.M[i][j]=(C.M[i][j]+M[i][k]*B.M[k][j]);
		return C;		
	}
};

matrix power(matrix Base,lli exp){
	if (exp==1) return Base;
	matrix tmp=power(Base,exp/2);
	return exp&1? tmp*tmp*Base: tmp*tmp;	
}


int main()
{
		matrix a;
		a.M[0][0]=a.M[0][1]=a.M[1][0]=1;
		a.M[1][1]=0;
		matrix f=power(a,4);		
		cout<<f.M[1][0]+f.M[1][1];
}
