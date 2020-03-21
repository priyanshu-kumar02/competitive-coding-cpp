lli binarySearch(lli A[],lli start,lli end,lli item)
{
lli mid;

	while(end-start>1)
	{
		mid=(start+end)/2;
		
		if(A[mid]<=item)
		start=mid;
		else
		end=mid;
	}
	
	//now our answer belongs to {arr[start],arr[end]} or does not exist
	
	if(A[end]==item)
	return end;
	else if(A[start]==item)
	return start;
	else 
	return -1;

	
}

