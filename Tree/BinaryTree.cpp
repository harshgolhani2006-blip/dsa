#include<iostream>
using namespace std;

struct BST{
    int data;
    BST*left,*right ;
};
BST *root,*temp,*ttemp,*p;
void init(){
    root=temp=ttemp=p=NULL;
}
void create_root(int x){
    root=new BST;
    root->data=x;
    root->left=root->right=NULL;
}
void ADD_Node(int x){
    temp=root;
    while(temp!=NULL){
        ttemp=temp;
        if(temp->data>x)
        temp=temp->left;
        else
        temp =temp->right;
    }
    p=new BST;
    p->data=x;p->left=p->right=NULL;
    if(ttemp->data>x)
    ttemp->left=p;
    else
    ttemp->right=p;
}
void printTree(BST* root,int space=0,int COUNT=5){
    if(root==NULL) 
    return;
    printTree(root->right,space+COUNT);
    for(int i=0;i<space; i++)cout<<" ";
    cout << root->data << endl;
    printTree(root->left,space+COUNT);
}

int main(){
    init();

    int n,x;
    cout<<"Enter number of nodes: ";
    cin>>n;

    cout<<"Enter root value: ";
    cin>>x;
    create_root(x);

    for(int i=1; i<n; i++){
        cout<<"Enter value: ";
        cin>>x;
        ADD_Node(x);
    }

    cout<<"\nBST Tree:\n";
    printTree(root);
}