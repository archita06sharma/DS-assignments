//Write a program to reverse a string.

#include <iostream>
using namespace std;

int main() {
    char str[100], rev[100];
    int i = 0, j = 0, len = 0;

    cout << "Enter a string: ";
    cin.getline(str, 100); 

    while (str[len] != '\0') {
        len++;
    }

    j = len - 1;
    for (i = 0; i < len; i++) {
        rev[i] = str[j];
        j--;
    }
    rev[i] = '\0'; 

    cout << "Reversed string: " << rev;

    return 0;
}
