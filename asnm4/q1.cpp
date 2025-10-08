#include <iostream>
using namespace std;
const int MAXLEN = 100;

class Queue {
    private: 
    int element[MAXLEN];
    int front,rear;
    public:
    Queue (){
        front =rear =-1;
    }

    bool isEmpty() const {
        return (front ==-1 || front>rear);
    }
    bool isFull() const{
        return (rear == MAXLEN-1);
    }

    int size () const {
        if( isEmpty()) return 0;
        return rear-front +1;
    }
    int peek() const {
        if(isEmpty()){
            cout<<"Queue is empty.\n";
            return -1;
        }else
        return element [front];
    }
    void enqueue(int x){
        if(isFull()){
            cout<<"Overflow : cannot enqueue "<<x<<"\n";
            return ;
        }
        if(isEmpty()){
            front = rear = 0;
        }else{
            rear ++;
        }
        element[rear]=x;
        cout<<x<< " enqueued.\n";
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Underflow .. nothing to dequeue.\n";
            return ;
        }
        int removed = element[front];
        if(front == rear){
            front = rear = -1;
        }else {
            front ++;
        }
        cout<<removed<<" dequeued.\n";
    }
    void display() const {
        if(isEmpty()){
            cout<<"Queue is empty \n";
            return ;
        }
        cout<<"Queue elements (front -> rear): ";
        for(int i = front; i<=rear;i++){
            cout<<element[i];
            if(i<rear) cout<<" ";
        }
        cout<<"\n";
    }
};

int main() {
    Queue Q; 
    int choice;
    while(1) {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek (front)\n";
        cout << "4. isEmpty\n5. isFull\n6. Display\n7. Size\n8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int x;
                cout << "Enter value to enqueue: ";
                cin >> x;
                Q.enqueue(x);
                break;
            }
            case 2:
                Q.dequeue();
                break;
            case 3:
                cout << "Front element: " << Q.peek() << "\n";
                break;
            case 4:
                cout << (Q.isEmpty() ? "Queue is empty\n" : "Queue is NOT empty\n");
                break;
            case 5:
                cout << (Q.isFull() ? "Queue is full\n" : "Queue is NOT full\n");
                break;
            case 6:
                Q.display();
                break;
            case 7:
                cout << "Size: " << Q.size() << "\n";
                break;
            case 8:
                cout << "Exiting. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    } 
}