#include <iostream>
using namespace std;

void change_value_a(int *x){ // Pass by reference using pointers (one way, another is  alias -> (int &x, b = 20))
    *x = 20;
}

void change_value_b(int &x){ // Passing by alias
    x = 40;
}

int main()
{
    int a = 10, b = 10, c = 10;
    int arr[] = {1, 2, 3, 4, 5};
    int *address_of_a = &a;
    int **ptr = &address_of_a;
    cout << &a << endl; // 0x7ffc2110077c => 140720863184764
    cout << &b << endl; // 0x7ffc21100780 => 140720863184768
    cout << &c << endl; // 0x7ffc21100784 => 140720863184772
    cout << address_of_a << endl; // 0x7ffc2110077c => 140720863184764 (Same as first)
    cout << &address_of_a << endl; // // 0x7ffceef03ee0 => 140724317208288 (Address of pointer to a)

    change_value_a(&a);
    cout << a << endl;

    change_value_b(b);
    cout << b << endl;

    cout << arr << endl; // address of arr[0]
    cout << *arr << endl;
    cout << (arr + 3) << endl;
    cout << *(arr + 3) << endl; // address ofarr[3]
    return 0;
}