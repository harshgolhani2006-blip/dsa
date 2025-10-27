#include<iostream>
using namespace std;
struct node {
    int data;
    node *next;
};
node *first, *temp, *ttemp,*p;
void init() {
    first = temp = ttemp = NULL;
}
void createfirst() {
    first = new node;
    cout << "Enter data for first node :";
    cin >> first->data;
    first->next = NULL;
}
void addnode() {
    ttemp = new node;
    cout << "Enter data for new node :";
    cin >> ttemp->data;
    ttemp->next = NULL;
    temp = first;
    while (temp->next != NULL) {
    
        temp = temp->next;
    }
    temp->next = ttemp;
}
void deletebefore(int x){    //delete node before node having value x   
    temp=first;
    if(first==NULL){
        cout<<"List is empty"<<endl;
        return;
    }else{
        cout<<"List is not empty"<<endl;
    }
    while(temp->next->data!=x)
    {
        ttemp=temp;
        temp=temp->next;
    }
    p=temp->next;
    ttemp->next=p;
    temp->next=NULL;
    delete temp;
    cout<<"Deleted node before "<<x<<endl;
}
void display() {
    temp = first;
    cout << "Linked list elements :";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    int n, i, x;
    init();
    cout << "Enter number of nodes :";
    cin >> n;
    createfirst();
    for (i = 1; i < n; i++) {
        addnode();
    }
    display();
    cout << "Enter the value before which you want to delete the node :";
    cin >> x;
    deletebefore(x);
    display();
}
    