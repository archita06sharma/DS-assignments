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

// Stack using 2 Queues
class Stack {
    Queue q1, q2;
public:
    void push(int x) {
        q2.enqueue(x);
        while (!q1.isEmpty()) {
            q2.enqueue(q1.dequeue());
        }
        // swap q1 and q2
        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }
    void pop() {
        if (q1.isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        q1.dequeue();
    }
    int top() {
        if (q1.isEmpty()) return -1;
        return q1.peek();
    }
    bool empty() { return q1.isEmpty(); }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl; // 30
    st.pop();
    cout << "Top after pop: " << st.top() << endl; // 20
}
