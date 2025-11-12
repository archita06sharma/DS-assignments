#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int d) {
        data = d;
        next = prev = NULL;
    }
};

// Function to insert node at end
void insertAtEnd(Node*& head, Node*& tail, int data) {
    Node* temp = new Node(data);
    if (head == NULL) {
        head = tail = temp;
        return;
    }
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

// Function to print DLL
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << " <-> ";
        temp = temp->next;
    }
    cout << " <-> NULL" << endl;
}

// Function to reverse DLL in groups of k
Node* reverseInGroups(Node* head, int k) {
    if (head == NULL) return NULL;

    Node* curr = head;
    Node* newHead = NULL;
    Node* temp = NULL;
    int count = 0;

    // Reverse first k nodes
    while (curr != NULL && count < k) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
        count++;
    }

    // After reversing, temp points to the node before new head
    if (temp != NULL)
        newHead = temp->prev;
    else
        newHead = head;

    // Now recurse for remaining list
    if (curr != NULL) {
        head->next = reverseInGroups(curr, k);
        if (head->next != NULL)
            head->next->prev = head;
    }

    return newHead;
}

// Main function
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Create DLL: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6
    for (int i = 1; i <= 6; i++)
        insertAtEnd(head, tail, i);

    int k = 2;  // you can change this to test

    cout << "Original List: ";
    printList(head);

    head = reverseInGroups(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}
