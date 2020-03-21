// Finds maximum subarray sum and number of subaarays having that sum,O(n)		

		s(arr[0]);
		sub[0]=arr[0];
		cnt[0]=1;
		lli maxx=arr[0];
		
		for (lli i = 1; i < n; i++)
		{
			s(arr[i]);
			if(sub[i-1]==0)
			sub[i]=arr[i],cnt[i]=cnt[i-1]+1;
			
			else if(arr[i]>sub[i-1]+arr[i])
			sub[i]=	arr[i],cnt[i]=1;
			
			else if(arr[i]<sub[i-1]+arr[i])
			sub[i]=sub[i-1]+arr[i],cnt[i]=cnt[i-1];
			
			maxx=max(maxx,sub[i]);
		}
		lli ans=0;
		for (int i = 0; i < n; i++)
		{
			if(sub[i]==maxx)
			ans+=cnt[i];
		}
		
		printf("%lld %lld\n",maxx,ans);