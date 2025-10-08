#include <iostream>
using namespace std;

int main() {
    int r1, c1, r2, c2, n1, n2;
    cout << "Enter rows and cols of A: ";
    cin >> r1 >> c1;
    cout << "Enter rows and cols of B: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Multiplication not possible!" << endl;
        return 0;
    }

    cout << "Enter number of non-zero elements in A: ";
    cin >> n1;
    int A[100][3];
    cout << "Enter triplet (row col value):" << endl;
    for (int i = 0; i < n1; i++) cin >> A[i][0] >> A[i][1] >> A[i][2];

    cout << "Enter number of non-zero elements in B: ";
    cin >> n2;
    int B[100][3];
    cout << "Enter triplet (row col value):" << endl;
    for (int i = 0; i < n2; i++) cin >> B[i][0] >> B[i][1] >> B[i][2];


    int BT[100][3], kB = 0;
    for (int col = 0; col < c2; col++) {
        for (int i = 0; i < n2; i++) {
            if (B[i][1] == col) {
                BT[kB][0] = B[i][1];
                BT[kB][1] = B[i][0];
                BT[kB][2] = B[i][2];
                kB++;
            }
        }
    }

  
    int C[200][3], k = 0;
    for (int i = 0; i < r1; i++) {      
        for (int j = 0; j < c2; j++) {  
            int sum = 0;
            for (int x = 0; x < n1; x++) {
                if (A[x][0] == i) {
                    for (int y = 0; y < kB; y++) {
                        if (BT[y][0] == j && A[x][1] == BT[y][1]) {
                            sum += A[x][2] * BT[y][2];
                        }
                    }
                }
            }
            if (sum != 0) {
                C[k][0] = i;
                C[k][1] = j;
                C[k][2] = sum;
                k++;
            }
        }
    }

    cout << "\nResult Triplet:" << endl;
    for (int p = 0; p < k; p++) {
        cout << C[p][0] << " " << C[p][1] << " " << C[p][2] << endl;
    }

    return 0;
}
