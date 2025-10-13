#include<iostream>
using namespace std;
struct node{
    int data;
    node*next;
};
node *first,*temp,*ttemp,*p;
void init(){
    first = temp = ttemp = NULL;
}
void createfirst(){
    first = new node;
    cout <<"Enter data for first node :";
    cin >> first->data;
    first->next=NULL;
}
void addnode(){
    ttemp=new node;
    cout <<"Enter data for node : ";
    cin >> ttemp->data;
    ttemp->next=NULL;
    temp =first;
    while(temp->next!=NULL){
         temp=temp->next;
    }
    temp->next=ttemp;
}
void Add_beforelast(int x){
    temp=first;
    while(temp->next!=NULL){
        ttemp=temp;
        temp=temp->next;
    }
    p=new node;
    p->data=x;
    p->next=temp;
    ttemp->next=p;
    cout <<"Before adding "<<x<<"Before last node"<<endl;
}
void display(){
temp=first;
cout <<"Linked list element :";
while(temp!=NULL){
cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    init();
    int n,x;
    cout << "How many nodes do you want to create: ";
    cin >> n;

    if (n > 0) {
        createfirst();
        for (int i = 0; i < n - 1; i++) {
            addnode();
        }
    }
    display();
    cout<<"Enter the data add new node";
    cin>>x;
   Add_beforelast(x);
   display();

    return 0;
}
