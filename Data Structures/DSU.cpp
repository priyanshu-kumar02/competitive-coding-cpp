//UNION-FIND DATA STRUCTURE -- COMPRESSED FIND ROOT O(LOG* N)
void initialise(lli arr[],lli size[],lli n)
{
	for (lli i=0 ; i<n ; i++)
	{
		arr[i]=i;
		size[i]=1;
	}
	
}

lli root(lli arr[],lli i)
{
	while (i!=arr[i])
	{
		arr[i]=arr[arr[i]];
		i=arr[i];
	}
	
return i;

}

lli find(lli arr[0],lli A,lli B)
{
return root(arr,A)==root(arr,B) ? 1 : 0 ;
}

void unite_weighted(lli arr[],lli size[],lli A,lli B)
{
	
	lli root_A=root(arr,A);
	lli root_B=root(arr,B);
	
	if(root_A!=root_B)
	{
		if(size[root_A]<size[root_B])
		{
		   arr[root_A]=root_B;
		   size[root_B]+=size[root_A];
		}

		else
		{
		   arr[root_B]=root_A;
		   size[root_A]+=size[root_B];	
		}
	}
}
