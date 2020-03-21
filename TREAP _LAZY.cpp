/**** TREAP(implicit) with LAZY UPDATE  ***********/
/* 0-based indexing  */ 


#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define vec vector
#define pb push_back
#define s(x) scanf("%lld",&x)
#define all(x)	x.begin(),x.end()
#define pii pair<int,int>
#define fi first
#define se second
#define SZ 100005 //1e5
 
typedef struct node{
	lli prior,size;
	lli val;//value stored in the array
	lli sum;//whatever info you want to maintain in segtree for each node
	lli lazy;//whatever lazy update you want to do
	struct node *l,*r;
}node;
typedef node* pnode;
pnode ROOT=NULL;
 
lli sz(pnode t){
	return t?t->size:0;
}
void upd_sz(pnode t){
	if(t)t->size=sz(t->l)+1+sz(t->r);
}
void lazy(pnode t){
	if(!t || !t->lazy)return;
	t->val+=t->lazy;//operation of lazy
	t->sum+=t->lazy*sz(t);
	if(t->l)t->l->lazy+=t->lazy;//propagate lazy
	if(t->r)t->r->lazy+=t->lazy;
	t->lazy=0;
}
void reset(pnode t){
	if(t)t->sum = t->val;//no need to reset lazy coz when we call this lazy would itself be propagated
}
void combine(pnode& t,pnode L,pnode R){//combining two ranges of segtree
	if(!L || !R)return void(t = L?L:R);
	node l=*L,r=*R;
	t->sum = l.sum + r.sum;
}
void operation(pnode t){//operation of segtree
	if(!t)return;
	reset(t);//reset the value of current node assuming it now represents a single element of the array
	lazy(t->l);lazy(t->r);//imp:propagate lazy before combining t->l,t->r;
	combine(t,t->l,t);
	combine(t,t,t->r);
}
void split(pnode t,pnode &l,pnode &r,lli pos,lli add=0){
	if(!t)return void(l=r=NULL);
	lazy(t);
	lli curr_pos = add + sz(t->l);
	if(curr_pos<=pos)//element at pos goes to left subtree(l)
		split(t->r,t->r,r,pos,curr_pos+1),l=t;
	else 
		split(t->l,l,t->l,pos,add),r=t;
	upd_sz(t);
	operation(t);
}
void merge(pnode &t,pnode l,pnode r){ //l->leftarray,r->rightarray,t->resulting array
	lazy(l);lazy(r);
	if(!l || !r) t = l?l:r;
	else if(l->prior>r->prior)merge(l->r,l->r,r),t=l;
	else    merge(r->l,l,r->l),t=r;
	upd_sz(t);
	operation(t);
}
pnode init(lli val){
	pnode ret = (pnode)malloc(sizeof(node));
	ret->prior=rand();ret->size=1;
	ret->val=val;
	ret->sum=val;ret->lazy=0;
	return ret;
}
lli range_query(pnode &t,lli l,lli r){//[l,r]
	pnode L,mid,R;
	split(t,L,mid,l-1);
	split(mid,t,R,r-l);//note: r-l!!
	lli ans = t->sum;
	merge(mid,L,t);
	merge(t,mid,R);
	return ans;
}
void range_update(pnode &t,lli l,lli r,lli val){//[l,r]
	pnode L,mid,R;
	split(t,L,mid,l-1);
	split(mid,t,R,r-l);//note: r-l!!
	t->lazy+=val; //lazy_update
	merge(mid,L,t);
	merge(t,mid,R);
}
 
void insert(pnode& t,lli val,lli pos){
	pnode tmp=init(val);
	pnode L,R;
	split(t,L,R,pos-1);
	merge(t,L,tmp);
	merge(t,t,R);
}
 
 
int main()
{
	lli t,n,c,option,p,q,v;
	s(t);
	
	while (t--)
	{	
		ROOT=NULL;
		s(n);s(c);
		
		for(lli i=0; i<n; i++){
			insert(ROOT,0LL,i);
		}
		
		for(lli i=0; i<c; i++)
		{
			s(option);
			if(option==0)
			{
				s(p);s(q);s(v);
				p--;q--;
				range_update(ROOT,p,q,v);	
			}
			else
			{
				s(p);s(q);
				p--;q--;
				printf("%lld\n",range_query(ROOT,p,q));
			}
		}		
	}
}
