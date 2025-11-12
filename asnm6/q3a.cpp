#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data=val;
        next=prev=NULL;
    }
};

class DoublyList{
    public:
    Node* head;
    Node* tail;
    
    DoublyList(){
        head=tail=NULL;
    }

    void insertAtBegin(int val){
        Node* newNode= new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
    }

    int size(){
        int count = 0;
        Node* temp=head;
        if(head==NULL){
            cout<<"List is empty.\n";
            return -1;
        }
        do{
            count++;
            temp=temp->next;
        }while(temp!=tail);
        count++;
        return count;
    }
};

int main(){
    DoublyList dl;
    dl.insertAtBegin(4);
    dl.insertAtBegin(3);
    dl.insertAtBegin(2);
    dl.insertAtBegin(1);
    cout<<"Size of list : "<<dl.size();
    return 0;
}