#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertBegin(Node*& head, int value) {
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = head;

    head = newNode;
}

void insertEnd(Node*& head, int value) {
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertPosition(Node*& head, int value, int position) {
    if (position < 0) {
        cout << "Invalid position" << endl;
        return;
    }

    if (position == 0) {
        insertBegin(head, value);
        return;
    }

    Node* temp = head;
    for (int i = 0; i < position - 1; i++) {
        if (temp == nullptr) {
            cout << "Invalid position" << endl;
            return;
        }
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Invalid position" << endl;
        return;
    }

    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

void display(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);
    insertEnd(head, 50);

    cout << "Original list: ";
    display(head);

    insertPosition(head, 99, 2);

    cout << "After insertion: ";
    display(head);

    return 0;
}