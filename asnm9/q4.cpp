#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=right=NULL;
    }
};


class binaryTree{
    public:
    //APPROACH 1: Min-Max validation
    bool isBST_MinMax(Node* root,int minVal,int maxVal){
        if(root==NULL) return true;
        if(root->data<=minVal || root->data>=maxVal){
            return false;
        }

        return isBST_MinMax(root->left,minVal,root->data) &&
                isBST_MinMax(root->right,root->data,maxVal);
    }

    //APPPROACH 2: Inorder TraversalCheck (prev pointer) pending 
    
};

int main(){
    Node* root = new Node(4);
    root->left= new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    binaryTree bt;

    cout << "Checking using Min-Max Method: ";
    if (bt.isBST_MinMax(root, INT_MIN, INT_MAX))
        cout << "BST\n";
    else
        cout << "Not a BST\n";

    return 0;
}
