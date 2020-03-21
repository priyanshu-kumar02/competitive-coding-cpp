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