#include <iostream>
using namespace std;

struct Node
{
    Node* prev;
    int value;
    Node* next;
};

void insert(Node* &head, int value) {
    Node* newNode = new Node();
    newNode->value = value;
    newNode->prev = nullptr;
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
    newNode->prev = temp;
}

void printForward(Node* head){
    if(head==nullptr) return;
    Node* temp = head;

    while(temp != nullptr){
        cout << temp->value << " <-> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

void printBackward(Node* head) {
    if (head == nullptr) return;

    Node* temp = head;

    // go to last node
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    // traverse backward
    while (temp != nullptr) {
        cout << temp->value << " <-> ";
        temp = temp->prev;
    }
    cout << "nullptr" << endl;
}

int main(){

    Node* head = nullptr;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);

    cout << "Forward: ";
    printForward(head);

    cout << "Backward: ";
    printBackward(head);

    return 0;
}