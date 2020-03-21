Ques:Edit distance is a way of quantifying how dissimilar two strings are, i.e., how many operations (add, delete or replace character) it would take to transform one string to the other. This is one of the most common variants of edit distance, also called Levenshtein distance, named after Soviet computer scientist, Vladimir Levenshtein. More formally, we have two strings, s1 and s2. There are 3 operations which can be applied to either string, namely: insertion, deletion and replacement.

#include<bits/stdc++.h>
#define lli long long int
#define pii pair<lli,lli>
#define mp(x,y) make_pair(x,y)
#define vec vector<lli>
using namespace std;


lli edit_distance(string source,string target,lli s1,lli s2)
{
	lli dp[s1+1][s2+1];
	for (lli j=0 ; j<=s2 ; j++)  //empty src can become trg by adding all its element
	{
		dp[0][j]=j;
	}
	
	for (lli i=0 ; i<=s1 ; i++) //empty trg can be made from src by deleting each src letter
	{
		dp[i][0]=i;
	}
	
	for (lli i=1 ; i<=s1 ; i++)
	{
		for (lli j=1 ; j<=s2 ; j++)
		{
			if(source.at(i-1)==target.at(j-1))
			dp[i][j]=dp[i-1][j-1];
			else
			dp[i][j]=min( dp[i-1][j-1]+1 , min(dp[i-1][j]+1,dp[i][j-1]+1) );
		}
		
	}
	
	for (lli i=0 ; i<8 ; i++)
	{
		for (lli j=0 ; j<7 ; j++)
		{
			cout<<dp[i][j]<<"  ";
		}
		cout<<endl;
	}
	
	return dp[s1][s2];
	


}

int main()
{
	string source,target;
	cin>>source>>target;
	lli s1=source.size(),s2=target.size();
	
	cout<<edit_distance(source,target,s1,s2);
	
	
	

}

