//symmetric matrix

#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter size of matrix [n*n]: ";
    cin>>n;

    int size=n*(n+1)/2;
    int arr[size];

    cout<<"Enter elements of symmetric triangular matrix: \n";
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
            int index;
            if(i>=j){
                index=(i*(i+1))/2+j;
            }else{
                index=(j*(j+1))/2+i;
            }
            cout<<arr[index]<< " ";
        }
        cout<<endl;
    }

    return 0;

}