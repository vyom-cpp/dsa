#include <map>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // brute
    bool brute(ListNode *head) {
        map<ListNode*, int> mpp;
        ListNode* temp = head;
        if(head == NULL || head->next == NULL)  return false;
        while(temp != NULL){
            if(mpp.find(temp) == mpp.end()) return true;
            else {mpp[temp] = 1;
            temp = temp->next;}
        }
        return false;
    }

    // optimal
    bool optimal(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)    return true;
        }
        return false;
    }
};