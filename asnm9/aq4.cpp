#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

Node* buildFromLevelOrder(const vector<int>& vals) {
    int n = vals.size();
    if (n == 0 || vals[0] == -1) return nullptr;

    Node* root = new Node(vals[0]);
    queue<Node*> q;
    q.push(root);
    int idx = 1;
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

vector<int> rightView(Node* root) {
    vector<int> ans;
    if (!root) return ans;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            Node* cur = q.front(); q.pop();
            // push children for next level
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
            // last node in this level -> right view
            if (i == sz - 1) ans.push_back(cur->val);
        }
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n; 
        cin >> n;
        vector<int> vals(n);
        for (int i = 0; i < n; ++i) cin >> vals[i];

        Node* root = buildFromLevelOrder(vals);
        vector<int> rv = rightView(root);

        // print in one line space-separated
        for (int i = 0; i < (int)rv.size(); ++i) {
            if (i) cout << ' ';
            cout << rv[i];
        }
        cout << '\n';

        // (Optional) free tree nodes to avoid leak in long runs. Omitted for brevity.
    }
    return 0;
}
