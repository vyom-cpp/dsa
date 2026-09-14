#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* nxt;

    Node(int data1, Node* nxt1){
        data = data1;
        nxt = nxt1;
    }

    Node(int data1){
        data = data1;
        nxt = nullptr;
    }
};


int findLength(Node* fast, Node* slow){
    int count = 1;
    fast = fast->nxt;
    while(slow != fast){
        count++;
        fast = fast->nxt;
    }
    return count;
}

int lengthOfLoop(Node* head){
    Node* fast = head;
    Node* slow = head;
    while(fast != nullptr && fast->nxt != nullptr){
        slow = slow->nxt;
        fast = fast->nxt->nxt;

        if(slow == fast){
            return findLength(slow, fast);
        }
    }
    return 0;
}