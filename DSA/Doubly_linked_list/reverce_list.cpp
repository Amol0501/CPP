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
        t -> next = last -> next;
        t -> prev = last;
        last -> next = t;
        last = t;
    }
}

void reverce(node *p){
    node *temp;
    while(p != 0){
        temp = p -> next;
        p -> next = p -> prev;
        p -> prev = temp;
        p = p -> prev;
        if(p != NULL && p -> next == NULL)
            first = p;
    }
}
void display(node *p){
    while(p != 0){
        cout << p -> data << " ";
        p = p -> next;
    }
}
int main(){
    int arr[6] = {1, 2, 3, 4, 5, 6};
    create(arr, 6);
    reverce(first);
    display(first);

    return 0;
}