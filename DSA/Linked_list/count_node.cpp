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

int count(node *p){
    int cnt = 0;
    while(p != 0){
        cnt++;
        p = p -> next;
    }
    return cnt;
}
int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    create(arr, 5);
    cout << count(first);
    return 0;
}