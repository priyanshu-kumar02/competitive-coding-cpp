/* 4-direction matrix DFS */


bool vis[55][55];
string grid[55];
 
int di[] = {-1, 0, +1, 0};
int dj[] = {0, +1, 0, -1};
 
bool valid(int i, int j) {
	return i>=1 and i<=n and j>=1 and j<=m;
}
 
void dfs(int i, int j) {
	vis[i][j] = true;
 
	for(int k = 0; k < 4; k++) {
		int ii = i + di[k];
		int jj = j + dj[k];
		if(valid(ii,jj) and !vis[ii][jj] and grid[ii][jj] !='#')
		dfs(ii,jj);
	}
}
 


/* 
8-direction delta
SPOJ- ABCPATH
*/

int di[]={-1,-1,-1,0,+1,+1,+1,0};
int dj[]={-1,0,+1,+1,+1,0,-1,-1};

