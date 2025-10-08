#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int d){
        this->data = d;
        this->next=NULL;
    }
};

void insertAtBeginning(int d,Node* &head,Node* &tail){
    Node* temp = new Node(d);
    if(head==NULL){
        head=temp;
        tail=temp;
    }else{
        temp->next=head;
        head=temp;  
    }
}

void insertAtValueAfter(int d,Node* &head,int value){
    if(head==NULL){
        cout<<"List is empty can not insert after\n";
        return;
    }
    Node* curr =head;
    while (curr != NULL && curr->data!=value){
        curr=curr->next;
    }
    if(curr==NULL){
        cout<<"Value"<<value<<" not found in list.\n";
        return;
    } 
    Node* temp = new Node(d);
    temp->next=curr->next;
    curr->next=temp;
}

int countAndDelete(int key,Node* &head,Node* &tail){
    int cnt=0;
    if(head!=NULL && head->data==key){
        Node* del = head;
        head=head->next;
        del->next=NULL;
        delete del;
        cnt++;
    }
    Node* curr=head;
    Node* prev = NULL;
    while(curr!= NULL){
        if(curr->data == key){
            cnt++;
            Node* del = curr;
            curr = curr ->next;
            if(prev !=NULL) prev->next=curr;
            if( del == tail) tail = prev;
            delete del;
        }else{
            prev = curr;
            curr = curr -> next;
        }
    }
    return cnt;
}

void display(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;   
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtBeginning(5,head,tail);
    insertAtBeginning(4,head,tail);
    insertAtBeginning(8,head,tail);
    insertAtBeginning(9,head,tail);
    insertAtValueAfter(7,head,8);
    insertAtValueAfter(7,head,8);
    insertAtValueAfter(7,head,9);
    insertAtValueAfter(5,head,8);
    insertAtValueAfter(7,head,5);
    insertAtValueAfter(2,head,5);

    display(head);
    int cnt=countAndDelete(7,head,tail);
    cout<<"\nThe number  of occurences of 7 is : "<<cnt;
    cout<<"\nUpdated list is : \n";
    display(head);
    return 0;
}