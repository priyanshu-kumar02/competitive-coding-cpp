/*
merge-sort with INVERSION count
https://www.spoj.com/problems/INVCNT/
called as merge_sort(0,n-1);
*/

ll inv;
ll arr[1000005];
 
void merge_sort(int ss,int se){
	
	if(ss>=se) return;
	merge_sort(ss,(ss+se)/2);
	merge_sort((ss+se)/2+1,se);
	
	ll aux[se-ss+1],l,r,mid=(ss+se)/2,i,j=0;
	l=ss,r=mid+1;
	
	for(i=ss; i<=se; i++)
	{
		if(l>mid) aux[j++]=arr[r++];
		else if(r>se or arr[l]<arr[r]) aux[j++]=arr[l++];
		else {
		inv+=mid-l+1;
		aux[j++]=arr[r++];	
		}
	}
	for(int i=ss,j=0; i<=se; i++)
	arr[i]=aux[j++];
}
