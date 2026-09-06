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
    if (arr.empty()) return nullptr; 
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* prev = head;
    head = head->next;
    head->prev = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL)  return NULL;
    Node* prev = head;
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    prev = tail->prev;
    prev->next = nullptr;
    tail->prev = nullptr;
    delete tail;
    return head;
}

Node* deleteK(Node* head, int k){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        if(count == k)  break;
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->next = nullptr;
    temp->prev = nullptr;
    delete(temp);
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head-> next;
    }
    cout << endl;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 2, 3, 4, 5};
    vector<int> arr3 = {1, 2, 3, 4, 5};
    vector<int> arr4 = {1, 2, 3, 4, 5};
    Node* head1 = convertArr2Dll(arr1);
    print(head1);

    // remove head
    Node* head2 = convertArr2Dll(arr2);
    head2 = deleteHead(head2);
    print(head2);

    // remove tail
    Node* head3 = convertArr2Dll(arr3);
    head3 = deleteTail(head3);
    print(head3);

    // remove k
    Node* head4 = convertArr2Dll(arr4);
    head4 = deleteK(head4, 2);
    print(head4);
    return 0;
}