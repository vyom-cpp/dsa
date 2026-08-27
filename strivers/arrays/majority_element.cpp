#include <iostream>
#include <vector>
#include <map>
using namespace std;

// brute; TC => O(n^2) and SC => O(1)
vector<int> brute_majority(vector<int> arr){
    int n = arr.size();
    for(int i = 0; i < arr.size(); i++){
        int count = 0;
        for(int j = 0; j < arr.size(); j++){
            if(arr[j] == arr[i])    count++;
        }
        if(count > n/2)     return {arr[i]};
    }
    return {-1};
}

// better;
vector<int> better_majority(vector<int> arr){
    map<int, int> mpp;
    int n = arr.size();

    // store nd update the frequency
    // ordered map; TC => O(nlogn) and SC => O(n)
    // unordered map; TC => O(n) in WC, TC => O(n^2) and SC = O(n)
    for(int i = 0; i < arr.size(); i++){
        mpp[arr[i]]++;
    }

    for(auto it : mpp){
        if(it.second > n / 2)   return {it.first};
    }
    return {-1};
}

// optimal; Moore's Voting Algo
// TC => O(n) if the problem states that the majority elements exists nd if the majority element does not exist then the TC => O(n) + O(n)
// SC => O(1) 
vector<int> optimal_majority(vector<int> arr){
    int ct = 0, el;
    for(int i = 0; i < arr.size(); i++){
        if(ct == 0){
            ct = 1;
            el = arr[i];
        } else if(arr[i] == el){
            ct++;
        } else {
            ct--;
        }
    }

    int ct2 = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == el){
            ct2++;
        }
    }

    if(ct2 > (arr.size() / 2))  return {el};
    return {-1};
}

int main() {
    vector<int> arr = {2, 2, 3, 3, 1, 2, 2};
    vector<int> result1 = brute_majority(arr);
    vector<int> result2 = better_majority(arr);
    vector<int> result3 = optimal_majority(arr);

    for(int itr : result1){
        cout << itr << " ";
    }
    cout << endl;


    for(int itr : result2){
        cout << itr << " ";
    }
    cout << endl;


    for(int itr : result3){
        cout << itr << " ";
    }
    cout << endl;
    return 0;
}