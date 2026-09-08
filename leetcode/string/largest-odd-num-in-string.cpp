// 1903. Largest Odd Number in String
#include <iostream>
#include <string>

using namespace std;

string largestOddNumber(string num) {
    for (int i = num.length() - 1; i >= 0; --i) {
        if ((num[i] - '0') % 2 != 0) {
            return num.substr(0, i + 1);
        }
    }
    return "";
}

int main() {
    string num1 = "52";
    string num2 = "4206";
    string num3 = "35427";

    cout << "Input: " << num1 << " -> Output: \"" << largestOddNumber(num1) << "\"" << endl;
    cout << "Input: " << num2 << " -> Output: \"" << largestOddNumber(num2) << "\"" << endl;
    cout << "Input: " << num3 << " -> Output: \"" << largestOddNumber(num3) << "\"" << endl;

    return 0;
}
