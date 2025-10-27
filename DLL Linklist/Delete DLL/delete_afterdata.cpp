#include<iostream>
using namespace std;
struct Dll{
    int data;
    Dll *next,*prev;
};
Dll *first,*temp,*ttemp,*p;
void init(){
    first=temp=ttemp=NULL;
}
void createfirst(){
    first=new Dll;
    cout<<"Enter data for first node: ";
    cin>>first->data;
    first->next=NULL;
    first->prev=NULL;
}
void addnode(){
    ttemp=new Dll;
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
void delete_afterdata(int x){
    temp=first;
    while(temp->data!=x)
    temp=temp->next;
    ttemp=temp->next;
    p=ttemp->next;
    temp->next=p;
    p->prev=temp;
    ttemp->next=ttemp->prev=NULL;
    delete ttemp;
    cout << "Node after " << x << " deleted successfully!" << endl;

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
    int n,x;
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
     cout << "Enter the data value after which node should be deleted: ";
    cin >> x;
    delete_afterdata(x);
    display();
    return 0;
}