#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> three_sum_brute(vector<int> nums){
    // first make a set to store the unique triplets only
    set<vector<int>> ans;
    for(int i = 0; i < nums.size(); i++){
        int num1 = nums[i];
        for(int j = i + 1; j < nums.size(); j++){
            int num2 = nums[j];
            for(int k = j + 1; k < nums.size(); k++){
                int num3 = nums[k];
                // this thing is not returing the unique triplet? think about the solution
                if(num1 + num2 + num3 == 0){
                    vector<int> triplet = {num1, num2, num3};
                    // sorting is required before inserting in the set, else it won't be able to identify the duplicates properly
                    sort(triplet.begin(), triplet.end());
                    ans.insert(triplet);
                }
            }
        }
    }
    return vector<vector<int>>(ans.begin(), ans.end());
}

// TC => O(n^2 * logM); M is the number of triplets
// SC => O(n) * O(no. of triplets) * 2;
vector<vector<int>> three_sum_better(vector<int> nums){
    set<vector<int>> st;
    for(int i = 0; i < nums.size(); i++){
        set<int> hashset;
        for(int j = i + 1; j < nums.size(); j++){
            int third = -(nums[i] + nums[j]);
            if(hashset.find(third) != hashset.end()){
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                // store the sorted temp in the set of list st.
                st.insert(temp);
            }
            // insert all the middle elements between i and j to the hashset and reinitialize the hashset everytime i and j changes
            hashset.insert(nums[j]);
        }
    }
    return vector<vector<int>>(st.begin(), st.end());
}

// TC => O(nlogn) + O(n^2)
// SC => O(no. of triplets)
vector<vector<int>> three_sum_optimal(vector<int> nums){
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++){
        if(i > 0 && nums[i] == nums[i-1])   continue;
        int j = i + 1, k = nums.size() - 1;
        while(j < k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0){
                j++;
            } else if (sum > 0){
                k--;
            } else {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j < k && nums[j] == nums[j - 1])  j++;
                while(j < k && nums[k] == nums[k + 1])  k--;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res1 = three_sum_brute(nums);
    vector<vector<int>> res2 = three_sum_better(nums);
    vector<vector<int>> res3 = three_sum_optimal(nums);
    for(const auto& ii : res1){
        for(int jj : ii){
            cout << jj << " ";
        }
        cout << "\n";
    }
    cout << endl;

    for(const auto& ii : res2){
        for(int jj : ii){
            cout << jj << " ";
        }
        cout << "\n";
    }
    cout << endl;

    for(const auto& ii : res2){
        for(int jj : ii){
            cout << jj << " ";
        }
        cout << "\n";
    }
    return 0;
}