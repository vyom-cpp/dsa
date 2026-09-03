// deletion (head, position, value, last)
#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data1){
        data = data1;
        next = nullptr; 
    }
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

// remove head
Node* removeHead(Node* head){
    if(head->next == NULL)  return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

// remove tail
Node* removeTail(Node* head){
    if(head == NULL || head->next == NULL)  return NULL;
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete(temp->next);
    temp->next = nullptr;
    return head;
}

// remove kth element
// tip:- always start with thinking the edge cases
Node* deleteK(Node* head, int k){
    if(head == NULL)    return head;
    if(k == 1)  removeHead(head);
    int count = 0;
    Node* temp = head;
    Node* prev = NULL;
    while (temp!=NULL)
    {
        count++;
        if(count == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// remove value
Node* deleteVal(Node* head, int el){
    if(head == NULL)    return head;
    if(head->data == el)  removeHead(head);
    Node* temp = head;
    Node* prev = NULL;
    while (temp!=NULL)
    {
        if(temp->data == el){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}


int main() {
    vector<int> arr1 = {1, 2, 3, 4};
    vector<int> arr2 = {1, 2, 3, 4};
    vector<int> arr3 = {1, 2, 3, 4};
    vector<int> arr4 = {1, 2, 3, 4};

    Node* head1 = convertArr2LL(arr1);
    head1 = removeHead(head1);
    Node* temp1 = head1;
    while(temp1 != nullptr){
        cout << temp1->data << " ";
        temp1 = temp1->next; 
    }
    cout << endl;

    Node* head2 = convertArr2LL(arr2);
    head2 = removeTail(head2);
    Node* temp2 = head2;
    while(temp2 != nullptr){
        cout << temp2->data << " ";
        temp2 = temp2->next;
    }
    cout << endl;

    Node* head3 = convertArr2LL(arr3);
    head3 = deleteK(head3, 3);
    Node* temp3 = head3;
    while(temp3 != nullptr){
        cout << temp3->data << " ";
        temp3 = temp3->next;
    }
    cout << endl;

    Node* head4 = convertArr2LL(arr4);
    head4 = deleteVal(head4, 3);
    Node* temp4 = head4;
    while(temp4 != nullptr){
        cout << temp4->data << " ";
        temp4 = temp4->next;
    }
    cout << endl;
    return 0;
}