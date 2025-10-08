//B) tri diagonal matrix

#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter size(n) of square matrix [n*n]: ";
    cin>>n;

    int size=3*n-2;
    int arr[size];
        cout<<"Enter elements of tri-diagonal matrix: "<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x;
                cin>>x;
                if(i==j) arr[i]=x;
                else if(i==j+1) arr[n+i-1]=x;
                else if(i==j-1) arr[2*n+i-1]=x;
            }
        }

    cout<<"Stored Tri-diagonal matrix: "<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)
                    cout<<arr[i]<<" ";
                else if(i==j+1)
                    cout<<arr[n+i-1]<<" ";
                else if(i==j-1)
                    cout<<arr[2*n+i-1]<<" ";
                else
                    cout<<"0 ";
            }
            cout<<endl;
        }
    return 0;
}