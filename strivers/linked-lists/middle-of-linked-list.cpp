// incase of even linked list, let's say 6 elements, middle ones will be element at position 3 and position 4; so you have to return element at position 4 not 3.
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
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

// TC => O(n + n/2) and SC => O(1) 
int brute(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }

    temp = head;
    int midNode = (count / 2) + 1;

    while(temp != nullptr){
        midNode--;
        if(midNode == 0)    break;
        temp = temp->next;
    }
    return temp->data;
}

// tortoise and hare method; fast and slow pointers
// TC => O(n/2) and SC => O(1)
int optimal(Node* head){
    Node* fast = head;
    Node* slow = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5, 6};
    Node* head1 = convertArr2LL(arr1);
    // head1 = brute(head1);
    // print(head1);
    cout << optimal(head1) << endl;
    return 0;
}