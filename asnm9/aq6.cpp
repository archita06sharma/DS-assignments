#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

// Find index of value in inorder[]
int findIndex(vector<int>& inorder, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree using inorder + postorder
Node* buildTreeHelper(vector<int>& inorder, vector<int>& postorder,
                      int inStart, int inEnd, int &postIndex) {

    if (inStart > inEnd) return NULL;

    // Postorder last element is always root
    int rootVal = postorder[postIndex--];
    Node* root = new Node(rootVal);

    // Find root in inorder
    int pos = findIndex(inorder, inStart, inEnd, rootVal);

    // IMPORTANT: build RIGHT FIRST, then LEFT
    root->right = buildTreeHelper(inorder, postorder, pos + 1, inEnd, postIndex);
    root->left  = buildTreeHelper(inorder, postorder, inStart, pos - 1, postIndex);

    return root;
}

Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int postIndex = postorder.size() - 1;
    return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, postIndex);
}

// For testing
void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    int n;
    cin >> n;

    vector<int> inorder(n), postorder(n);
    for (int i = 0; i < n; i++) cin >> inorder[i];
    for (int i = 0; i < n; i++) cin >> postorder[i];

    Node* root = buildTree(inorder, postorder);

    printInorder(root);
}
