#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
};

void insert(Node* &head,int value){
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = nullptr;

    if(head==nullptr){
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = newNode;
}

// iterative
Node* reverseList(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while(curr != nullptr){
        next = curr->next;   // store next
        curr->next = prev;   // reverse link

        prev = curr;         // move prev
        curr = next;         // move curr
    }
    return prev; // new head
}


void print(Node* head){
    Node* temp = head;

    while(temp != nullptr){
        cout << temp->value << " -> ";
        temp = temp->next;
    }

    cout << "nullptr" << endl;
}

int main(){
   
    Node* head = nullptr;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);

    cout << "Original List: ";
    print(head);

    head = reverseList(head);
    cout << "Reversed List: ";
    print(head);

    return 0;
}