#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TC -> O(n) and SC -> O(1)
bool check(vector<int> &nums){
    int drop_index = 0, n = nums.size();

    for(int i = 0; i < n; i++){
        if(nums[i] > nums[i+1]){
            drop_index++;
            break;
        }
    }

    left_rotate_d_places(nums, n, drop_index);

    for (int i = 0; i < n - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            return false;
        }
    }
    return true;
}

void left_rotate_d_places(vector<int> &nums, int n, int drop_index){
    reverse(nums.begin(), nums.begin() + drop_index);
    reverse(nums.begin() + drop_index, nums.end());
    reverse(nums.begin(), nums.end());
}

// Other way with just one loop
bool checkAgain(vector<int>& nums) {
    int count = 0;
    int n = nums.size();
        
    for (int i = 0; i < n; i++) {
        // Use modulo (%) to smoothly wrap the last element back to the first element
        if (nums[i] > nums[(i + 1) % n]) {
            count++;
        }
            
        // If we find more than 1 drop, it can't be a rotated sorted array
        if (count > 1) {
            return false;
        }
    }
        
    return true;
}



int main() {
    vector<int> nums = {3, 4, 5, 1, 2};
    
    return 0;
}