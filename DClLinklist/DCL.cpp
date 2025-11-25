#include<iostream>
using namespace std;

struct DCLL{
    int data;
    DCLL *first, *next, *prev;
};

DCLL *first = NULL, *temp;

void create_first(){
    first = new DCLL;
    cout<<"Enter First node: ";
    cin >> first->data;

    first->next = first;
    first->prev = first;
}

void Add_node(){
    DCLL *newnode = new DCLL;
    cout<<"Enter data: ";
    cin >> newnode->data;

    temp = first->prev;       // last node

    newnode->next = first;    
    newnode->prev = temp;     
    temp->next = newnode;     
    first->prev = newnode;    
}

void Add_many(){
    int n;
    cout<<"How many nodes you want to add: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        Add_node();
    }
}

void display(){
    if(first == NULL){
        cout<<"List empty";
        return;
    }
    temp = first;
    cout<<"DCLL List: ";
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != first);
}
 
int main(){
    create_first();
    Add_many();
    display();
}
