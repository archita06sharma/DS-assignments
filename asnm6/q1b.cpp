#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

class cirLinkedList{
    public:
    Node* head;

    cirLinkedList(){
        head = NULL;
    }

    void insertAtBegin(int val){
        Node* newNode= new Node(val);
        if(head == NULL){
            head=newNode;
            head->next=head;
        }else{
            newNode->next=head;
            Node* temp = head;
            while(temp->next != head){
                temp = temp-> next;
            }
            temp->next=newNode;
            head=newNode;
        }
    }

    void display(){
        if(head == NULL){
            cout<<"List is empty.\n";
            return;
        }
        Node* temp=head;
        // while(temp->next !=head){
        //     cout<<temp->data<<"->";
        //     temp = temp->next;
        // }
        // cout<<temp->data<<"\n";
        //or
        do{
            cout<<temp->data;
            temp = temp->next;
            if(temp!=head) cout<<"->";
        }while(temp!=head);
        cout<<"\n";

    }
    void insertAtEnd(int val){
        Node* newNode= new Node(val);

        if(head==NULL){
            head=newNode;
            newNode->next=head;
        }else{
            Node* temp = head;
            while(temp->next!=head){
                temp= temp->next;
            }
            temp->next=newNode;
            newNode->next=head;
        }
    }
    void insertBefore(int val,int srhval){
        if(head == NULL){
            cout<<":ist is empty.\n";
            return;
        }

        Node* newNode= new Node(val);
        //case 1 : insert before head...
        if(head->data == srhval){
            Node* temp = head;
            while(temp->next != head){
                temp = temp-> next;
            }
            temp->next=newNode;
            newNode->next=head;
            head=newNode;
            return;
        }

        //case 2: insert before a middle or last node. 
        Node* temp= head;
        while(temp->next!=head && temp->next->data!=srhval){
        temp=temp->next;
        }
        if(temp->next==head){
            
        }
        newNode->next=temp->next;
        temp->next=newNode;
        }
        
    
};

int main(){
    cirLinkedList cll;
    cll.insertAtBegin(3);
    cll.insertAtBegin(2);
    cll.insertAtBegin(1);
    cll.display();
    cll.insertAtEnd(4);
    cll.display();
    return 0;
}