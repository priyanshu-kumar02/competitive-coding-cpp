int jump[20][1005];
vec<int> graph[1005];
 
int  P[1005],L[1005]; //P=parent,L=level
int N;
 
//calculates (parent,level) arrays
void calc(int n) 				 
{
	if(n==1)
	L[n]=0,P[n]=-1;
	
	else
	L[n] = L[P[n]]+1;
	
	for (int i:graph[n])
	{
		if(i!=P[n])
		{
		 P[i]=n;
		 calc(i);
	    }
	}
}
 
void preprocess_LCA()
{
	int i,j;
	
	for(j=0;j<=N;j++)
		jump[0][j]=P[j];
		
	for (i = 1; 1<<i <=N ; i++) 
		for (j = 0; j <=N ; j++)
		jump[i][j]= jump[i-1][jump[i-1][j]];
}
 
int LCA(int p,int q)
{
	int i,diff;
	if(L[p]<L[q])
	swap(p,q);
	
	diff=L[p]-L[q];
	
	for(i=12;i>=0;i--) 
	if( diff&(1<<i)) p=jump[i][p];
		
	if(p==q) return p;
	 
	for(i=12;i>=0;i--)
	 if( jump[i][p]!=jump[i][q] )
	  p=jump[i][p],q=jump[i][q];
	
	return P[p];
}