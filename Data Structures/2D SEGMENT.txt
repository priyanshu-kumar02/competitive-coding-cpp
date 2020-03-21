//O(logm.logn) per query and update
//x-axis along rows (0,n-1) ; y-axis along columns (0,m-1)
//O(N^2) to build
//taken from http://e-maxx.ru/algo/segment_tree

void build_y(int ix,int iy,int lx,int rx,int ly,int ry)
{
	if (ly==ry)
	{
		if (lx==rx)
	    	t[ix][iy]=matrix[lx][ly];
		else
			t[ix][iy]=t[2*ix+1][iy]+t[2*ix+2][iy];
	}
	
	else 
	{
		int mid=(ly+ry)>>1;
		build_y(ix,2*iy+1,lx,rx,ly,mid);
		build_y(ix,2*iy+2,lx,rx,mid+1,ry);
		t[ix][iy]=t[ix][2*iy+1]+t[ix][2*iy+2];
	}
}

void build_x(int ix,int lx,int rx)
{
	if (lx!=rx)
	{
		int mid=(lx+rx)>>1;
		build_x(2*ix+1,lx,mid);
		build_x(2*ix+2,mid+1,rx);
	}
	build_y(ix,0,lx,rx,0,m-1);
}

lli sum_y(int ix,int iy, int ly,int ry,  int qlx,int qrx,int qly,int qry)
{
	if (ly>=qly and ry<=qry)
	{
		return t[ix][iy];
	}
	
	int mid=(ly+ry)>>1;
	
	if (qry<=mid)
	return sum_y(ix,2*iy+1,ly,mid,qlx,qrx,qly,qry);
	
	else if(qly>=mid+1)
	return sum_y(ix,2*iy+2,mid+1,ry,qlx,qrx,qly,qry);
	
	else
	return  sum_y(ix,2*iy+1,ly,mid,qlx,qrx,qly,qry)
		   +sum_y(ix,2*iy+2,mid+1,ry,qlx,qrx,qly,qry);
	
}



lli sum_x(int ix,int lx,int rx,int qlx,int qrx,int qly,int qry)
{
	if (lx>=qlx and rx<=qrx)
	{
		return sum_y(ix,0,0,m-1,qlx,qrx,qly,qry);
	}
	
	int mid=(lx+rx)>>1;
	
	if (qrx<=mid)
	return sum_x(2*ix+1,lx,mid,qlx,qrx,qly,qry);
	
	else if(qlx>=mid+1)
	return sum_x(2*ix+2,mid+1,rx,qlx,qrx,qly,qry);
	
	else
	return  sum_x(2*ix+1,lx,mid,qlx,qrx,qly,qry)
		   +sum_x(2*ix+2,mid+1,rx,qlx,qrx,qly,qry);
	
}

void update_y (int ix, int lx,int rx, int iy, int ly, int ry, int x, int y, int new_val) {
	if (ly == ry) {
		if (lx == rx)
			t[ix][iy] = new_val;
		else
			t[ix][iy] = t[ix*2+1][iy] + t[ix*2+2][iy];
	}
	else {
		int mid = (ly + ry)>>1;
		if (y <= mid)
			update_y (ix, lx, rx, iy*2+1, ly, mid, x, y, new_val);
		else
			update_y (ix, lx, rx, iy*2+2, mid+1, ry, x, y, new_val);
		t[ix][iy] = t[ix][iy*2+1] + t[ix][iy*2+2];
	}
}
 
void update_x (int ix, int lx, int rx, int x, int y, int new_val) {
	if (lx != rx) {
		int mid = (lx + rx)>>1;
		if (x <= mid)
			update_x (ix*2+1, lx, mid, x, y, new_val);
		else
			update_x (ix*2+2, mid+1, rx, x, y, new_val);
	}
	update_y (ix, lx, rx, 0, 0, m-1, x, y, new_val);
}
