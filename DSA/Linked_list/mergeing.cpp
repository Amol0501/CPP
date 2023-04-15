#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node *next;
}*first, *second, *third;

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

void create2(int arr[], int n){
    node *t, *last;
    second = new node;
    second -> data = arr[0];
    second -> next = NULL;
    last = second;
    for(int i = 1; i < n; i++){
        t = new node;
        t -> data = arr[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

void merge(node *p, node *q){
        // cout << "iaetk";x
    node *last;
    last = new node;
    if(p -> data > q -> data){
        third = q;
        q = q -> next;
        third -> next = NULL;
    }
    else{
        third = p;
        p = p -> next;
        third -> next = NULL;
    }
    while(p != 0 && q != 0){
        if(p -> data < q -> data){
            last -> next = p;
            last = p;
            p = p -> next;
            last -> next = NULL;
        }
        else{
            last -> next = q;
            last = q;
            q = q -> next;
            last -> next = NULL;
        }
    }
    if(p) last -> next = p;
    if(q) last -> next = q;
}

void display(node *p){
    while(p != 0){
        cout << p -> data << " ";
        p = p -> next;
    }
}
int main(){
    int arr[5] = {1, 3, 5, 7, 9};
    int arr2[4] = {2, 4, 6, 8};
    create(arr, 5);
    create2(arr2, 4);
    display(first);
    cout << endl;
    display(second);
    merge(first, second);
    cout << endl;
    // display(third);
    // cout << endl;
    display(second);
    // cout << " jenktlr;";
    return 0;
}