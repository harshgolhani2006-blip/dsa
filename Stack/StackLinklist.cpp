#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *top = NULL;

int Empty() {
    return (top == NULL);
}

void push(int x) {
    Node *n = new Node;
    n->data = x;
    n->next = top;
    top = n;
    cout << "Pushed: " << x << endl;
}

int pop() {
    if (Empty()) {
        cout << "Stack Underflow!" << endl;
        return -1;
    }
    Node *temp = top;
    int x = temp->data;
    top = top->next;
    delete temp;
    return x;
}

void display() {
    if (Empty()) {
        cout << "Stack Empty!" << endl;
        return;
    }

    Node *t = top;
    cout << "Stack: ";
    while (t != NULL) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int main() {
    int choice, value;

    cout<<"\nList of Stack Function\n";
    while (1) {
        cout << "\n1.Push \n 2.Pop\n  3.Display\n  4.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            push(value);
        }
        else if (choice == 2) {
            value = pop();
            if (value != -1)
                cout << "Popped: " << value << endl;
        }
        else if (choice == 3) {
            display();
        }
        else if (choice == 4) {
            cout << "Exiting...";
            break;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
