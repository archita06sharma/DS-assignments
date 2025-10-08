//Given an array of n-1 distinct integers in the range of 1 to n, find the missing number in it in a Sorted Array
//(a) Linear time

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8};
    int n = 8; 
    int missing = -1;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            missing = i + 1;
            break;
        }
    }

    if (missing == -1)
        missing = n;

    cout << "Missing number : " << missing;
    return 0;
}
