// insertion (head, position, value, last)
#include <vector>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    // Use a single constructor with a default parameter.
    // This supports both 1-argument and 2-argument instantiation.
    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1; 
    }
};

Node* convertArr2LL(vector<int> &arr){
    if (arr.empty()) return nullptr; 
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;    
}

// insert at head
Node* insertHead(Node* head, int val){ 
    Node* temp = new Node(val, head); 
    return temp;  
}

// insert at end
Node* insertTail(Node* head, int val){
    if(head == nullptr) return new Node(val);
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}

// insert val at kth position
Node* insertK(Node* head, int val, int k){
    if(head == nullptr){
        if(k == 1) return new Node(val);
        return nullptr;
    }

    if(k == 1) return insertHead(head, val);
    
    int count = 0;
    Node* temp = head;
    
    while(temp != nullptr){
        count++;
        if(count == k - 1){
            Node* x = new Node(val, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

// insert element before the value x
Node* insertBeforeValue(Node* head, int el, int val){
    if(head == nullptr){
        return NULL;
    }

    if(head->data == val) return new Node(el, head);
    
    Node* temp = head;
    
    while(temp->next != nullptr){
        if(temp->next->data == val){
            Node* x = new Node(val, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> arr1 = {2, 3, 4, 5};
    vector<int> arr2 = {2, 3, 4, 5};
    vector<int> arr3 = {2, 3, 4, 5};
    vector<int> arr4 = {2, 3, 4, 5};

    Node* head1 = convertArr2LL(arr1);
    head1 = insertHead(head1, 1);
    Node* temp1 = head1;
    while(temp1 != nullptr){
        cout << temp1->data << " ";
        temp1 = temp1->next;
    }
    cout << endl;

    Node* head2 = convertArr2LL(arr2);
    head2 = insertTail(head2, 1);
    Node* temp2 = head2;
    while(temp2 != nullptr){
        cout << temp2->data << " ";
        temp2 = temp2->next; 
    }
    cout << endl;

    Node* head3 = convertArr2LL(arr3);
    head3 = insertK(head3, 6, 3);
    Node* temp3 = head3;
    while(temp3 != nullptr){
        cout << temp3->data << " ";
        temp3 = temp3->next;
    }
    cout << endl;

    Node* head4 = convertArr2LL(arr4);
    head4 = insertBeforeValue(head4, 8, 3);
    Node* temp4 = head4;
    while(temp4 != nullptr){
        cout << temp4->data << " ";
        temp4 = temp4->next;
    }
    cout << endl;
    return 0;
}