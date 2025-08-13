#include<iostream>
using namespace std;
int main(){
    int n1,m1;
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

    for(int i=0;i<n1;i++){
        for(int j=0;j<m1;j++){
            if(i!=j&&i<j){
                int temp;
                temp=arr1[i][j];
                arr1[i][j]=arr1[j][i];
                arr1[j][i]=temp;       
            }
        }
    }


    cout<<"The transpose matrix is : \n";
    for(int i=0;i<n1;i++){
        for(int j=0;j<m1;j++){
            cout<<arr1[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}