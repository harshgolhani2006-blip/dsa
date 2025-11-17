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
void SwapLastSecondLast() {

    // only one node → no swap
    if (first->next == first)
        return;

    temp = first;

    // only two nodes → swap first & second
    if (first->next->next == first) {
        ttemp = first->next;
        int x = first->data;
        first->data = ttemp->data;
        ttemp->data = x;
        return;
    }

    // go to second-last node
    while (temp->next->next != first)
        temp = temp->next;

    // temp = 2nd last
    ttemp = temp->next;   // last

    // swap data
    int x = temp->data;
    temp->data = ttemp->data;
    ttemp->data = x;
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
    SwapLastSecondLast();
    Display();
    return 0;
}
