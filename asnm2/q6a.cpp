// /*6) Write a program to implement the following operations on a Sparse Matrix, assuming the matrix is represented using a triplet.
// (a) Transpose of a matrix.*/

// #include <iostream>
// using namespace std;

// const int MAX = 100;

// void transpose(int sparse[][3], int result[][3]) {
//     int rows = sparse[0][0];
//     int cols = sparse[0][1];
//     int terms = sparse[0][2];

//     result[0][0] = cols;  
//     result[0][1] = rows;  
//     result[0][2] = terms; 

//     if (terms > 0) {
//         int k = 1;
//         for (int col = 0; col < cols; ++col) {
//             for (int i = 1; i <= terms; ++i) {
//                 if (sparse[i][1] == col) {
//                     result[k][0] = sparse[i][1];  // new row = old col
//                     result[k][1] = sparse[i][0];  // new col = old row
//                     result[k][2] = sparse[i][2];  // value unchanged
//                     k++;
//                 }
//             }
//         }
//     }
// }

// void display(int sparse[][3]) {
//     int terms = sparse[0][2];
//     cout << "Row\tCol\tValue\n";
//     for (int i = 0; i <= terms; ++i) {
//         cout << sparse[i][0] << "\t" << sparse[i][1] << "\t" << sparse[i][2] << "\n";
//     }
// }

// int main() {
//     int sparse[MAX][3];
//     int result[MAX][3];
//     int rows, cols, terms;

//     cout << "Enter number of rows, columns and non-zero elements: ";
//     cin >> rows >> cols >> terms;

//     sparse[0][0] = rows;
//     sparse[0][1] = cols;
//     sparse[0][2] = terms;

//     cout << "Enter row, column and value for each non-zero element:\n";
//     for (int i = 1; i <= terms; ++i) {
//         cin >> sparse[i][0] >> sparse[i][1] >> sparse[i][2];
//     }

//     cout << "\nOriginal Sparse Matrix (Triplet form):\n";
//     display(sparse);

//     transpose(sparse, result);

//     cout << "\nTransposed Sparse Matrix (Triplet form):\n";
//     display(result);

//     return 0;
// }

#include <iostream>
using namespace std;

int main() {
    int r, c, n;
    cout << "Enter rows, cols and number of non-zero elements: ";
    cin >> r >> c >> n;

    int mat[100][3]; 
    cout << "Enter triplet (row col value):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
    }

   
    int freq[100] = {0};
    for (int i = 0; i < n; i++) {
        freq[mat[i][1]]++;
    }

    int index[100];
    index[0] = 0;
    for (int i = 1; i < c; i++) {
        index[i] = index[i - 1] + freq[i - 1];
    }

    int trans[100][3];
    for (int i = 0; i < n; i++) {
        int col = mat[i][1];
        int pos = index[col]++;
        trans[pos][0] = mat[i][1];
        trans[pos][1] = mat[i][0];
        trans[pos][2] = mat[i][2];
    }

    cout << "\nTranspose Triplet:" << endl;
    for (int i = 0; i < n; i++) {
        cout << trans[i][0] << " " << trans[i][1] << " " << trans[i][2] << endl;
    }

    return 0;
}
