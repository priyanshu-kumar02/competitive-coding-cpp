int main()
{
	//freopen("input.txt","r",stdin);
	int n,k;
	s(n);
	int arr[n];
	
	for(int i=0; i<n; i++)
	{
		s(arr[i]);
	}
	s(k);
	
	deque<int> dq;
	
	for(int i=0; i<k; i++)
	{
		while ( !dq.empty() and arr[dq.back()]<=arr[i])
		{
			dq.pop_back();
		}
		dq.push_back(i);
	}

	printf("%d ",arr[dq.front()]);
	
	for(int i=k; i<n; i++)
	{
	     while ( !dq.empty() and arr[dq.back()]<=arr[i])
	     dq.pop_back();
		
		if ( !dq.empty() and dq.front()<=i-k)
		dq.pop_front();
		
		
		dq.push_back(i);
		printf("%d ",arr[dq.front()]);
	}
	
 
 
 
}