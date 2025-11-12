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

    void insertAtEnd(int val){
        Node* newNode= new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }
    void insertBeforeNode(int val,int srhval){
        Node* newNode= new Node(val);
        Node* temp=head;
        if(head==NULL){
            cout<<"Can't insert before..list empty\n";
            return; // imp otherwise it will run afterwards...
        }
            
        if(head->data==srhval){
            newNode->next = head;
            head->prev=newNode;
            head=newNode;
            return;
        }

        while(temp!=NULL && temp->data != srhval){
            temp=temp->next;
        }

        if(temp==NULL){
            cout<<"Value not found therefore can't insert before.\n";
        }else{
            newNode->next=temp->next;
            temp->next->prev=newNode;
            newNode->prev=temp;
            temp->next=newNode;
        }

    }
    void deleteAtVal(int val){
        Node* curr=head;
        Node* prev=NULL;

        if(head==NULL){
            cout<<"List is empty ...";
            return;
        }else{
           while(curr!=NULL && curr->data !=val ){
                prev=curr;
                curr=curr->next;
            }
            if(curr == NULL){
                cout<<"Value not found therefore can't delete before\n";
            }else {
                prev->next=curr->next;
                curr->next->prev=prev;
                curr->next=NULL;
                curr->prev=NULL;
            }
        }
    }
    int search(int val){
        int idx=0;
        Node* temp = head;
        if(head==NULL){
            cout<<"List is empty.\n";
            return -1;
        }else{
            while(temp!=NULL && temp->data!=val){
                temp=temp->next;
                idx++;
            }
            if(temp==NULL){
                cout<<"Value not found.\n";
                return -1;
            }else{
                return idx;
            }
        }
    }
    void display(){
        Node* temp=head;
        if(head==NULL){
            cout<<"List is empty.\n";
        }else{
            while(temp!=NULL){
                cout<<temp->data<<"<=>";
                temp=temp->next;
            }
            cout<<"NULL\n";
        }
    }
};

int main(){
    DoublyList dl;
    dl.insertAtBegin(5);
    dl.insertAtBegin(4);
    dl.insertAtBegin(3);
    dl.insertAtEnd(6);
    dl.display();
    return 0;
}
