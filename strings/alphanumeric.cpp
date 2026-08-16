#include <iostream>
#include <cctype> // Required header

int main() {
    char ch1 = '9';
    char ch2 = 'a';
    char ch3 = '$';

    // std::isalnum returns a non-zero value (true) if alphanumeric, 0 (false) otherwise
    if (std::isalnum(ch1)) std::cout << ch1 << " is alphanumeric\n";
    if (std::isalnum(ch2)) std::cout << ch2 << " is alphanumeric\n";
    if (!std::isalnum(ch3)) std::cout << ch3 << " is NOT alphanumeric\n";

    return 0;
}
