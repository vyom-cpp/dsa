#include <iostream>
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

// TC => O(length) + O(length - k); Worst Case => O(2 * length) when k = 1
// SC => O(1)
Node* brute(Node* head, int k){
    int count = 1;
    Node* temp = head;
    while(temp->next != nullptr){
        count++;
        temp = temp->next;
    }

    if(k == 0){
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    int res = count - k;  // found the index from where I want to delete the node
    temp = head;
    while(temp != nullptr){
        res--;
        if(res == 0)    break;
        temp = temp->next;
    }
    Node* dltNode = temp->next;     // this is the nth node from end that is to be deleted
    temp->next = temp->next->next;
    delete dltNode;
    return head;
    // while(temp != nullptr){
    //     ct++;
    //     if(ct == count){

    //     }
    // }
}

// k = 2
// Take a fast pointer pointing head; and move two steps ahead; for example from 1 to move to 3
// Now take a slow pointer pointing head; and move both fast and slow pointer simultaneously two more steps, the moment you reach next == NULL with fast pointer, stop, the slow pointer will be at the previous node that is to be deleted
Node* optimal(Node* head, int k){
    Node* fast = head;
    Node* slow = head;
    while(k != 0){
        fast = fast->next;
        k--;
    }

    while(fast->next != nullptr){   // here I put it as (fast != nullptr) in while condition and the output was 1, 2, 3, 4, 5
        slow = slow->next;
        fast = fast->next;
    }
    Node* dltNode = slow->next;
    slow->next = slow->next->next;
    delete dltNode;
    return head;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5, 6}; 
    int k;
    cin >> k;  
    Node* head1 = convertArr2LL(arr1);
    head1 = brute(head1, k);
    print(head1); 

    vector<int> arr2 = {1, 2, 3, 4, 5, 6}; 
    Node* head2 = convertArr2LL(arr2);
    head2 = optimal(head2, k);
    print(head2); 
    return 0;
}