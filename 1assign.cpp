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
    if (root == NULL)
        return root;

    if (key < root->data) {
        root->left = Delete(root->left, key);
    }
    
    else if (key > root->data) {
        root->right = Delete(root->right, key);
    }
    
    else {
        
        tree* temp;
        if (root->left != NULL) {
            temp = root->left;  
            }       
            else {
             temp = root->right; 
            }
            delete root;  
            return temp;  

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
    tree *root = NULL;
    int choice ;
    do{
        cout<<"1.INSERT\n2.INORDER DISPLAY\n3.PREORDER DISPLAY\n4.POSTORDER DISPLAY\n5.SEARCHING\n6.DELETE\n7.LEVEL-WISE DISPLAY\n8.COPY OF TREE\n9.MIRROR OF TREE\n10.EXIT\n";
        cout<<"Enter your choices:";
        cin>>choice;
        switch(choice){
            case 1:{
               cout<<"Inserting in Tree:";
               root = new tree(100);
               root=insert(root , 50);
                root=insert(root , 150);
                root=insert(root , 70);
                root=insert(root , 20);
                root=insert(root , 120);
                root=insert(root , 180);
                root=insert(root , 10);
            
                 break;
            }
            case 2:{
                cout<<"displaying tree in inorder traversal:"<<"  ";
               inorder(root);
                cout<<endl;
               break;
            }
           case 3:{
               cout<<"displaying tree in inorder traversal:"<<"  ";
               inorder(root);
                cout<<endl;
                break;
           }
           case 4:{
               cout<<"displaying tree in postorder traversal:"<<"  ";
               postorder(root);
               cout<<endl; 
               break;
           }
           case 5:{
                tree *tofound =  search(root , 100);
                if(tofound!=NULL){
                    cout<<"the node is found"<<endl;
                 }
                else{
                     cout<<"the node is not found"<<endl;
                }
                break;
            }
           case 6:{
               cout<<"Tree after node deletion is :- "<<" ";
               Delete(root,20);
               inorder(root);
               cout<<endl;
               break;
           }
           case 7:{
               cout<<"level wise display:";
               display_level(root);
               cout<<endl; 
               break;
           }
           case 8:{
                cout<<"the copy of original tree is:";
                copy(root);
                break;
           }   
           case 9:{
                cout<<"mirrro of tree:";
                mirror(root);
                inorder(root);
                cout<<endl;
                break;
           }   
           case 10:{
                 cout<<"EXIT"<<endl;
                 break;
           }
        }
        cout << "Do you want to continue (1 for Yes, any other key for No): ";
                   cin >> choice;
         }  while (choice == 1);
         
         return 0;
}
