#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Build tree from level-order array where -1 means NULL.
// Uses a queue and consumes the array left-to-right.
Node* buildFromLevelOrder(const vector<int>& vals) {
    int n = vals.size();
    if (n == 0 || vals[0] == -1) return nullptr;

    Node* root = new Node(vals[0]);
    queue<Node*> q;
    q.push(root);

    int idx = 1; // next value index in vals to use as child
    while (!q.empty() && idx < n) {
        Node* cur = q.front(); q.pop();

        // left child
        if (idx < n) {
            if (vals[idx] != -1) {
                cur->left = new Node(vals[idx]);
                q.push(cur->left);
            }
            idx++;
        }

        // right child
        if (idx < n) {
            if (vals[idx] != -1) {
                cur->right = new Node(vals[idx]);
                q.push(cur->right);
            }
            idx++;
        }
    }
    return root;
}

// Standard recursive max depth (height) computation (counts nodes)
int maxDepth(Node* root) {
    if (!root) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left, right) + 1;
}

int main() {
    int T;
    cin >> T;     // number of test cases

    while (T--) {
        int n;
        cin >> n;  // number of nodes in level order input

        vector<int> vals(n);
        for (int i = 0; i < n; i++) {
            cin >> vals[i];   // read level order values
        }

        Node* root = buildFromLevelOrder(vals); // build the tree

        cout << maxDepth(root) << endl;         // print the depth
    }
    return 0;
}
