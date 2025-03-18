#include <iostream>
using namespace std;

// AVL Tree Node
class Node {
public:
    int player_id, score;
    Node *left, *right;
    int height;
    
    Node(int id, int sc) {
        player_id = id;
        score = sc;
        left = right = NULL;
        height = 1;
    }
};

// AVL Tree Class
class AVLTree {
public:
    Node* root;
    AVLTree() { root = NULL; }
    
    int getHeight(Node* node) {
        return node ? node->height : 0;
    }
    
    int getBalanceFactor(Node* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }
    
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        return x;
    }
    
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        return y;
    }
    
    Node* insert(Node* node, int id, int sc) {
        if (!node) return new Node(id, sc);
        
        if (sc < node->score)
            node->left = insert(node->left, id, sc);
        else if (sc > node->score)
            node->right = insert(node->right, id, sc);
        else
            return node;
        
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        
        int balance = getBalanceFactor(node);
        
        if (balance > 1 && sc < node->left->score)
            return rightRotate(node);
        if (balance < -1 && sc > node->right->score)
            return leftRotate(node);
        if (balance > 1 && sc > node->left->score) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && sc < node->right->score) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
    
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left)
            current = current->left;
        return current;
    }
    
    Node* remove(Node* root, int sc) {
        if (!root) return root;
        
        if (sc < root->score)
            root->left = remove(root->left, sc);
        else if (sc > root->score)
            root->right = remove(root->right, sc);
        else {
            if (!root->left || !root->right) {
                Node* temp = root->left ? root->left : root->right;
                if (!temp) {
                    temp = root;
                    root = NULL;
                } else
                    *root = *temp;
                delete temp;
            } else {
                Node* temp = minValueNode(root->right);
                root->score = temp->score;
                root->player_id = temp->player_id;
                root->right = remove(root->right, temp->score);
            }
        }
        
        if (!root) return root;
        
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
        int balance = getBalanceFactor(root);
        
        if (balance > 1 && getBalanceFactor(root->left) >= 0)
            return rightRotate(root);
        if (balance > 1 && getBalanceFactor(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && getBalanceFactor(root->right) <= 0)
            return leftRotate(root);
        if (balance < -1 && getBalanceFactor(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }
    
    void inorder(Node* root) {
        if (!root) return;
        inorder(root->right);
        cout << "Player ID: " << root->player_id << " | Score: " << root->score << endl;
        inorder(root->left);
    }
    
    void registerPlayer(int id, int sc) {
        root = insert(root, id, sc);
    }
    
    void displayLeaderboard() {
        if (!root) {
            cout << "No players in the game." << endl;
            return;
        }
        inorder(root);
    }
    
    void removePlayer(int sc) {
        root = remove(root, sc);
    }
};

int main() {
    AVLTree game;
    int choice, id, score;
    
    while (true) {
        cout << "\n1. Register Player\n2. Display Leaderboard\n3. Remove Player\n4. Exit\nEnter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter Player ID and Score: ";
                cin >> id >> score;
                game.registerPlayer(id, score);
                break;
            case 2:
                cout << "\nLeaderboard:\n";
                game.displayLeaderboard();
                break;
            case 3:
                cout << "Enter Score to Remove Player: ";
                cin >> score;
                game.removePlayer(score);
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Try again!\n";
        }
    }
    return 0;
}
