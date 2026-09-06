#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Nigga{
    int data;
    Nigga* next;
    Nigga* prev;

    Nigga(int data1, Nigga* next1, Nigga* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }

    Nigga(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Nigga* convertArr2Dll(vector<int> &arr){
    Nigga* head = new Nigga(arr[0]);
    Nigga* prev = head;
    for(int i = 1; i < arr.size(); i++){
        Nigga* temp = new Nigga(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Nigga* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head-> next;
    }
    cout << endl;
}

// Brute force; TC => O(n) + O(n) = O(2n) and SC => O(n)
// 1. Use Stack Data Structure and push everything inside it 
// 2. Then take it out in the LIFO fashion which is core idea of using stack
Nigga* brute(Nigga* head){
    stack<int> st;
    Nigga* temp = head;
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


// Better; Swap(next and prev) => ( current.next = last && current.prev = front)
// 1. Cannot swap data, so swap the links and move the head to the tail and vice versa
// 2. This will solve the question in single pass (wrap all of these in while loop) => (current != NULL)
//  last = current->back
//  current->back = current->next
//  current->next = last
//  current = current->back
Nigga* better(Nigga* head){
    if(head == NULL || head->next == NULL)  return head;
    Nigga* current = head;
    Nigga* last = NULL;
    while(current != NULL){
        last = current->prev;
        current->prev = current->next;
        current->next = last;
        current = current->prev;
    }
    return last->prev;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 2, 3, 4, 5};
    // Nigga* head = convertArr2Dll(arr);
    // print(head);

    Nigga* head1 = convertArr2Dll(arr1);
    head1 = brute(head1);
    print(head1);

    Nigga* head2 = convertArr2Dll(arr2);
    head2 = better(head2);
    print(head2);
    return 0;
}