#include <iostream>
using namespace std;

#define MAX 10

struct Stack {
    int data[MAX];
    int top;
};

Stack s, *p;

void init() {
    p = &s;
    p->top = -1;
}

int Empty() {
    return (p->top == -1);
}

int Full() {
    return (p->top == MAX - 1);
}

void push(int x) {
    if (Full()) {
        cout << "Stack Overflow!\n";
        return;
    }
    p->top++;
    p->data[p->top] = x;
    cout << "Inserted: " << x << endl;
}

int pop() {
    if (Empty()) {
        cout << "Stack Underflow!\n";
        return -1;
    }
    int x = p->data[p->top];
    p->top--;
    return x;
}

void display() {
    if (Empty()) {
        cout << "Stack Empty!" << endl;
        return;
    }
    cout << "Stack: ";
    for (int i = p->top; i >= 0; i--)
        cout << p->data[i] << " ";
    cout << endl;
}

int main() {

    init();
    int choice, value;

     cout<<"\n-----Choice Stack Function List:-----\n";
    while (1) {   
        cout << "\n1.Push\n  2.Pop\n  3.Display\n  4.Exit\n";
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
            cout << "Invalid choice!";
        }
    }

    return 0;
}
