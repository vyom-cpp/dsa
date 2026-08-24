// 26. Remove Duplicates from Sorted Array (Easy)
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.empty())    return 0;
    int i = 1;
    for(int j = 1; j < nums.size(); j++){
        if(nums[j] != nums[j-1]){
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}

int main() {
    vector<int> nums = {0, 0, 1, 1, 2, 2, 3, 4, 5};
    cout << removeDuplicates(nums) << endl;
    return 0;
}