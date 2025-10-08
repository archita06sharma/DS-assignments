#include <iostream>
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

// Function to reverse K nodes of the linked list
Node* reverseKNodes(Node* head, int K) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int count = 0;

    // First, check if there are at least K nodes to reverse
    Node* temp = head;
    int nodeCount = 0;
    while (temp != NULL && nodeCount < K) {
        temp = temp->next;
        nodeCount++;
    }
    if (nodeCount < K) return head; // Less than K nodes, no reversal

    // Reverse K nodes
    count = 0;
    curr = head;
    while (curr != NULL && count < K) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Now head is the last node of this reversed group
    // Connect it with the next reversed group
    if (next != NULL) {
        head->next = reverseKNodes(next, K);
    }

    return prev; // New head of this group
}

// Helper function to insert at end
void insertAtEnd(Node* &head, Node* &tail, int val) {
    Node* temp = new Node(val);
    if (head == NULL) {
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

// Helper function to display list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Example: 1->2->3->4->5->6->7->8
    for (int i = 1; i <= 8; i++) insertAtEnd(head, tail, i);

    cout << "Original List: ";
    display(head);

    int K = 3;
    head = reverseKNodes(head, K);

    cout << "Reversed in groups of " << K << ": ";
    display(head);

    return 0;
}
