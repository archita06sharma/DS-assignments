#include<iostream>
using namespace std;

int create(int arr[],int n){
    int size;
    cout<<"Enter size of arr : ";
    cin>>size;
    if(size>n) {cout<<"Space limit exceeded\n";return 0;}
    for(int i=0;i<size;i++){
        cout<<"Enter array element at index "<<i<<" : \n";
        cin>>arr[i];
    }
    return size;
}

void display(int arr[],int size){
    if (size==0) {cout<<"Array is empty\n";return;}
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int insert(int arr[],int size){
    int position,value;
    cout<<"Which place you want to insert (0 to "<<size<<") : ";
    cin>>position;
    if(position>size||position<0) {cout<<"Wrong index\n";return size;}
    cout<<"Enter value to be inserted : ";
    cin>>value;
    for(int i=size;i>position;i--) arr[i]=arr[i-1];
    arr[position]=value;
    size++;
    return size;
}

int del(int arr[],int size){
    int position;
    cout<<"Enter position to be deleted: (0 to "<<size-1<<") : ";
    cin>>position;
    if (position<0||position>size-1) {cout<<"Wrong index\n";return size;}
    for(int i=position;i<size;i++){
        arr[i]=arr[i+1];
    }
    size--;
    return size;
}

int linearSearch(int arr[],int size){
    int value;
    cout<<"Enter the element to be found : ";
    cin>>value;
    if(size==0) {cout<<"Array is empty.";return -1;}
    for(int i=0;i<size;i++){
        if (arr[i]==value) return i;
    }
    return -1;
}

int main(){
    int arr[100];
    int size=0,index;
    while(1){
        cout<<"---MENU---\n";
        cout<<"1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT ";
        cout<<"\nEnter choice : ";
        int choice;
        cin>>choice;
        switch(choice){
            case 1: size=create(arr,100); 
            break;

            case 2: display(arr,size);
            break;

            case 3: size=insert(arr,size);
            break;

            case 4: size= del(arr,size);
            break;

            case 5: index= linearSearch(arr,size);
            cout<<"Index of the element : "<<index<<"\n";
            break;

            case 6: return 0;

            default: cout<<"Entered choice is wrong.\n";
        }
    }
}