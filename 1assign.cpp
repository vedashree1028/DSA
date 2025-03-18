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
tree *Delete(tree *root , int key){
    if (root == nullptr)
        return root;

    // If the data to be deleted is smaller than the root's data, go left
    if (key < root->data) {
        root->left = Delete(root->left, key);
    }
    // If the data to be deleted is greater than the root's data, go right
    else if (key > root->data) {
        root->right = Delete(root->right, key);
    }
    // If data matches, this is the node to be deleted
    else {
        // **Case 1: Node has NO CHILDREN (Leaf Node)**
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // **Case 2: Node has ONE CHILD (Left Child Only)**
        else if (root->left != nullptr && root->right == nullptr) {
            tree* temp = root->left;
            delete root;
            return temp;
        }

        // **Case 3: Node has ONE CHILD (Right Child Only)**
        else if (root->right != nullptr && root->left == nullptr) {
            tree* temp = root->right;
            delete root;
            return temp;
        }
    }
    return root;
}
void mirror(tree *root){
    if(root==NULL){
        return;
    }
    swap(root->left,root->right);
    //cout<<root->data<<" ";
    if(root->left!=NULL || root->right!=NULL){
        mirror(root->left);
        mirror(root->right);
    }
  }

void copy(tree *root){
    tree *newroot = root;
    newroot->left=root->left;
    newroot->right=root->right;
    cout<<" ";
    inorder(newroot);

}
void display_level(tree* root) {
    if (root == NULL) 
        return;

    cout << root->data << " ";
    if (root->left!=NULL) {
        cout << root->left->data << " ";
    }
    if (root->right!=NULL) {
        cout << root->right->data << " ";
    }
    if (root->left!=NULL) { 
        display_level(root->left->left);
         display_level(root->left->right);
    }
    if (root->right!=NULL) {
        display_level(root->right->left);
        display_level(root->right->right);
    }
}
int main(){
    
   tree *root = new tree(100);
    root=insert(root , 50);
    root=insert(root , 150);
    root=insert(root , 70);
    //root=insert(root , 20);
    root=insert(root , 120);
    root=insert(root , 180);
    root=insert(root , 10);

    cout<<"displaying tree in inorder traversal:"<<"  ";
    inorder(root);
    cout<<endl;
  /*  cout<<"displaying tree in preorder traversal:"<<"  ";
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
    */
  root = Delete(root, 50);
  //cout<<"displaying tree in inorder traversal:"<<"  ";
  inorder(root);
  //cout<<endl;
  cout<<"Tree after node deletion is :- "<<" ";
  //preorder(root); 

 /* cout<<"level wise display:";
  display_level(root);
  cout<<endl;
  cout<<"the copy of original tree is:";
  copy(root);*/
   return 0;

}