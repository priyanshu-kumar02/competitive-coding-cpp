
//CHECKING BST
//IDEA: Keep track of allowed range for data of current node while traversing tree
#include<bits/stdc++.h>
struct node{
	int data;
	struct node* left;
	struct node* right;
};

int SIZE=0;
struct node* root=(struct node*)malloc(sizeof(struct node));

void build(int arr[],int index,struct node* root)
{
	if(index>=SIZE)
	return;
	
	root->data=arr[index];//data is given to current node,now its left and right pointers are to be decided
	
	if(2*index+1>=SIZE)//if current root pointer is a leaf,if not ->it'll definitely have a left child
	{
	root->left=root->right=NULL;
	return;
	}
	
	
	struct node* temp=(struct node*)malloc(sizeof(struct node));//can use a new node function directly to avoid malloc ,struct node* tmp=newNode();
	root->left=temp;
	build(arr,2*index+1,temp);
	
	if(2*index+2>=SIZE)//check right child exists or not
	{root->right=NULL;return;}
	
	struct node* temp2=(struct node*)malloc(sizeof(struct node));
	root->right=temp2;
	build(arr,2*index+2,root->right);
}

int check_BST(struct node* root,int min,int max)//min max denote allowed range for data of current node
{
	if(!root)
	return 1;
	
	if(root->data<min || root->data>max)
	return 0;
	
	return check_BST(root->left,min,root->data-1) && check_BST(root->right,root->data+1,max);
	
}

int main()
{
	srand(time(NULL));
	
	SIZE=6;
	int arr1[]={6,4,9,2,5,8};
	build(arr1,0,root);
	
	
	printf("%d\n",check_BST(root,INT_MIN,INT_MAX));
	


}
