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
    first->next = first;   // circular link
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
void DeleteLast() {

    // CASE-1: only one node
    if (first->next == first) {
        cout << "Deleted node: " << first->data << endl;
        delete first;
        first = NULL;
        return;
    }

    temp = first;

    // go to 2nd last node
    while (temp->next->next != first)
        temp = temp->next;

    ttemp = temp->next;   // last node
    temp->next = first;   // remove last

    cout << "Deleted node: " << ttemp->data << endl;
    delete ttemp;
}

void Display() {
    if (first == NULL) {
        cout << "List is empty";
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
    DeleteLast();
    Display();
    return 0;
}
