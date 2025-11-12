#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};

class cirll{
    public:
    Node* head;
    cirll(){
        head=nullptr;
    }

    void insertAtEnd(int val){
        Node* newNode=new Node(val);
        if(head==nullptr){
            head=newNode;
            head->next=head;
            return;
        }
        Node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=head;
    }

    bool parity(int n){
        int cnt=0;
        while(n!=0){
            if(n%2==1) cnt++;
                n/=2;
        }
        return (cnt%2==0);
    }

    void removeEvenParity(){
        if (head ==nullptr) return;

        Node* curr=head;
        Node* prev=nullptr;

        do{

            if(parity(curr->data)){
                if(curr==head && head->next==head){
                    delete head;
                    head=nullptr;
                    return;
                }    
                
                if(curr==head){
                    Node* last =head;
                    while (last->next != head) last = last->next;
                    last->next = head->next;
                    head = head->next;
                    delete curr;
                    curr = head;
                    prev = last; 
                }else{
                    prev->next=curr->next;
                    delete curr;
                    curr=prev->next;
                }
            }else{
                prev=curr;
                curr=curr->next;
            }
            if(head==nullptr || curr==head)
            break;
        }while(curr!=head);
    }

    
    void display(){
        if(head == nullptr){
            cout<<"List is empty\n";
            return;
        }
        Node* temp=head;
        do{
            cout<<temp->data;
            temp=temp->next;
            if(temp!=head) cout<<"->";
        }while(temp!=head);
        cout<<"\n";
    }
};

int main(){
    cirll list;
    list.insertAtEnd(9);
    list.insertAtEnd(11);
    list.insertAtEnd(34);
    list.insertAtEnd(6);
    list.insertAtEnd(13);
    list.insertAtEnd(21);
    
    cout<<"Original cll : ";
    list.display();

    list.removeEvenParity();

    cout<<"After removal : ";
    list.display();

    return 0;
}