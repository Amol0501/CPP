#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node *next;
}*first;

void create(int arr[], int n){
    node *t, *last;
    first = new node;
    first -> data = arr[0];
    first -> next = NULL;
    last = first;
    for(int i = 1; i < n; i++){
        t = new node;
        t -> data = arr[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

void delete_ele(node *p, int pos){ // position /index
cout << "aiengioerngin";
    node *q = new node;
    for(int i = 0; i < pos-1; i++){
        p = p -> next;
    }
    q = p;
    q -> next = p -> next;
    delete p;
}
void remove_duplicate(node *p){
    node *q = new node;
    q = p;
    int pos = 0;
    while(p != 0){
        cout << "While";
        if(p -> data == q -> data){
            cout << "if";
            delete_ele(first, pos);
            // q = p;
            p = p -> next;
        }
        else{
            cout << "else";
            pos++;
            q = p;
            p = p -> next;
        }
    }
}

void display(node *p){
    while(p != 0){
        cout << p -> data << " ";
        p = p -> next;
    }
}
int main(){
    int arr[5] = {1, 3, 3, 4, 5};
    create(arr, 5);
    display(first);
    remove_duplicate(first);
    display(first);
    return 0;
}