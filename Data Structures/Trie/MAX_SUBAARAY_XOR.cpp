// INSERTS XOR_TILL_i and SimultaneouslY finds maximum subarray xor till i
// return pair of form {maximum_subarray_xor,starting_idx_of_that_max_subarray}
// make sure to insert(0,0) before all operations

pii insert(int ss,int index)
{
	node* crawl=root;node* crawl2=root;
	int idx,result=0;
	
	for(int i=0; i<=30; i++)
	{
		idx= 1<<(30-i) & ss ? 1 : 0 ;
		
    	if (!crawl->ptr[idx])
        crawl->ptr[idx]=newNode();       
        
        if (idx==0)
		{
			if(crawl2->ptr[1]!=NULL)
			{crawl2=crawl2->ptr[1]; result=result|(1<<(30-i));}
			else
			crawl2=crawl2->ptr[0];
		}
		else
		{
			if (crawl2->ptr[0]!=NULL)
			{crawl2=crawl2->ptr[0]; result=result|(1<<(30-i));}
			else
			crawl2=crawl2->ptr[1];			
		}
		crawl=crawl->ptr[idx];	
	}	
	crawl->isLeaf=index;
	
	return {result,crawl2->isLeaf+1};
}
