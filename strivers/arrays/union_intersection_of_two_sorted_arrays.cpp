#include <iostream>
#include <set>
#include <vector>
using namespace std;

// brute
vector<int> union_calc(vector<int> a, vector<int> b){
    int n1 = a.size();
    int n2 = b.size();
    set<int> st;
    for(int i = 0; i < n1; i++){
        st.insert(a[i]);
    }
    for(int i = 0; i < n2; i++){
        st.insert(b[i]);
    }
    vector<int> temp;
    for(auto it : st){
        temp.push_back(it);
    }
    return temp;
}

// optimal
vector<int> union_calc_optimal(vector<int> a, vector<int> b){
    int n1 = a.size(), n2 = b.size(), i = 0, j = 0;
    vector<int> unionArr;
    while(i < n1 && j < n2){
        if(a[i] <= b[j]){
            if(unionArr.size() == 0 || unionArr.back() != a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
        }

        else {
            if(unionArr.size() == 0 || unionArr.back() != b[j]){
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }

    while(i < n1){
        if(unionArr.size() == 0 || unionArr.back() != a[i]){
            unionArr.push_back(a[i]);
        }
        i++;
    }

    while(j < n2){
        if(unionArr.size() == 0 || unionArr.back() != b[j]){
            unionArr.push_back(b[j]);
        }
        j++;
    }
    return unionArr;
}

// brute
vector<int> intersection_calc(vector<int> a, vector<int> b, int m, int n){
    vector<int> ans;
    vector<int> vis(m, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i] == b[j] && vis[j] == 0){
                ans.push_back(a[i]);
                vis[j] = 1;
                break;
            }
            if(b[j] > a[i])     break;
        }  
    }
    return ans;
}


// optimal
vector<int> intersection_calc(vector<int> a, vector<int> b, int m, int n){
    int i = 0, j = 0;
    vector<int> ans;
    while(i < n && j < m){
        if(a[i] < b[j]){
            i++;
        }
        else if(b[j] < a[i]){
            j++;
        }
        else{
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main() {
    
    return 0;
}