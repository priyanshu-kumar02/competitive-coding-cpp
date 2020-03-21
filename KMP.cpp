//0-based indexing

void computeLPS(string pat,lli lps[])  //lps->longest prefix suffix
{					//lps[i]denotes length of longest prefix of pat[0..i] thats also suffix

lli j=0,i=1;
lps[0]=0;

	while( i<pat.size() )
	{
	 
		 if(pat[i]==pat[j])
		 lps[i]=j+1, j++, i++;
	 
		 else
		 {
			if(j==0)
			lps[i]=0,i++;
			
			else
			j=lps[j-1];
		 }
	 }
	 
}

void kmp(string pat,string text)
{
lli n=text.size();
lli m=pat.size();
lli i=0,j=0;
lli lps[m];
computeLPS(pat,lps);

	while (i<n)
	{
		if (text[i]==pat[j])
		i++,j++;
		
		if(j==m)
		{
		printf("%lld\n",i-j);
		j=lps[j-1];
		}
		
		else if(i<n and pat[j]!=text[i])
		{
			if(j!=0)
			j=lps[j-1];
			else
			i++;
		}
	}
	
}