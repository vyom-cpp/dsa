#include <iostream>
using namespace std;

class Solution { 
public: 
    bool isAlphaNumeric(char ch){ 
        if((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')){ 
            return true; 
        } 
        return false; 
    } 
    
    bool isPalindrome(string s) { 
        int start = 0, end = s.length() - 1; 
        while(start < end){ 
            if(!isAlphaNumeric(s[start])){ 
                start++; 
                continue; 
            } 
            if(!isAlphaNumeric(s[end])){ 
                end--; 
                continue; 
            } 
            if(tolower(s[start]) != tolower(s[end])){ 
                return false; 
            } 
            start++; 
            end--; 
        } 
        return true; 
    } 
};

int main() {
    Solution solver;

    string test1 = "A man, a plan, a canal: Panama";
    cout << "Test 1: \"" << test1 << "\"\n";
    cout << "Result: " << (solver.isPalindrome(test1) ? "True" : "False") << "\n\n";

    // Test Case 2: Not a palindrome
    string test2 = "race a car";
    cout << "Test 2: \"" << test2 << "\"\n";
    cout << "Result: " << (solver.isPalindrome(test2) ? "True" : "False") << "\n\n";

    // Test Case 3: Empty string / symbols only
    string test3 = " ";
    cout << "Test 3: \"" << test3 << "\"\n";
    cout << "Result: " << (solver.isPalindrome(test3) ? "True" : "False") << "\n\n";

    // Custom User Input
    string userInput;
    cout << "Enter your own string to check: ";
    getline(cin, userInput); 
    
    if (solver.isPalindrome(userInput)) {
        cout << "Your string is a palindrome!\n";
    } else {
        cout << "Your string is NOT a palindrome.\n";
    }

    return 0;
}