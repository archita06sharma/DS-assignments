#include <iostream>
using namespace std;

void duplicateTwos(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 2) count++;
    }

    int newLength = n + count;
    
    for (int i = n - 1, j = newLength - 1; i >= 0; i--, j--) {
        if (arr[i] == 2) {
            if (j < n) arr[j] = 2; 
            j--;                     
            if (j < n) arr[j] = 2;  
        } else {
            if (j < n) arr[j] = arr[i]; 
        }
    }
    
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];  
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    duplicateTwos(arr, n);

    cout << "Modified array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
