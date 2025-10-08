// #include<iostream>
// using namespace std;

// class Node{
//     public:
//         int data;
//         Node* next;

//     Node(int d){
//         this->data = d;
//         this->next=NULL;
//     }
// };

// void insertAtBeginning(int d,Node* &head,Node* &tail){
//     Node* temp = new Node(d);
//     if(head==NULL){
//         head=temp;
//         tail=temp;
//     }else{
//         temp->next=head;
//         head=temp;  
//     }
// }

// void insertAtEnd(int d,Node* &head,Node* &tail){
//     Node* temp = new Node(d);
//     if(tail==NULL){
//         tail=temp;
//         head=temp;
//     }else{
//         tail->next=temp;
//         tail=temp;
//     }
// }

// void display(Node* &head){
//     Node* temp=head;
//     while(temp!=NULL){
//         cout<<temp->data<<"\n";
//         temp=temp->next;   
//     }
// }

// void insertAtValueAfter(int d,Node* &head,int value,Node* &tail){
//     if(head==NULL){
//         cout<<"List is empty can not insert after\n";
//         return;
//     }

//     if(tail->data == value){
//         insertAtEnd(d,head,tail);
//     }
//     Node* curr =head;
//     while (curr != NULL && curr->data!=value){
//         curr=curr->next;
//     }
//     if(curr==NULL){
//         cout<<"Value"<<value<<" not found in list.\n";
//         return;
//     } 
//     Node* temp = new Node(d);
//     temp->next=curr->next;
//     curr->next=temp;
//     // one case is missing agar tail pe value hui jiske baad insert karna hai to phir insertAtTail ko call karna hoga.
// }

// void insertAtValueBefore(int d,Node* &head,Node* &tail,int value){
//     if(head==NULL){
//         cout<<"List is empty can not insert after\n";
//         return;
//     }
//     if(head->data == value){
//         insertAtBeginning(d,head,tail);
//         return;
//     }

//     Node* curr =head;
//     while (curr->next != NULL && curr->next->data!=value){
//         curr=curr->next;
//     }
//     if(curr==NULL){
//         cout<<"Value"<<value<<" not found in list.\n";
//         return;
//     } 
//     Node* temp = new Node(d); // jab current ke next a data dekh rahe ho to curr ->next!=NULL dekhna hai baki curr!=NULL varna segmentation fault aa jayega.. :)
//     temp->next=curr->next;
//     curr->next=temp;
// }


// void deletionFromBeginning(Node* &head,Node* tail){
//     if(head==NULL){
//         cout<<"LIst is empty, nothing to delete.\n";
//     }
//     if(head==tail){
//         delete tail;
//         head=NULL;
//         tail=NULL;
//     }
//     Node* temp = head;
//     head=head->next;
//     temp-> next=NULL;
//     delete temp;
// }

// void deletionFromEnd(Node* &head,Node* &tail){
//     if(head==NULL){
//         cout<<"Nothing to delete. List is empty\n";
//     }
//     else if(head==tail){
//         delete tail;
//         head=NULL;
//         tail=NULL;
//     }
//     else {
//         Node* temp=head;
//         while(temp->next!=tail){
//             temp=temp->next;
//         }
//         temp->next=NULL;
//         delete tail;
//         tail=temp;
//     }
// }

// void deleteNodeAtValue(int value,Node* &head,Node* &tail){
//     if(head==NULL){
//         cout<<"List is empty. Nothing to delete.\n";
//     }
//     if(head==tail && head->data ==value){
//         delete tail;
//         tail=NULL;
//         head=NULL;
//         return;
//     }
//     if (head->data == value) {
//         Node* temp = head;
//         head = head->next;
//         temp->next = NULL;
//         delete temp;
//         return;
//     }

    
//         Node* curr=head;
//         while(curr->next!=NULL && curr->next->data!=value){
//             curr = curr -> next;
//         }
//         if(curr-> next == NULL){
//             cout<<"Value "<< value <<" not found in list.\n";
//             return;
//         }
//         Node* nodeToDelete = curr->next;
//         curr->next=nodeToDelete->next;

//         if(nodeToDelete == tail) {
//             tail=curr;
//         }
//         nodeToDelete->next = NULL;
//         delete nodeToDelete;
    
// }

// void searchNode(Node* &head,int value){
//     if(head==NULL){
//         cout<<"List is empty. Nothing to search.\n";
//         return;
//     }
       
//     Node* temp= head;
//     int position =1;
//     while(temp!=NULL){
//         if(temp->data == value){
//             cout<<"Position of "<<value<<" is "<< position;
//             return;
//         }
//         temp = temp -> next;
//         position++;
//     }
//     cout<<"Value not found in the list.\n";
// }

// int main(){
//     Node* head = NULL;
//     Node* tail = NULL;
//     while(1){
//         int choice;
    
//         cout<<"\n----- Menu -----\n";
//         cout<<"1.Insertion at begining\n";
//         cout<<"2.Insetion at end\n";
//         cout<<"3.Insertion in after a node having a specific value)\n";
//         cout<<"4.Insertion in before a node having a specific value)\n";
//         cout<<"5.Deletion from beginning\n";
//         cout<<"6.Deletion from end\n";
//         cout<<"7.Deletion from a specific node\n";
//         cout<<"8.Search for a node and display its position head\n";
//         cout<<"9.Display all the nodes values\n";
//         cout<<"10.Exit\n";

