#include <iostream>
#include <stack>
#include <vector>
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
        mover = temp;
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// TC => O(2n); SC=> O(n)
Node* brute(Node* head){
    Node* temp = head;
    stack<int> st;
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

// TC => O(n) and SC => O(1)
Node* optimal(Node* head){
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

// TC => O(n) and SC => O(n) because of recursive stack
Node* recursive_reverse_LL(Node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    Node* newHead = recursive_reverse_LL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    Node* head1 = convertArr2LL(arr1);
    head1 = brute(head1);
    print(head1);

    vector<int> arr2 = {1, 2, 3, 4, 5};
    Node* head2 = convertArr2LL(arr2);
    head2 = optimal(head2);
    print(head2);

    vector<int> arr3 = {1, 2, 3, 4, 5};
    Node* head3 = convertArr2LL(arr3);
    head3 = recursive_reverse_LL(head3);
    print(head3);
    return 0;
}