#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

// Insert at end helper
void insertAtEnd(int d, Node* &head, Node* &tail) {
    Node* temp = new Node(d);
    if (!head) {
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

// Detect and remove loop
void removeLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect loop
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;  // loop found
    }

    if (slow != fast) {
        cout << "No loop exists\n";
        return;
    }

    // Step 2: Find start of loop
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    Node* loopStart = slow;

    // Step 3: Remove loop
    Node* temp = loopStart;
    while (temp->next != loopStart) {
        temp = temp->next;
    }
    temp->next = NULL;

    cout << "Loop removed. Loop started at node: " << loopStart->data << "\n";
}

// Display list
void display(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtEnd(1, head, tail);
    insertAtEnd(7, head, tail);
    insertAtEnd(3, head, tail);
    insertAtEnd(6, head, tail);

    // Creating a loop: last node points to 7 (second node)
    tail->next = head->next;

    removeLoop(head);

    cout << "Linked List after loop removal: ";
    display(head);

    return 0;
}
