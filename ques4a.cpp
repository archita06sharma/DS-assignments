#include<iostream>
using namespace std;
int main(){
    int size;
    cout<<"Enter size of array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter array elements : ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"The original array is : ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    for(int i=0 ,j=size-1; i<j; i++,j--){
        int temp;
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }

    cout<<"\nThe reversed array is : ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}