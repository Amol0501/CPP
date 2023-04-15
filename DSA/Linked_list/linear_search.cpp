#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node *next;
}*first;

void create(int arr[], int n){
    node *last, *t;
    first = new node;
    first -> data = arr[0];
    first -> next = NULL;
    last = first;

    for(int i = 1 ; i < n ; i++){
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

int search(node *p, int ele){
    while(p != 0){
        if(p -> data == ele){
            return p->data;
        }
        p = p -> next;
    }
    return 0;
}
int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    create(arr, 5);
    display(first);
    int ele;
    cin >> ele;
    cout << search(first, ele);
}