#include<bits/stdc++.h>   //MAX HEAP
using namespace std;
#define lli long long int

lli heap[100000];
lli last=-1;


void heapifyUp(lli index)
{
	lli parent=(index-1)/2;
	while(parent>=0 && heap[parent]<heap[index])
	{
		swap(heap[index],heap[parent]);		
		index=parent;
		parent=(index-1)/2;
	}
	
}

void heapifyDown(lli i)
{
    lli l = 2*i+1;
    lli r = 2*i+2;
    lli max = i;
    if (l <= last && heap[l] > heap[i])
        max = l;
    if (r <= last && heap[r] > heap[max])
        max = r;
    if (max != i)
    {
        swap(heap[i],heap[max]);
        heapifyDown(max);
    }
}

void insert(lli val)
{
	last++;
	heap[last]=val;
	heapifyUp(last);
		
}


//exchange node to be deleted with last and delete that last,now either we'll have to heapifyUp or heapifyDown
void delNode(lli val)
{
	if(last==-1)
	return;

	lli i=0;
	while(i<=last && heap[i]!=val)
	i++;
	
	if(i==last+1)  //element not found
	return;
	
	heap[i]=heap[last];
	last--;
	
	if(i>0)
	{
	if(heap[(i-1)/2]<heap[i])
	heapifyUp(i);
	}
	
	else 
	heapifyDown(i);
}

int main()
{
	int arr[15]={90,61,3,40,60,62,8,6,7,5,4,80,110,2,20};
	
	for(int i=0;i<15;i++)
	insert(arr[i]);
	
	for(int i=0;i<=last;i++)
	{
	printf("%lld ",heap[i]);
    }
    	delNode(heap[0]);
cout<<endl;
    	for(int i=0;i<=last;i++)
	{
	printf("%lld ",heap[i]);
    }
	
}

