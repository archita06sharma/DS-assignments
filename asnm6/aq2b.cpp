#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val) {
        data = val;
        prev = next = nullptr;
    }
};

class DoublyList {
public:
    Node* head;
    Node* tail;

    DoublyList() {
        head = tail = nullptr;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    bool evenParity(int n) {
        int count = 0;
        while (n > 0) {
            if (n % 2 == 1)
                count++;
            n /= 2;
        }
        return (count % 2 == 0);
    }

    void removeEvenParityNodes() {
        if (head == nullptr) return;

        Node* curr = head;

        while (curr != nullptr) {
            if (evenParity(curr->data)) {
                Node* toDelete = curr;

                // If node is head
                if (curr == head) {
                    head = head->next;
                    if (head != nullptr)
                        head->prev = nullptr;
                }
                // If node is tail
                else if (curr == tail) {
                    tail = tail->prev;
                    if (tail != nullptr)
                        tail->next = nullptr;
                }
                // Middle node
                else {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                }

                curr = curr->next;
                delete toDelete;
            } else {
                curr = curr->next;
            }
        }
    }

    void display() {
        Node* temp = head;
        if (!temp) {
            cout << "List is empty\n";
            return;
        }
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr)
                cout << " <=> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyList dll;
    dll.insertAtEnd(18);
    dll.insertAtEnd(15);
    dll.insertAtEnd(8);
    dll.insertAtEnd(9);
    dll.insertAtEnd(14);

    cout << "Original DLL: ";
    dll.display();

    dll.removeEvenParityNodes();

    cout << "After removal: ";
    dll.display();

    return 0;
}
