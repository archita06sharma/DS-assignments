// //Write a program to delete all the vowels from the string

// #include <iostream>
// using namespace std;

// int main() {
//     char str[100], result[100];
//     int i = 0, j = 0;

//     cout << "Enter a string: ";
//     cin.getline(str, 100);

   
//     while (str[i] != '\0') {
//         if (!(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
//               str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')) {
//             result[j] = str[i];
//             j++;
//         }
//         i++;
//     }
//     result[j] = '\0';

//     cout << "String after deleting vowels: " << result;

//     return 0;
// }

#include <iostream>
using namespace std;

int main() {
    char str[100];
    int i = 0, j = 0;

    cout << "Enter a string: ";
    cin.getline(str, 100);

    while (str[i] != '\0') {
        if (!(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
              str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')) {
            str[j] = str[i];   
            j++;
        }
        i++;
    }
    str[j] = '\0';  
    cout << "String after deleting vowels: " << str;

    return 0;
}

