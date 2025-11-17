#include <iostream>
using namespace std;

struct scll {
    int data;
    scll *next;
};

scll *first = NULL, *temp, *ttemp;

void createfirst() {
    first = new scll;
    cout << "Enter first node data: ";
    cin >> first->data;
    first->next = first;
}

void Add_node() {
    temp = first;
    while (temp->next != first)
        temp = temp->next;

    ttemp = new scll;
    cout << "Enter new node data: ";
    cin >> ttemp->data;

    ttemp->next = first;
    temp->next = ttemp;
}

void DeleteBefore() {
    int val;
    cout << "Enter value before which to delete: ";
    cin >> val;

    temp = first;

    // CASE-1: Only one node
    if (first->next == first) {
        cout << "Not possible\n";
        return;
    }

    // CASE-2: delete BEFORE first → delete last node
    if (first->data == val) {
        while (temp->next->next != first)
            temp = temp->next;

        ttemp = temp->next; // last node
        temp->next = first;

        cout << "Deleted node: " << ttemp->data << endl;
        delete ttemp;
        return;
    }

    // CASE-3: delete before any other node
    while (temp->next->next != first && temp->next->next->data != val)
        temp = temp->next;

    if (temp->next->next->data != val) {
        cout << "Value not found!\n";
        return;
    }

    ttemp = temp->next;          // node to delete
    temp->next = ttemp->next;    // bypass

    cout << "Deleted node: " << ttemp->data << endl;
    delete ttemp;
}

void Display() {
    if (first == NULL) {
        cout << "List is empty\n";
        return;
    }

    temp = first;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != first);
    cout << endl;
}

int main() {
    createfirst();

    int n;
    cout << "How many more nodes to add: ";
    cin >> n;

    for (int i = 0; i < n; i++)
        Add_node();

    Display();
    DeleteBefore();
    Display();
    return 0;
}

