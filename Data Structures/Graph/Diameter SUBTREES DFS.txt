//Finds diameter of all subtrees(rooted at each node) for whole tree rooted at 'n' in O(n) time

vec<int> graph[100005];
int diam[100005],dmax[100005],x,i,y,k;


void diameter(int &n,int &p)
{
		dmax[n]=diam[n]=0,dmax[n]=0;
		int dmax2=0;
		for (int i :graph[n])
		{
			if (i!=p)
			{
					diameter(i,n);
					
					if (dmax[i]+1>=dmax[n])
					{
						dmax2=dmax[n];
						dmax[n]=dmax[i]+1;
					}
					else if (dmax[i]+1>dmax2)
					{
						dmax2=dmax[i]+1;
					}
					
					if (diam[i]>diam[n])
					diam[n]=diam[i];
			}
		}
		if(dmax[n]+dmax2>diam[n])
		diam[n]=(dmax[n]+dmax2);
}