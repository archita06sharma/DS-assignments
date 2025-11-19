// 3. Write a program for binary search tree (BST) having functions for the following
// operations:
// (a) Insert an element (no duplicates are allowed),
// (b) Delete an existing element,
// (c) Maximum depth of BST
// (d) Minimum depth of

#include<iostream>
using namespace std;
#include<queue>

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=right=nullptr;
    }
};

Node* insertNode(Node* root,int value){
    if(root==nullptr) return new Node(value);
    if(value>root->data){
        root->right=insertNode(root->right,value);
    }else if(value<root->data){
        root->left=insertNode(root->left,value);
    }else {
        cout<<"Duplicates are not allowed.\n";
    }
    return root;
}

Node* findMinNode(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

Node* deleteNode(Node* root,int value){
    if(root=NULL) return root;
    
    if(value < root->data){
        root->left = deleteNode(root->left, value);
    }
    else if(value > root->data){
        root->right = deleteNode(root->right, value);
    }
    else{
        // Case 1: No child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // Case 2: One child (right)
        else if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 2: One child (left)
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        else{
            Node* temp = findMinNode(root->right); // inorder successor
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

int maxDepth (Node* root){
    if(root==NULL) return 0;
    int left=maxDepth(root->left);
    int right=maxDepth(root->right);
    return max(left,right)+1;
}

int minDepth (Node* root){
    if(root==NULL) return 0;

    int left=minDepth(root->left);
    int right=minDepth(root->right);
    
    if(root->left==NULL) return right+1;
    if(root->right==NULL) return left+1;

    return min(left,right)+1;
}