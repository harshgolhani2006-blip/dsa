#include<iostream>
using namespace std;
struct node{
    int data;
    node*next,*prev;
};
node *first,*temp,*ttemp,*p;
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
void Add_afterLast(){
    temp=first;
    while(temp->next!=NULL)
    temp=temp->next;
    p=new node;
    cout<<"Enter data to insert after last :";
    cin>>p->data;
    p->next=NULL;
    p->prev=temp;
    temp->next=p;
    cout<<"Node inserted after last successfully.\n";
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
    Add_afterLast();
    display();
    return 0;
}