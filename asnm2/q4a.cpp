/*4) String Related Programs
(a) Write a program to concatenate one string to another string*/

#include<iostream>
using namespace std;
int main(){
    string str1, str2;

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    string result = str1 + str2; 

    cout << "Concatenated string: " << result << endl;

    return 0;
}

/*

#include <iostream>
using namespace std;

int main() {
    char str1[100], str2[50];

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    int len1 = 0;
    while (str1[len1] != '\0') {
        len1++;
    }

    int i = 0;
    while (str2[i] != '\0') {
        str1[len1] = str2[i];
        len1++;
        i++;
    }
    str1[len1] = '\0'; 

    cout << "Concatenated string: " << str1 << endl;

    return 0;
}

*/