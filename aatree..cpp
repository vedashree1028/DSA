/*
AA-TREE CODE
PRN:
123B1B184
123B1B185
123B1B186
123B1B187
123B1B188

*/
#include<iostream>
using namespace std;
class AAtree{
    
    public:
    int data;
    int level;
    AAtree *left , *right;

    AAtree(int d){
        data=d;
        level=1;
        left=right=NULL;
    }

};
// skew:for left-child violation (right rotation)
AAtree* skew(AAtree *root){
    if(!root || !root->left){
        return root;
    }
    if(root->left->level == root->level){
        AAtree *l = root->left;
        root->left = l->right;
        l->right = root;
        return l;
    }
    return root;
}

//split:for right child violation (left rotation)
AAtree *split(AAtree *root){
    if(!root || !root->right || !root->right->right){
        return root;
    }

    if(root->level == root->right->right->level){
        AAtree *r = root->right;
        root->right = r->left;
        r->left = root ;
        r->level += 1;
        return r;
    }
    return root;
}

//Insert value in AA Tree

AAtree *insert(AAtree *root , int key){
    if(root == NULL){
        return new AAtree(key);
    }
    if(key < root->data){
        root->left = insert(root->left , key);
    }
    else if(key > root->data){
        root->right = insert(root->right , key);
    }

    //fix violation

    root=skew(root);
    root=split(root);

    return root;
}
void printInorder(AAtree *root , int depth=0){
    if(root==NULL){
        return;
    }

    printInorder(root->left , depth + 1);
    cout<<root->data <<" (l"<< root->level <<")"<<endl;
    printInorder(root->right , depth + 1);
}
int main(){
    AAtree * root=NULL;
     root=insert(root,10);
     root=insert(root,20);
     root=insert(root,5);
     root=insert(root,15);
     root=insert(root,25);
     root=insert(root,30);

     cout<<"Inorder traversal with levels:\n";
     printInorder(root);

     return 0;
}
/*
OUTPUT:
                 10 
                /  \
               5    25
                   /  \
                  20   30
                  /
                 15
*/
