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

Node* getIntersectionNode(Node* headA, Node* headB) {
    if (headA == NULL || headB == NULL) return NULL;

    Node* a = headA;
    Node* b = headB;

    while (a != b) {   // searches for same address as a and b are pointers
        a = (a == NULL) ? headB : a->next;
        b = (b == NULL) ? headA : b->next;
    }
    return a;  // either intersection node OR NULL
}

int main() {
    // Shared part
    Node* intersect = new Node(8);
    intersect->next = new Node(5);

    // List A: 4 -> 1 -> 8 -> 5
    Node* headA = new Node(4);
    headA->next = new Node(1);
    headA->next->next = intersect;

    // List B: 5 -> 6 -> 1 -> 8 -> 5
    Node* headB = new Node(5);
    headB->next = new Node(6);
    headB->next->next = new Node(1);
    headB->next->next->next = intersect;

    Node* result = getIntersectionNode(headA, headB);

    if(result) {
        cout << "Intersected at " << result->data << endl;
    } else {
        cout << "No intersection\n";
    }

    return 0;
}
