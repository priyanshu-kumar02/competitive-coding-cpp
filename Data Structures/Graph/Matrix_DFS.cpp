//For problem:   http://codeforces.com/contest/598/problem/D

void dfs(int x,int y,vector<cordinates> &p,long int &cnt)
{
	visited[x][y]=true;
	cordinates tmp; tmp.x=x; tmp.y=y;
	p.push_back(tmp);
	
	if(a[x-1][y]=='*')
	cnt++;
	
	else if(!visited[x-1][y])
	dfs(x-1,y,p,cnt);
	
	if(a[x+1][y]=='*')
	cnt++;
	
	else if(!visited[x+1][y])
	dfs(x+1,y,p,cnt);
	
	if(a[x][y-1]=='*')
	cnt++;
	
	else if(!visited[x][y-1])
	dfs(x,y-1,p,cnt);
	
	if(a[x][y+1]=='*')
	cnt++;
	
	else if(!visited[x][y+1])
	dfs(x,y+1,p,cnt);

}

//later for all stored cordinates we will update their cost=count in main()
