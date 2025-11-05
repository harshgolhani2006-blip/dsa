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
void swap_lastSecondlast(){
    temp = first;
    while(temp->next->next != NULL)
        temp = temp->next;      // temp → second last node

    ttemp = temp->next;         // ttemp → last node

    temp->prev->next = ttemp;   // link node before 2nd last → last
    ttemp->prev = temp->prev;   // last node’s prev → node before 2nd last
    temp->next = NULL;          // 2nd last becomes last
    ttemp->next = temp;         // last → next = 2nd last
    temp->prev = ttemp;         // 2nd last → prev = last
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
    swap_lastSecondlast();
    display();
    return 0;
}