// FOR ASCENDING ORDER
// CALLED AS merge_sort(arr,0,size-1)  //EXACT RANGE TO BE GIVEN

void merge_sorted_parts(lli arr[],lli start,lli mid,lli end)
{
	lli p=start , q=mid+1;   			 //p,q represent indices of those 2 sorted arrays
	lli Aux[end-start+1],j=0;
	
	for(lli i=start;i<=end;i++)
	{
		if(p>mid)
		Aux[j++]=arr[q++];
		
	    else if(q>end)
		Aux[j++]=arr[p++];
		
		else if(arr[p]>arr[q])
		Aux[j++]=arr[q++];
		
		else
		Aux[j++]=arr[p++];
		
	}
	
	j=0;
	for(lli i=start;i<=end;i++)
	arr[i]=Aux[j++];
	
}

void merge_sort(lli arr[],lli start,lli end)
{
	if(start<end)
	{
		lli mid=(start+end)/2;
		merge_sort(arr,start,mid);
		merge_sort(arr,mid+1,end);
		
		merge_sorted_parts(arr,start,mid,end);
	}
}


