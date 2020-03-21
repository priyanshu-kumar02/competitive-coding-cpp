//SPOJ- ABCPATH

vec< vec<int> > dp(55,vec<int> (55,-1));
char grid[55][55];
int h,w;
int di[]={-1,-1,-1,0,+1,+1,+1,0};
int dj[]={-1,0,+1,+1,+1,0,-1,-1};

int dfs(int i,int j,char next)
{
	if(dp[i][j]!=-1) return dp[i][j];
	
	int this_sol=1;
	for(int it=0; it<8; it++)
	{
		if (i+di[it]>=0 and i+di[it]<h and j+dj[it]>=0 and j+dj[it]<w
		    and grid[i+di[it]][j+dj[it]]==next)
		this_sol=max(this_sol,1+dfs(i+di[it],j+dj[it],next+1));
	}
	dp[i][j]=this_sol;
	return dp[i][j];		
}
