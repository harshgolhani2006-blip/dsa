//ADD NEW NODE BEFORE AND AFTER GIVEN DATA---
#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

node *first, *temp, *ttemp ,*p;

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
void Add_after(int x,int y){
    temp=first;
    while(temp->data!=x)
    temp=temp->next;
    ttemp=temp->next;
    p=new node;
    p->data=y;
    p->next=ttemp;
    temp->next=p;
    cout<<"After adding "<<y<<" after "<<x<<endl;
}
void Add_before(int x,int y){
    temp=first;
    while(temp->data!=x){
    ttemp=temp;
    temp=temp->next;
    }
    p=new node;
    p->data=y;
    p->next=temp;
    ttemp->next=p;
    cout<<"Before adding "<<y<<" before "<<x<<endl;

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
    int n,x,y,choice;
    cout << "How many nodes do you want to create: ";
    cin >> n;
    cout<<"1.Add after given node\n2.Add before given node";
    cout<<"Enter the choice:";
    cin>>choice;
    if (n > 0) {
        createfirst();
        for (int i = 0; i < n - 1; i++) {
            addnode();
        }
    }

    display();
    cout<<"Enter the data add new node";
    cin>>x;
    cout<<"Enter the data to be added";
    cin>>y;
   Add_after(x,y);
   display();
   Add_before(x,y);
    display();
    return 0;
}
