// 7) Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an inversion if these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to count the number of inversions in an array

#include <iostream>
using namespace std;

int mergeAndCount(int A[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[100], R[100];
    for (int i = 0; i < n1; i++) L[i] = A[left + i];
    for (int j = 0; j < n2; j++) R[j] = A[mid + 1 + j];

    int i = 0, j = 0, k = left, invCount = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        } else {
            A[k++] = R[j++];
            invCount += (n1 - i); 
          
        }
    }
    while (i < n1) A[k++] = L[i++];
    while (j < n2) A[k++] = R[j++];

    return invCount;
}

int mergeSortAndCount(int A[], int left, int right) {
    int invCount = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        invCount += mergeSortAndCount(A, left, mid);
        invCount += mergeSortAndCount(A, mid + 1, right);
        invCount += mergeAndCount(A, left, mid, right);
    }
    return invCount;
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int A[100];
    cout << "Enter array: ";
    for (int i = 0; i < n; i++) cin >> A[i];

    int ans = mergeSortAndCount(A, 0, n - 1);
    cout << "Number of inversions = " << ans << endl;

    return 0;
}

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout << "Enter size of array: ";
//     cin >> n;

//     int A[100];   // assuming max 100 for simplicity
//     cout << "Enter elements:\n";
//     for (int i = 0; i < n; i++) {
//         cin >> A[i];
//     }

//     int count = 0;
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (A[i] > A[j]) {
//                 count++;
//             }
//         }
//     }

//     cout << "Number of inversions = " << count << endl;
//     return 0;
// }
