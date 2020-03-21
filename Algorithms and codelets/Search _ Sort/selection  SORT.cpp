void selection_Sort(lli arr[],lli n)
{
	
  lli i,j,min;
  
  for(i=0;i<n;i++)
  {
   min=i;  //index of min element
  	
  	for(j=i+1;j<n;j++)
  	{
  		if(arr[j]<arr[min])
  		min=j;
	}
	
	swap(arr[min],arr[i]);
  }
  	
}
