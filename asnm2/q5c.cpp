//  Lower triangular Matrix.

#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter size of matrix [n*n]: ";
    cin>>n;

    int size=n*(n+1)/2;
    int arr[size];

    cout<<"Enter elements of lower triangular matrix: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int val;
            cin>>val;
            if(i>=j){
                int index=(i*(i+1))/2+j;
                arr[index]=val;
            }
        }
    }

    cout<<"Entered matrix is: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i>=j){
                int index=(i*(i+1))/2+j;
                cout<<arr[index]<<" ";
            }else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }

    return 0;

}