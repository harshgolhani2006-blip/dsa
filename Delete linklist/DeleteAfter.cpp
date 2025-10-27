#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
node *first,*temp,*ttemp;
void init(){
    first=temp=ttemp=NULL;
}
void createfirst(){
    first=new node;
    cout<<"Enter data for first node :";
    cin>>first->data;
    first->next=NULL;
}
void addnode(){
    ttemp=new node;
    cout<<"Enter data for new node :";
    cin>>ttemp->data;
    ttemp->next=NULL;
    temp=first;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=ttemp;
} 
void deleteafter(int x){    //delete node after node having value x 
    temp = first;

    // find node with data = x
    while(temp != NULL){
        if(temp->data == x)
            break;
        temp = temp->next;
    }

    // if node not found
    if(temp == NULL){
        cout << "Node not found." << endl;
        return;
    }

    // if no node after x
    if(temp->next == NULL){
        cout << "No node after " << x << " to delete." << endl;
        return;
    }

    // delete next node
    ttemp = temp->next;
    temp->next = ttemp->next;
    cout << "Deleted node after " << x << " having value " << ttemp->data << endl;
    delete ttemp;
}

void display(){
    temp=first;
    cout<<"Linked list elements :";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}   
int main(){
    init();
    int n,x;
    cout<<"How many nodes do you want to create :";
    cin>>n;
    if(n>0){
        createfirst();
        for(int i=1;i<n;i++){
            addnode();
        }
        display();
        cout<<"Enter the value after which you want to delete the node :";
        cin>>x;
        deleteafter(x);
        display();
    }
    else{
        cout<<"Number of nodes should be greater than zero."<<endl;
    }
    return 0;
}
    
