#include <bits/stdc++.h>
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

class Solution {
public:
    vector<Node*> generate(int start, int end) {
        vector<Node*> result;

        if (start > end) {
            result.push_back(NULL);
            return result;
        }

        for (int rootVal = start; rootVal <= end; rootVal++) {

            vector<Node*> leftTrees = generate(start, rootVal - 1);
            vector<Node*> rightTrees = generate(rootVal + 1, end);

            for (Node* L : leftTrees) {
                for (Node* R : rightTrees) {
                    Node* root = new Node(rootVal);
                    root->left = L;
                    root->right = R;
                    result.push_back(root);
                }
            }
        }

        return result;
    }

    vector<Node*> generateTrees(int n) {
        return generate(1, n);
    }
};

void printTree(Node* root) {
    if (!root) {
        cout << "null ";
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();   
        q.pop();

        if (curr) {
            cout << curr->data << " ";
            q.push(curr->left);
            q.push(curr->right);
        } else {
            cout << "null ";
        }
    }
}

int main() {
    Solution s;
    vector<Node*> trees = s.generateTrees(3);

    cout << "Total Trees = " << trees.size() << endl;

    for (auto t : trees) {
        printTree(t);
        cout << endl;
    }
}
