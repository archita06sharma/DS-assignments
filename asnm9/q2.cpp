// 2. Implement following functions for Binary Search Trees (a) Search a given item (Recursive & Non-Recursive) (b) Maximum element of the BST (c) Minimum element of the BST (d) In-order successor of a given node the BST (e) In-order predecessor of a given node the BST

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data=value;
        left=right=NULL;
    }
};

// Insert node in BST 
Node* insert(Node* root,int value){
    if(root==NULL) return new Node(value);
    if(value< root->data){
        root->left = insert (root->left,value);
    }else if (value > root->data){
        root->right = insert( root->right,value);
    }
    return root;
}

//a) Search (recursive)

Node* searchRecursive (Node* root, int key){
    if(root==NULL || root->data == key){
        return root;
    }

    if( key <root->data){
        return searchRecursive(root->left,key);
    }else {
        return searchRecursive(root->right,key);
    }
}

// a) Search (Non - recursive)

Node* searchIterative(Node* root, int key){
    while(root!=NULL && root->data != key){
        if(key < root->data){
            root=root->left;
        }else{
            root=root->right;
        }
        return root;
    }
}

// b) Find Maximum element

Node* findMax(Node* root){
    if(root==NULL) return NULL;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}

// c) Find Minimum element
Node* findMin(Node* root){
    if(root==NULL) return NULL;
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

// d) Inorder Successor

Node* inorderSuccessor (Node* root,Node* node){
    if(node->right!=NULL){
        return findMin(node->right);
    }

    Node* succ=NULL;
    while(root!=NULL){
        if(node->data < root->data){
            succ=root;
            root=root->left;
        }else if(node->data > root ->data){
            root=root->right;
        }else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root,Node* node){
    if(node->left!=NULL){
        return findMax(node->left);
    }

    Node* pred=NULL;
    while(root!=NULL){ // when root is null means no tree then return null ..... 
        if(node->data > root->data){
            pred=root;
            root=root->right;
        }else if( node->data< root->data){
            root = root->left;
        }else break;
    }
    return pred;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    Node* root =NULL;
    int values[]= {20,8,22,4,12,10,14};
    for(int v: values){
        root = insert( root,v);
    }
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    //a) search

    int key =10;
    Node* res1 = searchRecursive(root,key);
    cout << "Search (Recursive): "<< (res1) ? (cout<<"Found"<<res1->data) : (cout<<"Not Found") << endl;

    Node* res2 = searchIterative(root, key);
    cout << "Search (Iterative): "<< (res2 )? (cout<<"Found"<<res1->data) : (cout<<"Not Found") << endl;

    //b) maximum element
    cout<<"Maximum element : "<<findMax(root)->data<<endl;

    // (c) Minimum element
    cout << "Minimum element: " << findMin(root)->data << endl;

    // (d) Inorder Successor of 10
    Node* node = searchIterative(root, 10);
    Node* succ = inorderSuccessor(root, node);
    if (succ)
        cout << "Inorder Successor of " << node->data << ": " << succ->data << endl;
    else
        cout << "No Inorder Successor for " << node->data << endl;


    // e) Inoreder predecessor of 10

    Node* pred = inorderPredecessor(root, node);
    if (pred)
        cout << "Inorder Predecessor of " << node->data << ": " << pred->data << endl;
    else
        cout << "No Inorder Predecessor for " << node->data << endl;

    return 0;
}