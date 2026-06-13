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

int nodeLen(Node* head){
    int count = 0;
    Node* temp = head;

    while(temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}

int main(){
   
    Node* head = nullptr;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);

    int len = nodeLen(head);
    cout << "Length : " << len << endl;

    return 0;
}