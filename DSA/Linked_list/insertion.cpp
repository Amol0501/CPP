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

void display(node *p){
    while(p != 0){
        cout << p -> data << " ";
        p = p -> next;
    }
}

void insert(node *p, int ele, int pos){
    node *q;
    q = new node;
    q -> data = ele;
    for(int i = 0 ; i < pos-1; i++){
        p = p -> next;
    }
    q -> next = p -> next;
    p -> next = q;
}


int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    create(arr, 5);
    display(first);
    int ele, pos;
    cin >> ele >> pos;
    insert(first, ele, pos);
    display(first);
    return 0;
}