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

void DeleteAfter() {
    int val;
    cout << "Enter value after which to delete: ";
    cin >> val;

    temp = first;

    // search the value
    while (temp->data != val) {
        temp = temp->next;
        if (temp == first) {
            cout << "Value not found!\n";
            return;
        }
    }

    // node to delete = temp->next
    ttemp = temp->next;

    // if deleting first node
    if (ttemp == first) {
        // move last pointer to new first
        scll *last = first;
        while (last->next != first)
            last = last->next;

        first = first->next;
        last->next = first;
    }

    // normal case
    temp->next = ttemp->next;

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
    DeleteAfter();
    Display();
    return 0;
}
