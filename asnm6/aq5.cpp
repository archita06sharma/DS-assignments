#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node *next, *prev, *up, *down;
    Node(int val) {
        data = val;
        next = prev = up = down = NULL;
    }
};

