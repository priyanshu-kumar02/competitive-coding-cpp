#include<bits/stdc++.h>  //refer geeksforgeeks.org,bst deletion

struct node{
	int val;
	struct node* left;
	struct node* right;
	
};

struct node* newNode(int val)
{
	struct node* ptr=(struct node*)malloc(sizeof(struct node));
	ptr->val=val;
	ptr->left=NULL;
	ptr->right=NULL;
	return ptr;
	
}

void inorder(struct node* root)
{
	if(root==NULL)
	return;
	
	inorder(root->left);
	printf("%d ",root->val);
	
	inorder(root->right);
}
struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root  //will return NULL if key not found so handle NULL properly while searching
    if (root == NULL || root->val == key)
       return root;
    
    // Key is greater than root's key
    if (key>root->val)
       return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}

//note that insertion would always take place as a child of some leaf
struct node* insert(struct node* node,int val)//makes a node and returns its pointer
{
	if(node==NULL)
	return newNode(val);
	
	if(val>=node->val)
	node->right=insert(node->right,val);
	
	else
	node->left=insert(node->left,val);
	
	return node; //returns the unchanged node
	
}


struct node* inorderSuccessor(struct node* root) //inorder predecessor can also be used for deletion. WHY???
{
	if(root->left==NULL)
	return root;

	return inorderSuccessor(root->left);
	
}
  /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
       // 3 CASES IN DELETION
struct node* delNode(struct node* node,int key)  //this function deletes the key in subtree having 'node' as root and returns the root of new subtree formed
{
	if(node==NULL)//this will happen wen key is not found and node reaches NULL,so we return NULL only
	return node;
	
	if(key>node->val)
	node->right=delNode(node->right,key);
	
	else if( key<node->val)
	node->left=delNode(node->left,key);
	
	else  //case of equality //will have 3 cases
	{
		if(node->left==NULL) //case wen only right exist or both are NULL
			{
			struct node *temp =node->right;    
            free(node);  //this doesn't give error coz node is actually not linked right now from its parent,coz we somewhere called 'node->right=delNode(...)'
            return temp;
			}	
		
		else if(node->right==NULL)
		{
				struct node *temp = node->left;
            free(node);
            return temp;
		}
		
		//case wen both child exist
		struct node* tmp2=inorderSuccessor(node->right);
		node->val=tmp2->val;
		
		node->right=delNode(node->right,tmp2->val);
		
	}
	
	return node;  //return this node after any of above modification
	
}

int main()
{
	int arr[]={50,30,70,20,40,60,80};
	struct node* root=NULL;
	
	for(int i=0;i<7;i++)
	root=insert(root,arr[i]);
	
	
	delNode(root,41);
	
	inorder(root);
	
	search(root,61)?printf("\n%d",search(root,61)->val):printf("NULL");

	
}
