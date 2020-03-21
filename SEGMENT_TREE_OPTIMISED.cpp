void check_lazy(lli i,lli ss,lli se)
	{
	if(lazy[i])
		{
		  tree[i]=1LL<<(lazy[i]);
		  if(ss!=se)  //not leaf
		  {
			  lazy[2*i+1]=lazy[i];
			  lazy[2*i+1+1]=lazy[i];
		  }
		  lazy[i]=0;
		}

	}
	
	//build function may be replaced by update_lazy but it increases time
	void build(lli l , lli r , lli node){
	lazy[node]=0;
    if(l == r){
        tree[node] = (1LL << color[perm[l]] );//depends on question
    }
    else{
        lli mid = (l + r) >> 1;
        build(l , mid , 2*node+1);
        build(mid + 1 , r , 2*node + 1+1);
        tree[node] = tree[2*node+1] | tree[2*node +1+ 1];
    }
}


	void update_lazy(lli i,lli qs,lli qe,lli val,lli ss,lli se) //i-> current working index in segtree
	{
		check_lazy(i,ss,se);
		
		if(qe<ss or qs>se or ss>se) return;
				
		if(ss>=qs and se<=qe)
		{
			tree[i]=1LL<<(val);
			if(ss!=se)
			{
			lazy[2*i+1]=val;
			lazy[2*i+1+1]=val;
			}return;
		}
		
		update_lazy(2*i+1,qs,qe,val,ss,(ss+se)/2);
		update_lazy(2*i+1+1,qs,qe,val,(ss+se)/2+1,se);
		tree[i]=tree[2*i+1] | tree[2*i+1+1];
		
	}

	//again 4 cases
	lli query(lli i,lli qs,lli qe,lli ss,lli se)
	{
		check_lazy(i,ss,se);
		
		if(qe<ss or qs>se or ss>se) return 0;
		
		if(ss>=qs and se<=qe) return tree[i];
		
		return query(2*i+1,qs,qe,ss,(ss+se)/2) | query(2*i+2,qs,qe,(ss+se)/2+1,se);
			
	}
