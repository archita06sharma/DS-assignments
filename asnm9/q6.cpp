#include<bits/stdc++.h>
using namespace std;

class PriorityQueue{
    public:
    vector<int> heap;  //max=heap

    //return index of parent ,left child, right child
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }

    //Insert element in priority queue 
    void push(int val){
        heap.push_back(val);
        int i=heap.size()-1;

        //Fix max=heap property (heapify up)
        while(i!=0 && heap[parent(i)]<heap[i]){
            swap(heap[i],heap[parent(i)]);
            i=parent(i);
        }
    }

    //return highest priority element(max element)
    int top(){
        if(heap.empty()) return -1;
        return heap[0];
    }

    //remove highest priority element
    void pop(){
        int n=heap.size();
        if(n==0) return ;

        heap[0]=heap[n-1];
        heap.pop_back();

        heapifyDown(0);
    }

    //heapify down
    void heapifyDown(int i){
        int largest=i;
        int l=left(i);
        int r=right(i);
        if (l < heap.size() && heap[l] > heap[largest])
            largest = l;

        if (r < heap.size() && heap[r] > heap[largest])
            largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    //check if empty
    bool empty(){
        return heap.empty();
    }

};

int main(){
    PriorityQueue pq;
    pq.push(30);
    pq.push(10);
    pq.push(40);
    pq.push(5);
    pq.push(50);

    cout<<"Priority Queue (Max-Heap):\n";

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    return 0;
}