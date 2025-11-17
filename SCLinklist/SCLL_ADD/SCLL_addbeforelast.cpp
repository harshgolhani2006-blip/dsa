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
void AddBeforeLast() {
    temp = first;

    // Move temp to the node BEFORE last
    while (temp->next->next != first)
        temp = temp->next;

    // Create new node
    ttemp = new scll;
    cout << "Enter new data: ";
    cin >> ttemp->data;

    // Insert between temp and last
    ttemp->next = temp->next;
    temp->next = ttemp;

    cout << "Node added before last!\n";
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
    AddBeforeLast();
    Display();
    return 0;
}
