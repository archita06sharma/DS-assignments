#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

void insertAtEnd(int d, Node* &head, Node* &tail){
    Node* temp = new Node(d);
    if(head == NULL){
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* rotateLeft(Node* head, int k){
    if(head == NULL || head->next == NULL || k == 0) return head;

    // Step 1: find length
    int n = 1;
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
        n++;
    }

    // Step 2: effective rotations
    k = k % n;
    if(k == 0) return head;

    // Step 3: make it circular
    tail->next = head;

    // Step 4: move k steps to find new head
    Node* newTail = head;
    for(int i=1; i<k; i++){
        newTail = newTail->next;
    }
    Node* newHead = newTail->next;

    // Step 5: break the circle
    newTail->next = NULL;

    return newHead;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtEnd(1, head, tail);
    insertAtEnd(2, head, tail);
    insertAtEnd(3, head, tail);
    insertAtEnd(4, head, tail);
    insertAtEnd(5, head, tail);

    cout << "Original List: ";
    display(head);

    int k = 2;
    head = rotateLeft(head, k);

    cout << "After rotating left by " << k << " positions: ";
    display(head);

    return 0;
}
