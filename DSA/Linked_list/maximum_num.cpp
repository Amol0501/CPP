#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node *next;
}*first;


void create(int arr[] , int n){
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
    if(p != 0){
        cout << p -> data << " ";
        display(p -> next);
    }
}

int max(node *p){
    int max = INT16_MIN;
    while(p != 0){
        if(max < p -> data)
            max = p -> data;
        p = p -> next;
    }
    return max;
}

int main(){
    int arr[5] = {1, 2, 12, 111, 5};
    create(arr, 5);
    display(first);
    cout << "\nMaximum element is: " << max(first);
}
