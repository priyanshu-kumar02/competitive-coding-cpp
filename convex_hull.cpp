//CONVEX-HULL FOR FINDING MAXIMUM Y FOR PARTCULAR X,CHANGE BINARY SEARCH TO GET MINIMUM Y

struct line{
lli m,c, y(lli x) {return m*x+c;}
};

struct convex_hull{

	lli sz;
	line* hull;

	convex_hull(lli max_sz){ hull=new line[max_sz] , sz=0;}
	
	bool irrelevant(line p,line t,line n)						//previous,this,next
	{
	return (t.c-t.c)*(t.m-p.m) <= (p.c-t.c)*(n.m-t.m);
	}
	
	void add(line l)
	{
	hull[sz++]=l;
	
		while (sz>2 and irrelevant(hull[sz-3] ,hull[sz-2], hull[sz-1]) )
		hull[sz-2]=hull[sz-1],sz--;	
	}


		lli query(lli x)
		{
		lli l=-1,r=sz-1,m;
		
			while (r-l>1)
			{
				m=(l+r)/2;
				if( hull[m].y(x) <= hull[m+1].y(x) )
				l=m;
				else
				r=m;
			}
		//cout<<hull[r].m<<","<<hull[r].c<<endl;	
		return hull[r].y(x);	
		}

};
