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

bool isCircular (Node* head){
    if(head==NULL) return false;

    Node* temp= head->next;
    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }
    if(temp==head) return true;
    else return false;
}

int main(){
    Node* head = new Node(2);
    Node* second = new Node(6);
    Node* third = new Node(6);
    Node* fourth = new Node(7);
    Node* fifth = new Node(5);

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;

    // fifth ->next = head;

    if(isCircular(head)) cout<<"True";
    else cout<<"False";
    return 0;
}