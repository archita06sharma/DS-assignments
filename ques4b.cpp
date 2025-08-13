#include<iostream>
using namespace std;
int main(){
    int n1,m1,n2,m2;
    cout<<"Enter no. of rows of matrix: ";
    cin>>n1;
    cout<<"Enter no. of columns of matrix: ";
    cin>>m1;
    int arr1[n1][m1];
    cout<<"Enter elements of matrix: \n";
    for(int i=0;i<n1;i++){
        for(int j=0;j<m1;j++){
            cin>>arr1[i][j];
        }
    }

    cout<<"Enter no. of rows of matrix 2: ";
    cin>>n2;
    cout<<"Enter no. of columns of matrix 2: ";
    cin>>m2;
    int arr2[n2][m2];
    cout<<"Enter elements of matrix:\n";
    for(int i=0;i<n2;i++){
        for(int j=0;j<m2;j++){
            cin>>arr2[i][j];
        }
    }

    int arr[n1][m2];
    if(m1!=n2){
        cout<<"Multiplication not possible.";
    }else{
        for(int i=0;i<n1;i++){
            for(int j=0;j<m2;j++){
                arr[i][j]=0;
                for(int k=0;k<m1;k++){
                    arr[i][j]+=arr1[i][k]*arr2[k][j];
                }
            }
            
        }
    }

    cout<<"array after multiplication\n";
    
    for(int i=0;i<n1;i++){
        for(int j=0;j<m2;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
