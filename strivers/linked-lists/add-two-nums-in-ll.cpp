#include <iostream>
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
    if(arr.empty()) return nullptr;
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
        head = head-> next;
    }
    cout << endl;
}

Node* addison(Node* num1, Node* num2){
    Node* dummyHead = new Node(-1);
    Node* current = dummyHead;
    Node* t1 = num1;
    Node* t2 = num2;
    int carry = 0;
    while(t1 != NULL || t2 != NULL){
        int sum = carry;
        if(t1)  sum += t1->data;
        if(t2)  sum += t2->data;
        Node* nn = new Node(sum % 10);
        carry = sum / 10;
        current->next = nn;
        current = current->next;
        if(t1)  t1 = t1->next;
        if(t2)  t2 = t2->next;
    }
    if(carry)   {
        Node* nn = new Node(carry);
        current->next = nn;
    }
    return dummyHead->next;
}

int main() {
    vector<int> arr1 = {2, 4, 6};
    vector<int> arr2 = {3, 8, 7};

    Node* head1 = convertArr2LL(arr1);
    Node* head2 = convertArr2LL(arr2);
    Node* res = addison(head1, head2);
    print(res);
    return 0;
}
//  2->4->6->*              |    642
//  3->8->7->*              |   +783
//  5->2->4->1->*           |   1425
//  Intution
//  L1 and L2 lists are given; and there will be a carry variable = 0, and pointer t1 and t2 to the lists respectively, it will add l1.data and l2.data, if there is any carry, it will be stored in that variable and the unit digit will be pushed to the answer list.
// Loop will run till untill the next of both l1 and l2 are pointing towards null.
// A dummyNode is required 