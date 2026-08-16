#include <iostream>
#include <string>
#include <algorithm> // Required for std::reverse

using namespace std;

bool isPalindrome(string str) {
    string reversed_str = str; 
    reverse(reversed_str.begin(), reversed_str.end());
    
    return str == reversed_str;
}

int main() {
    string str = "race car";
    
    if (isPalindrome(str)) {
        cout << str << " is a palindrome." << endl;
    } else {
        cout << str << " is NOT a palindrome." << endl;
    }
    
    return 0;
}
