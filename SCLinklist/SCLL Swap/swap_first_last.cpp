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
void SwapFirstLast() {

    // CASE-1: only one node
    if (first->next == first) {
        cout << "Only one node — no swap\n";
        return;
    }

    temp = first;

    // move temp to LAST node
    while (temp->next != first)
        temp = temp->next;

    // swap first->data and last->data
    int x = first->data;
    first->data = temp->data;
    temp->data = x;

    cout << "First and Last nodes swapped!\n";
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
    SwapFirstLast();
    Display();
    return 0;
}
