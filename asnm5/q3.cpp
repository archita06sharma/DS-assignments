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

void insertAtEnd(int d,Node* & head, Node * & tail){
    Node* temp = new Node(d);
    if(head==NULL){
        head=tail=temp;
    }else{
        tail->next = temp;
        tail = temp;
    }
}

void display(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    cout<<"\n";
}

int findMiddle(Node* head){
    if(head==NULL){
        cout<<"List is empty.\n";
        return -1;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast!= NULL && fast->next!=NULL){  // order of condition matters !!! :)
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow->data;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtEnd(1, head, tail);
    insertAtEnd(2, head, tail);
    insertAtEnd(3, head, tail);
    insertAtEnd(4, head, tail);
    insertAtEnd(5, head, tail);
    insertAtEnd(6, head, tail);

    cout << "Linked List: ";
    display(head);

    cout << "Middle element is: " << findMiddle(head) << endl;


    return 0;
}