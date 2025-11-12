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
        do{
            cout<<temp->data<<"->";
            temp = temp->next;
        }while(temp!=head);
        cout<<temp->data;
        cout<<"\n";
    }
};
int main(){
    cirLinkedList cll;
    cll.insertAtBegin(3);
    cll.insertAtBegin(2);
    cll.insertAtBegin(1);
    cll.display();
    return 0;
}