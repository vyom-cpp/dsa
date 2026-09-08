#include <iostream>
#include <vector>
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

Node* oddEven(Node* head){
    vector<int> ans;
    Node* temp = head;
    while(temp != NULL && temp->next != NULL){
        ans.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp)    ans.push_back(temp->data);
    temp = head->next;
    while(temp != NULL && temp->next != NULL){
        ans.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp)    ans.push_back(temp->data);

    temp = head;
    int i = 0;
    while(temp != NULL){
        temp->data = ans[i];
        i++;
        temp=temp->next;
    }
    return head;
}

int main() {
    vector<int> arr = {1, 4, 3, 2, 5, 6};
    Node* head1 = convertArr2LL(arr);
    head1 = oddEven(head1);
    print(head1);
    return 0;
}