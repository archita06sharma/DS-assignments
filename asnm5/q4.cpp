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

void insertAtEnd(int d, Node* &head, Node* &tail) {
    Node* temp = new Node(d);
    if (head == NULL) {
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

Node* reverseList(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    while(curr!=NULL){
        Node* nextNode = curr -> next;
        curr-> next = prev;
        prev= curr;
        curr= nextNode; 
    }
    return prev; // head of reversed ll
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtEnd(1, head, tail);
    insertAtEnd(2, head, tail);
    insertAtEnd(3, head, tail);
    insertAtEnd(4, head, tail);

    cout << "Original List: ";
    display(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    display(head);

    return 0;
}
