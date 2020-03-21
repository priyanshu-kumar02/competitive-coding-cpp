#include<stdio.h>
#include<time.h>
#include<malloc.h>
#include<math.h>

struct node{
        int data;
        struct node *left;
        struct node *right;
        struct node *parent;
};

struct node *root=NULL;

int height(struct node* temp){
        if(temp==NULL)
                return 0;
        if(height(temp->left)>height(temp->right))
                return height(temp->left)+1;
        return height(temp->right)+1;
}

int depth(struct node *temp){
        int dept=1;
        while(temp->parent!=NULL){
                dept++;
                temp=temp->parent;
        }
        return dept;
}

struct node* lastNode(struct node *temp){
        if(depth(temp)==height(root))
                return NULL;
        if(depth(temp)==height(root)-1){
                if(temp->left!=NULL&&temp->right!=NULL)
                        return NULL;
                if(temp->left==NULL)
                        return temp;
                if(temp->right==NULL)
                        return temp;
        }        
        struct node *last;
        last=lastNode(temp->left);
        if(last!=NULL)
                return last;
        last=lastNode(temp->right);
        if(last!=NULL)
                return last;
        return NULL;
}

void insert(int val){
        if(root==NULL){
                struct node *ptr=(struct node *)malloc(sizeof(struct node));
                ptr->data=val;
                ptr->left==NULL;
                ptr->right=NULL;
                ptr->parent=NULL;
                root=ptr;
                return;
        }
        struct node *last=lastNode(root);
        struct node *temp2=root;
        while(last==NULL){
                if(temp2->left==NULL)
                        last=temp2;
                temp2=temp2->left;
        }
        struct node *ptr=(struct node *)malloc(sizeof(struct node));
        ptr->data=val;
        ptr->left==NULL;
        ptr->right=NULL;
        ptr->parent=NULL;
        if(last->left==NULL){
                last->left=ptr;
                ptr->parent=last;
                last=ptr;
        }
        else if(last->left!=NULL){
                last->right=ptr;
                ptr->parent=last;
                last=ptr;
        }
        if(last->parent!=NULL){
        while(last->data>last->parent->data){
                int d=last->data;
                last->data=last->parent->data;
                last->parent->data=d;
                last=last->parent;
                if(last->left->data>last->data){
                d=last->data;
                last->data=last->left->data;
                last->left->data=d;
                }
                if(last->right!=NULL){
                if(last->right->data>last->data){
                d=last->data;
                last->data=last->right->data;
                last->right->data=d;
                }
                }
                if(last->parent==NULL)
                        break;
        }
        }
        
        return ;
}

void postorder(struct node *temp){
        if(temp==NULL)
                return ;
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ",temp->data);
}
void preorder(struct node *temp){
        if(temp==NULL)
                return ;
        printf("%d ",temp->data);
        preorder(temp->left);
        preorder(temp->right);
}
void inorder(struct node *temp){
        if(temp==NULL)
                return ;
        inorder(temp->left);
        printf("%d ",temp->data);
        inorder(temp->right);
}

void delete(struct node *temp,int val){
        if(temp==NULL){
                return;
        }
        if(val>temp->data)
                return;
        if(val<temp->data){
                delete(temp->left,val);
                delete(temp->right,val);
        }
        int flag=0;
        struct node *last=lastNode(root);
        struct node *temp2=root;
        if(last==NULL){
               while(temp2->right!=NULL){
                        temp2=temp2->right;
               }
               last=temp2;
               flag=1;
        }
        if(last->left!=NULL&&last->right!=NULL){
                last=last->right;
                flag=2;
        }
        if(flag!=1&&last->right==NULL){
                last=last->left;
                flag=3;
        }
        temp->data=last->data;
        if(flag==1||flag==2){
                last->parent->right=NULL;
                free(last);
        }
        if(flag==3){
                last->parent->left=NULL;
                free(last);
        }
        struct node *temp3=temp;
        if(temp->parent!=NULL){
        while(temp->data>temp->parent->data){
                int d=temp->data;
                temp->data=temp->parent->data;
                temp->parent->data=d;
                temp=temp->parent;
                if(temp->left->data>temp->data){
                d=temp->data;
                temp->data=temp->left->data;
                temp->left->data=d;
                }
                if(temp->right!=NULL){
                if(temp->right->data>temp->data){
                d=temp->data;
                temp->data=temp->right->data;
                temp->right->data=d;
                }
                }
                if(temp->parent==NULL)
                        break;
        }
        }
        temp=temp3;
        l1 : if(temp->left!=NULL&&temp->right!=NULL){
                if(temp->data>temp->left->data&&temp->data>temp->right->data){
                        return;
                }
                if(temp->left->data>=temp->right->data){
                        int e=temp->data;
                        temp->data=temp->left->data;
                        temp->left->data=temp->data;
                        temp=temp->left;
                }
                if(temp->right->data>temp->left->data){
                        int e=temp->data;
                        temp->data=temp->right->data;
                        temp->right->data=temp->data;
                        temp=temp->right;
                }
                
                goto  l1;
        }
}

int main(){
        srand(time(NULL));
        int n=4+rand()%4;
        printf("n=%d\n",n);
        int i;
        for(i=0;i<n;i++){
                int x=rand()%50+1;
                printf("%d ",x);
                insert(x);
        }
        
        printf("\n1.traversals\n2.delete a value\n3.insert\n4.exit\n");
        while(1){
                int y;
                scanf("%d",&y);
                if(y==1){
                        preorder(root);
                        printf("\n");
                        inorder(root);
                        printf("\n");
                        postorder(root);
                        printf("\n");
                }
                if(y==2){
                        int r;
                        scanf("%d",&r);
                        delete(root,r);
                }
                if(y==3){
                        int r;
                        scanf("%d",&r);
                        insert(r);
                }
                if(y==4){
                        break;
                }
        }
        return 0;
}
