#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool checkIncreasing(queue<int> &q) {
    stack<int> st;
    int expected = 1;
    int n = q.size();

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == expected) {
            expected++;
        } else {
            while (!st.empty() && st.top() == expected) {
                st.pop();
                expected++;
            }

            if (curr != expected) {
                st.push(curr);
            }
        }
    }

    // pop remaining stack
    while (!st.empty() && st.top() == expected) {
        st.pop();
        expected++;
    }

    return (expected == n + 1);
}

int main() {
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    if (checkIncreasing(q))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
