#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class binaryTree{
    public:

    bool isLeaf(Node* node){
        return node!=NULL && node->left==NULL && node->right==NULL;
    }

    //sum of all left leaves

    int sumOfLeftLeaves(Node* root){
        if(root==NULL) return 0;
        int sum=0;
        //if left child exists and is a leaf node, add its value
        if(isLeaf(root->left)){
            sum+=root->left->data;
        }else{
            //otherwise, go deeper into left subtree
            sum+=sumOfLeftLeaves(root->left);
        }

        //continue reursion on the right subtree
        sum+=sumOfLeftLeaves(root->right);

        return sum;
    }

};

int main(){
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    binaryTree bt;

    cout << "Sum of all left leaves: " << bt.sumOfLeftLeaves(root);

    return 0;
}