//         cout<<"Enter choice : ";
//         cin>>choice;
//         int value,after,before;

//         switch(choice){
//             case(1):
//                 cout<<"Enter value to insert";
//                 cin>>value;
//                 insertAtBeginning(value,head,tail);
//             break;

//             case(2):
//                 cout<<"Enter value to insert";
//                 cin>>value;
//                 insertAtEnd(value,head,tail);
//             break;

//             case(3):
//                 cout<<"Enter value to insert and after which in order";
//                 cin>>value>>after;
//                 insertAtValueAfter(value,head,after,tail);
//             break;

//             case(4):
//                 cout<<"Enter value to insert and before which in order";
//                 cin>>value>>after;
//                 insertAtValueBefore(value,head,tail,before);
//             break;

//             case(5):
//                 deletionFromBeginning(head,tail);
//             break;

//             case(6):
//                 deletionFromEnd(head,tail);
//             break;

//             case(7):
//                 cout<<"Enter value to delete : ";
//                 cin>>value;
//                 deleteNodeAtValue(value,head,tail);
//             break;

//             case(8):
//                 cout<<"Enter node valur to search : ";
//                 cin>>value;
//                 searchNode(head,value);
//             break;

//             case(9):
//                 display(head);
//             break;

//             case(10):
//                 return 0;
//             break;

//             default:
//                 cout<<"Wrong choice\n";
//             break;
//         }
//     }
// }


#include<iostream>
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

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertAtBeginning(int d) {
        Node* temp = new Node(d);
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            temp->next = head;
            head = temp;
        }
    }

    void insertAtEnd(int d) {
        Node* temp = new Node(d);
        if (tail == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "\n";
            temp = temp->next;
        }
    }

    void insertAtValueAfter(int d, int value) {
        if (head == NULL) {
            cout << "List is empty, cannot insert after\n";
            return;
        }
        if (tail->data == value) {  // if inserting after last node
            insertAtEnd(d);
            return;
        }
        Node* curr = head;
        while (curr != NULL && curr->data != value) {
            curr = curr->next;
        }
        if (curr == NULL) {
            cout << "Value " << value << " not found in list.\n";
            return;
        }
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }

    void insertAtValueBefore(int d, int value) {
        if (head == NULL) {
            cout << "List is empty, cannot insert before\n";
            return;
        }
        if (head->data == value) {
            insertAtBeginning(d);
            return;
        }
        Node* curr = head;
        while (curr->next != NULL && curr->next->data != value) {
            curr = curr->next;
        }
        if (curr->next == NULL) {
            cout << "Value " << value << " not found in list.\n";
            return;
        }
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }

    void deletionFromBeginning() {
        if (head == NULL) {
            cout << "List is empty, nothing to delete.\n";
            return;
        }
        if (head == tail) {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void deletionFromEnd() {
        if (head == NULL) {
            cout << "Nothing to delete. List is empty\n";
            return;
        } else if (head == tail) {
            delete tail;
            head = NULL;
            tail = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void deleteNodeAtValue(int value) {
        if (head == NULL) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        if (head == tail && head->data == value) {
            delete tail;
            head = NULL;
            tail = NULL;
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            return;
        }
        Node* curr = head;
        while (curr->next != NULL && curr->next->data != value) {
            curr = curr->next;
        }
        if (curr->next == NULL) {
            cout << "Value " << value << " not found in list.\n";
            return;
        }
        Node* nodeToDelete = curr->next;
        curr->next = nodeToDelete->next;
        if (nodeToDelete == tail) {
            tail = curr;
        }
        nodeToDelete->next = NULL;
        delete nodeToDelete;
    }

    void searchNode(int value) {
        if (head == NULL) {
            cout << "List is empty. Nothing to search.\n";
            return;
        }
        Node* temp = head;
        int position = 1;
        while (temp != NULL) {
            if (temp->data == value) {
                cout << "Position of " << value << " is " << position << "\n";
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "Value not found in the list.\n";
    }
};

int main() {
    LinkedList myList;
    while (1) {
        int choice;
        cout << "\n----- Menu -----\n";
        cout << "1. Insertion at beginning\n";
        cout << "2. Insertion at end\n";
        cout << "3. Insertion after a node value\n";
        cout << "4. Insertion before a node value\n";
        cout << "5. Deletion from beginning\n";
        cout << "6. Deletion from end\n";
        cout << "7. Deletion of a specific node\n";
        cout << "8. Search a node\n";
        cout << "9. Display all nodes\n";
        cout << "10. Exit\n";

        cout << "Enter choice : ";
        cin >> choice;
        int value, after, before;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                myList.insertAtBeginning(value);
                break;

            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                myList.insertAtEnd(value);
                break;

            case 3:
                cout << "Enter value to insert and after which value: ";
                cin >> value >> after;
                myList.insertAtValueAfter(value, after);
                break;

            case 4:
                cout << "Enter value to insert and before which value: ";
                cin >> value >> before;
                myList.insertAtValueBefore(value, before);
                break;

            case 5:
                myList.deletionFromBeginning();
                break;

            case 6:
                myList.deletionFromEnd();
                break;

            case 7:
                cout << "Enter value to delete: ";
                cin >> value;
                myList.deleteNodeAtValue(value);
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                myList.searchNode(value);
                break;

            case 9:
                myList.display();
                break;

            case 10:
                return 0;

            default:
                cout << "Wrong choice\n";
                break;
        }
    }
}
