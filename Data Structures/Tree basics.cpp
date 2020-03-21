#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//FORMING A COMPLETE BINARY TREE USING GIVEN DATA
struct node{
	int data;
	struct node* left;
	struct node* right;
};

int SIZE=rand()%40+10,nodes=0;
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

void inorder(struct node* root)
{
if(root==NULL)
return;
nodes++; //counts nodes
printf("%d ",root->data);
inorder(root->left);
inorder(root->right);	
}

int height_find(struct node* root,int height)
{
	
	if(root==NULL)
	return height;
	height_find(root->left,height+1);
}

int main()
{
	srand(time(NULL));
	SIZE=rand()%10+10;
	
	int arr[SIZE];
	
	for(int i=0;i<SIZE;i++)
	{
		
		arr[i]=rand()%40+10;
		printf("%d ",arr[i]);
	}
	printf("\n");
	
	
	build(arr,0,root);
	inorder(root);
	printf("\nNode=%d\n",nodes);
	printf("\nHeight=%d\n",height_find(root,0));

}
