#include<bits/stdc++.h>
using namespace std;

class HeapSort{
    public:
    void heapifyMax(vector<int> & arr,int n,int i){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        
        if(left<n && arr[left]>arr[largest]){
            largest=left;
        }
        if(right<n && arr[right]>arr[largest]){
            largest=right;
        }

        if(largest!=i){
            swap(arr[i],arr[largest]);
            heapifyMax(arr,n,largest);
        }

    }

     // Heapify for Min-Heap
    void heapifyMin(vector<int> &arr, int n, int i) {
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < n && arr[left] < arr[smallest])
            smallest = left;

        if (right < n && arr[right] < arr[smallest])
            smallest = right;

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapifyMin(arr, n, smallest);
        }
    }

    // Heapsort → Increasing Order (Max Heap)
    void heapSortIncreasing(vector<int> &arr) {
        int n = arr.size();

        // Build Max Heap
        for (int i = n/2 - 1; i >= 0; i--)
            heapifyMax(arr, n, i);

        // Extract elements
        for (int i = n - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            heapifyMax(arr, i, 0);
        }
    }

    // Heapsort → Decreasing Order (Min Heap)
    void heapSortDecreasing(vector<int> &arr) {
        int n = arr.size();

        // Build Min Heap
        for (int i = n/2 - 1; i >= 0; i--)
            heapifyMin(arr, n, i);

        // Extract elements
        for (int i = n - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            heapifyMin(arr, i, 0);
        }
    }

};

int main(){
    vector<int> arr={10,3,15,7,8,23,98,29};

    HeapSort hs;

    // Copy array for both sorts
    vector<int> inc = arr;
    vector<int> dec = arr;

    hs.heapSortIncreasing(inc);
    hs.heapSortDecreasing(dec);
    
    cout << "Increasing order: ";
    for (int x : inc) cout << x << " ";
    cout << endl;

    cout << "Decreasing order: ";
    for (int x : dec) cout << x << " ";
    cout << endl;

    return 0;
}

