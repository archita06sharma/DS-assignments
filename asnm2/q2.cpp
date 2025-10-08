#include<iostream>
using namespace std;
void bubbleSort(int arr[],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        bool isSorted=true;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = false;
            }
        }
        if (isSorted) {
            break;
        }
    }
    
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[]={64,34,25,12,22,11,90};
    int n=7;
    
    cout << "Original array: ";
    printArray(arr, n);

    bubbleSort(arr, n);  

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}