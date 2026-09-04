// #237 (Delete node in a linked list) -> Medium
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
    node->val = node->next->val;
    ListNode* temp = node->next;
    node->next = node->next->next;
    delete temp;
}

ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return NULL;   
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        cout << current->val;
        if (current->next != NULL) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    vector<int> values = {4, 5, 1, 9};
    ListNode* head = createLinkedList(values);
    cout << "Original List: ";
    printList(head);
    ListNode* nodeToDelete = head->next; 
    deleteNode(nodeToDelete);
    cout << "List after deleting node 5: ";
    printList(head);
    return 0;
}
