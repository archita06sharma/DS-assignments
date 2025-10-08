#include <iostream>
using namespace std;

const int MAXLEN = 5; 

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

int main() {
    CircularQueue Q;
    int choice;

    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek (front)\n";
        cout << "4. isEmpty\n5. isFull\n6. Display\n7. Size\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int x;
                cout << "Enter value to enqueue: ";
                cin >> x;
                Q.enqueue(x);
                break;
            }
            case 2:
                Q.dequeue();
                break;
            case 3:
                cout << "Front element: " << Q.peek() << "\n";
                break;
            case 4:
                cout << (Q.isEmpty() ? "Queue is empty\n" : "Queue is NOT empty\n");
                break;
            case 5:
                cout << (Q.isFull() ? "Queue is full\n" : "Queue is NOT full\n");
                break;
            case 6:
                Q.display();
                break;
            case 7:
                cout << "Size: " << Q.size() << "\n";
                break;
            case 0:
                cout << "Exiting. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}
