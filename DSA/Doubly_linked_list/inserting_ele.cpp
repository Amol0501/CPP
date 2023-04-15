#include<iostream>
using namespace std;
class node{
    public:
        node *prev;
        int data;
        node *next;
}*first;

void create(int arr[], int n){
    node *t, *last;
    first = new node;
    first -> prev = NULL;
    first -> data = arr[0];
    first -> next = NULL;
    last = first;

    for(int i = 1; i < n; i++){
        t = new node;
        t -> data = arr[i];
        t -> prev = last;
        t -> next = last -> next;
        last -> next = t;
        last = t;
    }
}
void inserting(node *p, int ele, int pos){
    node *t;
    t = new node;
    t -> data = ele;
    t -> prev = t -> next = NULL;
    for(int i = 0; i < pos - 2; i++){
        p = p -> next;
    }
    node *q;
    q = p -> next;
    p -> next = t;
    t -> next = q;
    q -> prev = t;
    t -> prev = p;
    
}
void display(node *p){
    while(p != 0){
        cout << p -> data << " ";
        p = p -> next;
    }
    
}
int main(){
    int arr[6] = {1, 2, 3, 5, 6, 7};
    create(arr, 6);
    int ele, pos;
    cin >> ele >> pos;
    inserting(first, ele, pos);
    display(first);
    return 0;
}