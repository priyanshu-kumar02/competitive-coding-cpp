//Finds radius of all subtrees rooted at each node in O(nlogn)

vec<int> graph[100001];
vec<int> wt[100001];
int diam[100001],dmax[100001],rad[100001],droot[100001],End[100001],x,w,V,y;
int jump[20][100005];

//dmax[i]=maximum depth from ith node
//droot[i]=distance of i from root
//End[i]=  farthest node from i below i




void dfs(int n,int p)
{
	    diam[n]=dmax[n]=rad[n]=0;
		int dmax2=0;
		End[n]=n;
		
		for (int j=0; j<graph[n].size() ;j++)
		{
			int i=graph[n][j],wgt=wt[n][j];
			if (i!=p)
			{
					droot[i]=droot[n]+wgt;
					dfs(i,n);
			
					diam[n]=max(diam[i],diam[n]);
					rad[n]=max(rad[i],rad[n]);
					
					if (dmax[i]+wgt>=dmax[n])
					{
						dmax2=dmax[n];
						dmax[n]=dmax[i]+wgt;
						End[n]=End[i];
					}
					
					else if (dmax[i]+wgt>dmax2)
					dmax2=dmax[i]+wgt;				
			}
		}
		if(dmax[n]+dmax2>diam[n])
		{
			diam[n]=(dmax[n]+dmax2);
			int x=End[n];
			for (int i = 19; i >=0 ; i--)
			{
				if (dmax2+droot[jump[i][x]]-droot[n]>(dmax[n]+dmax2)>>1)
				{
					x=jump[i][x];
				}
				
			}
			rad[n]=min(droot[End[n]]-droot[jump[0][x]],droot[x]-droot[n]+dmax2);
		}
}	