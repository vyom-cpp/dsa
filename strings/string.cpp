#include <iostream>
using namespace std;

int main() {
    char str[100]; // cannot be resized
    string stt = "vyom sutariya"; // dynamic => runtime resize

    cout << "Enter character array: ";
    cin.getline(str, 100, '@'); // Here @ is a delimiter, means string will stop taking input when @ appears
    cout << "Output: " << str << endl;  
    return 0;
}