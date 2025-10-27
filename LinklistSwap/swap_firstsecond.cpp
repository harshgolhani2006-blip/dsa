#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

node *first, *temp, *ttemp,*p;

void init() {
    first = temp = ttemp = NULL;
}

void createfirst() {
    first = new node;
    cout << "Enter data for first node: ";
    cin >> first->data;
    first->next = NULL;
}

void addnode() {
    ttemp = new node;
    cout << "Enter data for new node: ";
    cin >> ttemp->data;
    ttemp->next = NULL;

    temp = first;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = ttemp;
}
void swap_firstsecond() {   //function to swap first and second node
    if (first == NULL || first->next == NULL) {
        cout << "Not enough nodes to swap." << endl;
        return;
    }else{
        cout<<"Swapping first two nodes"<<endl;
    }
    temp = first;
    ttemp = temp->next;
    p=ttemp->next;
    ttemp->next = temp;
    temp->next = p;
    first = ttemp;
}

void display() {
    temp = first;
    cout << "Linked list elements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    init();
    int n;
    cout << "How many nodes do you want to create: ";
    cin >> n;

    if (n > 0) {
        createfirst();
        for (int i = 0; i < n - 1; i++) {
            addnode();
        }
    }
    display();
    swap_firstsecond();
    display();
    return 0;
}
