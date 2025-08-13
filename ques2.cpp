#include<iostream>
using namespace std;

int del(int arr[],int n,int j ){
    for(int i=j;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;
    return n;
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];

    cout<<"Enter elements : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                n= del (arr,n,j);
                j--;  //imp line !! agar j-- nahi karte then if there are 3 consecutive same number 2 will be there. 
            }
        }
    }


    cout<<"\nArray after deletion\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}