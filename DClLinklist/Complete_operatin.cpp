// #include<iostream>
// using namespace std;

// struct DCLL{
//     int data;
//     DCLL *first, *next, *prev;
// };

// DCLL *first = NULL, *temp;


// void create_first(){
//     first = new DCLL;
//     cout<<"Enter First node: ";
//     cin >> first->data;

//     first->next = first;
//     first->prev = first;
// }


// //------------------------------------------------
// // ADD OPERATIONS
// //------------------------------------------------

// void Add_at_end(){
//     DCLL *newnode = new DCLL;
//     cout<<"Enter data: ";
//     cin >> newnode->data;

//     temp = first->prev;

//     newnode->next = first;
//     newnode->prev = temp;

//     temp->next = newnode;
//     first->prev = newnode;
// }

// void Add_at_begin(){
//     DCLL *newnode = new DCLL;
//     cout<<"Enter data: ";
//     cin >> newnode->data;

//     DCLL *last = first->prev;

//     newnode->next = first;
//     newnode->prev = last;

//     last->next = newnode;
//     first->prev = newnode;

//     first = newnode;
// }

// void Add_many(){
//     int n;
//     cout<<"How many nodes to add: ";
//     cin >> n;

//     for(int i=0; i<n; i++)
//         Add_at_end();
// }

// void Add_at_pos(){
//     int pos, count = 1;
//     cout<<"Enter position: ";
//     cin >> pos;

//     if(pos == 1){
//         Add_at_begin();
//         return;
//     }

//     temp = first;
//     while(count < pos-1 && temp->next != first){
//         temp = temp->next;
//         count++;
//     }

//     if(count != pos-1){
//         cout<<"Invalid Position\n";
//         return;
//     }

//     DCLL *newnode = new DCLL;
//     cout<<"Enter data: ";
//     cin >> newnode->data;

//     DCLL *nxt = temp->next;

//     newnode->next = nxt;
//     newnode->prev = temp;

//     temp->next = newnode;
//     nxt->prev = newnode;

//     cout<<"Inserted at position "<<pos<<endl;
// }


// //----------------------------------------------
// // REMOVE OPERATIONS
// //----------------------------------------------

// void remove_first(){
//     if(first == NULL){
//         cout<<"List empty\n"; return;
//     }

//     if(first->next == first){
//         delete first;
//         first = NULL;
//         cout<<"Node removed\n"; 
//         return;
//     }

//     DCLL *last = first->prev;
//     temp = first;

//     first = first->next;

//     first->prev = last;
//     last->next = first;

//     delete temp;
//     cout<<"First node removed\n";
// }

// void remove_last(){
//     if(first == NULL){
//         cout<<"List empty\n"; return;
//     }

//     if(first->next == first){
//         delete first;
//         first = NULL;
//         cout<<"Node removed\n"; 
//         return;
//     }

//     DCLL *last = first->prev;
//     temp = last->prev;

//     temp->next = first;
//     first->prev = temp;

//     delete last;
//     cout<<"Last node removed\n";
// }

// void remove_value(){
//     int val;
//     cout<<"Enter value to remove: ";
//     cin >> val;

//     temp = first;

//     do{
//         if(temp->data == val){

//             if(temp == first){
//                 remove_first();
//                 return;
//             }

//             DCLL *p = temp->prev;
//             DCLL *n = temp->next;

//             p->next = n;
//             n->prev = p;

//             delete temp;
//             cout<<"Value removed\n";
//             return;
//         }
//         temp = temp->next;

//     }while(temp != first);

//     cout<<"Value not found\n";
// }


// //---------------------------------------
// // EXTRA OPERATIONS
// //---------------------------------------

// void swap_nodes(){
//     int a, b;
//     cout<<"Enter node1 value: ";
//     cin >> a;
//     cout<<"Enter node2 value: ";
//     cin >> b;

//     if(a == b){
//         cout<<"Same values, no swap\n";
//         return;
//     }

