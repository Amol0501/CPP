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
    while (p != 0){
        cout << p -> data << " ";
        p = p -> next;
    }
}
int main(){
    // node n1;
    int arr[5] = {1, 2, 3, 4, 5};
    create(arr, 5);
    display(first);
    // cout << n1.sum()
    return 0;
}