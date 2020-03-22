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

//seen return all indexes where pat starts (0-bases)
vector<int> kmp(string text, string pat)
{
    vector<int> seen_at;
    int len = 0;
    vector<int> lps = computeLPS(pat);

    for (int i = 0; i < text.size(); i++) {
        while (text[i] != pat[len] and len != 0)
            len = lps[len - 1];

        if (text[i] == pat[len])
            len++;

        if (len == pat.size()){
            seen_at.push_back(i - len + 1);
            len = lps[len - 1];
        }
    }
    return seen_at;
}
