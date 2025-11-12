#include<iostream>
using namespace std;

class Node{
    public:
    char ch;
    Node* next;
    Node* prev;

    Node(char val){
        ch=val;
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
    void display(){
        Node* temp=head;
        if(head==NULL){
            cout<<"List is empty.\n";
        }else{
            while(temp!=NULL){
                cout<<temp->ch<<"<=>";
                temp=temp->next;
            }
            cout<<"NULL\n";
        }
    }
    bool isPalindrome(){
        if (head==NULL){
            cout<<"List is empty.\n";
        }
        Node* start = head;
        Node* end = tail;
        do{
            if(start->ch==end->ch){
                start=start->next;
                end=end->prev;
            }
            else {
                return false;
            }
        }while(start!=end && start->prev != end && start != NULL && end!=NULL);
        return true;

    }
};
int main(){
    DoublyList dl;
    dl.insertAtBegin('L');
    dl.insertAtBegin('E');
    dl.insertAtBegin('V');
    dl.insertAtBegin('E');
    dl.insertAtBegin('L');
    // dl.insertAtBegin('F');
    dl.display();
    if(dl.isPalindrome()){
        cout<<"Is palindrome.\n";
    }else{
        cout<<"Not a palindrome.\n";
    }
    return 0;
}
