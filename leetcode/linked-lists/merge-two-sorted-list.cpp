/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* res = dummy;
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        while(t1 != nullptr && t2 != nullptr){
            if(t1->val <= t2->val){
                res->next = t1;
                t1 = t1->next;
            } else {
                res->next = t2;
                t2 = t2->next;
            }
            res = res->next;
        }
        if(t1 != nullptr) {
            res->next = t1;
        } else {
            res->next = t2;
        }
    
        ListNode* actualHead = dummy->next;
        delete dummy; 
        return actualHead;
    }
};