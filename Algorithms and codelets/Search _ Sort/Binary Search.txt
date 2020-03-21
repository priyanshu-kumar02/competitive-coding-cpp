lli binary_search(lli start,lli end,lli arr[],lli item)
{
	lli mid;
	
	while(start<=end)
	{
		
	mid=(start+end)/2;
	
	if(arr[mid]==item)
	return mid;
	
	
		if(arr[mid]>item)
		end=mid-1;
		else
		start=mid+1;
	}
	
	return -1;

}

