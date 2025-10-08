#include<iostream>
using namespace std;
int binarySearch(int arr[],int n,int key){
    int start,mid,end;
    start=0;end=n-1;
    while(start<=end){
        mid=(start+end)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
        else if(arr[mid]<key){
            start=mid+1;
        }
        else 
            return -1;
    }
}

int main(){
    int arr[]={1,3,6,8,22,45,78,100};
    int key,index,n;
    n=8;
    cout<<"Enter the element to be found: ";
    cin>>key;
    index=binarySearch(arr,n,key);
    cout<<"The index at which element is found is : "<<index;
    return 0;
}