#include <iostream>
using namespace std;

const int MAXLEN = 10; 

class CircularQueue {
private:
    int element[MAXLEN];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }

    bool isEmpty() const {
        return (front == -1);
    }

    bool isFull() const {
        return ((rear + 1) % MAXLEN == front);
    }

    int size() const {
        if (isEmpty()) return 0;
        if (rear >= front) return rear - front + 1;
        return (MAXLEN - front + rear + 1);
    }

    int peek() const {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return element[front];
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "OVERFLOW: cannot enqueue " << x << "\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAXLEN;
        }
        element[rear] = x;
        cout << x << " enqueued.\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "UNDERFLOW: nothing to dequeue\n";
            return -1;
        }
        int removed = element[front];
        if (front == rear) {
            front = rear = -1; 
        } else {
            front = (front + 1) % MAXLEN;
        }
        return removed;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue contents (front -> rear): ";
        int i = front;
        while (true) {
            cout << element[i];
            if (i == rear) break;
            cout << " ";
            i = (i + 1) % MAXLEN;
        }
        cout << "\n";
    }
};
void interleaveQueue(CircularQueue &Q) {
    int n = Q.size();
    if (n % 2 != 0) {
        cout << "Queue has odd number of elements, cannot interleave!\n";
        return;
    }

    int half = n / 2;
    CircularQueue firstHalf;

    for (int i = 0; i < half; i++) {
        firstHalf.enqueue(Q.dequeue());
    }

    while (!firstHalf.isEmpty()) {
        Q.enqueue(firstHalf.dequeue()); 
        Q.enqueue(Q.dequeue());       
    }
}

int main() {
    CircularQueue Q;

    int arr[] = {4, 7, 11, 20, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        Q.enqueue(arr[i]);
    }

    cout << "Original Queue: ";
    Q.display();

    interleaveQueue(Q);

    cout << "Interleaved Queue: ";
    Q.display();

    return 0;
}
