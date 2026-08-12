#include <iostream>
#include <vector>

using namespace std;

// void sortColors(vector<int> & nums){
//     int n = nums.size();
//     int count0 = 0, count1 = 0, count2 = 0;
//     for(int i = 0; i < n; i++){
//         if(nums[i] == 0) count0++;
//         else if(nums[i] == 1) count1++;
//         else if(nums[i] == 2) count2++;
//     }

//     int index = 0;
//     for(int i = 0; i < count0; i++){
//         nums[index++] = 0;
//     }
//     for(int i = 0; i < count1; i++){
//         nums[index++] = 1;
//     }
//     for(int i = 0; i < count2; i++){
//         nums[index++] = 2;
//     }    
// }

// this is the most optimized approach, dnf algorithm (dutch national flag)
void sortColors(vector<int> &nums){
    int low = 0, mid = 0, n = nums.size(), high = n - 1;
    while(mid <= high){
        if(nums[mid] == 0){
        swap(nums[low], nums[mid]);
        low++;
        mid++;
    } else if(nums[mid] == 1){
        mid++;
    } else {
        swap(nums[high], nums[mid]);
        high--;
    }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);

    // Added: Print the sorted array to verify it works
    for(int num : nums) {
        cout << num << " ";
    }
    cout << "\n";


    // Dutch national flag algorithms - an optimize approach using loop just once using the for loop just once in a single pass with constant space complexity
    return 0;
}
