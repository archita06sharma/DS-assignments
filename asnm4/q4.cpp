#include <iostream>
using namespace std;

const int MAXLEN = 100;

class CircularQueue {
    char element[MAXLEN];
    int front, rear, count;

public:
    CircularQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty() { return count == 0; }
    bool isFull() { return count == MAXLEN; }

    void enqueue(char x) {
        if (isFull()) return;
        rear = (rear + 1) % MAXLEN;
        element[rear] = x;
        count++;
    }

    char dequeue() {
        if (isEmpty()) return '#'; 
        char val = element[front];
        front = (front + 1) % MAXLEN;
        count--;
        return val;
    }

    char peek() {
        if (isEmpty()) return '#';
        return element[front];
    }
};

void firstNonRepeating(string str) {
    CircularQueue q;
    int freq[26] = {0};

    for (char ch : str) {
        
        freq[ch - 'a']++;
        q.enqueue(ch);

        while (!q.isEmpty() && freq[q.peek() - 'a'] > 1) {
            q.dequeue();
        }

        if (q.isEmpty())
            cout << -1 << " ";
        else
            cout << q.peek() << " ";
    }
    cout << endl;
}

int main() {
    string input = "aabc";
    firstNonRepeating(input);
    return 0;
}
