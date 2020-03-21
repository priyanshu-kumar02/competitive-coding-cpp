lli partition(lli arr[],lli start,lli end)
{
	lli j=start+1;
	lli pivot=arr[start];
	
	for(lli i=start+1;i<=end;i++)
	{
		if(arr[i]<pivot)
		swap(arr[i],arr[j++]);
	}
	swap(arr[start],arr[j-1]);
	return j-1;
}

void quicksort(lli arr[],lli start,lli end)
{
	if(start<end)
	{
		int piv_pos=partition(arr,start,end);
		quicksort(arr,start,piv_pos-1);
		quicksort(arr,piv_pos+1,end);
	}
}