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

void AddAfter() {
    int val;
    cout << "Enter value after which to insert: ";
    cin >> val;

    temp = first;

    // search the value
    do {
        if (temp->data == val)
            break;
        temp = temp->next;
    } while (temp != first);

    if (temp->data != val) {
        cout << "Value not found!\n";
        return;
    }

    ttemp = new scll;
    cout << "Enter new data: ";
    cin >> ttemp->data;

    ttemp->next = temp->next;
    temp->next = ttemp;

    cout << "Node inserted successfully!\n";
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

    for (int i = 0; i < n; i++) {
        Add_node();
        Display();
    }

    AddAfter();
    Display();

    return 0;
}