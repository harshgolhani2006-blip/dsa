#include<iostream>
using namespace std;

struct BST{
    int data;
    BST *left, *right;
};

BST *root, *temp, *ttemp, *p;

void init(){
    root = temp = ttemp = p = NULL;
}

void create_root(int x){
    root = new BST;
    root->data = x;
    root->left = root->right = NULL;
}

void ADD_Node(int x){
    temp = root;
    while(temp != NULL){
        ttemp = temp;
        if(x < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    p = new BST;
    p->data = x;
    p->left = p->right = NULL;

    if(x < ttemp->data)
        ttemp->left = p;
    else
        ttemp->right = p;
}

/*---------------------------------------------
   PRINT TREE VERTICALLY (SIDEWAYS)
----------------------------------------------*/
void printTree(BST *root, int space = 0, int COUNT = 5){
    if(root == NULL) return;

    printTree(root->right, space + COUNT);

    for(int i = 0; i < space; i++) cout << " ";
    cout << root->data << endl;

    printTree(root->left, space + COUNT);
}

/*---------------------------------------------
   HEIGHT OF TREE
----------------------------------------------*/
int height(BST *root){
    if(root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

/*---------------------------------------------
   PRINT GIVEN LEVEL (WITHOUT QUEUE)
----------------------------------------------*/
void printLevel(BST *root, int level){
    if(root == NULL) return;
    if(level == 1){
        cout << root->data << " ";
        return;
    }
    printLevel(root->left, level - 1);
    printLevel(root->right, level - 1);
}

/*---------------------------------------------
   COUNT NODES IN A LEVEL
----------------------------------------------*/
int countLevel(BST* root, int L){
    if(root==NULL) return 0;
    if(L==1) return 1;
    return countLevel(root->left,L-1) + countLevel(root->right,L-1);
}

/*---------------------------------------------
   WIDTH = MAX NODES IN ANY LEVEL
----------------------------------------------*/
int width(BST *root){
    int h = height(root);
    int maxW = 0;

    for(int i=1; i<=h; i++){
        int count = countLevel(root,i);
        if(count > maxW) maxW = count;
    }
    return maxW;
}

/*---------------------------------------------
   REMOVE ALL LEAVES (DEFOLIATION)
----------------------------------------------*/
BST* removeLeaves(BST *root){
    if(root == NULL) return NULL;

    // If current node is a leaf
    if(root->left == NULL && root->right == NULL){
        cout << "Removing leaf: " << root->data << endl; // Print leaf being removed
        delete root;
        return NULL;
    }

    // Recur for left and right subtrees
    root->left = removeLeaves(root->left);
    root->right = removeLeaves(root->right);

    return root;
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
    cout<<"\n\nVertical Tree:\n";
    //printTree(root);
    cout<<endl;
}
int main(){
    init();
    int n, x;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter root value: ";
    cin >> x;
    create_root(x);

    for(int i = 1; i < n; i++){
        cout << "Enter value: ";
        cin >> x;
        ADD_Node(x);
    }
    Display();

    cout << "\nBST (Vertical Print):\n";
    printTree(root);

    cout << "\nHeight of tree = " << height(root);

    cout << "\nLevel Order (each level):\n";
    int h = height(root);
    for(int i=1; i<=h; i++){
        cout << "Level " << i << ": ";
        printLevel(root, i);
        cout << endl;
    }

    cout << "\nWidth (max nodes in a level) = " << width(root);

    cout << "\n\nRemoving all leaves...\n";
    root = removeLeaves(root);

    cout << "Tree after defoliation:\n";
     Display();
    printTree(root);

    return 0;
}
