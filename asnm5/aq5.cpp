#include <iostream>
using namespace std;

class Node {
public:
    int coeff, pow;
    Node* next;
    Node(int c, int p) {
        coeff = c;
        pow = p;
        next = NULL;
    }
};

void insert(Node*& head, int c, int p) {
    Node* temp = new Node(c, p);
    if (!head) head = temp;
    else {
        Node* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = temp;
    }
}

Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* tail = NULL;

    while (poly1 && poly2) {
        if (poly1->pow == poly2->pow) {
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0) { // avoid zero terms
                insert(result, sumCoeff, poly1->pow);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->pow > poly2->pow) {
            insert(result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        }
        else {
            insert(result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }
    }

    while (poly1) {
        insert(result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }
    while (poly2) {
        insert(result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return result;
}

void display(Node* head) {
    while (head) {
        cout << "[" << head->coeff << "," << head->pow << "]";
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    insert(poly1, 5, 2);
    insert(poly1, 4, 1);
    insert(poly1, 2, 0);

    insert(poly2, 5, 1);
    insert(poly2, 5, 0);

    cout << "Poly1: "; display(poly1);
    cout << "Poly2: "; display(poly2);

    Node* result = addPolynomials(poly1, poly2);

    cout << "Result: "; display(result);
    return 0;
}
