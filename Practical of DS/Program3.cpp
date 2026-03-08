//C++ Program to Insert and Delete Node in Singly Linked List
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

// Global head pointer
Node *head = nullptr;

// Count total nodes
int countNode(Node *ptr) {
    int count = 0;
    while(ptr != nullptr) {
        count++;
        ptr = ptr->next;
    }
    return count;
}

// Insert at beginning
void insertAtBeginning(Node *ptr, int num) {

    Node *n = new Node;
    n->data = num;
    n->next = nullptr;

    if(head == NULL) {
        head = n;
    }
    else {
        n->next = head;
        head = n;
    }
}

// Insert at given position
void insertAtPosition(Node *ptr, int pos, int num) {

    int count = countNode(ptr);

    if(pos > count + 1 || pos < 1) {
        cout << "Invalid position - " << pos << endl;
        return;
    }

    Node *n = new Node;
    n->data = num;
    n->next = nullptr;

    if(pos == 1) {
        insertAtBeginning(ptr, num);
    }
    else {

        for(int i = 1; i < pos - 1; i++) {
            ptr = ptr->next;
        }

        if(ptr != nullptr) {
            n->next = ptr->next;
            ptr->next = n;
        }
    }
}

// Append node at end
void appendNode(Node *ptr, int num) {

    Node *n = new Node;
    n->data = num;
    n->next = nullptr;

    if(head == NULL) {
        head = n;
    }
    else {
        while(ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = n;
    }
}

// Delete node
void deleteNode(Node *ptr, int pos) {

    int count = countNode(ptr);

    if(pos > count || pos < 1) {
        cout << "Invalid position - " << pos << endl;
        return;
    }

    if(pos == 1) {
        head = head->next;
        delete ptr;
    }
    else {

        for(int i = 1; i < pos - 1; i++) {
            ptr = ptr->next;
        }

        Node *temp = ptr->next;
        ptr->next = temp->next;

        delete temp;
    }
}

// Display list
void show(Node *ptr) {

    while(ptr != nullptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    cout << endl;
}

int main() {

    insertAtBeginning(head,3);
    insertAtBeginning(head,4);
    insertAtBeginning(head,5);

    insertAtPosition(head,2,10);
    insertAtPosition(head,22,12);

    show(head);

    deleteNode(head,2);

    show(head);

    appendNode(head,2);
    appendNode(head,1);

    show(head);

    return 0;
}