# Declaration

- `#include <vector>`
- `vector<int> vec;` <!-- size not specified, so it is zero  -->
- `vector<int> vec = {1, 2, 3};`
- `vector<int> vec = (3, 0);` <!-- (3,0) means (size, value) It will make a vector of size 3 and all the values will be zeroes -->

# Vector Functions

- size
- push_back
- pop_back
- front
- back
- at

# Imp

````vector<int> nums;

    nums.push_back(10);
    nums.push_back(20);
    nums.push_back(30);

    cout << "Elements: ";
    for (int x : nums)          // This x iss not for indexing, this is for each loop value and the type of vector specified above and iterator i should be same, in this case it is <char>
    {
        cout << x << " ";
    }

    // Constant extra space means only one variable should be taken and linear complexity means only one loop is allowed
````
