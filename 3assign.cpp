#include<iostream>
using namespace std;
class Tree{
    public:

    int data;
    Tree *left;
    Tree *right;

    Tree(){
        data=0;
        left=NULL;
        right=NULL;
    }

    Tree(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
Tree *insert(Tree *node , int key ){
    if(node==NULL){
        return new Tree(key);
    }

    if(node->data==key){
        return node;
    }

    if(node->data > key){
        node->left=insert(node->left,key);
    }

    else if(node->data<key){
        node->right=insert(node->right,key);
    }
}
int height(Tree *root){
    if(root==NULL){
        return -1;
        return 1 + max(height(root->left) , height(root->right));
    }
}
void display_BFS(Tree *root , int level){
    if(root==NULL){
        return ;
    }
    if(level==1){
    cout<<root->data<<" ";
    }
    else{
         display_BFS(root->left , level-1);
         display_BFS(root->right , level-1);
    }
}
void BFS(Tree * root){
    int h = height(root);

    for(int i=1 ; i<=h ; i++){
        display_BFS(root , i);
    }
}
void display_DFS(Tree *root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";  
    display_DFS(root->left);    
    display_DFS(root->right);   
}

int main(){
    Tree *root= new Tree(90);
    root=insert(root , 50);
    root=insert(root , 150);
    root=insert(root , 70);
    root=insert(root , 120);
    root=insert(root , 180);
    root=insert(root , 10);
    cout<<endl;
    cout<<"bfs display:"<<endl;
    BFS(root);
    cout<<endl;
    cout<<"dfs display:"<<endl;
    display_DFS(root);
    cout<<endl;
}