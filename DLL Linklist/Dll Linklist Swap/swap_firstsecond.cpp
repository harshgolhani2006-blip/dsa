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
void Swap_firstsecond(){
    temp = first;           // first node
    ttemp = temp->next;     // second node

    temp->next = ttemp->next;
    ttemp->next->prev = temp;   // adjust third node’s prev
    ttemp->prev = NULL;
    ttemp->next = temp;
    temp->prev = ttemp;

    first = ttemp;          // update first pointer
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
    Swap_firstsecond();
        display();
    return 0;
}