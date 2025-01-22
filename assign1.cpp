#include<iostream>
using namespace std;
class tree{
    public:
    int data;
    tree *left;
    tree *right;

    tree(){
        data=0;
        left=NULL;
        right=NULL;
    }

    tree(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
tree *insert(tree * node , int data){
    if(node==NULL){
        return new tree(data);
    }
    if(node->data==data){
        return node;
    }
    if(node->data > data){
        node->left=insert(node->left , data);
    }
    else{
        node->right=insert(node->right , data);
    }
}
void inorder(tree * root ){

    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

}
void preorder(tree *root){
    if(root!=NULL){
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    }
}
void postorder(tree *root){
    if(root!=NULL){
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    }
}
tree *search(tree *root , int key){
    if(root==NULL || root->data==key){
        return root;
    
    }
    else if(root->data > key){
       return search(root->left , key);
    }
    else{
        return search(root->right , key);
     
    }
}
int main(){
    
   tree *root = new tree(100);
   // root=insert(root , 100);
    root=insert(root , 50);
    root=insert(root , 150);
    root=insert(root , 70);
    root=insert(root , 20);
    root=insert(root , 120);
    root=insert(root , 180);

    cout<<"displaying tree in inorder traversal:"<<"  ";
    inorder(root);
    cout<<endl;
    cout<<"displaying tree in preorder traversal:"<<"  ";
    preorder(root);
    cout<<endl;
    cout<<"displaying tree in postorder traversal:"<<"  ";
    postorder(root);
    cout<<endl;
  tree *tofound =  search(root , 100);
  if(tofound!=NULL){
    cout<<"the node is found"<<endl;
  }
  else{
    cout<<"the node is not found"<<endl;
  }
  
    return 0;

}
