	#include<bits/stdc++.h>
	using namespace std;
	#define lli int
	#define vec vector
	#define pb push_back
	#define s(x) scanf("%d",&x)
	#define pii pair<int,int>
 
	lli M[20][100005];
	lli arr[100005];
	lli Log[100005],P[20];
	lli q,n,L,R,lg,ans,i,j;
 
	void log_table(){
		Log[1]=0;
		for (int i = 2;i <= n;++i)
        Log[i] = Log[i/2] + 1;
	}
 
	void make_dp_matrix(){

		for(i=0;i<n;i++)
		M[0][i]=arr[i];
 
		for(i=1;i<=18;i++)
		for(j=0;j+P[i]<=n;j++)
		 M[i][j]= min( M[i-1][j] , M[i-1][j+P[i-1]] );
	}
 
	int main()
	{
		//freopen("input.txt","r",stdin);
		s(n);
		log_table();
		
		for(lli po2=0;po2<=20;po2++)
		P[po2]=1<<po2;
		
		for (lli i = 0; i < n; i++)
		s(arr[i]);
		
		make_dp_matrix();
		s(q);
				
		while (q--){
			scanf("%d %d",&L,&R);
			lg=Log[R-L+1];
			ans= min( M[lg][L], M[lg][R-P[lg]+1] );
			printf("%d\n",ans);
		}
		
	}
