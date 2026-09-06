#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    // constructor
    Node(int data1, Node* next1, Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node* convertArr2Dll(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head-> next;
    }
    cout << endl;
}

Node* insertBeforeHead(Node* head, int val){
    Node* newNode = new Node(val, head, nullptr);
    newNode->prev = nullptr;
    return newNode;
}
 
Node* insertAfterTail(Node* head, int val){
    Node* prevs = head;
    while(prevs->next != NULL){
        prevs = prevs->next;
    }
    Node* newNode = new Node(val, nullptr, prevs);
    newNode->prev = prevs;
    prevs->next = newNode;
    return head;
}

Node* insertAfterKPos(Node* head, int val, int k){
    if(k == 0) {
        return insertBeforeHead(head, val); 
    }
    
    Node* temp = head;
    int count = 0;
    
    while(temp != nullptr){
        count++;
        if(count == k){
            break;
        }
        temp = temp->next;
    }
    
    if (temp == nullptr) {
        return head; 
    }

    if(temp->next == nullptr){   
        return insertAfterTail(head, val);
    }
    
    // between 'temp' and 'temp->next'
    Node* nextNode = temp->next;
    Node* newNode = new Node(val, nextNode, temp);
    
    temp->next = newNode;
    nextNode->prev = newNode;
    
    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 2, 3, 4, 5};
    vector<int> arr3 = {1, 2, 3, 4, 5};
    vector<int> arr4 = {1, 2, 3, 4, 5};
    Node* head = convertArr2Dll(arr);
    // Node* head1 = convertArr2Dll(arr1);
    // print(head1);

    Node* head2 = convertArr2Dll(arr2);
    head2 = insertBeforeHead(head2, 0);
    print(head2);

    Node* head3 = convertArr2Dll(arr3);
    head3 = insertAfterTail(head3, 6);
    print(head3);

    Node* head4 = convertArr2Dll(arr4);
    head4 = insertAfterKPos(head4, 10, 3);
    print(head4);
    return 0;
}