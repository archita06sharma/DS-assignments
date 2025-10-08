//3) String Anagrams
//Given two strings str1 and str2, determine if they form an anagram pair.

#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    string str1,str2;

    cout<<"Enter first string: ";
    cin>>str1;

    cout<<"Enter second string: ";
    cin>>str2;

    if(str1.length()!=str2.length()){
        cout<<"Not an anagram pair";
        return 0;
    }

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    if(str1==str2) cout<<"Anagram pair";
    else cout<<"Not an anagram pair";
    
    return 0;
}