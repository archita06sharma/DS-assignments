//addition

#include <iostream>
using namespace std;

int main() {
    int n1, n2, r, c;
    cout << "Enter rows, cols: ";
    cin >> r >> c;

    cout << "Enter number of non-zero elements in matrix A: ";
    cin >> n1;
    int A[100][3];
    cout << "Enter triplet (row col value):" << endl;
    for (int i = 0; i < n1; i++)
        cin >> A[i][0] >> A[i][1] >> A[i][2];

    cout << "Enter number of non-zero elements in matrix B: ";
    cin >> n2;
    int B[100][3];
    cout << "Enter triplet (row col value):" << endl;
    for (int i = 0; i < n2; i++)
        cin >> B[i][0] >> B[i][1] >> B[i][2];

    int C[200][3];
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0]; C[k][1] = A[i][1]; C[k][2] = A[i][2];
            i++; k++;
        }
        else if (B[j][0] < A[i][0] || (B[j][0] == A[i][0] && B[j][1] < A[i][1])) {
            C[k][0] = B[j][0]; C[k][1] = B[j][1]; C[k][2] = B[j][2];
            j++; k++;
        }
        else {
            int sum = A[i][2] + B[j][2];
            if (sum != 0) {
                C[k][0] = A[i][0]; C[k][1] = A[i][1]; C[k][2] = sum;
                k++;
            }
            i++; j++;
        }
    }

    while (i < n1) {
        C[k][0] = A[i][0]; C[k][1] = A[i][1]; C[k][2] = A[i][2];
        i++; k++;
    }
    while (j < n2) {
        C[k][0] = B[j][0]; C[k][1] = B[j][1]; C[k][2] = B[j][2];
        j++; k++;
    }

    cout << "\nResult Triplet:" << endl;
    for (int p = 0; p < k; p++) {
        cout << C[p][0] << " " << C[p][1] << " " << C[p][2] << endl;
    }

    return 0;
}
