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
//Inorder.
void Inorder(BST *node){
    if(node!=NULL){
        Inorder(node->left);
        cout<<node->data<<" ";
        Inorder(node->right);
    }
}
//Preorder.
void preorder(BST*node){
    if(node!=NULL){
        cout<<node->data<<" ";
        preorder(node->left);
        preorder(node->right);
    }
}
//Postorder.
void Postorder(BST*node){
    if(node!=NULL){
    Postorder(node->left);
    Postorder(node->right);
    cout<<node->data<<" ";
}
}
void Display(){
    cout<<"\nInorder : ";
    Inorder(root);
    cout<<"\nPreorder : ";
    preorder(root);
    cout<<"\nPostorder : ";
    Postorder(root);
    cout<<endl;
}
void printTree(BST* root,int space=0,int COUNT=5){
    if(root==NULL) 
    return;
    printTree(root->right,space+COUNT);
    for(int i=0;i<space; i++)cout<<" ";
    cout << root->data << endl;
    printTree(root->left,space+COUNT);
}
BST* deleteNode(BST* root, int key){
    if(root == NULL)
        return root;

    // Search the key
    if(key < root->data){
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->data){
        root->right = deleteNode(root->right, key);
    }
    else {
        // FOUND the node to delete

        // Case 1: No child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // Case 2: One child
        else if(root->left == NULL){
            BST* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            BST* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children ⇒ replace with inorder successor
        BST* temp = root->right;
        while(temp->left != NULL)
            temp = temp->left;

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
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
    Display();

    cout<<"\nBST Tree:\n";
    printTree(root);

    int key;
cout << "\nEnter value to delete: ";
cin >> key;

root = deleteNode(root, key);

cout << "\nBST After Deletion:\n";
printTree(root);
Display();
}