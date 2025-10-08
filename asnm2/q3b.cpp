//binary search

#include <iostream>
using namespace std;

int findMissing(int arr[], int n) {
    int left = 0, right = n - 2;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == mid + 1) {
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return left + 1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8};
    int n = 8; 
    cout << "Missing number: " << findMissing(arr, n);
    return 0;
}
