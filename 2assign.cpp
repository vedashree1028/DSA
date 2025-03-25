#include<iostream>
using namespace std;
class AVL{
    public:

    int data;
    AVL *right , *left;
    int height;

    AVL(){
        data=0;
        right=NULL;
        left=NULL;
        height=1;
    } 

    AVL(int d){
        data=d;
        right=NULL;
        left=NULL;
        height=1;
    }
};
int gethgt(AVL *root){
    if (root == NULL)
        return 0;
    return root->height;
}
int balancefactor(AVL *root){
    if(root==NULL){
        return 0;
    }
    return gethgt(root->left) - gethgt(root->right);
}
AVL *rightrotation(AVL *y){
    AVL *x = y->left;
    AVL *t2= x->right;

    x->right=y;
    y->left=t2;

    y->height = max(gethgt(y->left) , gethgt(y->right)) + 1;
    x->height = max(gethgt(x->left) , gethgt(x->right)) + 1;

    return x;
}
AVL *leftrotation(AVL *y){
    AVL *x = y->right;
    AVL *t2= x->left;

    x->left=y;
    y->right=t2;

    y->height = max(gethgt(y->left) , gethgt(y->right)) + 1;
    x->height = max(gethgt(x->left) , gethgt(x->right)) + 1;

    return x;
}
AVL *insert(AVL *node , int key){
    if(node==NULL){
        return new AVL(key);
    }
    else if (node->data==key){
        return node;
    }
    else if(node->data > key){
        node->left=insert(node->left , key);
    }
    else{
        node->right=insert(node->right , key);
    }

    node->height = 1 + max(gethgt(node->left), gethgt(node->right));

    int bf =balancefactor(node);

    if (bf > 1 && balancefactor(node->left) >= 0) {
        return rightrotation(node);
    }
    if (bf < -1 && balancefactor(node->right) <= 0) {
        return leftrotation(node);
    }
    if (bf > 1 && balancefactor(node->left) < 0) { 
        node->left = leftrotation(node->left);
        return rightrotation(node);
    }
    if (bf < -1 && balancefactor(node->right) > 0) { 
        node->right = rightrotation(node->right);
        return leftrotation(node);
    }

return node;
}
AVL *Delete(AVL *root , int key){
    if (root == NULL)
        return root;

    if (key < root->data) {
        root->left = Delete(root->left, key);
    }
    
    else if (key > root->data) {
        root->right = Delete(root->right, key);
    }
    
    else {
        
        AVL* temp;
        if (root->left != NULL) {
            temp = root->left;  
            }       
            else {
             temp = root->right; 
            }
            delete root;  
            return temp;  
    }
    root->height = 1 + max(gethgt(root->left), gethgt(root->right));

    int bf =balancefactor(root);
    if (bf > 1 && balancefactor(root->left) >= 0) {
        return rightrotation(root);
    }
    if (bf < -1 && balancefactor(root->right) <= 0) {
        return leftrotation(root);
    }
    if (bf > 1 && balancefactor(root->left) < 0) { 
        root->left = leftrotation(root->left);
        return rightrotation(root);
    }
    if (bf < -1 && balancefactor(root->right) > 0) { 
        root->right = rightrotation(root->right);
        return leftrotation(root);
    }

return root;
}
void inorder(AVL *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
int main(){
    int choice;
    int val;
    AVL *root=NULL; 
    do{
        cout<<"1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n";
        cout<<"Enter your choice:";
        cin>>choice;

        switch(choice){
            case 1: {
                cout << "Enter the value to insert: ";
                cin >> val;
                root = insert(root, val);
                break;
            }

            case 2:{
                cout<<"Deleting the node:";
                root = Delete(root , 20);
                inorder(root);
                cout<<endl;
                break;
            }

            case 3:{
                cout<<"Displaying the tree:";
                inorder(root);
                cout<<endl;
                break;
            }
        }
        cout << "Do you want to continue (1 for Yes, any other key for No): ";
        cin >> choice;
    }while(choice==1);

    return 0;
}
