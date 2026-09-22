#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        temp = mover;
    }
    return head;
}

// TC => O(2n) and SC => O(n)
bool brute(Node* head){
    stack<int> st;
    Node* temp = head;
    while(temp != nullptr){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp != nullptr){
        int num = st.top();
        st.pop();
        if(num == temp->data){
            temp = temp->next;
        }
        else {
            return false;
        }
    }
    return true;
}


int main() {
    vector<int> arr1 = {1, 2, 3, 2, 3};
    Node* head1 = convertArr2LL(arr1);
    cout << brute(head1) << endl;
    return 0;
}