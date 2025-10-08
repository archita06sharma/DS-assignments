//upper triangular matrix

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of matrix [n*n]: ";
    cin>>n;

    int size=n*(n+1)/2;
    int arr[size];

    cout<<"Enter elements of upper triangular matrix: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            if(j>=i){
                int index=(i*(2*n-i+1))/2+(j-i);
                arr[index]=x;
            }
        }
    }

    cout<<"Entered matrix is: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>=i){
                int index=(i*(2*n-i+1))/2+(j-i);
                cout<<arr[index]<<" ";
            }else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }

    return 0;

}