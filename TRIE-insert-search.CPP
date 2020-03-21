// TRIE-FOR NUMBERS ONLY

struct node{
	struct node* ptr[10];    //pointers to next level
	bool isLeaf;
};node* root;

node* newNode()
{ 
	node* New=(node*)malloc(sizeof(node));
	for(int i=0; i<10; i++)
    	New->ptr[i]=NULL;
	
	New->isLeaf=false;
	return New;
}

void insert(string ss)
{
	node* crawl=root;
	int sz=ss.size(),idx;
	
	for(int i=0; i<sz; i++)
	{
		idx=ss[i]-'0';
    	if (!crawl->ptr[idx])
        crawl->ptr[idx]=newNode();
		crawl=crawl->ptr[idx];	
	}	
	crawl->isLeaf=true;
}

bool search(string ss)
{
    int sz = ss.size(),idx;
    node* crawl = root;
 
    for (int i = 0; i < sz; i++)
    {
        idx = ss[i]-'0';
        if (!crawl->ptr[idx])
        return false;
        crawl = crawl->ptr[idx];
    }
    return (crawl!= NULL && crawl->isLeaf);
}
