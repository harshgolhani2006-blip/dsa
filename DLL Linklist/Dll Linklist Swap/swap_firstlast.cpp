#include<iostream>
using namespace std;
struct node{
    int data;
    node*next,*prev;
};
node *first,*temp,*ttemp;
void init(){
    first=temp=ttemp=NULL;
}
void createfirst(){
    first=new node;
    cout<<"Enter data for first node: ";
    cin>>first->data;
    first->next=NULL;
    first->prev=NULL;
}
void addnode(){
    ttemp=new node;
    cout<<"Enter data for new node: ";
    cin>>ttemp->data;
    ttemp->next=NULL;
    ttemp->prev=NULL;

    temp=first;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=ttemp;
    ttemp->prev=temp;
}
void Swap_firstlast() {
    temp = first;
    while(temp->next != NULL)
        temp = temp->next;   // now temp points to last node

    // temp = last, first = first node
    ttemp = first->next;     // store second node
    ttemp->prev = temp;      // link second node's prev to last node
    temp->prev->next = first; // link second last's next to first

    first->next = NULL;
    first->prev = temp->prev;

    temp->next = ttemp;
    temp->prev = NULL;

    first = temp; // update first pointer
}
void display(){
    temp=first;
    cout<<"Doubly Linked list elements: ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    init();
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;
    if(n<=0){
        cout<<"Number of nodes should be greater than zero"<<endl;
    }else{
        createfirst();
        for(int i=1;i<n;i++){
            addnode();
        }
        display();
    }
    Swap_firstlast();
    display();
    return 0;
}