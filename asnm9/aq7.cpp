#include <bits/stdc++.h>
using namespace std;

// Tree node for the BST
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Doubly linked list node
struct DNode {
    int val;
    DNode* prev;
    DNode* next;
    DNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};

// 1) Inorder traversal to collect sorted values from a BST
void inorderCollect(TreeNode* root, vector<int>& out) {
    if (!root) return;
    inorderCollect(root->left, out);
    out.push_back(root->val);
    inorderCollect(root->right, out);
}

// 2) Merge two sorted vectors (like merge step of merge-sort)
vector<int> mergeSortedVectors(const vector<int>& a, const vector<int>& b) {
    vector<int> merged;
    int i = 0, j = 0;
    while (i < (int)a.size() && j < (int)b.size()) {
        if (a[i] <= b[j]) merged.push_back(a[i++]);
        else merged.push_back(b[j++]);
    }
    while (i < (int)a.size()) merged.push_back(a[i++]);
    while (j < (int)b.size()) merged.push_back(b[j++]);
    return merged;
}

// 3) Build doubly linked list from a sorted vector
DNode* buildDLL(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    DNode* head = new DNode(vals[0]);
    DNode* tail = head;
    for (int k = 1; k < (int)vals.size(); ++k) {
        DNode* node = new DNode(vals[k]);
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    return head;
}

// Utility to print DLL as requested
void printDLL(DNode* head) {
    DNode* cur = head;
    while (cur) {
        cout << cur->val;
        if (cur->next) cout << " <--> ";
        cur = cur->next;
    }
    cout << " <--> null\n";
}

// Example helper: insert into BST (normal BST insert)
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val <= root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

int main() {
    // Build example BSTs (you can change these to test other trees)
    // T1 values: 20,10,30,25,50,100  (insert order below)
    TreeNode* T1 = nullptr;
    for (int x : {20, 10, 30, 25, 50, 100}) T1 = insertBST(T1, x);

    // T2 values: 5, 70
    TreeNode* T2 = nullptr;
    for (int x : {5, 70}) T2 = insertBST(T2, x);

    // Collect sorted arrays from each BST
    vector<int> s1, s2;
    inorderCollect(T1, s1);   // s1 will be sorted
    inorderCollect(T2, s2);   // s2 will be sorted

    // Merge the two sorted arrays
    vector<int> merged = mergeSortedVectors(s1, s2);

    // Build doubly linked list from merged values
    DNode* head = buildDLL(merged);

    // Print result
    printDLL(head);

    return 0;
}
