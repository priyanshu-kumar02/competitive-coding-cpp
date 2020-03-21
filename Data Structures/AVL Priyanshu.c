#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 

struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};
 

int max(int a, int b)
{
    return (a > b)? a : b;
}
 

int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 

struct node* newNode(int key)
{
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  
    return(node);
}
 

struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    return x;
}

struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;
 

    y->left = x;
    x->right = T2;
 
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    return y;
}
 
int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 
struct node* insert(struct node* node, int key)
{

    if (node == NULL)
        return(newNode(key));
 
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
 

    node->height = max(height(node->left), height(node->right)) + 1;
 
    int balance = getBalance(node);
 
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
 
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
 
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 

    return node;
}
 

void preorder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root)
{
if(root==NULL)
return;


        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);

}
 
void inorder(struct node* root)
{
if(root==NULL)
return;


        inorder(root->left);
        inorder(root->right);
        printf("%d ", root->key);

}
 
 void printmenu()
{
printf("1.Create tree.\n2.Print preorder traversal.\n3.Print postorder traversal.\n4.Print inorder traversal.\n5.Exit\n");

}

int main()
{
srand(time(NULL));

 int input=-1,i=1;
 printmenu();
 scanf("%d",&input);
 		struct node* root=NULL;
while(input!=5)
	{


	if(input==1)
	{
		root=NULL;
		//int nodes=7;
		int nodes=10;
		printf("Number of nodes created= %d\n",nodes);
		printf("Value of nodes= ");
		for( i=1;i<=nodes;i++)
		{
		int value=rand()%50+1;
		printf("%d ",value);
		root=insert(root,value);
		}
		
		printf("\n");
	}
	
    if(input==2)
    {
	    printf("Pre-Order traversal: ");
	    preorder(root);
	    printf("\n");
    }
    
     if(input==3)
    {
    printf("Post-Order traversal: ");
    postorder(root);
    printf("\n");
    }
    
     if(input==4)
    {
    printf("In-Order traversal: ");
    inorder(root);
    printf("\n");
    }
    
    if(input==5)
    return 0;
    
     printmenu();
     scanf("%d",&input);
     
	}   //end of while
 
 
    
}


   
