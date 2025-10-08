#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int getMinIndex(queue<int> &q, int sortedIndex) {
    int minIndex = -1;
    int minVal = INT_MAX;
    int n = q.size();

    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();

        // check only unsorted part
        if (curr <= minVal && i <= sortedIndex) {
            minVal = curr;
            minIndex = i;
        }
        q.push(curr); // rotate
    }
    return minIndex;
}

// bring minimum element to rear at correct position
void insertMinToRear(queue<int> &q, int minIndex) {
    int minVal;
    int n = q.size();

    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();

        if (i == minIndex) {
            minVal = curr; // hold the min element
        } else {
            q.push(curr); // rotate
        }
    }
    q.push(minVal); // place min at rear
}

void sortQueue(queue<int> &q) {
    int n = q.size();
    for (int i = 1; i <= n; i++) {
        int minIndex = getMinIndex(q, n - i);
        insertMinToRear(q, minIndex);
    }
}

int main() {
    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    sortQueue(q);

    cout << "Sorted Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
