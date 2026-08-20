#include <iostream>
#include <string>


bool checkPalindrome(const std::string& s, int left, int right) {

    if (left >= right) {
        return true;
    }
    

    if (s[left] != s[right]) {
        return false;
    }
    

    return checkPalindrome(s, left + 1, right - 1);
}


bool isPalindrome(const std::string& s) {
    return checkPalindrome(s, 0, s.length() - 1);
}

int main() {
    std::string test1 = "racecar";
    std::string test2 = "hello";

    std::cout << std::boolalpha;
    std::cout << test1 << " is palindrome: " << isPalindrome(test1) << std::endl;
    std::cout << test2 << " is palindrome: " << isPalindrome(test2) << std::endl;

    return 0;
}