//     DCLL *x = NULL, *y = NULL;
//     temp = first;

//     do{
//         if(temp->data == a) x=temp;
//         if(temp->data == b) y=temp;
//         temp=temp->next;
//     }while(temp != first);

//     if(x==NULL || y==NULL){
//         cout<<"Values not found\n"; return;
//     }

//     int t = x->data;
//     x->data = y->data;
//     y->data = t;

//     cout<<"Swapped\n";
// }

// void search_node(){
//     int val, index=1;
//     cout<<"Enter value to search: ";
//     cin >> val;

//     temp = first;

//     do{
//         if(temp->data == val){
//             cout<<"Found at position "<<index<<endl;
//             return;
//         }
//         temp = temp->next;
//         index++;

//     }while(temp != first);

//     cout<<"Not found\n";
// }

// void count_nodes(){
//     int count = 0;
//     temp = first;

//     do{
//         count++;
//         temp = temp->next;
//     }while(temp != first);

//     cout<<"Total nodes: "<<count<<endl;
// }

// void reverse_display(){
//     if(first == NULL){
//         cout<<"List empty\n"; 
//         return;
//     }

//     DCLL *last = first->prev;
//     temp = last;

//     cout<<"Reverse: ";
//     do{
//         cout<<temp->data<<" ";
//         temp = temp->prev;
//     }while(temp != last);
//     cout<<endl;
// }

// void clear_list(){
//     if(first == NULL){
//         cout<<"List empty\n"; return;
//     }

//     DCLL *curr = first->next;
//     while(curr != first){
//         DCLL *del = curr;
//         curr = curr->next;
//         delete del;
//     }

//     delete first;
//     first = NULL;

//     cout<<"All nodes deleted\n";
// }


// //---------------------------------------
// // DISPLAY
// //---------------------------------------

// void display(){
//     if(first == NULL){
//         cout<<"List empty\n"; return;
//     }

//     temp = first;
//     cout<<"DCLL: ";

//     do{
//         cout<<temp->data<<" ";
//         temp = temp->next;
//     }while(temp != first);

//     cout<<endl;
// }


// //---------------------------------------
// // MAIN MENU
// //---------------------------------------

// int main(){
//     int ch;

//     create_first();

//     do{
//         cout<<"\n--- DCLL OPERATIONS ---\n";
//         cout<<"1. Add at beginning\n";
//         cout<<"2. Add at end\n";
//         cout<<"3. Add many\n";
//         cout<<"4. Add at position\n";
//         cout<<"5. Remove first\n";
//         cout<<"6. Remove last\n";
//         cout<<"7. Remove value\n";
//         cout<<"8. Swap nodes\n";
//         cout<<"9. Search\n";
//         cout<<"10. Count nodes\n";
//         cout<<"11. Reverse display\n";
//         cout<<"12. Clear list\n";
//         cout<<"13. Display\n";
//         cout<<"14. Exit\n";
//         cout<<"Enter choice: ";
//         cin >> ch;

//         switch(ch){
//             case 1: Add_at_begin(); break;
//             case 2: Add_at_end(); break;
//             case 3: Add_many(); break;
//             case 4: Add_at_pos(); break;
//             case 5: remove_first(); break;
//             case 6: remove_last(); break;
//             case 7: remove_value(); break;
//             case 8: swap_nodes(); break;
//             case 9: search_node(); break;
//             case 10: count_nodes(); break;
//             case 11: reverse_display(); break;
//             case 12: clear_list(); break;
//             case 13: display(); break;
//             case 14: cout<<"Exiting..."; break;
//             default: cout<<"Invalid Choice\n";
//         }

//     }while(ch != 14);
// }
#include<iostream>
using namespace std;

struct DCLL{
    int data;
    DCLL *next, *prev;
};

DCLL *first = NULL, *temp;


//----------------------------------
// DISPLAY
//----------------------------------
void display(){
    if(first == NULL){
        cout<<"List empty\n";
        return;
    }
    temp = first;

    cout<<"DCLL: ";
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != first);
    cout<<"\n";
}


