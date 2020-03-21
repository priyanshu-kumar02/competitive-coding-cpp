#include<iostream>
#include<vector>
#define lli long long int
using namespace std;

lli n; //size of tree and actual array
lli tree[100];

void update(lli x,lli val)
{
    for(; x<=n ; x+=x&(-x))
     tree[x]+=val;
}

lli query(lli R)
{
    lli sum=0;

    for( ; R>0 ; R-=R&(-R))
    sum+=tree[R];

    return sum;
}

int main()
{

 lli arr[]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
 n=17;
 	//tree.resize(20);
 	for(lli i=1;i<=16;i++)
 	{
     	 update(i,arr[i]);
 	}

cout<<query(7)-query(2-1);
}

/*
Note: To update value at i'th index from v1 to v2
	{
	update(i,-v1);
	update(i,v2);
	}
*/