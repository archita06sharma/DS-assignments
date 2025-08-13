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
        int rowSum=0;
        for(int j=0;j<m1;j++){
            rowSum+=arr1[i][j];
        }
        cout<<"Sum of row "<<i+1<<" is : "<<rowSum<<"\n";
    }


    for (int j=0;j<m1;j++){
        int colSum=0;
        for(int i=0;i<n1;i++){
            colSum+=arr1[j][i];
        }
         cout<<"Sum of column "<<j+1<<" is : "<<colSum<<"\n";
    }
    return 0;
}