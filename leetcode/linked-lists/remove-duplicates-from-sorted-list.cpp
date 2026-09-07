// 83. Remove Duplicates from Sorted List
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
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

Node* deleteDuplicates(Node* head){
    Node* current = head;
    if(head == nullptr || head->next == nullptr) return head;
    while(current != nullptr && current->next != nullptr){
        if(current->data == current->next->data){
            Node* duplicate = current->next;
            current->next = current->next->next;
            delete duplicate;
        } else {
            current = current->next;
        }
    }
    return head;
}

int main() {
    vector<int> arr = {1, 1, 1, 2, 3, 4, 5, 5, 5, 6, 8};
    Node* head = convertArr2LL(arr);
    head = deleteDuplicates(head);
    print(head);
    return 0;
}