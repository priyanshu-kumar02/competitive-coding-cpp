//O(nm) in worst case
//useful when many patterns are to be matched in same txt
//0-based indexing except printing statement
//YOU MAY SKIP CHECKING EXPLICITLY WHEN WINDOW==HASH COZ COLLISION PROBABILITY IS SMALL, AND THUS MAKE IT O(N) //worked for spoj!!!

const lli M=100000000+7;
const lli base=251;

void RABIN_KARP(string text,string pattern)
{
	lli base=1,cnt=0,found=1;
	lli sz=pattern.size(),SZ=text.size();
	vec<int> seen_at;	
	lli window=0,hash=0;
	
	for(lli i=pattern.size()-1; i>=0; i--)
	{
		window=(window+text[i]*base)%M;
		hash=(hash+pattern[i]*base)%M;
		if(i>0)
		base=(base*251)%M;
	}
	
	for(lli i=pattern.size(); i<=SZ; i++)
	{		
		if (window==hash)
		{
			for(int j=0; j<sz; j++)
			{
				found=1;
				if (text[(i-sz)+j]!=pattern[j] )
				{found=0; break;}
			}
			if (found)
			{cnt++; seen_at.pb(i-sz);}
		}
		if(i<SZ)
		window=( (window-text[i-sz]*base)*251+text[i])%M;	
		if (window<0)
		window+=M;	
	}
	if (cnt==0)
	{cout<<"Not Found\n"; return;}	
	
	cout<<cnt<<endl;
	for(unsigned  int i=0; i<seen_at.size(); i++)
	 cout<<seen_at[i]+1<<" ";
	cout<<endl;
}