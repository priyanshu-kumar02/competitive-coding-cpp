//0-based indexing

vector<int> computeLPS(string pat) {					
    vector<int> lps(pat.size(), 0);
    int len = 0;
 
    for(int i = 1; i < pat.size(); i++) {
        while(pat[i] != pat[len] and len != 0) 
            len = lps[len-1];
 
        if(pat[i] == pat[len])
            len++;
        lps[i] = len;
    }
    return lps;
}

void kmp(string pat,string text)
{
	ll n=text.size();
	ll m=pat.size();
	int i=0,j=0;
	vector<int> lps = computeLPS(pat);

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
