/***********************		TREAP(implicit)-   IIIT:HYDERABAD QUORA BLOG   	***************************
 *PROBLEM: http://www.spoj.com/problems/GSS6	
 *0-base indexing of array  		
 *Replace function is a combination of insert and delete functions																**/

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define vec vector
#define pb push_back
#define s(x) scanf("%d",&x)
#define all(x)	x.begin(),x.end()
#define pii pair<int,int>
#define fi first
#define se second
#define SZ 100005 //1e5
#define boost ios::sync_with_stdio(0)
 
struct node{
	int prior,size;
	int val; //value stored in array
	int maxPre,max,maxSuff,sum;//whatever info you want to maintain in segtree for each node
	struct node *l,*r;
};

typedef node* pnode;
pnode ROOT=NULL;
 
int sz(pnode t){
	return t?t->size:0;
}
 
void upd_sz(pnode t){
	if(t)
	t->size=sz(t->l)+1+sz(t->r);
}
 
void reset(pnode t){
	if(t) 
	t->maxPre= t->max= t->maxSuff= t->sum= t->val; 
}

void combine(pnode t,pnode L,pnode R)//combining two ranges of segtree
{
	if(!L || !R)return void(t = L?L:R)	;
	
	node l=*L,r=*R;  //its necessary to copy contents first (WHY?)
	t->sum     =  l.sum+r.sum;
	t->maxPre  =  max(l.maxPre,l.sum+r.maxPre);
	t->max     =  max( max(l.max,r.max),l.maxSuff+r.maxPre);
	t->maxSuff =  max(r.maxSuff,r.sum+l.maxSuff);
}
 
void operation(pnode t)//operation of segtree
{
	if(!t)return;
	reset(t);
	combine(t,t->l,t);
	combine(t,t,t->r);
}

void split(pnode t,pnode &l,pnode &r,int pos,int add=0)
{
	if(!t)return void(l=r=NULL);
	int curr_pos = add + sz(t->l);
	
	if(curr_pos<=pos)//element at pos goes to left subtree(l)
		split(t->r,t->r,r,pos,curr_pos+1),l=t;
	else 
		split(t->l,l,t->l,pos,add),r=t;
	upd_sz(t);
	operation(t);
}
 
void merge(pnode &t,pnode l,pnode r)  //l->leftarray,r->rightarray,t->resulting array
{ 
	if(!l || !r) t = l?l:r;
	else if(l->prior>r->prior)merge(l->r,l->r,r),t=l;
	else    merge(r->l,l,r->l),t=r;
	upd_sz(t);
	operation(t);
}

pnode init(int val)
{
	pnode ret = (pnode)malloc(sizeof(node));
	ret->prior=rand(),ret->size=1;
	ret->val=  val;
	reset(ret);
	return ret;
}

int range_query(pnode &t,int l,int r)
{
	pnode L,mid,R;
	split(t,L,mid,l-1);
	split(mid,t,R,r-l);//note: r-l!!
	
	int ans = t->max;
   
	merge(mid,L,t);
	merge(t,mid,R);
	return ans;
}
 
void insert(pnode &t,int pos,int val)
{
	pnode tmp=init(val);
	pnode L,R;
	split(t,L,R,pos-1);
	merge(t,L,tmp);
	merge(t,t,R);
}
 
void remove(pnode &t,int pos)
{
	pnode L,mid,R;
	split(t,L,mid,pos-1);
	split(mid,mid,R,0);
	merge(t,L,R);
}

void replace(int pos,int val)
{
	remove(ROOT,pos);
	insert(ROOT,pos,val);	
}


int main()
{
	int n,q,x,y;
	char option;
	boost;cin.tie(0);
	
		ROOT=NULL;
		cin>>n;
		
		for(int i=0; i<n; i++)
		{ cin>>x; insert(ROOT,i,x); }
		
		cin>>q;		
		for(int i=0; i<q; i++)
		{
			cin>>option;
			if(option=='I'){
				cin>>x>>y;
				insert(ROOT,x-1,y);	
			}
			else if(option=='D'){
				cin>>x;
				remove(ROOT,x-1);
			}
			else if(option=='R'){
				cin>>x>>y;
				replace(x-1,y);
			}
			else if(option=='Q'){
				cin>>x>>y;
				printf("%d\n",range_query(ROOT,x-1,y-1));
			}
		}	
}
