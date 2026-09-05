// #209 
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* convertArr2LL(vector<int> &arr) {
    if (arr.empty()) return nullptr;  
    ListNode* head = new ListNode(arr[0]);
    ListNode* mover = head;
    for(int i = 1; i < arr.size(); i++){
        ListNode* temp = new ListNode(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;    
}

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* nextNode = nullptr;  
    while (current != nullptr) {
        nextNode = current->next; 
        current->next = prev;     
        prev = current;            
        current = nextNode;
    }
    return prev; 
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << " -> nullptr" << endl;
}

void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    ListNode* head = convertArr2LL(arr);
    cout << "Original List: ";
    printList(head);
    head = reverseList(head);  
    cout << "Reversed List: ";
    printList(head);
    freeList(head);   
    return 0;
}
