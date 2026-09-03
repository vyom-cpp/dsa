#include <iostream>
#include <vector>
using namespace std;

struct Node{
    public: // control who can read or modify the variables and functions inside an object.
    int data;
    Node* next;

    public:
    // below is the constructor; special function used to create and initialize a new Node object in memory; not necessary to define always but Omitting a constructor leaves uninitialized variables with random memory garbage which results to segmentation faults
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr; 
    }
};

// professional way to initialize it; above written thing is same as thiss
// Node(int data1, Node* next1) : data(data1), next(next1) {
//     // Leave the body empty!
// }

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

int lengthOfLL(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp != nullptr){
        temp = temp->next; 
        count++;
    }
    return count;
}

int search_in_ll(Node* head, int val){
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == val)   return 1;
        temp = temp->next;
    }
    return 0;
}

int main() {
    vector<int> arr = {10, 1, 2, 3, 4};
    // Node *y = new Node(arr[0], nullptr);
    // cout << y << endl;

    Node* head = convertArr2LL(arr);
    Node* temp = head;
    // cout << head->data << endl;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next; 
    }
    cout << endl;
    cout << lengthOfLL(head) << endl;
    cout << search_in_ll(head, 10) << endl;
    return 0;
}

// The difference comes down to what is stored in memory: a Node is the actual object containing data, while a Node* is a pointer that stores the memory address where a Node is located.Think of a Node as a physical house, and a Node* as a piece of paper with the house's street address written on it.