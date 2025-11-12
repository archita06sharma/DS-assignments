// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* prev;
//     Node* next;

//     Node(int val) {
//         data = val;
//         prev = next = nullptr;
//     }
// };

// class DoublyList {
// public:
//     Node* head;
//     DoublyList() { head = nullptr; }

//     void insertAtEnd(int val) {
//         Node* newNode = new Node(val);
//         if (!head) {
//             head = newNode;
//             return;
//         }
//         Node* temp = head;
//         while (temp->next)
//             temp = temp->next;
//         temp->next = newNode;
//         newNode->prev = temp;
//     }

//     void correctWrongPointer() {
//         if (!head) return;

//         Node* temp = head;
//         while (temp) {
            
//             if (temp->next && temp->next->prev != temp) {
//                 temp->next->prev = temp;
//             }
//             if (temp->prev && temp->prev->next != temp) {
//                 temp->prev->next = temp;
//             }
//             temp = temp->next;
//         }
//     }

//     void display() {
//         Node* temp = head;
//         while (temp) {
//             cout << temp->data;
//             if (temp->next) cout << " <=> ";
//             temp = temp->next;
//         }
//         cout << endl;
//     }
// };

// int main() {
//     DoublyList dll;

//     Node* n1 = new Node(1);
//     Node* n2 = new Node(2);
//     Node* n3 = new Node(3);

//     n1->next = n2;
//     n2->prev = n1;
//     n2->next = n1; 
//     n3->prev = n2;

//     dll.head = n1;

//     // cout << "Before correction: " << endl;
//     // dll.display(); 

//     dll.correctWrongPointer();

//     cout << "After correction: " << endl;
//     dll.display();

//     return 0;
// }
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int v) : data(v), prev(nullptr), next(nullptr) {}
};

// Safe display: prints nodes reachable from head
void safe_display(Node* head) {
    Node* cur = head;
    int idx = 0;
    cout << "Forward traversal: ";
    while (cur) {
        cout << cur->data;
        if (cur->next) cout << " <=> ";
        cur = cur->next;
        idx++;
        if (idx > 100) { // safety against infinite loops
            cout << " ... stopped to avoid infinite loop!\n";
            break;
        }
    }
    cout << "\n";
}

// Fix prev pointers according to next pointers
void correct_links(Node* head) {
    Node* prev = nullptr;
    Node* cur = head;
    while (cur) {
        cur->prev = prev;  // correct prev pointer
        prev = cur;
        cur = cur->next;
    }
}

int main() {
    // Build test case with broken links
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    // Broken links
    n1->next = n2;
    n2->prev = n1;
    n2->next = n1;   // wrong link creating a cycle
    n3->prev = n2;   // isolated
    // n3->next is nullptr

    Node* head = n1;

    cout << "Before correction:\n";
    safe_display(head);

    // Fix links
    correct_links(head);

    cout << "After correction:\n";
    safe_display(head);

    return 0;
}