//----------------------------------
// CREATE FIRST NODE
//----------------------------------
void create_first(){
    first = new DCLL;
    cout<<"Enter First node: ";
    cin >> first->data;

    first->next = first;
    first->prev = first;

    display();
}


//----------------------------------
// ADD AT END
//----------------------------------
void add_end(){
    DCLL *newnode = new DCLL;
    cout<<"Enter data: ";
    cin >> newnode->data;

    temp = first->prev;

    newnode->next = first;
    newnode->prev = temp;

    temp->next = newnode;
    first->prev = newnode;

    display();
}


//----------------------------------
// ADD AT BEGIN
//----------------------------------
void add_begin(){
    DCLL *newnode = new DCLL;
    cout<<"Enter data: ";
    cin >> newnode->data;

    DCLL *last = first->prev;

    newnode->next = first;
    newnode->prev = last;

    last->next = newnode;
    first->prev = newnode;
    first = newnode;

    display();
}


//----------------------------------
// ADD MANY
//----------------------------------
void add_many(){
    int n;
    cout<<"How many nodes: ";
    cin>>n;

    for(int i=0;i<n;i++){
        add_end();
    }
}


//----------------------------------
// ADD AT POSITION
//----------------------------------
void add_pos(){
    int pos;
    cout<<"Enter position: ";
    cin>>pos;

    if(pos<=1){ add_begin(); return; }

    int count = 1;
    temp = first;
    while(count < pos-1 && temp->next != first){
        temp = temp->next;
        count++;
    }

    if(count != pos-1){
        cout<<"Invalid position\n";
        return;
    }

    DCLL *newnode = new DCLL;
    cout<<"Enter data: ";
    cin>>newnode->data;

    DCLL *nxt = temp->next;

    newnode->next = nxt;
    newnode->prev = temp;

    temp->next = newnode;
    nxt->prev = newnode;

    display();
}


//----------------------------------
// REMOVE FIRST
//----------------------------------
void remove_first(){
    if(first == NULL){ cout<<"List empty\n"; return; }

    if(first->next == first){
        delete first;
        first = NULL;
        display();
        return;
    }

    DCLL *last = first->prev;
    temp = first;

    first = first->next;
    first->prev = last;
    last->next = first;

    delete temp;

    display();
}


//----------------------------------
// REMOVE LAST
//----------------------------------
void remove_last(){
    if(first == NULL){ cout<<"List empty\n"; return; }

    if(first->next == first){
        delete first;
        first = NULL;
        display();
        return;
    }

    DCLL *last = first->prev;
    temp = last->prev;

    temp->next = first;
    first->prev = temp;

    delete last;

    display();
}


//----------------------------------
// REMOVE BY VALUE
//----------------------------------
void remove_value(){
    if(first == NULL){ cout<<"List empty\n"; return; }

    int val;
    cout<<"Enter value: ";
    cin>>val;

    temp = first;

    do{
        if(temp->data == val){
            if(temp == first){
                remove_first();
                return;
            }

            DCLL *p = temp->prev;
            DCLL *n = temp->next;

            p->next = n;
            n->prev = p;

            delete temp;

            display();
            return;
        }
        temp = temp->next;

    }while(temp != first);

    cout<<"Value not found\n";
}


//----------------------------------
// SWAP TWO NODES
//----------------------------------
void swap_nodes(){
    int a,b;
    cout<<"Enter value1: ";
    cin>>a;
    cout<<"Enter value2: ";
    cin>>b;

    if(a==b){ cout<<"Same values\n"; return; }

    DCLL *x=NULL, *y=NULL;
    temp = first;

    do{
        if(temp->data == a) x = temp;
        if(temp->data == b) y = temp;
        temp = temp->next;
    }while(temp != first);

    if(x==NULL || y==NULL){
        cout<<"Value not found\n";
        return;
    }

    int t = x->data;
    x->data = y->data;
    y->data = t;

    display();
}


