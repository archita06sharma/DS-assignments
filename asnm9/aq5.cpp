#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) {
        val = x;
        left = right = NULL;
    }
};

int findIndex(vector<int>& inorder, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

Node* buildTreeHelper(vector<int>& preorder, vector<int>& inorder,
                      int inStart, int inEnd, int& preIndex) {

    if (inStart > inEnd) return NULL;

    int rootVal = preorder[preIndex++];
    Node* root = new Node(rootVal);

    int pos = findIndex(inorder, inStart, inEnd, rootVal);

    root->left = buildTreeHelper(preorder, inorder,
                                 inStart, pos - 1, preIndex);

    root->right = buildTreeHelper(preorder, inorder,
                                  pos + 1, inEnd, preIndex);

    return root;
}

Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preIndex = 0;
    return buildTreeHelper(preorder, inorder, 0, inorder.size() - 1, preIndex);
}

// For testing (print inorder)
void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}


int main() {
    int n;
    cin >> n;

    vector<int> preorder(n), inorder(n);
    for (int i = 0; i < n; i++) cin >> preorder[i];
    for (int i = 0; i < n; i++) cin >> inorder[i];

    Node* root = buildTree(preorder, inorder);

    printInorder(root);
}