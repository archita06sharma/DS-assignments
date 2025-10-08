//8.Write a program to count the total number of distinct elements in an array of length n.

// #include<iostream>
// using namespace std;

// int countDistinct(int *arr,int n){
//     int count =0;
//     for(int i=0;i<n;i++){
//         bool isDistinct= true;
//         for(int j=i+1;j<n;j++){
//             if(arr[i]==arr[j]){
//                 isDistinct = false;
//                 break;
//             }
//         }
//         if(isDistinct){
//             count++;
//         }
//     }
//     return count; 
// }

// int main(){
//     int n ;
//     cout<<"Enter size of array: ";
//     cin>>n;

//     int arr[n];
//     cout<<"Enter elements: ";
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }

//     int result = countDistinct(arr,n);
//     cout<<"Total distinct elements "<<result<<endl;

//     return 0;
// }

#include <iostream>
#include <algorithm> 
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int A[100];
    cout << "Enter array: ";
    for (int i = 0; i < n; i++) cin >> A[i];

    sort(A, A + n);

    int count = 1; 
    for (int i = 1; i < n; i++) {
        if (A[i] != A[i - 1]) count++;
    }

    cout << "Total distinct elements = " << count << endl;

    return 0;
}
