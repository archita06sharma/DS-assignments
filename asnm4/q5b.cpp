//with one queue

#include <iostream>
using namespace std;

const int MAXLEN = 100;

class Queue {
    int arr[MAXLEN], front, rear, count;
public:
    Queue() { front = 0; rear = -1; count = 0; }
    bool isEmpty() { return count == 0; }
    bool isFull() { return count == MAXLEN; }
    void enqueue(int x) {
        if (isFull()) return;
        rear = (rear + 1) % MAXLEN;
        arr[rear] = x;
        count++;
    }
    int dequeue() {
        if (isEmpty()) return -1;
        int val = arr[front];
        front = (front + 1) % MAXLEN;
        count--;
        return val;
    }
    int peek() { return isEmpty() ? -1 : arr[front]; }
    int size() { return count; }
};

class Stack1Q {
    Queue q;
public:
    void push(int x) {
        int sz = q.size();
        q.enqueue(x);
        for (int i = 0; i < sz; i++) {
            q.enqueue(q.dequeue());
        }
    }
    void pop() {
        if (q.isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        q.dequeue();
    }
    int top() {
        return q.isEmpty() ? -1 : q.peek();
    }
    bool empty() { return q.isEmpty(); }
};

int main() {
    Stack1Q st;
    st.push(5);
    st.push(15);
    st.push(25);

    cout << "Top: " << st.top() << endl; // 25
    st.pop();
    cout << "Top after pop: " << st.top() << endl; // 15
}