//----------------------------------
// SEARCH
//----------------------------------
void search_node(){
    int v,i=1;
    cout<<"Enter value to search: ";
    cin>>v;

    temp = first;
    do{
        if(temp->data == v){
            cout<<"Found at position "<<i<<"\n";
            display();
            return;
        }
        temp = temp->next;
        i++;
    }while(temp!=first);

    cout<<"Not found\n";
}


//----------------------------------
// COUNT NODES
//----------------------------------
void count_nodes(){
    int c=0;
    temp = first;

    do{
        c++;
        temp=temp->next;
    }while(temp!=first);

    cout<<"Total nodes: "<<c<<"\n";
    display();
}


//----------------------------------
// SORT ASCENDING
//----------------------------------
void sort_asc(){
    DCLL *i = first;
    do{
        DCLL *j = i->next;
        while(j != first){
            if(i->data > j->data)
                swap(i->data, j->data);
            j = j->next;
        }
        i = i->next;
    }while(i != first);

    display();
}


//----------------------------------
// SORT DESCENDING
//----------------------------------
void sort_desc(){
    DCLL *i = first;
    do{
        DCLL *j = i->next;
        while(j != first){
            if(i->data < j->data)
                swap(i->data, j->data);
            j = j->next;
        }
        i = i->next;
    }while(i != first);

    display();
}


//----------------------------------
// ROTATE LEFT
//----------------------------------
void rotate_left(){
    int k;
    cout<<"Rotate left by: ";
    cin>>k;

    while(k--) first = first->next;

    display();
}


//----------------------------------
// ROTATE RIGHT
//----------------------------------
void rotate_right(){
    int k;
    cout<<"Rotate right by: ";
    cin>>k;

    while(k--) first = first->prev;

    display();
}


//----------------------------------
// COPY LIST
//----------------------------------
void copy_list(){
    if(first == NULL){ cout<<"List empty\n"; return; }

    DCLL *copy = new DCLL;
    copy->data = first->data;
    copy->next = copy;
    copy->prev = copy;

    DCLL *cur = first->next;

    while(cur != first){
        DCLL *n = new DCLL;
        n->data = cur->data;

        DCLL *last = copy->prev;

        n->next = copy;
        n->prev = last;

        last->next = n;
        copy->prev = n;

        cur = cur->next;
    }

    cout<<"Copied list: ";
    temp = copy;

    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=copy);

    cout<<"\n";
}


//----------------------------------
// MAIN
//----------------------------------
int main(){
    int ch;

    create_first();

    do{
        cout<<"\n--- DCLL OPERATIONS ---\n";
        cout<<"1. Add begin\n";
        cout<<"2. Add end\n";
        cout<<"3. Add many\n";
        cout<<"4. Add position\n";
        cout<<"5. Remove first\n";
        cout<<"6. Remove last\n";
        cout<<"7. Remove value\n";
        cout<<"8. Swap nodes\n";
        cout<<"9. Search\n";
        cout<<"10. Count nodes\n";
        cout<<"11. Sort asc\n";
        cout<<"12. Sort desc\n";
        cout<<"13. Rotate left\n";
        cout<<"14. Rotate right\n";
        cout<<"15. Copy list\n";
        cout<<"16. Exit\n";
        cout<<"Enter choice: ";
        cin>>ch;

        switch(ch){
            case 1: add_begin(); break;
            case 2: add_end(); break;
            case 3: add_many(); break;
            case 4: add_pos(); break;
            case 5: remove_first(); break;
            case 6: remove_last(); break;
            case 7: remove_value(); break;
            case 8: swap_nodes(); break;
            case 9: search_node(); break;
            case 10: count_nodes(); break;
            case 11: sort_asc(); break;
            case 12: sort_desc(); break;
            case 13: rotate_left(); break;
            case 14: rotate_right(); break;
            case 15: copy_list(); break;
            case 16: cout<<"Exit\n"; break;
            default: cout<<"Invalid\n";
        }

    }while(ch != 16);
}
